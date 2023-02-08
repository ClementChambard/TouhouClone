#include "BulletManager.h"
#include "AnmBullets.h"
#include "PlayerEntity.h"
#include <math/Random.h>

struct BulletType {
    float hitboxSize;
    int sprite0;
    animscript_t anm;
    char colortype;
    float breaksize;
    int breaknum;
    float breakspeed;
};

std::vector<glm::vec<3,int>> Color16 = {
    {192,192,192},
    {128,  8,  8},
    {255,  8,  8},
    {128,  8,128},
    {224,  8,224},
    { 48, 48,192},
    { 80, 80,255},
    {  8,160,160},
    {  8,224,224},
    {  8,208,  8},
    {  8,255,  8},
    {128,255, 48},
    {192,192,  8},
    {255,255,  8},
    {255,208,  8},
    {255,255,255}
};
std::vector<glm::vec<3,int>> Color8 = {
    {192,192,192},
    {255, 21, 21},
    {224, 32,224},
    { 80, 80,255},
    {  8,224,224},
    {  8,255,  8},
    {255,255,  8},
    {255,255,255}
};
std::vector<glm::vec<3,int>> Color4 = {
    {255, 16, 16},
    {128,  8,255},
    {  8,255,  8},
    {255,255,  8}
};

std::vector<BulletType> BulletTypes = {
    {3.12f,  0,bullets0 ,0,    1.f,2,2}, //pellet           0
    {3.12f, 32,bullets1 ,0,    1.f,2,2}, //pellet2          1
    {3.12f, 16,bullets2 ,0,    1.f,2,2}, //popcorn          2
    {3.12f, 48,bullets2 ,0,    1.f,2,2}, //pellet3          3
    {4.27f, 64,bullets3 ,0,1.6667f,3,2}, //ball             4
    {4.27f, 80,bullets4 ,0,1.6667f,3,2}, //ball2            5
    {4.27f, 96,bullets3 ,0,1.6667f,3,2}, //outline          6
    {4.27f,112,bullets4 ,0,1.6667f,3,2}, //outline2         7
    {3.12f,128,bullets3 ,0,1.6667f,3,2}, //rice             8
    {3.12f,160,bullets3 ,0,1.6667f,3,2}, //kunai            9
    {3.12f,176,bullets3 ,0,1.6667f,3,2}, //shard            10
    {3.12f,208,bullets3 ,0,1.6667f,3,2}, //amulet           11       
    {3.12f,224,bullets3 ,0,1.6667f,3,2}, //arrowhead        12
    {3.12f,240,bullets3 ,0,1.6667f,3,2}, //bullet           13
    {4.27f,256,bullets3 ,0,1.6667f,3,2}, //laserhead        14
    {3.12f,272,bullets3 ,0,1.6667f,3,2}, //bacteria         15
    {4.27f,288,bullets5 ,0,1.6667f,3,2}, //star             16
    {4.27f,  0,bullets3 ,3,1.6667f,3,2}, //coin             17
    {8.73f,368,bulletl0 ,1,2.6667f,3,2}, //mentos           18
    {8.73f,376,bulletl1 ,1,2.6667f,3,2}, //mentos2          19
    {6.32f,392,bulletl0 ,1,2.6667f,3,2}, //jellybean        20
    {6.32f,400,bulletl0 ,1,2.6667f,3,2}, //knife            21
    {6.32f,408,bulletl0 ,1,2.6667f,3,2}, //butterfly        22
    {8.73f,416,bulletl2 ,1,2.6667f,3,2}, //bigstar1         23
    {8.73f,424,bulletl3 ,1,2.6667f,3,2}, //bigstar2         24
    {6.32f,  0,bulletfb0,4,    1.f,1,1}, //fireball0        25
    {6.32f,  0,bulletfb1,4,    1.f,1,1}, //fireball1        26
    {6.32f,  0,bulletfb2,4,    1.f,1,1}, //fireball2        27
    {6.32f,  0,bulletfb3,4,    1.f,1,1}, //fireball3        28
    {8.73f,444,bulletl0 ,1,2.6667f,3,2}, //heart            29
    {8.73f,384,bulletl4 ,1,2.6667f,3,2}, //pulse            30
    {6.32f,452,bulletl6 ,1,2.6667f,3,2}, //arrow            31
    {10.0f,432,bulletl5 ,2,    5.f,4,5}, //bubble           32
    {8.73f,548,bulletorb,1,2.6667f,3,2}, //orb              33
    {3.12f,468,bullets3 ,0,1.6667f,3,2}, //droplet          34
    {3.12f,144,bullets5 ,0,1.6667f,3,2}, //rice spin        35
    {3.12f,192,bullets5 ,0,1.6667f,3,2}, //shard spin       36
    {4.27f,304,bullets6 ,0,1.6667f,3,2}, //star2            37
    {0.00f,352,bullets0 ,0,    1.f,1,1}, //laser            38
    {6.32f,  0,bulletno0,4,    1.f,1,1}, //note0            39
    {6.32f,  0,bulletno1,4,    1.f,1,1}, //note1            40
    {6.32f,  0,bulletno2,4,    1.f,1,1}, //note2            41
    {6.32f,  0,bulletno3,4,    1.f,1,1}, //note3            42
    {6.32f,  0,bulletl0 ,1,2.6667f,3,2}, //rest             43
};
    
std::vector<BulletManager::BulletHandler*> BulletManager::handlers;
BulletManager::Bullet* BulletManager::bullet_pool;
int BulletManager::current_pos = 0;

void BulletManager::Init() { bullet_pool = new Bullet[2000]; }

int BulletManager::AddHandler()
{
    for (size_t i = 0; i < handlers.size(); i++)
        if (handlers[i] == nullptr)
        {
            handlers[i] = new BulletHandler(i);
            return i;
        }
    handlers.push_back(new BulletHandler(handlers.size()));
    return handlers.size()-1;
}

void BulletManager::DestroyHandler(unsigned int& i)
{
    if (i == handlers.size()-1)
    {
        delete handlers[i]; handlers[i] = nullptr;
        while (handlers[i] == nullptr && i >= 0) { handlers.pop_back(); i--; }
    }
    else if (i < handlers.size() && handlers[i] != nullptr) { delete handlers[i]; handlers[i] = nullptr; }
    i = -1;
}

void BulletManager::ClearHandlers()
{
    for (size_t i = 0; i < handlers.size(); i++) if (handlers[i] != nullptr) delete handlers[i];
    handlers.clear();
    handlers.resize(0);
}

void BulletManager::Transform::Apply(Bullet* bu)
{
    switch (type)
    {
    case EX_SPEED_UP:
        bu->saccelframe = 15;
        bu->accel = -10.f/15.f;
        bu->speed += 10.f;
        break;
    case EX_ANIM:
        if (a > 0) AnmManager::interrupt(bu->anm,6+a);
        break;
    case EX_ACCEL_F:
        bu->accel = r;
        bu->angleaccel = 0;
        bu->saccelframe = bu->frame + a;
        break;
    case EX_ACCEL_S:
        bu->angleaccel = r;
        bu->aaccelframe = bu->frame + a;
        break;
    case EX_STEP:
        if (bu->steps >= b) return;
        if (bu->frame < bu->saccelframe) return;
        bu->saccelframe = bu->frame + a;
        bu->accel = -bu->storedspeed/(float)a;
        if (bu->frame != 0) 
        {
            //NSEngine::AudioEngine::PlaySound(handlers[bu->handler]->snd2);
            bu->speed = bu->storedspeed;
            bu->direction += r;
            bu->steps++;
        }
        break;
    case 256:
        bu->dontdespawn=true;
        break;
    }

}

#include "CollisionManager.h"
#include <Error.h>
#include <math/math.h>
void BulletManager::Bullet::Update()
{
    if (frame < saccelframe) speed+=accel;
    if (frame < aaccelframe) direction+=angleaccel;
    if (frame != 0)
    {
        x += math::lengthdir_x(speed,direction);
        y += math::lengthdir_y(speed,direction);
    }
    if (anm != -1) AnmManager::UpdateChild(anm,x,y,0,0,0,direction-PI1_2,1,1,true);
    if (x < -200 || x > 200 || y < -300 || y > 300)
    {
        if (!dontdespawn && frame < 500)
        {
            if (anm != -1) AnmManager::deleteAnim(anm);
            if (box != -1) CollisionManager::destroyEnemyHitbox(box);
            Reset();
        }
    }
    frame ++;
    if (box != -1) CollisionManager::MoveBox(0,box,x,y);
}
#include "Pickup.h"
void BulletManager::Bullet::Delete(bool itemspawn)
{
    if (itemspawn) Pickup::SpawnCancelPickup(x,y);
    int t = BulletTypes[handlers[handler]->anmType].colortype;
    glm::vec<3,int> col = t==0?Color16[handlers[handler]->anmColor]:(t==1?Color8[handlers[handler]->anmColor]:(t==2?Color4[handlers[handler]->anmColor]:glm::vec<3,int>(255,255,255)));
    effectEtamaBreak(x,y,BulletTypes[handlers[handler]->anmType].breaksize,col.r,col.g,col.b,BulletTypes[handlers[handler]->anmType].breaknum,BulletTypes[handlers[handler]->anmType].breakspeed);
    if (anm != -1) AnmManager::interrupt(anm,1);
    if (box != -1) CollisionManager::destroyEnemyHitbox(box);
    Reset();
}

#define BH_MAX_BULLET 2000
BulletManager::BulletHandler::BulletHandler(int id)
{
    this->id = id;
}

BulletManager::BulletHandler::~BulletHandler() {}

void BulletManager::BulletHandler::Fire(float x, float y)
{
    PlayerEntity* p = PlayerEntity::GetInstance();
    float AngToPlayer = math::point_direction(x,y,p->x,p->y);
    float aRing = PI2/(float)ct1;
    //fire bullet :
    if (mode < 9)
    for (int j = 0; j < ct1; j++)
    {
        for (float i = 0; i < ct2; i++)
        {
            float a = 0.f;
            float jj = j - (int)(ct1/2.f) + (1-(ct1%2))*0.5f;
            switch(mode)
            {
                case AIM_AT:
                    a += AngToPlayer;
                case AIM_ST:
                    a += ang1+jj*ang2;
                    break;
                case AIM_RAND:
                case AIM_MEEK:
                    a = Random::Floatm11() * ang2 + ang1;
                    break;
                case AIM_ST_RING2:
                    a -= AngToPlayer;
                case AIM_AWAY_RING:
                    a += aRing/2;
                case AIM_AT_RING:
                    a += AngToPlayer;
                case AIM_ST_RING:
                case AIM_RAND_RING:
                    a += (j*aRing)+ang1+(i*ang2);
                    break;
            }
            float s = spd1 + (spd2-spd1) * (float)i/(float)ct2;
            if (mode == AIM_RAND_RING || mode == AIM_MEEK) s = spd1 + (spd2-spd1)*Random::Float01();
            BulletManager::CreateBullet(id,x,y,s,a);
        }
    }
    else if (mode < 11)
        for (int i = 0; i < ct1; i++)
        {
            for (int j = 0; j < ct2/2+1; j++)
            {
                float a = 0;
                a = aRing*i+ang1;
                if (mode == 9) a+= AngToPlayer;
                float a1 = a-j*ang2;
                float a2 = a+j*ang2;
                float s = spd2+(spd1-spd2)*(1-(float)j/((float)ct2/2+1));
                BulletManager::CreateBullet(id,x,y,s,a1);
                if (j!=0) BulletManager::CreateBullet(id,x,y,s,a2);
            }
        }
    //NSEngine::AudioEngine::PlaySound(snd1);
}

void BulletManager::etClear(float x, float y, float r)
{
    for (int i = 0; i < 2000; i++)
        if (bullet_pool[i].active)
            if (math::point_distance_sq(x,y,bullet_pool[i].x,bullet_pool[i].y) < (r*r))
                bullet_pool[i].Delete(false);
}
void BulletManager::etCancel(float x, float y, float r)
{
    for (int i = 0; i < 2000; i++)
        if (bullet_pool[i].active)
            if (math::point_distance_sq(x,y,bullet_pool[i].x,bullet_pool[i].y) < (r*r))
                bullet_pool[i].Delete(true);
}

void BulletManager::CreateBullet(int id, float x, float y, float s, float a)
{
    int i = 0;
    while(bullet_pool[current_pos].active && i < BH_MAX_BULLET) {current_pos=(current_pos+1)%BH_MAX_BULLET;i++;}
    if (bullet_pool[current_pos].active) bullet_pool[current_pos].Delete(false);
    bullet_pool[current_pos].handler = id;
    bullet_pool[current_pos].frame = 0;
    bullet_pool[current_pos].active = true;
    bullet_pool[current_pos].x = x + handlers[id]->offx;
    bullet_pool[current_pos].y = y + handlers[id]->offy;
    bullet_pool[current_pos].direction = a;
    bullet_pool[current_pos].speed = s;
    bullet_pool[current_pos].storedspeed = s;
    AnmManager::UpdateChild(bullet_pool[current_pos].anm = AnmManager::newAnim(BulletTypes[handlers[id]->anmType].anm),x,y,0,0,0,a,1,1,1);
    AnmManager::anim(bullet_pool[current_pos].anm)->set_sprite(BulletTypes[handlers[id]->anmType].sprite0+handlers[id]->anmColor-1);
    bullet_pool[current_pos].box = CollisionManager::NewEnemyHitbox(x,y,BulletTypes[handlers[id]->anmType].hitboxSize);
    current_pos = (current_pos+1)%BH_MAX_BULLET;
}

