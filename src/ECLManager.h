#ifndef ECLMANAGER
#define ECLMANAGER

#include <iostream>

#include "EnemyData.h"

#include <NSEngine.h>


#define ECLS ECLManager::ECLSub
#define ECLSUB(x) void x(ECLManager::ECLSub* thisSub)
#define ECLRETURN thisSub->active = false; return;
#define thisEnm thisSub->endat


class ECLManager {
    public:

        struct ECLSub;

        typedef void (*ECLSub_t)(ECLS*);
        struct asyncSubs {
            std::vector<ECLSub*> subs;
            void Update();
            ~asyncSubs();
        };

        struct ECLSub {
            ECLSub_t sub = nullptr;
            int frame = 0;
            bool active = false;
            int16_t flags = 0;
            EnemyData* endat = nullptr;
            float* vars = nullptr;
            ECLSub* sync_child = nullptr;
            asyncSubs* asyncchilds = nullptr;

            void Update(bool child = false);
            void Delete();
            void Async(ECLSub_t sub);
            void Sync(ECLSub_t sub);
            void changeSub(ECLSub_t sub);
            void flagSet(int16_t n);
            void flagClear(int16_t n);
        };



        static EnemyData* boss;
        static void SetBoss(ECLSub* s) { if (s==nullptr) { boss = nullptr; thebossanms.Delete(); } else { boss = s->endat; thebossanms.Create(); } }

        static void Init(ECLSub_t sub = nullptr);
        static void Clear();

        static int newSub(ECLSub_t sub);
        static int enmCreate(ECLSub_t sub, float x, float y, float hp, int score, int item);
        static int enmCreateM(ECLSub_t sub, float x, float y, float hp, int score, int item);
        static int enmCreateF(ECLSub_t sub, float x, float y, float hp, int score, int item);
        static int enmCreateFM(ECLSub_t sub, float x, float y, float hp, int score, int item);
        static void enmKillAll();
        static void deleteSub(int i);
        static ECLSub* Sub(int i);

        static void Update();

        static int difficulty;
        static int stage;
        static bool CAPTURE;

        static void DEBUGDRAW()
        {
            NSEngine::draw_set_layer(NSEngine::engineData::debugLayer);
            for (int i = 0; i < 200; i++)
            {
                if (sub_pool[i].active && sub_pool[i].endat != nullptr)
                {
                    std::string s = std::to_string(sub_pool[i].endat->life) + "/" + std::to_string(sub_pool[i].endat->lifeMax);
 //                   NSEngine::SpriteManager::draw_text(gameassets::fnt_small,s.c_str(),{sub_pool[i].endat->x,sub_pool[i].endat->y+32.f},{1,1},c_white);
                    s = std::to_string(sub_pool[i].endat->speed.x) + "  " +  std::to_string(sub_pool[i].endat->speed.y);
                    NSEngine::SpriteManager::draw_text(gameassets::fnt_small,s.c_str(),{sub_pool[i].endat->pos.x,sub_pool[i].endat->pos.y+48.f},{1,1},c_white);
                }
            }
        }

        static void etBreak(float x, float y, bool item, float rate);

    private:
        static bool isinit;
        static ECLSub* sub_pool;
        static int pos;

        struct bossAnms {
            int bossbar1 = -1, bossbar2 = -1, bossbar3 = -1;
            int bossIndicator = -1;
            float lifeDisplayed = 0;
            std::vector<int> bossbarsections;
            std::vector<int> stars;
            int staractive = 0;
            void Create();
            void AddSection(float life);
            void ClearSections();
            void Stars(int i);
            void Delete();
            void Update();
        };
    public:
        static bossAnms thebossanms;
};


#endif
