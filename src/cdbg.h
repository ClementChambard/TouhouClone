#ifndef CDBG06
#define CDBG06

#include <AnmManager.h>

class cdbg {

    public:
        static void Start(void (*Anmfunc)(AnimScript*), int time = 3000, int id = 0);
        static void Update(float framespeed = 1.f);
        static void Stop();
        static void Fail();
    private:
        static int time;
        static int anm;
        static int bonus;
        static uint8_t tries;
        static uint8_t captures;
        static bool started;
        static int frame;
        static bool fail;
};

#endif
