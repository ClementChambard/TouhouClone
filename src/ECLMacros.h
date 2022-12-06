#include <NSEngine.h>
#include "Timer.h"
#include "cdbg.h"
#include "PlayerEntity.h"
#include "BulletManager.h"
#include "CollisionManager.h"
#include "AnmEffects.h"

#define Sub_ thisSub->
#define Enm_ thisEnm->
#define Ecl_ ECLManager::
#define Anm_ AnmManager::
#define Tim_ Timer::
#define Bul_ BulletManager::
#define Snd_ NSEngine::AudioEngine::
#define Crt_ cdbg::
#define Ple_ PlayerEntity::GetInstance()->

#define fFrame(x) if (subframe == (x)) {
#define fFrame2(x,y) if (subframe == (x) || subframe == (y)) {
#define fFrame3(x,y,z) if (subframe == (x) || subframe == (y) || subframe == (z)) {
#define fFrame4(x,y,z,w) if (subframe == (x) || subframe == (y) || subframe == (z) || subframe == (w)) {
#define gFrame2(x,y) if (subframe == (x) || subframe == (y)) { subframe = x;
#define gFrame3(x,y,z) if (subframe == (x) || subframe == (y) || subframe == (z)) { subframe = x;
#define gFrame4(x,y,z,w) if (subframe == (x) || subframe == (y) || subframe == (z) || subframe == (w)) { subframe = x;
#define oFrame(x) } if (subframe == (x)) {
#define oFrame2(x,y) } if (subframe == (x) || subframe == (y)) {
#define oFrame3(x,y,z) } if (subframe == (x) || subframe == (y) || subframe == (z)) {
#define oFrame4(x,y,z,w) } if (subframe == (x) || subframe == (y) || subframe == (z) || subframe == (w)) {
#define pFrame2(x,y) } if (subframe == (x) || subframe == (y)) { subframe = x;
#define pFrame3(x,y,z) } if (subframe == (x) || subframe == (y) || subframe == (z)) { subframe = x;
#define pFrame4(x,y,z,w) } if (subframe == (x) || subframe == (y) || subframe == (z) || subframe == (w)) { subframe = x;
#define mFrame(x) } else if (subframe == (x)) {
#define mFrame2(x,y) } else if (subframe == (x) || subframe == (y)) {
#define mFrame3(x,y,z) } else if (subframe == (x) || subframe == (y) || subframe == (z)) {
#define mFrame4(x,y,z,w) } else if (subframe == (x) || subframe == (y) || subframe == (z) || subframe == (w)) {
#define nFrame2(x,y) } else if (subframe == (x) || subframe == (y)) { subframe = x;
#define nFrame3(x,y,z) } else if (subframe == (x) || subframe == (y) || subframe == (z)) { subframe = x;
#define nFrame4(x,y,z,w) } else if (subframe == (x) || subframe == (y) || subframe == (z) || subframe == (w)) { subframe = x;
#define fModFrame(x) if (subframe%(x) == 0) {
#define oModFrame(x) } if (subframe%(x) == 0) {
#define mModFrame(x) } else if (subframe%(x) == 0) {
#define eFrame }

#define NewBulletHandler(x) static int x = -1; if (!BulletManager::ValidHandler(x))

#define InterruptTime(t,x) if (Tim_ Timeout()) thisSub->changeSub(x);
#define InterruptLife(l,x) if (Enm_ life <= l) { Crt_ Stop(); Sub_ changeSub(x); }
#define Interrupt(l,t,x) if (Enm_ life <= l || Tim_ Timeout()) { if (Enm_ life <= l) Crt_ Stop(); thisSub->changeSub(x); }

#define CheckLimitsReturn if (Enm_ pos.y < -350.f || Enm_ pos.x > 250.f || Enm_ pos.x < -250.f || Enm_ pos.y > 350) { ECLRETURN; }
#define CheckLimitsDelete if (Enm_ pos.y < -350.f || Enm_ pos.x > 250.f || Enm_ pos.x < -250.f || Enm_ pos.y > 350) { Sub_ Delete(); ECLRETURN; }

#define ECLVARS(x) thisSub->vars = new float[x]
#define VAR(x) thisSub->vars[x]
#define d2(x,y) ECLManager::difficulty==0?x:y
#define d3(x,y,z) ECLManager::difficulty==0?x:(ECLManager::difficulty==1?y:z)
#define d4(x,y,z,w) ECLManager::difficulty==0?x:(ECLManager::difficulty==1?y:(ECLManager::difficulty==2?z:w))

#define WaitBoss() Sub_ Sync([](ECLManager::ECLSub* thisSub){if (Ecl_ boss == nullptr) ECLRETURN;})
#define Wait(x) Sub_ Sync([](ECLManager::ECLSub* thisSub){fFrame(x) ECLRETURN; eFrame})

#define subframe thisSub->frame
#define subhp thisEnm->life
#define subanm thisEnm->anm0
