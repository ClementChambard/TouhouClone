#ifndef ENEMYDATA
#define ENEMYDATA

#include <math/math.h>
#include "THAnim.h"
#include <Assets.h>
#include "CollisionManager.h"
#include <math/Random.h>
#include <glm/glm.hpp>

struct DropData {
    float radius = 24;
    struct Drop { int id = 0; int count = 1; };
    std::vector<Drop> BonusDrop;
    void AddDrop(int id, int count) { BonusDrop.push_back({id,count}); }
    ~DropData() { BonusDrop.clear(); }
};

struct EnemyData {

    glm::vec2 pos;
    glm::vec2 speed;
    THAnim* anm0 = nullptr;

    int hitBox = -1;
    int hurtBox = -1;

    int baseItemDrop = 0;
    DropData* drops = nullptr;
    void BonusDrop(int id, int count) { if (drops == nullptr) drops = new DropData(); drops->AddDrop(id,count); }
    void DropAera(float r) { if (drops != nullptr) drops->radius = r; }
    void ClearDrops() { delete drops; drops = nullptr; }
    void DropAll();
    int score = 1000;
    char dieAnim = 0b00000001;

    int hitsound = gameassets::se_damage00;
    char hitsoundframe = 0;
    bool spell = false;
    bool mirror = false;

    int invFrame = 0;

    std::vector<int> anmSlots;
    float lifeMax = 0;
    float life = 0;

    float hitangle = 0.f;

    glm::vec4* movelimit = nullptr;

    void Update();

    ~EnemyData();

    void SetLife(float l, bool m = true)
    {
        life = l; if (m) lifeMax = l;
    }

    void Die();

    void MovePos(float x, float y) { pos = glm::vec2(mirror?-x:x, 224.f-y); }
    void MovePosTime(int time, int mode, float x, float y) { ITP_ (&pos, pos, glm::vec2(mirror?-x:x, 224-y), mode, time, false); }
    void MovePosRel(float x, float y) { pos += glm::vec2(mirror?-x:x, y); }
    void MovePosRelTime(int time, int mode, float x, float y) { ITP_ (&pos, pos, pos+glm::vec2(mirror?-x:x, 224-y), mode, time, false); }
    //void MoveVel(float r, float spd);
    //void MoveVelTime(int time, int mode, float r, float spd);
    //void MoveVelRel(float r, float spd);
    //void MoveVelRelTime(int time, int mode, float r, float spd);
    //void MoveCircle(float t, float spd, float rad, float radinc);
    //void MoveCircleTime(int time, int mode, float t, float spd, float rad, float radinc);
    //void MoveCircleRel(float t, float spd, float rad, float radinc);
    //void MoveCircleRelTime(int time, int mode, float t, float spd, float rad, float radinc);

    void MoveRand(int time, int mode, float dist)
    {
        float a = Random::Angle();
        glm::vec2 posTo = pos + math::lengthdir_vec(dist, a);
        if (movelimit != nullptr)
        {
            glm::vec2 p = glm::vec2(movelimit->x,movelimit->y);
            glm::vec2 s = glm::vec2(movelimit->z, movelimit->w);
            posTo = math::clamp(posTo, p-s/2.f, p+s/2.f);
        }
        ITP_ (&pos, pos, posTo, mode, time, false);
    }
    //void MoveRandRel(int time, int mode, float dist);
    //void MoveBoss();
    //void MoveBossRel();
    //void MovePos3d(float x, float y, float z);
    //void MovePos3dRel(float x, float y, float z);
    //void MoveAdd(float x, float y);
    //4 moveEllipse
    //other movement
    void setHurtbox(float r) { this->hurtBox = CollisionManager::NewEnemyHurtbox(pos.x,pos.y,r); }
    void setHitbox(float r) { this->hitBox = CollisionManager::NewEnemyHitbox(pos.x,pos.y,r); }
    void setXYSpeed(float xs, float ys) { speed = glm::vec2(mirror?-xs:xs, ys); }
    void setSpeed(float dir, float spd) { setXYSpeed(math::lengthdir_x(spd,dir),math::lengthdir_y(spd,dir)); }
    void SpeedXYTime(int time, int mode, float xs, float ys) { ITP_ (&speed, speed, glm::vec2(mirror?-xs:xs, ys), mode, time, false); }
    void SpeedTime(int time, int mode, float dir, float spd) { SpeedXYTime(time,mode,math::lengthdir_x(spd,dir),math::lengthdir_y(spd,dir)); }
    void MoveLimit(float x, float y, float w, float h)
    {
        if (movelimit != nullptr) delete movelimit;
        movelimit = new glm::vec4(mirror?-x:x,224-y,w,h);
    }
    void MoveLimitReset()
    {
        if (movelimit != nullptr) delete movelimit;
        movelimit = nullptr;
    }
    

};

#endif
