#ifndef PLAYERENTITY
#define PLAYERENTITY

#include <NSEngine.h>
#include "PlayerHUD.h"
#include "THAnim.h"
#define SHOOT_COOLDOWN 3

class PlayerEntity {
    public:
        static PlayerEntity* GetInstance(int player = -1);
        static void DestroyInstance();

        PlayerEntity(int player);
        ~PlayerEntity();

        void Update(float framespeed = 1.f);

        void Collect(int pickup_type, float ywhencollected);

        void AddScore(int score) { this->score += score; }

        void Die();
        void Graze();

        int deadframe = 0;
        float x = 0;
        float y = -180;
        int maxdmg = 0;
        std::vector<float> xp = std::vector<float>(10);
        std::vector<float> yp = std::vector<float>(10);
        float itembox;

        bool isMaxPower() { return power >= maxpower; }

    private:
        THAnim* anm;
 
        static PlayerEntity* Instance;

        float speed_nf, speed_f;
        float hsp,vsp,hsp_frac=0,vsp_frac=0;
 
        bool focus = false;
        bool controllable = true;
        bool canshoot = true; 

        int invFrame = 0;

        int power = 0;
        int powerstep = 20;
        int maxpower = 80;
        int score = 0;
        int hiscore = 0;
        int life = 10;
        int spell = 10;
        int pointValue = 10000;
        int graze = 0;
        PlayerHUD* HUD;
};

#endif
