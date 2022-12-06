#include "EnemyData.h"
#include "PlayerEntity.h"
#include "CollisionManager.h"

void EnemyData::Update()
{
    float px = pos.x;
    pos += speed;

    if (hurtBox != -1)
    {
        float d = 0;
        if (CollisionManager::IsHit(2,hurtBox,d))
        {
            d = (float) fmin(d,PlayerEntity::GetInstance()->maxdmg);
            hitangle = CollisionManager::box(2,hurtBox).lasthitangle;
            if (invFrame > 0) d = 0;
            if (d != 0)
            {
                life -= d*(spell?1.f/7.f:1);
                PlayerEntity::GetInstance()->AddScore(100);
                if (hitsound != -1 && hitsoundframe == 0)
                {
                    hitsoundframe = 3;
                    NSEngine::AudioEngine::PlaySound(hitsound);
                }
            }
        }
        CollisionManager::MoveBox(2,hurtBox,pos.x,pos.y);
    }

    if (hitBox != -1)
        CollisionManager::MoveBox(0,hitBox,pos.x,pos.y);

    if (anm0 != nullptr) anm0->Update(pos.x-px,pos.x,pos.y);
    for (size_t i = 0; i < anmSlots.size(); i++)
        AnmManager::UpdateChild(anmSlots[i],pos.x,pos.y,0,0,0,0,1,1,1);

    hitsoundframe = (char) fmax(hitsoundframe-1,0);
    invFrame = (int) fmax(invFrame-1,0);
}

EnemyData::~EnemyData()
{
    if (drops != nullptr) { delete drops; drops = nullptr; }
    if (hurtBox != -1) CollisionManager::destroyEnemyHurtbox(hurtBox);
    if (hitBox != -1) CollisionManager::destroyEnemyHitbox(hitBox);
    if (anm0 != nullptr) { delete anm0; anm0 = nullptr; }
    for (size_t i = 0; i < anmSlots.size(); i++)
        AnmManager::deleteAnim(anmSlots[i]);
    NSEngine::InterpolateManager::RemoveReference(&pos);
    NSEngine::InterpolateManager::RemoveReference(&pos.y);
    NSEngine::InterpolateManager::RemoveReference(&speed);
    NSEngine::InterpolateManager::RemoveReference(&speed.y);
}

#include "Pickup.h"
void EnemyData::DropAll()
{
    if (baseItemDrop != -1)
    Pickup::SpawnPickup(baseItemDrop,pos.x,pos.y,pos.x,pos.y+20.f);
    if (drops == nullptr) return;
    for (DropData::Drop d : drops->BonusDrop)
    {
        if (d.id != -1)
        for(int i = 0; i < d.count; i++)
        {
        float r = drops->radius/2.f + Random::Float01()*drops->radius/2.f; float a = Random::Angle();
        float xx = pos.x+math::lengthdir_x(r,a); float yy = pos.y+math::lengthdir_y(r,a);
        Pickup::SpawnPickup(d.id,xx,yy,xx,yy+20.f);
        }
    }
}

#include "AnmEffects.h"
void EnemyData::Die()
{
    effectExplodeEnemy(pos.x,pos.y,hitangle,dieAnim);
    DropAll();
    PlayerEntity::GetInstance()->AddScore(score);
}
