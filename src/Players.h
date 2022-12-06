#ifndef PLAYER00_H
#define PLAYER00_H

#include "AnmPl00.h"
#include "AnmPl01.h"
#include "AnmPl03.h"
#include "THAnim.h"

#include <functional>

struct PlayerData {
    std::function<std::string(void)> shtfile;
    std::function<THAnim*(void)> anim;
    std::function<animscript_t(bool)> OptionAnm;
    std::function<animscript_t(int)> BulletAnm;
};

extern PlayerData Pl00;
extern PlayerData Pl01;
extern PlayerData Pl02;
extern PlayerData Pl03;

#endif
