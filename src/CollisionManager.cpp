#include "CollisionManager.h"
#include <math/math.h>

float CollisionManager::playerBoxX;
float CollisionManager::playerBoxY;
float CollisionManager::playerBoxR;
float CollisionManager::playerGBoxR;
int CollisionManager::pos1 = 0;
int CollisionManager::pos2 = 0;
int CollisionManager::pos3 = 0;
CollisionManager::CollisionBox* CollisionManager::EnemyHitbox;
CollisionManager::CollisionBox* CollisionManager::PlayerHitbox;
CollisionManager::CollisionBox* CollisionManager::EnemyHurtbox;


void CollisionManager::Init()
{
    EnemyHitbox = new CollisionBox[3000];
    PlayerHitbox = new CollisionBox[1000];
    EnemyHurtbox = new CollisionBox[200];
}
void CollisionManager::Reset()
{
    delete[] EnemyHitbox;
    delete[] PlayerHitbox;
    delete[] EnemyHurtbox;
    Init();
}
#include "PlayerEntity.h"
void CollisionManager::Update()
{
    PlayerBox(PlayerEntity::GetInstance()->x,PlayerEntity::GetInstance()->y);
    for (int i = 0; i < 3000; i++)
    {
        if (!EnemyHitbox[i].active) continue;
        float dist = math::point_distance_sq(playerBoxX,playerBoxY,EnemyHitbox[i].x,EnemyHitbox[i].y);
        if (dist < (EnemyHitbox[i].r+playerBoxR)*(EnemyHitbox[i].r+playerBoxR))
        {
            EnemyHitbox[i].iscolliding = true;
            PlayerEntity::GetInstance()->Die();
        }
        else if (!EnemyHitbox[i].grazed && dist < (EnemyHitbox[i].r+playerGBoxR)*(EnemyHitbox[i].r+playerGBoxR))
        {
            EnemyHitbox[i].grazed = true; 
            PlayerEntity::GetInstance()->Graze();
        }
    }

    for (int i = 0; i < 200; i++) EnemyHurtbox[i].damage = 0;

    for (int i = 0; i < 1000; i++)
    {
        if (!PlayerHitbox[i].active) continue;
        for (int j = 0; j < 200; j++)
        {
            if (!EnemyHurtbox[j].active) continue;
            float dist = math::point_distance_sq(PlayerHitbox[i].x,PlayerHitbox[i].y,EnemyHurtbox[j].x,EnemyHurtbox[j].y);
            if (dist < (PlayerHitbox[i].r+EnemyHurtbox[j].r)*(PlayerHitbox[i].r+EnemyHurtbox[j].r))
            {
                EnemyHurtbox[j].iscolliding = true; 
                EnemyHurtbox[j].damage += PlayerHitbox[i].damage;
                EnemyHurtbox[j].lasthitangle = math::point_direction(EnemyHurtbox[j].x,EnemyHurtbox[j].y,PlayerHitbox[i].x,PlayerHitbox[i].y);
                PlayerHitbox[i].iscolliding = true;
            }
        }
    }
}

void CollisionManager::PlayerBox(float x, float y, float radius, float grazeRadius)
{
    playerBoxX = x;
    playerBoxY = y;
    if (radius != -1) playerBoxR = radius;
    if (grazeRadius != -1) playerGBoxR = grazeRadius;
}

int CollisionManager::NewEnemyHitbox(float x, float y, float radius)
{
    int i = 0;
    while (EnemyHitbox[pos1].active && i++ < 3000) pos1 = (pos1+1)%3000;
    EnemyHitbox[pos1].active = true;
    EnemyHitbox[pos1].x = x;
    EnemyHitbox[pos1].y = y;
    EnemyHitbox[pos1].r = radius;
    i = pos1++; pos1%=3000;
    return i;
}
int CollisionManager::NewPlayerHitbox(float x, float y, float radius, float damage)
{
    int i = 0;
    while (PlayerHitbox[pos2].active && i++ < 1000) pos2 = (pos2+1)%3000;
    PlayerHitbox[pos2].active = true;
    PlayerHitbox[pos2].x = x;
    PlayerHitbox[pos2].y = y;
    PlayerHitbox[pos2].r = radius;
    PlayerHitbox[pos2].damage = damage;
    i = pos2++; pos2%=1000;
    return i;
}
int CollisionManager::NewEnemyHurtbox(float x, float y, float radius)
{
    int i = 0;
    while (EnemyHurtbox[pos3].active && i++ < 200) pos3 = (pos3+1)%200;
    EnemyHurtbox[pos3].active = true;
    EnemyHurtbox[pos3].x = x;
    EnemyHurtbox[pos3].y = y;
    EnemyHurtbox[pos3].r = radius;
    i = pos3++; pos3%=200;
    return i;
}

void CollisionManager::destroyEnemyHitbox(int i)
{
    if (i < 3000 && i >= 0) if (EnemyHitbox[i].active)
    {
        EnemyHitbox[i].active = false;
        EnemyHitbox[i].iscolliding = false;
        EnemyHitbox[i].grazed = false;
    }
}
void CollisionManager::destroyPlayerHitbox(int i)
{
    if (i < 1000 && i >= 0) if (PlayerHitbox[i].active)
    {
        PlayerHitbox[i].active = false;
        PlayerHitbox[i].iscolliding = false;
    }
}
void CollisionManager::destroyEnemyHurtbox(int i)
{
    if (i < 200 && i >= 0) if (EnemyHurtbox[i].active)
    {
        EnemyHurtbox[i].active = false;
        EnemyHurtbox[i].iscolliding = false;
        EnemyHurtbox[i].grazed = false;
        EnemyHurtbox[i].damage = 0;
    }
}

int CollisionManager::closestBox(int type, float x, float y)
{
    CollisionBox* array = nullptr;
    int m;
    if (type == 0) { array = EnemyHitbox; m = 3000; }
    if (type == 1) { array = PlayerHitbox; m = 1000; }
    if (type == 2) { array = EnemyHurtbox; m = 200; }
    float dist = 100000000;
    int closest = -1;
    for (int i = 0; i < m; i++)
    {
        if (!array[i].active) continue;
        float d = math::point_distance_sq(array[i].x,array[i].y,x,y);
        if (d < dist) { dist = d; closest = i; }
    }
    return closest;
}

void CollisionManager::boxPosition(int type, int i, float& x, float& y)
{
    if (type == 0) if (i < 3000 && i >= 0) if (EnemyHitbox[i].active) { x = EnemyHitbox[i].x; y = EnemyHitbox[i].y; }
    if (type == 1) if (i < 1000 && i >= 0) if (PlayerHitbox[i].active) { x = PlayerHitbox[i].x; y = PlayerHitbox[i].y; }
    if (type == 2) if (i < 200 && i >= 0) if (EnemyHurtbox[i].active) { x = EnemyHurtbox[i].x; y = EnemyHurtbox[i].y; }
}
CollisionManager::CollisionBox CollisionManager::box(int type, int i)
{
    if (type == 0) if (i < 3000 && i >= 0) return EnemyHitbox[i];
    if (type == 1) if (i < 1000 && i >= 0) return PlayerHitbox[i];
    if (type == 2) if (i < 200 && i >= 0) return EnemyHurtbox[i];
    return {};
}

void CollisionManager::MoveBox(int type, int i, float x, float y)
{
    if (type == 0) if (i < 3000 && i >= 0) if (EnemyHitbox[i].active) { EnemyHitbox[i].x = x; EnemyHitbox[i].y = y; }
    if (type == 1) if (i < 1000 && i >= 0) if (PlayerHitbox[i].active) { PlayerHitbox[i].x = x; PlayerHitbox[i].y = y; }
    if (type == 2) if (i < 200 && i >= 0) if (EnemyHurtbox[i].active) { EnemyHurtbox[i].x = x; EnemyHurtbox[i].y = y; }
}

bool CollisionManager::IsActive(int type, int i)
{
    if (type == 0) if (i < 3000 && i >= 0) return EnemyHitbox[i].active;
    if (type == 1) if (i < 1000 && i >= 0) return PlayerHitbox[i].active;
    if (type == 2) if (i < 200 && i >= 0) return EnemyHurtbox[i].active;
    return false;
}
bool CollisionManager::IsHit(int type, int i, float& damage)
{
    if (type == 0) if (i < 3000 && i >= 0) { damage = EnemyHitbox[i].damage; return EnemyHitbox[i].iscolliding; }
    if (type == 1) if (i < 1000 && i >= 0) { damage = PlayerHitbox[i].damage; return PlayerHitbox[i].iscolliding; }
    if (type == 2) if (i < 200 && i >= 0) { damage = EnemyHurtbox[i].damage; return EnemyHurtbox[i].iscolliding; }
    return false;
}

#include <SpriteManager.h>
void CollisionManager::DEBUG_DRAW_BOXES()
{
    NSEngine::draw_set_layer(NSEngine::engineData::debugLayer);
    for (int i = 0; i < 3000; i++)
    {
        if (EnemyHitbox[i].active) NSEngine::draw_circle_color(EnemyHitbox[i].x-96,EnemyHitbox[i].y,EnemyHitbox[i].r,{255,0,0,128},{255,0,0,128}); 
    }
    for (int i = 0; i < 1000; i++)
    {
        if (PlayerHitbox[i].active) NSEngine::draw_circle_color(PlayerHitbox[i].x-96,PlayerHitbox[i].y,PlayerHitbox[i].r,{0,255,0,128},{0,255,0,128}); 
    }
    for (int i = 0; i < 200; i++)
    {
        if (EnemyHurtbox[i].active) NSEngine::draw_circle_color(EnemyHurtbox[i].x-96,EnemyHurtbox[i].y,EnemyHurtbox[i].r,{0,0,255,128},{0,0,255,128}); 
    }
    NSEngine::draw_circle_color(playerBoxX-96,playerBoxY,playerGBoxR,{255,255,0,128},{255,255,0,128});
    NSEngine::draw_circle_color(playerBoxX-96,playerBoxY,playerBoxR,{255,255,255,255},{255,255,255,255});
}
