#ifndef ANMPL01
#define ANMPL01

#include "AnmManagerOld/AnmManager.h"

class AnmPl01 {
    public:
        static void Init();
};

extern void pl01Center(AnimScript* anm);
extern void pl01ToLeft(AnimScript* anm);
extern void pl01FromLeft(AnimScript* anm);
extern void pl01ToRight(AnimScript* anm);
extern void pl01FromRight(AnimScript* anm);

extern void pl01Bullet0(AnimScript* anm);
extern void pl01Bullet1_1(AnimScript* anm);
extern void pl01Bullet1_2(AnimScript* anm);
extern void pl01Bullet1_3(AnimScript* anm);
extern void pl01Bullet1Hit(AnimScript* anm);
extern void pl01Bullet2_1(AnimScript* anm);
extern void pl01Bullet2_1Hit(AnimScript* anm);
extern void pl01Bullet2_2(AnimScript* anm);
extern void pl01Bullet2_2Hit(AnimScript* anm);
extern void pl01Bullet2_3(AnimScript* anm);
extern void pl01Bullet2_3Hit(AnimScript* anm);

extern void pl01Option(AnimScript* anm);
extern void pl01OptionFP(AnimScript* anm);

extern void pl01Dead(AnimScript* anm);

#endif
