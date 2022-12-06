#ifndef ANMFRONT
#define ANMFRONT

#include <AnmManager.h>

class AnmFront {
    public: static void Init();
    private: static bool isinit;
};

extern void frontAll(AnimScript* anm);
extern void frontPoly(AnimScript* anm);
extern void frontBgP1(AnimScript* anm);
extern void frontBgP2(AnimScript* anm);
extern void frontBgP3(AnimScript* anm);
extern void frontBgP4(AnimScript* anm);
extern void frontTxtP1(AnimScript* anm);
extern void frontTxtP2(AnimScript* anm);
extern void frontTxtP3(AnimScript* anm);
extern void frontTxtP4(AnimScript* anm);
extern void frontTxtP5(AnimScript* anm);
extern void frontTxtP6(AnimScript* anm);
extern void frontTxtP7(AnimScript* anm);
extern void frontTxtP8(AnimScript* anm);
extern void frontTxtP9(AnimScript* anm);
extern void frontDisabled(AnimScript* anm);
extern void frontRecP1(AnimScript* anm);
extern void frontRecP2(AnimScript* anm);
extern void frontRecP3(AnimScript* anm);
extern void frontRecP4(AnimScript* anm);
extern void frontRecP5(AnimScript* anm);
extern void frontRecP6(AnimScript* anm);
extern void frontRecP7(AnimScript* anm);
extern void frontRecP8(AnimScript* anm);
extern void frontRecP9(AnimScript* anm);
extern void frontRecP10(AnimScript* anm);
extern void frontRecP11(AnimScript* anm);
extern void frontRecP12(AnimScript* anm);
extern void frontRecP13(AnimScript* anm);
extern void frontRecP14(AnimScript* anm);
extern void frontHeart(AnimScript* anm);
extern void frontSpell(AnimScript* anm);
extern void frontSCNumP1(AnimScript* anm);
extern void frontSCNumP2(AnimScript* anm);
extern void frontSCFail(AnimScript* anm);
//truc sprite 34
//rectangle noir
extern void frontSCGetB(AnimScript* anm);
extern void frontSCFailB(AnimScript* anm);
extern void frontFullPower(AnimScript* anm);
extern void frontHighScore(AnimScript* anm);
extern void frontExtend(AnimScript* anm);
extern void frontILineP1(AnimScript* anm);
extern void frontILineP2(AnimScript* anm);
extern void frontILine(AnimScript* anm);
extern void frontBossStar(AnimScript* anm);
extern void frontDifficulty1(AnimScript* anm);
extern void frontDifficulty2(AnimScript* anm);
//2* sprite 62 + 1* sprite 63
extern void frontSCTime(AnimScript* anm);
extern void frontEnemy(AnimScript* anm);

extern void front120(AnimScript* anm);
extern void front121(AnimScript* anm);

extern void frontPauseBack1(AnimScript* anm);
extern void frontPauseBack2(AnimScript* anm);
extern void frontPauseTitle12(AnimScript* anm);
extern void frontPauseOption1(AnimScript* anm);
extern void frontPauseTitle3(AnimScript* anm);
extern void frontPauseOption2(AnimScript* anm);

extern void frontLifebarP1(AnimScript* anm);
extern void frontLifebarP2(AnimScript* anm);
extern void frontLifebarP3(AnimScript* anm);
extern void frontLifebarP4(AnimScript* anm);
#endif
