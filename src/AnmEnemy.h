#ifndef ANMENEMY
#define ANMENEMY
#include <AnmManager.h>

class AnmEnemy {
    public:
        static void Init();
};

void Enm0p1(AnimScript* anm);
void Enm0p2(AnimScript* anm);
void Enm0p3(AnimScript* anm);
void Enm0p4(AnimScript* anm);
void Enm0p5(AnimScript* anm);

void EnmB(AnimScript* anm);
void EnmBfade(AnimScript* anm);

int Enm1(int offset, bool fadein);
void Enm1p1(AnimScript* anm);
void Enm1p2(AnimScript* anm);
void Enm1p3(AnimScript* anm);
void Enm1Fp1(AnimScript* anm);

void Enm2PU(AnimScript* anm);
void Enm2PD(AnimScript* anm);
void Enm2U(AnimScript* anm);
void Enm2D(AnimScript* anm);

int EnmAura(float size, int coltype, int r, int g, int b);
void EnmAuraP1(AnimScript* anm);
void EnmAuraP2(AnimScript* anm);
void EnmAuraP3(AnimScript* anm);

#endif
