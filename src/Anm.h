#include "AnmAscii.h"
#include "AnmBullets.h"
#include "AnmEffects.h"
#include "AnmEnemy.h"
#include "AnmFront.h"
#include "AnmPl00.h"
#include "AnmPl01.h"
#include "AnmPl03.h"
#include "AnmSt01.h"
#include "PlayerHUD.h"
#include "textAnm.h"

#ifndef ANM_H
#define ANM_H

inline void AnmInitAll()
{
    AnmAscii::Init();
    AnmBullets::Init();
    AnmEffects::Init();
    AnmEnemy::Init();
    AnmFront::Init();
    AnmPl00::Init();
    AnmPl01::Init();
    AnmPl03::Init();
    AnmSt01::Init();
    AsciiManager::Init();
}

#endif
