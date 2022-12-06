#ifndef ANMPL00
#define ANMPL00

#include <AnmManager.h>

class AnmPl00 {
    public:
        static void Init();
        static std::vector<void(*)(AnimScript*)> buletsanms;             
};


extern void pl00Center(AnimScript* anm);
extern void pl00ToLeft(AnimScript* anm);
extern void pl00FromLeft(AnimScript* anm);
extern void pl00ToRight(AnimScript* anm);
extern void pl00FromRight(AnimScript* anm);
extern void pl00Bullet0(AnimScript* anm);
extern void pl00Bullet1(AnimScript* anm);
extern void pl00Bullet2(AnimScript* anm);
extern void pl00Option(AnimScript* anm);
extern void pl00OptionFP(AnimScript* anm);
extern void pl00Dead(AnimScript* anm);

#endif
