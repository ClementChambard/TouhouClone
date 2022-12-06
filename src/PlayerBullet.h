#ifndef PLAYERBULLET
#define PLAYERBULLET

#include <NSEngine.h>
#include <math/math.h>
#include "Players.h"
#include <vector>

#define OPTION_MOVE_TIME 8


class ShooterManager {
    public:
        static void Init(PlayerData* player, int& powmax, int&powstep, float& hitbox, float& grazebox, float& itembox, float& spdnf, float& spdf, int& maxdmg);
        static void Delete();

        static void Update(bool shooting, bool focus, float framespeed = 1.f);

        static void SetPower(float p) { power = p; }

        static void OptionDie();
        static void OptionRespawn();

        struct Option {
            float nfx = 0.f, nfy = 0.f, fx = 0.f, fy = 0.f, x = 0.f, y = 0.f;
            int16_t anm1 = -1; int16_t anm2 = -1;
            bool isDrawn = false;
            int powermin = 1000, powermax = 1000;
        };

        struct Bullet {
            int8_t shooterID = 0;
            bool hit = false;
            bool active = false;
            bool persistant = false;
            float x = 0.f, y = 0.f;
            float speed = 0.f, direction = 0.f;
            int16_t anm = -1;
            int16_t box = -1;
            int additionalData = 0.f;
            void Delete();
        };

        struct intRange { int min = 0, max = 0; };

        struct Shooter {
            int8_t fire_rate = 3.f, start_delay = 0.f;
            int16_t dmg = 16.f;
            float off_x = 0.f, off_y = 0.f;
            float hitbox_x = 0.f, hitbox_y = 0.f;
            float angle = PI/2.f, speed = 24.f;
            int32_t unknown_sht_int32 = 0;
            int8_t option = 0;
            int8_t unknown_sht_byte_0 = 0;
            int8_t anm = 0, anm_hit = 0;
            int16_t sfx_id = -1;
            int8_t fire_rate2 = 0.f, start_delay2 = 0;
            int32_t func_on_init = 0, func_on_tick = 0, func_on_hit = 0;
            int32_t _old_on_draw = 0;
            int32_t flag0 = 0;
            int32_t flag1 = 0;
            int32_t flag2 = 0;
            int32_t flag3 = 0;
            int32_t flag4 = 0;
            int32_t flag5 = 0;
            int32_t flag6 = 0;
            int32_t flag7 = 0;
        };

        static bool shoot;

    private:
        static PlayerData* player;
        static int power;
        static int powerstep;
        static int bulletcount;
        static int optioncount;
        static int shootercount;
        static Bullet* bullets;
        static Option* options;
        static Shooter* shooters;
        static intRange* shootersPower;
        static bool* shootersFocus;
        static float shootCounter;
        static int current_pos;
        static int src_bulletsnd;
        static int pwr_lvl_cnt;
        static int max_dmg;
};

#endif
