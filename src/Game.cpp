#include "Game.h"
#include <math/math.h>
#include <math/Random.h>
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
//constructor + destructor
Game::Game(){}
Game::~Game(){}

NSEngine::LayerRenderer* ren;

//init all game objects here
void Game::INIT()
{

    NSEngine::Init();

    int windowFlags = 0;
    int windowWidth = 640;
    int windowHeight = 480;

    window.Init("Touhou NS", windowWidth, windowHeight, windowFlags);
    window.addDisplayMode({960, 720, 0});
    window.addDisplayMode({1280, 960, 0});
    window.setDisplayMode(2);

    NSEngine::Subsystems();
    AnmInitAll();
    NSEngine::setMaxFps(60);
    NSEngine::createCamera(NS_CAM_3D, windowWidth, windowHeight);

    ren = new NSEngine::LayerRenderer(new NSEngine::AnimShader());
    GL_ Init(ren);
    Pickup::Init();
    BulletManager::Init();
    CollisionManager::Init();

    NSEngine::EndInit();
    ren->addLayer(&NSEngine::engineData::layers[NSEngine::engineData::debugLayer]);
}

int Game::d;
bool Game::menu;
// game loop
#include "AnmEffects.h"
#include "AnmBullets.h"
void Game::GAMELOOP()
{
    menu = true;
    d = 0;
    int p = 0;
    NSEngine::Color coly = {255,255,0,255};
    NSEngine::Color colw = {255,255,255,255};
    //NSEngine::draw_set_halign(NSEngine::fa_center);
    //NSEngine::draw_set_valign(NSEngine::fa_center);
    while(NSEngine::IsRunning())
    {


        NSEngine::StartFrame();

        NSEngine::StartUpdate();
        if (Inputs::Keyboard().Pressed(NSK_f10)) window.nextDisplaymode();
        if (NSEngine::IsFBF() && !Inputs::Keyboard().Pressed(NSK_backspace) && !Inputs::Keyboard().Down(NSK_equals)) continue;
        NSEngine::UpdateEngine();

        if(menu)
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
                menu = false;
                SETUPGAME(d,p);
                //NSEngine::AudioEngine::PlaySound(gameassets::se_ok00);
            }
        }
        else
            LOOPGAME();
        NSEngine::EndUpdate();

        //ren->initFrame();
        window.InitDrawing();
        if (menu)
        {
            NSEngine::draw_set_layer(NSEngine::engineData::debugLayer);
            //NSEngine::SpriteManager::draw_text(gameassets::fnt_base,("Player"+std::to_string(p)).c_str(),{0,220},{1,1},{64,96,255,255});
            //NSEngine::SpriteManager::draw_text(gameassets::fnt_base,"EASY",{0,180},{2,2},d==0?coly:colw);
            //NSEngine::SpriteManager::draw_text(gameassets::fnt_base,"NORMAL",{0,60},{2,2},d==1?coly:colw);
            //NSEngine::SpriteManager::draw_text(gameassets::fnt_base,"HARD",{0,-60},{2,2},d==2?coly:colw);
            //NSEngine::SpriteManager::draw_text(gameassets::fnt_base,"LUNATIC",{0,-180},{2,2},d==3?coly:colw);
        }
        NSEngine::RenderEngine();
        if (NSEngine::engineData::gameflags & 0b00000010)
            CollisionManager::DEBUG_DRAW_BOXES();
        //ren->renderLayers();
        window.EndDrawing(GL_ Render);

        NSEngine::EndFrame();
    }
}


void Game::CLEAN()
{
    BulletManager::Cleanup();
    Pickup::Cleanup();
    CollisionManager::Cleanup();
    AsciiManager::Cleanup();
    AnmManager::Cleanup();
    window.destroy();
    NSEngine::Quit();
}
