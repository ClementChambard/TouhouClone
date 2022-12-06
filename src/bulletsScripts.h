#ifndef BULLETSSCRIPTS
#define BULLETSSCRIPTS

#include "PlayerBullet.h"

class pbscr {

    public:
        static std::vector<void (*)(ShooterManager::Bullet*)> scrinit;
        static std::vector<void (*)(ShooterManager::Bullet*)> scrtick;
        static std::vector<void (*)(ShooterManager::Bullet*)> scrhit;

        static std::vector<int> sounds;

        static void Init();
    private:
        static void addInit(void (*function)(ShooterManager::Bullet*)) { scrinit.push_back(function); }
        static void addTick(void (*function)(ShooterManager::Bullet*)) { scrtick.push_back(function); }
        static void addHit(void (*function)(ShooterManager::Bullet*)) { scrhit.push_back(function); }
        static bool initialized;
};

#endif
