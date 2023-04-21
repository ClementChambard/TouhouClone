#ifndef PLAYERENTITY
#define PLAYERENTITY

#include "PlayerHUD.h"
#include "THAnim.h"
#include <NSEngine.h>
#define SHOOT_COOLDOWN 3

class PlayerEntity {
public:
    static PlayerEntity* GetInstance(int player = -1);
    static void DestroyInstance();

    explicit PlayerEntity(int player);
    PlayerEntity(PlayerEntity const&) = delete;
    PlayerEntity& operator=(PlayerEntity const&) = delete;
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
    THAnim* anm = nullptr;

    static PlayerEntity* Instance;

    float speed_nf = 0.f, speed_f = 0.f;
    float hsp = 0.f, vsp = 0.f, hsp_frac = 0.f, vsp_frac = 0.f;

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
    PlayerHUD* HUD = nullptr;
};

#endif
