#ifndef PLAYERHUD
#define PLAYERHUD

#include "AnmManagerOld/AnmManager.h"

class PlayerHUD {
    public:
        PlayerHUD(long hiscore, int powermax, int powerstep);
        ~PlayerHUD();

        void Update(float power, int score, int life, int spell, int pointValue, int graze, float framespeed = 1.f);
        void Draw(bool debug = false);
        static int etama;
        static int anmscr;
        static int laser;
        static int item;
        static int itemc;
        static long hiscore;
        static long score;
        static int pointValue;
        static int graze;
        static int power;
        static int maxpower;
        static int steppower;
    private:
        int anmh[8];
        int anms[8];
        int life = 10;
        int spell = 10;
};

#endif
