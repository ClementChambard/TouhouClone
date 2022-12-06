#include "bulletsScripts.h"
#include <Assets.h>
#include "CollisionManager.h"
#include "AnmEffects.h"
#include <math/Random.h>

std::vector<void (*)(ShooterManager::Bullet*)> pbscr::scrinit;
std::vector<void (*)(ShooterManager::Bullet*)> pbscr::scrtick;
std::vector<void (*)(ShooterManager::Bullet*)> pbscr::scrhit;
std::vector<int> pbscr::sounds;
bool pbscr::initialized = false;


void BulletInitBase(ShooterManager::Bullet* b)
{
    return;
}

void BulletInitRandAngle(ShooterManager::Bullet* b)
{
    b->direction += Random::Floatm11()*.6;
}

void BulletInitHomein(ShooterManager::Bullet* b)
{
    b->additionalData = CollisionManager::closestBox(2,b->x,b->y);
}

void BulletInitLaser(ShooterManager::Bullet* b)
{
    b->persistant = true;
}

void BulletHitBase(ShooterManager::Bullet* b)
{
    b->hit = true;
    b->additionalData = 0;
    b->speed /= 6.f;
    AnmManager::interrupt(b->anm,2);
    CollisionManager::destroyPlayerHitbox(b->box);
}

void BulletHitLaser(ShooterManager::Bullet* b)
{

}

void BulletHitMissile(ShooterManager::Bullet* b)
{
    BulletHitBase(b);
}

void BulletHitSplash1(ShooterManager::Bullet* b)
{
    BulletHitBase(b);
    AnmManager::UpdateChild(AnmManager::newAnim(effectSplash),b->x,b->y,0,0,0,b->direction,1,1,1);
}
void BulletHitSplash2(ShooterManager::Bullet* b)
{
    BulletHitBase(b);
    int a;
    AnmManager::UpdateChild(a=AnmManager::newAnim(effectSplash),b->x,b->y,0,0,0,b->direction,1,1,1);
    AnmManager::anim(a)->set_color(255,128,255);
}

void BulletTickBase(ShooterManager::Bullet* b)
{
    if (!b->active) return;
    if (b->hit)
    {
        if (b->additionalData > 30) b->active = false;
        b->additionalData ++;
    }
    b->x += math::lengthdir_x(b->speed, b->direction);
    b->y += math::lengthdir_y(b->speed, b->direction);
    CollisionManager::MoveBox(1,b->box,b->x,b->y);
    if (b->x > 200 || b->x < -200 || b->y > 300 || b->y < -240) 
    {
        b->active = false;
        AnmManager::deleteAnim(b->anm);
        CollisionManager::destroyPlayerHitbox(b->box);
    }
}

void BulletTickMissile(ShooterManager::Bullet* b)
{
    b->speed = fmin(b->speed+0.2f,30);
    BulletTickBase(b);
}

void BulletTickLaser(ShooterManager::Bullet* b)
{
    BulletHitLaser(b);   
}

void BulletTickHomein(ShooterManager::Bullet* b)
{
    if (!b->active) return;

    if (b->hit)
    {
        if (b->additionalData > 30) b->active = false;
        b->additionalData ++;
    }

    if (b->hit == false && b->additionalData != -1)
    {
        if (CollisionManager::IsActive(2,b->additionalData))
        {
            float x, y; CollisionManager::boxPosition(2,b->additionalData,x,y);
            float d = math::point_direction(b->x,b->y,x,y);
            if (d > b->direction && (d-b->direction < b->direction+2*PI-d) || d < b->direction && (b->direction-d > d+2*PI-b->direction)) b->direction += 0.1;
            else  b->direction -= 0.1;
            if (b->direction > PI) b->direction -= 2*PI;
            if (b->direction < -PI) b->direction += 2*PI;
            if (abs(b->direction-d) < 0.1) b->direction = d;
        }
        else b->additionalData = -1;
    }
    if (b->additionalData == -1)
    {
        b->additionalData = CollisionManager::closestBox(2,b->x,b->y);
    }
    b->x += math::lengthdir_x(b->speed, b->direction);
    b->y += math::lengthdir_y(b->speed, b->direction);
    CollisionManager::MoveBox(1,b->box,b->x,b->y);
    if (b->x > 300 || b->x < -300 || b->y > 300 || b->y < -240)
    {
        b->active = false;
        AnmManager::deleteAnim(b->anm);
        CollisionManager::destroyPlayerHitbox(b->box);
    }
}

void pbscr::Init()
{
    if (initialized) return;
    addInit(&BulletInitBase);
    addInit(&BulletInitHomein);
    addInit(&BulletInitLaser);
    addInit(&BulletInitBase);
    addInit(&BulletInitBase);
    addInit(&BulletInitRandAngle);
    addInit(&BulletInitBase);
    addInit(&BulletInitBase);
    addTick(&BulletTickBase);
    addTick(&BulletTickHomein);
    addTick(&BulletTickLaser);
    addTick(&BulletTickMissile);
    addTick(&BulletTickBase);
    addTick(&BulletTickBase);
    addTick(&BulletTickBase);
    addHit(&BulletHitBase);
    addHit(&BulletHitBase);
    addHit(&BulletHitLaser);
    addHit(&BulletHitMissile);
    addHit(&BulletHitBase);
    addHit(&BulletHitSplash1);
    addHit(&BulletHitSplash2);
    addHit(&BulletHitBase);
    addHit(&BulletHitBase);
    sounds.push_back(gameassets::se_plst00);
    for(int i = 0; i < 63; i++) sounds.push_back(0);
    sounds.push_back(gameassets::se_msl);
    initialized = true;
}

