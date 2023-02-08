#ifndef ANMASCII
#define ANMASCII

#include "AnmManagerOld/AnmManager.h"

class AnmAscii {
    public: static void Init();
    private: static bool isInit;
};

extern void CardTest(AnimScript* anm);
extern void asciiCardnameBg(AnimScript* anm);
extern void asciiCardHistory(AnimScript* anm);

extern void asciiNum1(AnimScript* anm);
extern void asciiNum2(AnimScript* anm);

extern void asciiNum3(AnimScript* anm);
extern void asciiNum4(AnimScript* anm);
extern void asciiNum5(AnimScript* anm);
extern void asciiNum6(AnimScript* anm);
extern void asciiNum7(AnimScript* anm);
extern void asciiNum8(AnimScript* anm);
extern void asciiNum9(AnimScript* anm);
extern void asciiNum10(AnimScript* anm);
extern void asciiNum11(AnimScript* anm);
extern void asciiNum12(AnimScript* anm);

extern void asciiLoadP1(AnimScript* anm);
extern void asciiLoadP2(AnimScript* anm);
extern void asciiLoadP3(AnimScript* anm);
extern void asciiLoad(AnimScript* anm);
extern void asciiLoadEff(AnimScript* anm);
extern void asciiLoadEffMake(AnimScript* anm);
#endif
