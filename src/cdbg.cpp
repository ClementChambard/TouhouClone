#include "cdbg.h"
#include <math/math.h>
#include "Timer.h"
#include "PlayerEntity.h"
#include "AnmEffects.h"
#include "AnmAscii.h"
#include "AnmFront.h"
#include "textAnm.h"
#include "ECLManager.h"
bool cdbg::started = false;
int cdbg::frame = 0;
int cdbg::time = 3000;
int cdbg::bonus = 0;
uint8_t cdbg::tries = 0;
uint8_t cdbg::captures = 0;
int cdbg::anm = -1;
bool cdbg::fail = 0;

void cdbg::Start(void (*AnmFunc)(AnimScript*), int time, int id)
{
    cdbg::time = time;
    cdbg::bonus = ECLManager::stage*1000000*(float)(ECLManager::difficulty+1)/2.f;;
    cdbg::tries = tries+1;
    cdbg::captures = 0;
    if (anm != -1) AnmManager::deleteAnim(anm);
    anm = AnmManager::newAnim(AnmFunc);
    AnmManager::UpdateChild(anm,0,224,0,0,0,0,1,1,1);
    frame = 0;
    Timer::SetTime(time/60.f);
    Timer::ShowTime(true,true);
    started = true;
    fail = false;
    NSEngine::AudioEngine::PlaySound(gameassets::se_cat00);
    if (ECLManager::boss != nullptr) ECLManager::boss->spell = true;
}

void cdbg::Update(float framespeed)
{
    static int anmCircle = -1;
    static int anmCdTxt = -1;
    static bool fade = false;
    static textAnm* bonusanm = nullptr;
    static textAnm* capturesanm = nullptr;
    static textAnm* triesanm = nullptr;
    static int anmFail = -1;
    static int anmslash = -1;
    static int decrease = 0;
    if (!started) 
    {
        if (AnmManager::IsActive(anmCircle)) {AnmManager::deleteAnim(anmCircle); anmCircle = -1;}
        if (AnmManager::IsActive(anmCdTxt)) {AnmManager::interrupt(anmCdTxt,1); anmCdTxt = -1;}
        if (bonusanm != nullptr) delete bonusanm; bonusanm = nullptr;
        if (capturesanm != nullptr) delete capturesanm; capturesanm = nullptr;
        if (triesanm != nullptr) delete triesanm; triesanm = nullptr;
        if (anmslash != -1) AnmManager::deleteAnim(anmslash); anmslash = -1;
        if (anmFail != -1) AnmManager::deleteAnim(anmFail); anmFail = -1;
        return;
    }
    if (Timer::Timeout())
    {
        fail = true;
        Stop();
        return;
    }
    if (frame == 0)
    {
        decrease = 0;
        setSpellcardDuration(time);
        if (AnmManager::IsActive(anmCircle)) AnmManager::deleteAnim(anmCircle);
        if (AnmManager::IsActive(anmCdTxt)) AnmManager::deleteAnim(anmCdTxt);
        anmCdTxt = AnmManager::newAnim(CardTest);
        AnmManager::UpdateChild(anmCdTxt,0,0,0,0,0,0,1,1,1);
        if (anmFail != -1) AnmManager::deleteAnim(anmFail); anmFail = -1;
        if (bonusanm != nullptr) delete bonusanm; bonusanm = new textAnm(8,7,frontSCNumP1);
        if (capturesanm != nullptr) delete capturesanm; capturesanm = new textAnm(2,7,frontSCNumP1,95,1); capturesanm->set_number(captures);
        if (triesanm != nullptr) delete triesanm; triesanm = new textAnm(2,7,frontSCNumP1,116,1); triesanm->set_number(tries);
        if (anmslash != -1) AnmManager::deleteAnim(anmslash); anmslash = AnmManager::newAnim(frontSCNumP2);
        anmCircle = AnmManager::newAnim(effectSpellcardRing);
        AnmManager::UpdateChild(AnmManager::newAnim(effectSpellcardAttack),0,224,0,0,0,0,1,1,1);
    }
    else if (frame == 300) decrease =  (2*bonus/(30*(time-300)))*10;
    if (fail)
    {
        if (anmFail == -1) anmFail = AnmManager::newAnim(frontSCFail);
        if (bonusanm != nullptr) delete bonusanm; bonusanm = nullptr;
    }
    PlayerEntity* p = PlayerEntity::GetInstance();
    bool tofade = p->y > 120;
    if (fade && !tofade) 
    {
        fade = false; 
        AnmManager::interrupt(anmCdTxt,2);
        AnmManager::interrupt(anmslash,2);
        if (anmFail != -1) AnmManager::interrupt(anmFail,2);
        if (bonusanm != nullptr) bonusanm->interrupt(2);
        if (triesanm != nullptr) triesanm->interrupt(2);
        if (capturesanm != nullptr) capturesanm->interrupt(2);
    }
    else if (!fade && tofade) 
    {
        fade = true; 
        AnmManager::interrupt(anmCdTxt,3);
        AnmManager::interrupt(anmslash,3);
        if (anmFail != -1) AnmManager::interrupt(anmFail,3);
        if (bonusanm != nullptr) bonusanm->interrupt(3);
        if (triesanm != nullptr) triesanm->interrupt(3);
        if (capturesanm != nullptr) capturesanm->interrupt(3);
    }
    if (ECLManager::boss != nullptr)
    AnmManager::UpdateChild(anmCircle,ECLManager::boss->pos.x,ECLManager::boss->pos.y,0,0,0,0,1,1,1);
    frame += framespeed;
    bonus-=decrease;
    if (bonusanm != nullptr) bonusanm->set_number(bonus);
}

void cdbg::Stop() { 
    if (!started) return;
    started = false; 
    if (ECLManager::boss != nullptr) ECLManager::boss->spell = false;
    AnmManager::deleteAnim(anm); anm = -1;
    if (!fail) 
    {
        AnmManager::newAnim(frontSCGetB);
        Timer::ShowCardScore(bonus);
        PlayerEntity::GetInstance()->AddScore(bonus);
        NSEngine::AudioEngine::PlaySound(gameassets::se_cardget);
    }
    else AnmManager::newAnim(frontSCFailB);
    AnmManager::newAnim(frontSCTime);
    Timer::ShowTimeScore(frame/60.f);
    Timer::ShowTime(true,false);
}

void cdbg::Fail() {
    fail = true;
}
