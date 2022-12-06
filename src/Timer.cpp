#include "Timer.h"
#include <NSEngine.h>
#include "AnmAscii.h"
#include "PlayerEntity.h"

float Timer::time = 0.f;
bool Timer::show = 0;
int Timer::nb1 = -1, Timer::nb2 = -1, Timer::nb3 = -1, Timer::nb4 = -1, Timer::dot = -1;


bool Timer::Timeout() { return time <= 0; }

void Timer::SetTime(float t)
{
    t = fmax(0,t);
    if (nb1!= -1 && nb2 != -1 && nb3 != -1 && nb4 != -1)
    {
        AnmManager::anim(nb1)->offset_sprite(-(int)floor(time)%10);
        AnmManager::anim(nb2)->offset_sprite(-(int)floor(time/10.f)%10);
        AnmManager::anim(nb3)->offset_sprite(-(int)floor(time*10.f)%10);
        AnmManager::anim(nb4)->offset_sprite(-(int)floor(time*100.f)%10);
        time = t;
        AnmManager::anim(nb1)->offset_sprite((int)floor(time)%10);
        AnmManager::anim(nb2)->offset_sprite((int)floor(time/10.f)%10);
        AnmManager::anim(nb3)->offset_sprite((int)floor(time*10.f)%10);
        AnmManager::anim(nb4)->offset_sprite((int)floor(time*100.f)%10);
    }
    else time = t;
}

void Timer::ShowTime(bool b, bool spell)
{
    if (!b) if (nb1!=-1&&nb2!=-1&&nb3!=-1&&nb4!=-1&&dot!=-1) 
    {
        AnmManager::deleteAnim(nb1);
        AnmManager::deleteAnim(nb2);
        AnmManager::deleteAnim(nb3);
        AnmManager::deleteAnim(nb4);
        AnmManager::deleteAnim(dot);
        nb1=nb2=nb3=nb4=dot=-1;
        return;
    }
    if (nb1 == -1) 
    {
        nb1 = AnmManager::newAnim(asciiNum2,-1,1);
        AnmManager::anim(nb1)->offset_sprite((int)floor(time)%10);
    }
    if (nb2 == -1) 
    {
        nb2 = AnmManager::newAnim(asciiNum1,-1,1);
        AnmManager::anim(nb2)->offset_sprite((int)floor(time/10.f)%10);
    }
    if (nb3 == -1) 
    {
        nb3 = AnmManager::newAnim(asciiNum1,-1,1);
        AnmManager::anim(nb3)->offset_sprite((int)(floor(time)*10)%10);
        AnmManager::anim(nb3)->set_scale(.5,.5);
        AnmManager::UpdateChild(nb3,26,-4,0,0,0,0,1,1,1);
    }
    if (nb4 == -1) 
    {
        nb4 = AnmManager::newAnim(asciiNum2,-1,1);
        AnmManager::anim(nb4)->offset_sprite((int)(floor(time)*100)%10);
        AnmManager::anim(nb4)->set_scale(.5,.5);
        AnmManager::UpdateChild(nb4,20,-4,0,0,0,0,1,1,1);
    }
    if (dot == -1) 
    {
        dot = AnmManager::newAnim(asciiNum1,-1,1);
        AnmManager::anim(dot)->offset_sprite(11);
        AnmManager::UpdateChild(dot,22,0,0,0,0,0,1,1,1);
    }
    if (!spell) 
    {
        interruptAll(3);
        return;
    }
    interruptAll(2);
}

void Timer::ShowTimeScore(float time, float bestTime)
{
    if (time >= 100.f) time = 99.99f;
    if (bestTime >= 100.f) bestTime = 99.99f;
    float xx = 36.f, yy1 = -104.f, yy2 = yy1-16.f;
    int n1 = AnmManager::newAnim(asciiNum2,-1,1); AnmManager::anim(n1)->offset_sprite((int)floor(time)%10); AnmManager::UpdateChild(n1,xx,yy1,0,0,0,0,1,1,1);
    int n2 = AnmManager::newAnim(asciiNum1,-1,1); AnmManager::anim(n2)->offset_sprite((int)floor(time/10.f)%10); AnmManager::UpdateChild(n2,xx,yy1,0,0,0,0,1,1,1);
    int n3 = AnmManager::newAnim(asciiNum1,-1,1); AnmManager::anim(n3)->offset_sprite((int)floor(time*10)%10); AnmManager::UpdateChild(n3,xx+20-50,yy1-4+100,0,0,0,0,.5,.5,1);
    int n4 = AnmManager::newAnim(asciiNum2,-1,1); AnmManager::anim(n4)->offset_sprite((int)floor(time*100)%10); AnmManager::UpdateChild(n4,xx+20-50,yy1-4+100,0,0,0,0,.5,.5,1);
    int d = AnmManager::newAnim(asciiNum1,-1,1); AnmManager::anim(d)->offset_sprite(11); AnmManager::UpdateChild(d,xx+22,yy1,0,0,0,0,1,1,1);
    int s = AnmManager::newAnim(asciiNum1,-1,1); AnmManager::anim(s)->offset_sprite(12); AnmManager::UpdateChild(s,xx+32-50,yy1-4+100,0,0,0,0,.5,.5,1); 
    AnmManager::interrupt(n1,10);AnmManager::interrupt(n2,10);AnmManager::interrupt(n3,10);AnmManager::interrupt(n4,10);AnmManager::interrupt(d,10);AnmManager::interrupt(s,10);
    n1 = AnmManager::newAnim(asciiNum2,-1,1); AnmManager::anim(n1)->offset_sprite((int)floor(bestTime)%10); AnmManager::UpdateChild(n1,xx,yy2,0,0,0,0,1,1,1); AnmManager::anim(n1)->set_color(128,128,128);
    n2 = AnmManager::newAnim(asciiNum1,-1,1); AnmManager::anim(n2)->offset_sprite((int)floor(bestTime/10.f)%10); AnmManager::UpdateChild(n2,xx,yy2,0,0,0,0,1,1,1);AnmManager::anim(n2)->set_color(128,128,128);
    n3 = AnmManager::newAnim(asciiNum1,-1,1); AnmManager::anim(n3)->offset_sprite((int)floor(bestTime*10)%10); AnmManager::UpdateChild(n3,xx+20-50,yy2-4+100,0,0,0,0,.5,.5,1);AnmManager::anim(n3)->set_color(128,128,128);
    n4 = AnmManager::newAnim(asciiNum2,-1,1); AnmManager::anim(n4)->offset_sprite((int)floor(bestTime*100)%10); AnmManager::UpdateChild(n4,xx+20-50,yy2-4+100,0,0,0,0,.5,.5,1);AnmManager::anim(n4)->set_color(128,128,128);
    d = AnmManager::newAnim(asciiNum1,-1,1); AnmManager::anim(d)->offset_sprite(11); AnmManager::UpdateChild(d,xx+22,yy2,0,0,0,0,1,1,1);AnmManager::anim(d)->set_color(128,128,128);
    s = AnmManager::newAnim(asciiNum1,-1,1); AnmManager::anim(s)->offset_sprite(12); AnmManager::UpdateChild(s,xx+32-50,yy2-4+100,0,0,0,0,.5,.5,1); AnmManager::anim(s)->set_color(128,128,128);
    AnmManager::interrupt(n1,10);AnmManager::interrupt(n2,10);AnmManager::interrupt(n3,10);AnmManager::interrupt(n4,10);AnmManager::interrupt(d,10);AnmManager::interrupt(s,10);
}

void Timer::interruptAll(int i)
{
    AnmManager::interrupt(nb1,i);
    AnmManager::interrupt(nb2,i);
    AnmManager::interrupt(nb3,i);
    AnmManager::interrupt(nb4,i);
    AnmManager::interrupt(dot,i);
}

void Timer::Update()
{
    static int src_timeout = NSEngine::AudioEngine::CreateSource();
    if (time > 0)
    {
        float timePrevious = time;
        if (nb1 == -1 || nb2 == -1) return;
        static bool fade = false;
        if (PlayerEntity::GetInstance()->y > 120) {if(!fade) {interruptAll(5);fade=true;}}
        else if (fade) {interruptAll(4);fade=false;}
 /*       
        if (floor(timePrevious/10.f) != floor(time/10.f))
        {
            AnimManager::anim(nb1)->offset_sprite(9);
            AnimManager::anim(nb2)->offset_sprite(-1);
        }
        else AnimManager::anim(nb1)->offset_sprite(-1);*/
        SetTime(time-1.f/60.f);
        if (floor(timePrevious) == floor(time)) return;
        if (time == 0) interruptAll(7);
        if (time <= 2)
        {
            NSEngine::AudioEngine::PlaySoundAtSource(src_timeout,gameassets::se_timeout2);
            interruptAll(9);
        }
        else if (time <= 5)
        {
            NSEngine::AudioEngine::PlaySoundAtSource(src_timeout,gameassets::se_timeout);
            interruptAll(8);
        }
    }
}

void Timer::ShowCardScore(int score)
{
    int i = score % 10;
    score /= 10;
    AnmManager::anim(AnmManager::newAnim(asciiNum10,-1,true))->offset_sprite(i);
    if (score <= 0 ) return;
    i = score % 10;
    score /= 10;
    AnmManager::anim(AnmManager::newAnim(asciiNum9,-1,true))->offset_sprite(i);
    if (score <= 0 ) return;
    i = score % 10;
    score /= 10;
    AnmManager::anim(AnmManager::newAnim(asciiNum8,-1,true))->offset_sprite(i);
    if (score <= 0 ) return;
    AnmManager::newAnim(asciiNum12,-1,true);
    i = score % 10;
    score /= 10;
    AnmManager::anim(AnmManager::newAnim(asciiNum7,-1,true))->offset_sprite(i);
    if (score <= 0 ) return;
    i = score % 10;
    score /= 10;
    AnmManager::anim(AnmManager::newAnim(asciiNum6,-1,true))->offset_sprite(i);
    if (score <= 0 ) return;
    i = score % 10;
    score /= 10;
    AnmManager::anim(AnmManager::newAnim(asciiNum5,-1,true))->offset_sprite(i);
    if (score <= 0 ) return;
    AnmManager::newAnim(asciiNum11,-1,true);
    i = score % 10;
    score /= 10;
    AnmManager::anim(AnmManager::newAnim(asciiNum4,-1,true))->offset_sprite(i);
    if (score <= 0 ) return;
    i = score % 10;
    score /= 10;
    AnmManager::anim(AnmManager::newAnim(asciiNum3,-1,true))->offset_sprite(i);
}
