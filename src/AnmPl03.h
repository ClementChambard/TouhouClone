#ifndef ANMPL03
#define ANMPL03

#include "AnmManagerOld/AnmManager.h"

class AnmPl03 {
    public:
        static void Init();
};

extern void pl03Center(AnimScript* anm);
extern void pl03ToLeft(AnimScript* anm);
extern void pl03FromLeft(AnimScript* anm);
extern void pl03ToRight(AnimScript* anm);
extern void pl03FromRight(AnimScript* anm);

extern void pl03Bullet0(AnimScript* anm);
extern void pl03Bullet1(AnimScript* anm);
extern void pl03Bullet2(AnimScript* anm);

extern void pl03Option(AnimScript* anm);
extern void pl03OptionFP(AnimScript* anm);

extern void pl03Dead(AnimScript* anm);

#endif
