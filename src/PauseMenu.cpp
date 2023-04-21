#include "PauseMenu.h"
#include "AnmFront.h"
#include "GAMELOOP.h"
#include "GameInputs.h"
#include <Engine.hpp>
#include <NSEngine.h>

int PauseMenu::anmback = -1;
int PauseMenu::anmtitle = -1;
int PauseMenu::optionOn = 0;

bool PauseMenu::opened = false;
bool PauseMenu::firstupdate = false;

std::vector<PauseMenu::option> PauseMenu::options;

PauseMenu::conf PauseMenu::Confirm;
#include "Game.h"
void PauseMenu::Open(int i)
{
    if (opened)
        return;
    opened = true;
    firstupdate = true;
    NSEngine::getInstance()->flags().val |= 0b10000000;
    anmback = AnmManager::newAnim(frontPauseBack1, -1, 1);
    anmtitle = AnmManager::newAnim(frontPauseTitle12, -1, 1);
    AnmManager::UpdateChild(anmback, -240, 64, 0, 0, 0, 0, 1, 1, 1);
    AnmManager::UpdateChild(anmtitle, -240, 64, 0, 0, 0, 0, 1, 1, 1);
    optionOn = 0;
    // NSEngine::AudioEngine::PlaySound(gameassets::se_pause);
    switch (i) {
    case 0:
        options.emplace_back(
            0, 0, []() { PauseMenu::Close(); }, true);
        options.emplace_back(
            1, -33, []() {PauseMenu::Close();ENDGAME();NSEngine::getInstance()->flags().val |= 0b01000000; }, false, true);
        options.emplace_back(
            2, -66, []() { PauseMenu::Close(); }, false, true);
        options.emplace_back(
            3, -99, []() { PauseMenu::Close(); }, false);
        options.emplace_back(
            4, -132, []() {PauseMenu::Close();ENDGAME();Stg01::Init(0);PlayerEntity::GetInstance(0); }, false, true);
        break;
    case 1:
        AnmManager::anim(anmtitle)->offset_sprite(1);
        options.emplace_back(
            1, -33, []() {PauseMenu::Close();ENDGAME();NSEngine::getInstance()->flags().val |= 0b01000000; }, true);
    }
}

void PauseMenu::Close()
{
    opened = false;
    NSEngine::getInstance()->flags().val &= 0b01111111;
    AnmManager::interrupt(anmback, 1);
    AnmManager::interrupt(anmtitle, 1);
    for (option o : options)
        o.del();
    options.clear();
}

void PauseMenu::Update()
{
    if (!opened)
        return;
    if (firstupdate) {
        firstupdate = false;
        return;
    }
    int dir = KEYPRESSED(K_DOWN) - KEYPRESSED(K_UP);
    if (Confirm.open) {
        if (dir != 0)
            Confirm.Chg();
        else if (KEYPRESSED(K_SHOOT) || KEYPRESSED(K_CONFIRM))
            Confirm.Confirm();
        else if (Inputs::Keyboard().Pressed(NSK_escape) || KEYPRESSED(K_SPELL)) {
            if (Confirm.confirm) {
                Confirm.Chg();
            } // NSEngine::AudioEngine::PlaySound(gameassets::se_cancel00); }
            else
                Confirm.Confirm();
        }
        return;
    }
    if (dir != 0) {
        // NSEngine::AudioEngine::PlaySound(gameassets::se_select00);
        options[optionOn].isNotOn();
        optionOn += dir;
        optionOn = (int)math::warp((float)optionOn, 0, (float)options.size());
        options[optionOn].isOn();
    } else if (KEYPRESSED(K_SHOOT) || KEYPRESSED(K_CONFIRM))
        options[optionOn].click();
    if (Inputs::Keyboard().Pressed(NSK_escape))
        Close();
}

PauseMenu::option::option(int sprite, float yoffset, std::function<void(void)> click, bool first, bool confirm)
    : onClick(click)
{
    needsConfirm = confirm;
    anm = AnmManager::newAnim(frontPauseOption1, -1, 1);
    AnmManager::anim(anm)->incy(yoffset);
    AnmManager::anim(anm)->offset_sprite(sprite);
    AnmManager::anim(anm)->raise_interrupt(first ? 17 : 3);
    AnmManager::UpdateChild(anm, -112, 48, 0, 0, 0, 0, 1, 1, 1);
}

void PauseMenu::option::isOn()
{
    AnmManager::interrupt(anm, 7);
}
void PauseMenu::option::isNotOn()
{
    AnmManager::interrupt(anm, 3);
}
void PauseMenu::option::click()
{
    // AnmManager::interrupt(anm,6);
    // NSEngine::ScheduleTask(30,[this](){
    //     if (needsConfirm) Confirm.Open(onClick);
    //     else onClick();
    // },-1,true);
    // NSEngine::AudioEngine::PlaySound(gameassets::se_ok00);
}
void PauseMenu::option::del()
{
    AnmManager::interrupt(anm, 1);
}

void PauseMenu::conf::Open(std::function<void(void)> funct)
{
    func = funct;
    open = true;
    confirm = false;
    anmtitle = AnmManager::newAnim(frontPauseTitle3, -1, 1);
    anmyes = AnmManager::newAnim(frontPauseOption2, -1, 1);
    anmno = AnmManager::newAnim(frontPauseOption2, -1, 1);
    AnmManager::anim(anmyes)->offset_sprite(10);
    AnmManager::anim(anmno)->offset_sprite(11);
    AnmManager::anim(anmno)->incy(-30);
    AnmManager::UpdateChild(anmyes, -112, 48, 0, 0, 0, 0, 1, 1, 1);
    AnmManager::UpdateChild(anmno, -112, 48, 0, 0, 0, 0, 1, 1, 1);
    AnmManager::UpdateChild(anmtitle, -112, 48, 0, 0, 0, 0, 1, 1, 1);
    AnmManager::interrupt(anmyes, 3);
    AnmManager::interrupt(anmno, 17);
    AnmManager::interrupt(PauseMenu::anmtitle, 14);
    AnmManager::interrupt(PauseMenu::anmback, 14);
    for (option o : options)
        AnmManager::interrupt(o.anm, 5);
}

void PauseMenu::conf::Chg()
{
    if (confirm) {
        confirm = false;
        AnmManager::interrupt(anmno, 7);
        AnmManager::interrupt(anmyes, 3);
    } else {
        confirm = true;
        AnmManager::interrupt(anmno, 3);
        AnmManager::interrupt(anmyes, 7);
    }
    // NSEngine::AudioEngine::PlaySound(gameassets::se_select00);
}

void PauseMenu::conf::Confirm()
{
    if (confirm) {
        AnmManager::interrupt(anmyes, 6);
    } // NSEngine::AudioEngine::PlaySound(gameassets::se_ok00);}
    else {
        AnmManager::interrupt(anmno, 6);
    } // NSEngine::AudioEngine::PlaySound(gameassets::se_cancel00);}
    // NSEngine::ScheduleTask(30,[this](){
    // AnmManager::interrupt(PauseMenu::anmtitle,7);
    // AnmManager::interrupt(PauseMenu::anmback,7);
    // for (option o : options) AnmManager::interrupt(o.anm,4);
    // AnmManager::interrupt(options[optionOn].anm,17);
    // if (confirm) func();
    // open = false;
    // AnmManager::interrupt(anmtitle,1);
    // AnmManager::interrupt(anmyes,1);
    // AnmManager::interrupt(anmno,1);
    // },-1,true);
}
