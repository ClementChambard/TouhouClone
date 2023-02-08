#include "Pickup.h"
#include "PlayerEntity.h"
#include <math/math.h>

#define PICKUP_PICK_DISTANCE 64.f

#include "AnmBullets.h"

int src_pickupsound;

int Pickup::lastPickup = 0;
int Pickup::lastCancelPickup = 0;
Pickup* Pickup::PickupPool;
Pickup* Pickup::CancelPickupPool;

const float gravityheight = (float) abs(0.5f * PICKUP_MAX_SPEED * PICKUP_MAX_SPEED * PICKUP_ACCEL);
const float gravitytime = (float) abs(PICKUP_MAX_SPEED / PICKUP_ACCEL);

void Pickup::Init()
{
    //src_pickupsound = NSEngine::AudioEngine::CreateSource();
    PickupPool = new Pickup[500];
    CancelPickupPool = new Pickup[2048];
}

void Pickup::SpawnPickup(int type, float x, float y, float xto, float yto)
{
    //if (type == 5 || type == 6) NSEngine::AudioEngine::PlaySound(gameassets::se_bonus2);
    //if (type == 3 || type == 4) NSEngine::AudioEngine::PlaySound(gameassets::se_bonus);
    float spd = PICKUP_MAX_SPEED;
    float frames = gravitytime + (yto-y-gravityheight) / PICKUP_MAX_SPEED;
    PickupPool[lastPickup].x = x;
    PickupPool[lastPickup].xto = xto;
    PickupPool[lastPickup].y = y;
    PickupPool[lastPickup].yto = yto;
    PickupPool[lastPickup].type = type;
    PickupPool[lastPickup].spd = spd;
    PickupPool[lastPickup].xstep = (xto-x) / frames;
    PickupPool[lastPickup].active = true;
    PickupPool[lastPickup].collected = false;
    AnmManager::UpdateChild(PickupPool[lastPickup].anm=ItemAnim(type),x,y,0,0,0,0,1,1,1,y>=228?3:0);
    lastPickup = (lastPickup+1)%500;
}

void Pickup::SpawnCancelPickup(float x, float y)
{
    CancelPickupPool[lastCancelPickup].x = x;
    CancelPickupPool[lastCancelPickup].xto = x;
    CancelPickupPool[lastCancelPickup].y = y;
    CancelPickupPool[lastCancelPickup].yto = y;
    CancelPickupPool[lastCancelPickup].type = 50;
    CancelPickupPool[lastCancelPickup].spd = 0;
    CancelPickupPool[lastCancelPickup].xstep = 0;
    CancelPickupPool[lastCancelPickup].active = true;
    CancelPickupPool[lastCancelPickup].collected = false;
    AnmManager::UpdateChild(CancelPickupPool[lastCancelPickup].anm=AnmManager::newAnim(bulletItemCancel),x,y,0,0,0,0,1,1,1);
    lastCancelPickup = (lastCancelPickup+1)%2048;
}

void Pickup::Collect_All()
{
    PlayerEntity* player = PlayerEntity::GetInstance();
    for (int i = 0; i < 500; i++) if (PickupPool[i].active && !PickupPool[i].collected)
    {
        PickupPool[i].collected = true;
        PickupPool[i].ywhencollected = player->y;
        PickupPool[i].spd = PICKUP_COLLECTED_MAX_SPEED/2.f;
        PickupPool[i].xstep = 0;
    }
}

void Pickup::unCollect_All()
{
    PlayerEntity* player = PlayerEntity::GetInstance();
    for (int i = 0; i < 500; i++) if (PickupPool[i].active && !PickupPool[i].collected)
    {
        PickupPool[i].collected = false;
        PickupPool[i].ywhencollected = 0;
        PickupPool[i].spd = 0;
        PickupPool[i].xstep = 0;
    }
}

void Pickup::Collect_All(int type)
{
    PlayerEntity* player = PlayerEntity::GetInstance();
    for (int i = 0; i < 500; i++) if (PickupPool[i].active && PickupPool[i].type == type && !PickupPool[i].collected)
    {
        PickupPool[i].collected = true;
        PickupPool[i].ywhencollected = player->y;
        PickupPool[i].spd = 0;
        PickupPool[i].xstep = 0;
    }
}

void Pickup::Update(float framespeed)
{
    PlayerHUD::item = 0;
    PlayerHUD::itemc = 0;
    for (int i = 0; i < 500; i++)
        PickupPool[i].Pupdate(framespeed);
    for (int i = 0; i < 2048; i++)
        CancelPickupPool[i].Pupdate(framespeed);
}

void Pickup::Pupdate(float framespeed)
{
        if (!active) return;
        PlayerEntity* player = PlayerEntity::GetInstance();
        if (type == 50) { PlayerHUD::itemc++; ywhencollected++; if (ywhencollected == 20) collected = true; }
        else PlayerHUD::item++;
        if ((type == 0 || type == 3) && player->isMaxPower())  type = 7;
        float dist = math::point_distance_sq(x,y,player->x,player->y);
        float yy = y;
        if (collected)
        {
            if (dist < PICKUP_PICK_DISTANCE)
            {
                active = false;
                AnmManager::deleteAnim(anm);
                anm = -1;
                player->Collect(type, ywhencollected);
                //NSEngine::AudioEngine::PlaySoundAtSource(src_pickupsound, gameassets::se_item00);
                return;
            }
            float ang = math::point_direction(x,y,player->x,player->y);
            spd += PICKUP_COLLECTED_ACCEL;
            if (spd > PICKUP_COLLECTED_MAX_SPEED)  spd = PICKUP_COLLECTED_MAX_SPEED;
            x += math::lengthdir_x(spd, ang);
            y += math::lengthdir_y(spd, ang);
        }
        else
        {
            if (dist < player->itembox*player->itembox)
            {
                collected = true;
                spd = abs(spd);
                xstep = 0;
                ywhencollected = player->y;
                return;
            }
            if (y > yto-gravityheight)  spd += PICKUP_ACCEL;
            if (spd < -PICKUP_MAX_SPEED+1)  spd = -PICKUP_MAX_SPEED+1;
            y += spd;
            if (abs(xto-x) > abs(xstep))  x += xstep;
            if (y < -240 || x < -200 || x > 200)
            {
                active = false;
                AnmManager::deleteAnim(anm);
            }
        }
        if (y < 228) AnmManager::UpdateChild(anm,x,y,0,0,0,0,1,1,true,yy>=228?2:0);
        else AnmManager::UpdateChild(anm,x,type<2?216.f:208.f,0,0,0,0,1,1,true,yy<228?3:0);
}

Pickup::Pickup() {}

#include "textAnm.h"

void Pickup::CreateCollectText(std::string text, float x, float y, int r, int g, int b)
{
    //AsciiElement* e = AsciiManager::newTxt(GL_ L16,gameassets::fnt_pickup1,text);
    //e->set_align(NSEngine::fa_center,NSEngine::fa_center);
    //e->set_color(r,g,b); e->set_alpha(0); e->alpha_time(40,0,255); e->set_pos(x,y); e->pos_time(40,4,x,y+8);
    //std::function<void(void)> f1 = [e](){
        //e->set_font(gameassets::fnt_pickup2);
    //};
    //std::function<void(void)> f2 = [e](){
    //    e->set_font(gameassets::fnt_pickup3);
    //};
    //std::function<void(void)> f3 = [e](){
    //    e->destroy();
    //};
    //NSEngine::ScheduleTask(44,f1);
    //NSEngine::ScheduleTask(52,f2);
    //NSEngine::ScheduleTask(60,f3);
}
