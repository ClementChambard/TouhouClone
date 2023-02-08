#include "Game.h"
#include <math/math.h>
#include <math/Random.h>
#include "AnmManagerOld/AnmManager.h"
#include "Pickup.h"
#include "PlayerEntity.h"
#include "cdbg.h"
#include <iostream>
#include "Stg01.h"
#include "BulletManager.h"
#include "Timer.h"
//#include <Profiler.h>
#include "CollisionManager.h"
#include "GAMELOOP.h"
#include "GameInputs.h"
#include "Anm.h"
#include "AnmEffects.h"
#include "AnmBullets.h"

#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480

//constructor + destructor
Game::Game() : NSEngine::IEngine(WINDOW_WIDTH, WINDOW_HEIGHT, "Touhou NS") {}

NSEngine::LayerRenderer* ren;

//init all game objects here
void Game::on_create()
{
    window().addDisplayMode({960, 720, 0});
    window().addDisplayMode({1280, 960, 0});
    window().setDisplayMode(2);

    AnmInitAll();
    setMaxFps(60);
    NSEngine::createCamera(NS_CAM_3D, WINDOW_WIDTH, WINDOW_HEIGHT);

    ren = new NSEngine::LayerRenderer(new NSEngine::AnimShader());
    GL_ Init(ren);
    Pickup::Init();
    BulletManager::Init();
    CollisionManager::Init();

    //ren->addLayer(&NSEngine::engineData::layers[NSEngine::engineData::debugLayer]);

    //NSEngine::draw_set_halign(NSEngine::fa_center);
    //NSEngine::draw_set_valign(NSEngine::fa_center);
    d = 0;
    flags().val |= 0b01000000;
    setRenderFunc(GL_ Render);
}

NSEngine::Color coly = {255,255,0,255};
NSEngine::Color colw = {255,255,255,255};
int p = 0;

void Game::on_update()
{
    if(flags().val & 0b01000000)
    {
        int dnow = d + (KEYPRESSED(K_DOWN)-KEYPRESSED(K_UP));
        if (dnow > 3) dnow = 3; if (dnow < 0) dnow = 0;
        //if (dnow != d) NSEngine::AudioEngine::PlaySound(gameassets::se_select00);
        d = dnow;
        if (Inputs::Keyboard().Pressed(NSK_0)) p = 0;
        if (Inputs::Keyboard().Pressed(NSK_1)) p = 1;
        if (Inputs::Keyboard().Pressed(NSK_2)) p = 2;
        if (Inputs::Keyboard().Pressed(NSK_3)) p = 3;
        if (KEYPRESSED(K_CONFIRM))
        {
            flags().val &= 0b10111111;
            Stg01::Init(d);
            PlayerEntity::GetInstance(p);
            //NSEngine::AudioEngine::PlaySound(gameassets::se_ok00);
        }
    }
    else
    {
        if (Inputs::Keyboard().Pressed(NSK_escape)) PauseMenu::Open(0);
        PauseMenu::Update();
        if (!(flags().val&0b10000000))
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
    AnmManager::Update(1, flags().val & 0b10000000);
}

// game loop
void Game::on_render()
{
    ren->initFrame();
    if (flags().val & 0x01000000)
    {
        NSEngine::draw_set_layer(NSEngine::engineData::debugLayer);
        //NSEngine::SpriteManager::draw_text(gameassets::fnt_base,("Player"+std::to_string(p)).c_str(),{0,220},{1,1},{64,96,255,255});
        //NSEngine::SpriteManager::draw_text(gameassets::fnt_base,"EASY",{0,180},{2,2},d==0?coly:colw);
        //NSEngine::SpriteManager::draw_text(gameassets::fnt_base,"NORMAL",{0,60},{2,2},d==1?coly:colw);
        //NSEngine::SpriteManager::draw_text(gameassets::fnt_base,"HARD",{0,-60},{2,2},d==2?coly:colw);
        //NSEngine::SpriteManager::draw_text(gameassets::fnt_base,"LUNATIC",{0,-180},{2,2},d==3?coly:colw);
    }
    AnmManager::Draw();
    if (flags().flags.debugInfo)
        CollisionManager::DEBUG_DRAW_BOXES();
    //ren->renderLayers();
}


void Game::on_destroy()
{
    BulletManager::Cleanup();
    Pickup::Cleanup();
    CollisionManager::Cleanup();
    AsciiManager::Cleanup();
    AnmManager::Cleanup();
}
