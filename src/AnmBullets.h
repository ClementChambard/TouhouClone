#ifndef ANMBULLETS
#define ANMBULLETS

#include "AnmManagerOld/AnmManager.h"

class AnmBullets {
    public:
        static void Init();
};

extern int ItemAnim(int itemid);

extern void bulletTest1(AnimScript* anm);

extern void bullets0(AnimScript* anm);
extern void bullets1(AnimScript* anm);
extern void bullets2(AnimScript* anm);
extern void bullets3(AnimScript* anm);
extern void bullets4(AnimScript* anm);
extern void bullets5(AnimScript* anm);
extern void bullets6(AnimScript* anm);
extern void bulletl0(AnimScript* anm);
extern void bulletl1(AnimScript* anm);
extern void bulletl2(AnimScript* anm);
extern void bulletl3(AnimScript* anm);
extern void bulletl4(AnimScript* anm);
extern void bulletl5(AnimScript* anm);
extern void bulletl6(AnimScript* anm);
extern void bulletorb(AnimScript* anm);
extern void bulletfb0(AnimScript* anm);
extern void bulletfb1(AnimScript* anm);
extern void bulletfb2(AnimScript* anm);
extern void bulletfb3(AnimScript* anm);
extern void bulletno0(AnimScript* anm);
extern void bulletno1(AnimScript* anm);
extern void bulletno2(AnimScript* anm);
extern void bulletno3(AnimScript* anm);

extern void bulletItemNormal(AnimScript* anm);
extern void bulletItemCancel(AnimScript* anm);

extern void effectEtamaBreak(float x, float y, float s, int r, int g, int b, int n = 2, float speed = 2);

#endif
