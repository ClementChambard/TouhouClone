#ifndef BULLETS
#define BULLETS

#include <vector>
#include "BulletMacros.h"
#include "PlayerHUD.h"
//#include <Assets.h>

#define CID(i) if(i>=handlers.size())return;

extern int getAnm(int type, int color);

class BulletManager {
    public:

        struct Bullet {
            float speed = 1.f;
            float storedspeed = 1.f;
            float direction = 0.f;
            float x = 0.f, y = 0.f;
            int16_t anm = -1;
            int16_t box = -1;
            int8_t steps = 0;
            char aaccelframe = 0;
            char saccelframe = 0;
            float accel = 0;
            float angleaccel = 0;
            short int handler = -1;
            int frame = 0;
            bool active = false;
            bool dontdespawn=false;
            void Update();
            void Delete(bool itemspawn);
            void Reset()
            {
                speed = 1.f;
                storedspeed = 1.f;
                direction = 0.f;
                x = 0.f, y = 0.f;
                anm = -1;
                box = -1;
                steps = 0;
                aaccelframe = 0;
                saccelframe = 0;
                accel = 0;
                angleaccel = 0;
                handler = -1;
                frame = 0;
                active = false;
                dontdespawn = false;
            }
        };

        struct Transform {
            int frame = 0;
            int type = 0;
            int a,b,c,d;
            float r,s,m,n;
            void Apply(Bullet* b);
        };

        static void Init();
        static void Cleanup()
        {
            delete[] bullet_pool;
            for (auto i: handlers) delete i;
        }

        static bool ValidHandler(unsigned int i) { return i < handlers.size() && i >= 0 && handlers[i] != nullptr; }

        static void Update()
        {
            PlayerHUD::etama = 0;
            for (int i = 0; i < 2000; i++)
            {
                if (!bullet_pool[i].active) continue;
                if (ValidHandler(bullet_pool[i].handler))
                for (Transform t : handlers[bullet_pool[i].handler]->transforms) if (t.frame == bullet_pool[i].frame || t.type == EX_STEP) t.Apply(&(bullet_pool[i]));
                    bullet_pool[i].Update();
                PlayerHUD::etama += bullet_pool[i].active;
            }
        }

        static int AddHandler();
        static void DestroyHandler(unsigned int& i);
        static void ClearHandlers();

        static void etOn(unsigned int id, float x, float y) { CID(id) handlers[id]->Fire(x,y); }
        static void etSprite(unsigned int id, int type, int color) { CID(id) handlers[id]->anmType = type; handlers[id]->anmColor = color; }
        static void etOffset(unsigned int id, float x, float y) { CID(id) handlers[id]->offx = x; handlers[id]->offy = y; }
        static void etAngle(unsigned int id, float angle1, float angle2) { CID(id) handlers[id]->ang1 = angle1; handlers[id]->ang2 = angle2; }
        static void etSpeed(unsigned int id, float speed1, float speed2) { CID(id) handlers[id]->spd1 = speed1; handlers[id]->spd2 = speed2; }
        static void etCount(unsigned int id, int count1, int count2) { CID(id) handlers[id]->ct1 = count1; handlers[id]->ct2 = count2; }
        static void etAim(unsigned int id, int aimMode) { CID(id) handlers[id]->mode = aimMode; }
        static void etSound(unsigned int id, int sound1, int sound2) { CID(id) /*handlers[id]->snd1 = sound1; handlers[id]->snd2 = sound2;*/ }
        static void etEx(unsigned int id, int frame, int type, int a, int b, int c, int d, float r, float s, float m, float n) { CID(id) handlers[id]->transforms.push_back({frame,type,a,b,c,d,r,s,m,n}); }
        static void CreateBullet(int id, float x, float y, float s, float a);

        static void etClear(float x = 0, float y = 0, float rad = 500);
        static void etCancel(float x = 0, float y = 0, float rad = 500);

    private:

        class BulletHandler {
            public:
                BulletHandler(int id);
                ~BulletHandler();

                void Update();

                void Fire(float x, float y);

            private:
                int id;
                std::vector<Transform> transforms;
                int anmType = -1; int anmColor = -1;
                int spawnAnm = -1;
                float offx = 0.f, offy = 0.f;
                float ang1 = 0.f, ang2 = 0.f;
                float spd1 = 1.f, spd2 = 1.f;
                int ct1 = 1, ct2 = 1, mode = 0;
                //int snd1 = gameassets::se_tan00, snd2 = gameassets::se_kira00;
                friend class BulletManager;
        };

        static std::vector<BulletHandler*> handlers;
        static Bullet* bullet_pool;
        static int current_pos;
};

#endif
