#include "PlayerEntity.h"
#include "AnmEffects.h"
#include "AnmFront.h"
#include "BulletManager.h"
#include "CollisionManager.h"
#include "ECLManager.h"
#include "GameInputs.h"
#include "PauseMenu.h"
#include "Pickup.h"
#include "PlayerBullet.h"
#include "Players.h"
#include "cdbg.h"
#include <FileOpener.h>
#include <math/math.h>
#define PLAYER_BORDER_LEFT -184
#define PLAYER_BORDER_RIGHT 184
#define PLAYER_BORDER_TOP 194
#define PLAYER_BORDER_BOTTOM -208
#define PLAYER_COLLECTION_LINE 120
PlayerEntity::PlayerEntity(int player)
{
    PlayerData* data = nullptr;
    switch (player) {
    case 0:
        data = &Pl00;
        break;
    case 1:
        data = &Pl01;
        break;
    case 2:
        data = &Pl02;
        break;
    case 3:
        data = &Pl03;
        break;
    default:
        data = &Pl00;
    }
    anm = data->anim();
    float hb, gb;
    ShooterManager::Init(data, maxpower, powerstep, hb, gb, itembox, speed_nf, speed_f, maxdmg);
    power = powerstep;
    HUD = new PlayerHUD(0, maxpower, powerstep);
    CollisionManager::PlayerBox(x, y, hb, gb);
}

PlayerEntity* PlayerEntity::Instance = nullptr;
PlayerEntity* PlayerEntity::GetInstance(int player)
{
    if (Instance == nullptr)
        Instance = new PlayerEntity(player != -1 ? player : 0);
    return Instance;
}
void PlayerEntity::DestroyInstance()
{
    delete Instance;
    Instance = nullptr;
}

PlayerEntity::~PlayerEntity()
{
    delete anm;
    delete HUD;
}

void PlayerEntity::Collect(int PickupType, float ywhencollected)
{
    int lifeforextends = life - life % 5 + 5;
    int spellfornew = spell - spell % 5 + 5;
    int powerforpowerup = (1 + floor((float)power / (float)powerstep)) * powerstep;
    int power_before = power;
    switch (PickupType) {
    case 0:
        if (power < maxpower) {
            power++;
            score += 100;
            break;
        }
    case 1: {
        int value = (float)pointValue * fmin(-0.00249f * (-(float)ywhencollected + 240.f) + 1.3f, 1.f);
        value -= value % 10;
        score += value;
        Pickup::CreateCollectText(std::to_string(value), x, y, 255, 255, value == pointValue ? 0 : 255);
        break;
    }
    case 2:
        power += powerstep;
        break;
    case 3:
        life += 1;
        break;
    case 4:
        life += 5;
        break;
    case 5:
        spell += 1;
        break;
    case 6:
        spell += 5;
        break;
    case 7:
        power = maxpower;
        break;
    }
    if (power_before != power) {
        if (power >= powerforpowerup) {
            // NSEngine::AudioEngine::PlaySound(gameassets::se_powerup);
            Pickup::CreateCollectText("p", x, y, 255, 255, 0);
        } else {
            float pow = 100.f * (float)power / (float)powerstep;
            Pickup::CreateCollectText(std::to_string((int)pow), x, y);
        }
        if (power_before < maxpower && power >= maxpower)
            AnmManager::newAnim(frontFullPower);
        if (power > maxpower)
            power = maxpower;
    }
    if (life > 40)
        life = 40;
    if (spell > 40)
        spell = 40;
    if (life >= lifeforextends) {
        // NSEngine::AudioEngine::PlaySound(gameassets::se_extend);
        AnmManager::newAnim(frontExtend);
    }
    if (spell >= spellfornew) { }
    // NSEngine::AudioEngine::PlaySound(gameassets::se_cardget);
}

void PlayerEntity::Update(float framespeed)
{
    if (controllable) {

        /////   MOVE   /////
        math::shift_vector(xp, x);
        math::shift_vector(yp, y);
        hsp = hsp_frac;
        vsp = vsp_frac;
        static int anmSlow = -1;
        bool lshift = KEYDOWN(K_FOCUS);
        if (!focus && lshift)
            anmSlow = AnmManager::newAnim(effectSlow2);
        else if (focus && !lshift) {
            AnmManager::interrupt(anmSlow, 1);
            anmSlow = -1;
        }
        focus = lshift;
        int xdir = KEYDOWN(K_RIGHT) - KEYDOWN(K_LEFT);
        int ydir = KEYDOWN(K_UP) - KEYDOWN(K_DOWN);
        if (xdir != 0 || ydir != 0) {
            float dir = math::point_direction(0, 0, xdir, ydir);
            hsp += math::lengthdir_x(framespeed * (focus ? speed_f : speed_nf), dir);
            vsp += math::lengthdir_y(framespeed * (focus ? speed_f : speed_nf), dir);
        }
        x += floor(hsp);
        y += floor(vsp);
        if (x > PLAYER_BORDER_RIGHT) {
            x = PLAYER_BORDER_RIGHT;
            hsp = 0;
            xdir = 0;
        }
        if (x < PLAYER_BORDER_LEFT) {
            x = PLAYER_BORDER_LEFT;
            hsp = 0;
            xdir = 0;
        }
        if (y > PLAYER_BORDER_TOP) {
            y = PLAYER_BORDER_TOP;
            vsp = 0;
        }
        if (y < PLAYER_BORDER_BOTTOM) {
            y = PLAYER_BORDER_BOTTOM;
            vsp = 0;
        }
        hsp_frac = hsp - floor(hsp);
        vsp_frac = vsp - floor(vsp);

        if (y > PLAYER_COLLECTION_LINE)
            Pickup::Collect_All();

        /////   ANIMATION   /////
        anm->Update(xdir, x, y);
        if (anmSlow != -1)
            AnmManager::UpdateChild(anmSlow, x, y, 0, 0, 0, 0, 1, 1, true);
    }

    /////   SHOOT   /////
    bool sht = KEYDOWN(K_SHOOT) && canshoot && controllable;
    ShooterManager::SetPower(power);
    ShooterManager::Update(sht, focus, framespeed);

    HUD->Update(power, score, life, spell, pointValue, graze, framespeed);

    /////   DIE   /////
    if (deadframe == 8) {
        Pickup::unCollect_All();
        anm->PlayAnimSP();
        life -= 5;
        AnmManager::UpdateChild(AnmManager::newAnim(effectExplodeLarge), x, y, 0, 0, 0, 0, 1, 1, 1);
        ShooterManager::OptionDie();
        controllable = false;
        power = fmax(powerstep, power - powerstep / 2);
        // drop items :
        // float r = 165;
        float a = PI / 12.f;
        Pickup::SpawnPickup(0, x, y, x + math::lengthdir_x(165, PI / 2.f), y + math::lengthdir_y(165, PI / 2.f));
        Pickup::SpawnPickup(0, x, y, x + math::lengthdir_x(165, PI / 2.f - a), y + math::lengthdir_y(165, PI / 2.f - a));
        Pickup::SpawnPickup(0, x, y, x + math::lengthdir_x(165, PI / 2.f + a), y + math::lengthdir_y(165, PI / 2.f + a));
        Pickup::SpawnPickup(0, x, y, x + math::lengthdir_x(165, PI / 2.f - 2 * a), y + math::lengthdir_y(165, PI / 2.f - 2 * a));
        Pickup::SpawnPickup(0, x, y, x + math::lengthdir_x(165, PI / 2.f + 2 * a), y + math::lengthdir_y(165, PI / 2.f + 2 * a));
        Pickup::SpawnPickup(0, x, y, x + math::lengthdir_x(165, PI / 2.f - 3 * a), y + math::lengthdir_y(165, PI / 2.f - 3 * a));
        Pickup::SpawnPickup(0, x, y, x + math::lengthdir_x(165, PI / 2.f + 3 * a), y + math::lengthdir_y(165, PI / 2.f + 3 * a));
        cdbg::Fail();
        ECLManager::CAPTURE = false;
        x = 0;
        y = -240;
        invFrame = 240;
        if (life < 0)
            PauseMenu::Open(1);
    } else if (deadframe == 28)
        anm->Reset();
    else if (deadframe > 28 && deadframe < 68) {
        y += 1.5f;
        anm->Update(0, x, y);
        BulletManager::etClear();
    } else if (deadframe == 68) {
        deadframe = 0;
        controllable = true;
        ShooterManager::OptionRespawn();
    }
    if (deadframe > 0)
        deadframe++;

    /////   INVINCIBILITY   /////
    if (invFrame > 0) {
        invFrame--;
        if (invFrame % 2 == 0) {
            if (invFrame % 4 == 0)
                anm->Anim()->color_time(2, 0, 255, 255, 255);
            else
                anm->Anim()->color_time(2, 0, 0, 0, 255);
        }
    }
}

void PlayerEntity::Die()
{
    if (invFrame > 0 || deadframe > 0)
        return;
    deadframe = 1;
    // static int src = NSEngine::AudioEngine::CreateSource();
    // NSEngine::AudioEngine::PlaySoundAtSource(src,gameassets::se_pldead00);
    AnmManager::UpdateChild(AnmManager::newAnim(effectExplode), x, y, 0, 0, 0, 0, 1, 1, 1);
}

void PlayerEntity::Graze()
{
    graze++;
    score += 10;
    // static int src = NSEngine::AudioEngine::CreateSource();
    // NSEngine::AudioEngine::PlaySoundAtSource(src,gameassets::se_graze);
    AnmManager::UpdateChild(AnmManager::newAnim(effectBase4), x, y, 0, 0, 0, 0, 1, 1, 1);
}
