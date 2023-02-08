#ifndef ANMEFFECTS
#define ANMEFFECTS

#include "AnmManagerOld/AnmManager.h"


class AnmEffects {
    public: static void Init();
    private: static bool isInit;
};


extern void setSpellcardDuration(int t);
extern void effectSpellcardRingP1(AnimScript* anm);
extern void effectSpellcardRingP2(AnimScript* anm);
extern void effectSpellcardRing(AnimScript* anm);
extern void effectSpellcardAttackP1(AnimScript* anm);
extern void effectSpellcardAttackP2(AnimScript* anm);
extern void effectSpellcardAttackP3(AnimScript* anm);
extern void effectSpellcardAttackP4(AnimScript* anm);
extern void effectSpellcardAttackP5(AnimScript* anm);
extern void effectSpellcardAttackP6(AnimScript* anm);
extern void effectSpellcardAttack(AnimScript* anm);

extern void effectBase1(AnimScript* anm);
extern void effectBase2(AnimScript* anm);
extern void effectBase3(AnimScript* anm);
extern void effectBase4(AnimScript* anm);

extern void effectSlow1(AnimScript* anm);
extern void effectSlow2(AnimScript* anm);
extern void effectSlow3(AnimScript* anm);

extern void effectExplodeLarge(AnimScript* anm);
extern void effectExplode(AnimScript* anm);
extern void effectExplodeP1(AnimScript* anm);
extern void effectExplodeP2(AnimScript* anm);
extern void effectExplodeNeg1(AnimScript* anm);
extern void effectExplodeNeg2(AnimScript* anm);
extern void effectExplodeNegP(AnimScript* anm);
extern void effectExplodeEnemy(float x, float y, float a, char colors);
extern void effectExplodeEnemyP1(AnimScript* anm);
extern void effectExplodeEnemyP2(AnimScript* anm);
extern void effectExplodeEnemyP3(AnimScript* anm);
extern void effectExplodeMapleBig(float x, float y, float s, int n, int n2, int t);
extern void effectExplodeMapleBigP(AnimScript* anm);

extern void effectMaple(float x, float y, float s, char type, int r1=255, int g1=255, int b1=255, int r2=255, int g2=255, int b2=255);
extern void effectMapleP1(AnimScript* anm);
extern void effectMapleP2(AnimScript* anm);
extern void effectMapleP3(AnimScript* anm);
extern void effectMapleP4(AnimScript* anm);
extern void effectMapleP5(AnimScript* anm);
extern void effectMapleP6(AnimScript* anm);

extern void effectMaple3D1(AnimScript* anm);
extern void effectMaple3D2(AnimScript* anm);
extern void effectMaple3D3(AnimScript* anm);
extern void effectMaple3D4(AnimScript* anm);
extern void effectMaple3D5(AnimScript* anm);
extern void effectMaple3D6(AnimScript* anm);

extern void effectMagicSquare1(AnimScript* anm);
extern void effectMagicSquare2(AnimScript* anm);

extern void setAuraColor(int i);
extern void effectAura(AnimScript* anm);
extern void effectAuraP1(AnimScript* anm);
extern void effectAuraP2(AnimScript* anm);
extern void effectAuraP3(AnimScript* anm);
extern void effectAura3Dleaf1(AnimScript* anm);
extern void effectAura3Dleaf2(AnimScript* anm);

extern void effectBreakWave(float a, float x, float y, float s, int r, int g, int b, int n = 4);
extern void effectBreakWaveP(AnimScript* anm);

extern void effectSplash(AnimScript* anm);

extern void effectCharge(float angle, float x, float y, int r, int g, int b, int speed, bool reverse);
extern void effectChargeP1(AnimScript* anm);
extern void effectChargeP2(AnimScript* anm);

#endif
