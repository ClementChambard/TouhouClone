#include "ECLManager.h"

ECLManager::ECLSub* ECLManager::sub_pool;
EnemyData* ECLManager::boss = nullptr;
int ECLManager::difficulty;
int ECLManager::stage;
bool ECLManager::CAPTURE = true;

void ECLManager::Init(ECLSub_t sub)
{
    if (sub_pool != nullptr)
        delete[] sub_pool;
    sub_pool = new ECLSub[200];
    newSub(sub);
    //   std::cin>>ECLManager::difficulty;
}

void ECLManager::Update()
{
    for (int i = 0; i < 200; i++) {
        if (!sub_pool[i].active)
            continue;
        sub_pool[i].Update();
    }
    if (boss != nullptr)
        thebossanms.Update();
}

void ECLManager::asyncSubs::Update()
{
    for (size_t i = 0; i < subs.size(); i++)
        if (subs[i] != nullptr) {
            subs[i]->Update(true);
            if (!subs[i]->active) {
                delete subs[i];
                subs[i] = nullptr;
                if (i == subs.size() - 1)
                    while (subs[i--] == nullptr)
                        subs.pop_back();
            }
        }
}
ECLManager::asyncSubs::~asyncSubs()
{
    for (size_t i = 0; i < subs.size(); i++)
        delete subs[i];
    subs.clear();
}

#include <Error.h>
void ECLS::Update(bool child)
{
    if (asyncchilds != nullptr) {
        asyncchilds->Update();
    }
    if (sync_child != nullptr) {
        sync_child->Update();
        if (!sync_child->active) {
            delete sync_child;
            sync_child = nullptr;
        }
        return;
    }
    sub(this);
    frame++;
    if (endat != nullptr && !child)
        endat->Update();
}

void ECLS::Delete()
{
    active = false;
    if (asyncchilds != nullptr) {
        delete asyncchilds;
        asyncchilds = nullptr;
    }
    if (endat != nullptr) {
        delete endat;
        endat = nullptr;
    }
}

void ECLS::changeSub(ECLSub_t sub)
{
    if (asyncchilds != nullptr) {
        delete asyncchilds;
        asyncchilds = nullptr;
    }
    this->sub = sub;
    frame = 0;
}

void ECLS::flagSet(int16_t n) { flags |= n; }
void ECLS::flagClear(int16_t n) { flags &= (~n); }

void ECLS::Async(ECLSub_t sub)
{
    if (asyncchilds == nullptr)
        asyncchilds = new asyncSubs();

    ECLSub* async_child = new ECLSub();
    async_child->sub = sub;
    async_child->flags = flags;
    async_child->endat = endat;
    async_child->vars = vars;
    async_child->active = true;
    asyncchilds->subs.push_back(async_child);
}
void ECLS::Sync(ECLSub_t sub)
{
    sync_child = new ECLSub();
    sync_child->sub = sub;
    sync_child->flags = flags;
    sync_child->endat = endat;
    sync_child->vars = vars;
    sync_child->active = true;
}

int ECLManager::pos = 0;
int ECLManager::newSub(ECLSub_t sub)
{
    if (sub == nullptr)
        return -1;
    int i = 0;
    while (sub_pool[pos].active && i++ < 200)
        pos = (pos + 1) % 200;
    i = pos;
    pos = (pos + 1) % 200;
    sub_pool[i].active = true;
    sub_pool[i].sub = sub;
    sub_pool[i].frame = 0;
    return i;
}

int ECLManager::enmCreate(ECLSub_t sub, float x, float y, float hp, int score, int item)
{
    int i = newSub(sub);
    Sub(i)->endat = new EnemyData();
    Sub(i)->endat->pos = glm::vec2(x, 224 - y);
    Sub(i)->endat->life = Sub(i)->endat->lifeMax = hp != 0 ? hp : 1;
    Sub(i)->endat->baseItemDrop = item;
    Sub(i)->endat->score = score;
    return i;
}
int ECLManager::enmCreateM(ECLSub_t sub, float x, float y, float hp, int score, int item)
{
    int i = enmCreate(sub, -x, y, hp, score, item);
    Sub(i)->endat->mirror = true;
    Sub(i)->flagSet(0b0100000000000000);
    return i;
}
int ECLManager::enmCreateF(ECLSub_t sub, float x, float y, float hp, int score, int item)
{
    if (boss == nullptr)
        return enmCreate(sub, x, y, hp, score, item);
    return -1;
}
int ECLManager::enmCreateFM(ECLSub_t sub, float x, float y, float hp, int score, int item)
{
    if (boss == nullptr)
        return enmCreateM(sub, x, y, hp, score, item);
    return -1;
}

void ECLManager::deleteSub(int i)
{
    if (i < 0 || i >= 200 || !sub_pool[i].active)
        return;
    sub_pool[i].Delete();
}

ECLManager::ECLSub* ECLManager::Sub(int i)
{
    if (i < 0 || i >= 200 || !sub_pool[i].active)
        return nullptr;
    return &(sub_pool[i]);
}

#include "AnmFront.h"

ECLManager::bossAnms ECLManager::thebossanms;

void ECLManager::bossAnms::Create()
{
    bossbar1 = AnmManager::newAnim(frontLifebarP1);
    bossbar2 = AnmManager::newAnim(frontLifebarP2);
    bossbar3 = AnmManager::newAnim(frontLifebarP3);
    bossIndicator = AnmManager::newAnim(frontEnemy);
    AnmManager::UpdateChild(bossbar1, boss->pos.x, boss->pos.y, 0, 0, 0, 0, 1, 1, 1);
    AnmManager::UpdateChild(bossbar2, boss->pos.x, boss->pos.y, 0, 0, 0, 0, 1, 1, 1);
    AnmManager::UpdateChild(bossbar3, boss->pos.x, boss->pos.y, 0, 0, 0, 0, 1, 1, 1);
    AnmManager::UpdateChild(bossIndicator, boss->pos.x, 0, 0, 0, 0, 0, 1, 1, 1);
    AnmManager::anim(bossbar1)->set_rot(1, lifeDisplayed / boss->lifeMax * PI2, PI1_2);
    if (stars.size() == 0)
        for (int i = 0; i < 10; i++) {
            stars.push_back(AnmManager::newAnim(frontBossStar));
            AnmManager::UpdateChild(stars[i], (float)(i * 10), 0, 0, 0, 0, 0, 1, 1, 1);
        }
}

void ECLManager::bossAnms::Delete()
{
    AnmManager::interrupt(bossbar1, 1);
    bossbar1 = -1;
    AnmManager::interrupt(bossbar2, 1);
    bossbar2 = -1;
    AnmManager::interrupt(bossbar3, 1);
    bossbar3 = -1;
    AnmManager::deleteAnim(bossIndicator);
    ClearSections();
    Stars(0);
}

#include "PlayerEntity.h"

void ECLManager::bossAnms::Update()
{
    lifeDisplayed = abs(boss->life - lifeDisplayed) < 100 ? boss->life : (lifeDisplayed < boss->life ? lifeDisplayed + 100 : lifeDisplayed - 100);
    static bool fadin = false;
    bool playerin = math::point_in_rectangle(PlayerEntity::GetInstance()->x, PlayerEntity::GetInstance()->y, boss->pos.x - 90.f, boss->pos.y - 90.f, boss->pos.x + 90.f, boss->pos.y + 90.f);
    int interrupt = 0;
    if (fadin && !playerin) {
        fadin = false;
        interrupt = 2;
    }
    if (!fadin && playerin) {
        fadin = true;
        interrupt = 3;
    }
    AnmManager::UpdateChild(bossbar1, boss->pos.x, boss->pos.y, 0, 0, 0, 0, 1, 1, 1, interrupt);
    AnmManager::UpdateChild(bossbar2, boss->pos.x, boss->pos.y, 0, 0, 0, 0, 1, 1, 1, interrupt);
    AnmManager::UpdateChild(bossbar3, boss->pos.x, boss->pos.y, 0, 0, 0, 0, 1, 1, 1, interrupt);
    AnmManager::UpdateChild(bossIndicator, boss->pos.x, 0, 0, 0, 0, 0, 1, 1, 1);
    for (int s : bossbarsections)
        AnmManager::UpdateChild(s, boss->pos.x, boss->pos.y, 0, 0, 0, 0, 1, 1, 1, interrupt);
    AnmManager::anim(bossbar1)->set_rot(1, lifeDisplayed / boss->lifeMax * PI2, PI1_2);
}

void ECLManager::bossAnms::AddSection(float life)
{
    bossbarsections.push_back(AnmManager::newAnim(frontLifebarP4, -1, 1));
    float a = PI2 * life / boss->lifeMax;
    AnmManager::anim(bossbarsections.back())->set_rot(0, 0, a);
    a += PI1_2;
    AnmManager::anim(bossbarsections.back())->set_pos(math::lengthdir_x(56, a), math::lengthdir_y(56, a), 0);
    AnmManager::UpdateChild(bossbarsections.back(), boss->pos.x, boss->pos.y, 0, 0, 0, 0, 1, 1, 1);
}

void ECLManager::bossAnms::ClearSections()
{
    for (int s : bossbarsections)
        if (s != -1)
            AnmManager::interrupt(s, 1);
    bossbarsections.clear();
}

void ECLManager::bossAnms::Stars(int i)
{
    if (i < 0)
        return;
    while (staractive != i) {
        if (staractive < i) {
            if (staractive >= 0)
                AnmManager::interrupt(stars[staractive], 4);
            staractive++;
        } else {
            if (staractive > 0)
                staractive--;
            AnmManager::interrupt(stars[staractive], 1);
        }
    }
}

#include "BulletManager.h"
void ECLManager::etBreak(float x, float y, bool item, float rate)
{
    float r = 16.f;
    int f = 0;
    while (r < 640.f) {
        std::function<void(void)> func = [x, y, item, r]() {
            if (item)
                BulletManager::etCancel(x, y, r);
            else
                BulletManager::etClear(x, y, r);
        };
        // NSEngine::ScheduleTask(f,func);
        f++;
        r += rate;
        func();
    }
}

void ECLManager::enmKillAll()
{
    for (int i = 0; i < 200; i++) {
        if (sub_pool[i].active && sub_pool[i].endat != nullptr)
            if (!(sub_pool[i].flags & 128 || sub_pool[i].flags & 32 || sub_pool[i].flags & 1024))
                sub_pool[i].Delete();
    }
}
