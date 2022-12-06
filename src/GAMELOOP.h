
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

inline void SETUPGAME(int difficulty, int player = -1) //character ...
{
    static int p = 0;
    if (player != -1) p = player;
    Stg01::Init(difficulty);
    PlayerEntity::GetInstance(p);
}

inline void LOOPGAME()
{
    if (Inputs::Keyboard().Pressed(NSK_escape)) PauseMenu::Open(0);
    PauseMenu::Update();       
    if (!(NSEngine::engineData::gameflags&0b10000000))
    {
        PlayerEntity::GetInstance()->Update();
        Pickup::Update();
        cdbg::Update();
        BulletManager::Update();
        CollisionManager::Update();
        Stg01::Update();
        Timer::Update();
    }
}

inline void ENDGAME()
{
    PlayerEntity::DestroyInstance();
    Stg01::UnInit();
    AnmManager::DeleteAll();
    NSEngine::draw_set_halign(NSEngine::fa_center);
    NSEngine::draw_set_valign(NSEngine::fa_center);
    CollisionManager::Reset();
}

#endif
