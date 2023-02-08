
#ifndef GAMELOOP_H
#define GAMELOOP_H

#include "Stg01.h"
#include "PlayerEntity.h"
#include "Pickup.h"
#include "cdbg.h"
#include "BulletManager.h"
#include "PauseMenu.h"
#include "CollisionManager.h"
#include "Timer.h"

inline void ENDGAME()
{
    PlayerEntity::DestroyInstance();
    Stg01::UnInit();
    AnmManager::DeleteAll();
    //NSEngine::draw_set_halign(NSEngine::fa_center);
    //NSEngine::draw_set_valign(NSEngine::fa_center);
    CollisionManager::Reset();
}

#endif
