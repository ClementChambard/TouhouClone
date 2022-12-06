#include "AnmAscii.h"
#include <NSEngine.h>

int asc239;
int asc240;
int asc241;
int asc242;
int asc243;
int asc244;
int asc245;
int asc246;
int asc247;
int asc248;
int asc249;
int asc250;
int asc251;
int asc252;
int asc253;
int asc254;
int asc255;
int asc256;

int asc290;
int asc291;
int asc292;

bool AnmAscii::isInit = false;
void AnmAscii::Init()
{
    if (isInit) return;
    int tex_ascii = gameassets::tex_ascii;
    asc239 = GS_ AddSprite(tex_ascii,16,144,16,16);
    asc240 = GS_ AddSprite(tex_ascii,32,144,16,16);
    asc241 = GS_ AddSprite(tex_ascii,48,144,16,16);
    asc242 = GS_ AddSprite(tex_ascii,64,144,16,16);
    asc243 = GS_ AddSprite(tex_ascii,80,144,16,16);
    asc244 = GS_ AddSprite(tex_ascii,96,144,16,16);
    asc245 = GS_ AddSprite(tex_ascii,112,144,16,16);
    asc246 = GS_ AddSprite(tex_ascii,128,144,16,16);
    asc247 = GS_ AddSprite(tex_ascii,144,144,16,16);
    asc248 = GS_ AddSprite(tex_ascii,160,144,16,16);
    asc249 = GS_ AddSprite(tex_ascii,176,144,16,16);
    asc250 = GS_ AddSprite(tex_ascii,192,144,16,16);
    asc251 = GS_ AddSprite(tex_ascii,208,144,16,16);
    asc252 = GS_ AddSprite(tex_ascii,224,144,16,16);
    asc253 = GS_ AddSprite(tex_ascii,240,144,16,16);
    asc254 = GS_ AddSprite(tex_ascii,208,240,48,16);
    asc255 = GS_ AddSprite(tex_ascii,0,192,256,40);
    asc256 = GS_ AddSprite(tex_ascii,0,182,144,10);
    int tex_ascii2 = NSEngine::TextureManager::RegisterTexture("assets/textures/ascii/loading.png");
    asc290 = GS_ AddSprite(tex_ascii2,1,1,254,62);
    asc291 = GS_ AddSprite(tex_ascii2,1,65,254,62);
    asc292 = GS_ AddSprite(tex_ascii2,65,129,62,62);
}

void CardTest(AnimScript* anm)
{
    if (anm->frame == 0)
    {
        anm->visible(false);
        anm->create_child(asciiCardnameBg);
        anm->create_child(asciiCardHistory);
    }
    if (anm->frame == 1) anm->frame = 0;
    if (anm->frame == 50) anm->destroy();
    if (anm->interrupt == 1) anm->frame = 1;
}

void asciiCardnameBg(AnimScript* anm)
{
    float xx = -320 + 416.f-128+96;
    float yy = 240-384.f-20;
    if (anm->frame == 0)
    {
        anm->set_layer(GL_ L18);
        anm->set_sprite(asc255);
        anm->set_alpha(0);
        anm->set_scale(4,4);
        anm->scale_time(60,4,1,1);
        anm->set_pos(xx,yy,0.f);
    }
    else if (anm->frame == 30) anm->alpha_time(30,0,255);
    else if (anm->frame == 60) anm->pos_time(60,10,xx,yy+384.f,0);
    else if (anm->frame == 61) anm->frame = 60;
    else if (anm->frame == 91) anm->destroy();
    if (anm->interrupt == 3) anm->alpha_time(8,1,128);
    else if (anm->interrupt == 2) anm->alpha_time(8,1,255);
    else if (anm->interrupt == 1)
    {
        anm->pos_time(30,4,xx+256,yy+384,0);
        anm->frame = 61;
    }
}

void asciiCardHistory(AnimScript* anm)
{
    float xx = -320 + 376.0f-72+96;                                                                     
    float yy = 240-35.0f-5;
    if (anm->frame == 0)
    {
        anm->set_layer(GL_ L19);
        anm->set_sprite(asc256);
        anm->set_alpha(0);
        anm->set_pos(xx,yy,0);
    }
    else if (anm->frame == 90) anm->alpha_time(30,0,255);
    else if (anm->frame == 91) anm->frame = 90;
    else if (anm->frame == 121) anm->destroy();
    if (anm->interrupt == 3) anm->alpha_time(8,1,32);
    else if (anm->interrupt == 2) anm->alpha_time(8,1,255);
    else if (anm->interrupt == 1)
    {
        anm->pos_time(30,4,xx+296,yy,0);
        anm->frame = 91;
    }
}

void asciiNum1(AnimScript* anm)
{
    if (anm->frame == 0)
    {
        anm->set_sprite(asc239);
        anm->set_layer(GL_ L26);
        anm->set_pos(-112,201,0);//39
    }
    else if (anm->frame == 1) anm->frame = 0;
    else if (anm->frame == 31) anm->alpha_time(20,0,255);
    else if (anm->frame == 141) anm->alpha_time(20,0,0);
    else if (anm->frame == 171) anm->destroy();
    if (anm->interrupt == 2) { anm->pos_time(60,9,-112,189,0); anm->set_color(255,255,255); } //51
    else if (anm->interrupt == 3) { anm->pos_time(60,9,-112,217,0); anm->set_color(255,255,255); } //23
    else if (anm->interrupt == 4) anm->alpha_time(20,0,255);
    else if (anm->interrupt == 5) anm->alpha_time(20,0,64);
    else if (anm->interrupt == 7) anm->set_color(255,255,255);
    else if (anm->interrupt == 8)
    {
        anm->set_color(255,144,144);
        float xs=anm->xs_(); float ys=anm->ys_();
        anm->set_scale(xs*1.4f,ys*1.4f);
        anm->scale_time(8,0,xs,ys);
    }
    else if (anm->interrupt == 9)
    {
        anm->set_color(255,64,64);
        float xs=anm->xs_(); float ys=anm->ys_();
        anm->set_scale(xs*1.8f,ys*1.8f);
        anm->scale_time(8,0,xs,ys);
    }
    else if (anm->interrupt == 10) { anm->frame = 1; anm->set_alpha(0); }
}

void asciiNum2(AnimScript* anm)
{
    if (anm->frame == 0)
    {
        anm->set_sprite(asc239);
        anm->set_layer(GL_ L26);
        anm->set_pos(-100,201,0);
    }
    else if (anm->frame == 1) anm->frame = 0;
    else if (anm->frame == 31) anm->alpha_time(20,0,255);
    else if (anm->frame == 141) anm->alpha_time(20,0,0);
    else if (anm->frame == 171) anm->destroy();
    if (anm->interrupt == 2) { anm->pos_time(60,9,-100,189,0); anm->set_color(255,255,255); }
    else if (anm->interrupt == 3) { anm->pos_time(60,9,-100,217,0); anm->set_color(255,255,255); }
    else if (anm->interrupt == 4) anm->alpha_time(20,0,255);
    else if (anm->interrupt == 5) anm->alpha_time(20,0,64);
    else if (anm->interrupt == 7) anm->set_color(255,255,255);
    else if (anm->interrupt == 8)
    {
        anm->set_color(255,144,144);
        float xs=anm->xs_(); float ys=anm->ys_();
        anm->set_scale(xs*1.4f,ys*1.4f);
        anm->scale_time(8,0,xs,ys);
    }
    else if (anm->interrupt == 9)
    {
        anm->set_color(255,64,64);
        float xs=anm->xs_(); float ys=anm->ys_();
        anm->set_scale(xs*1.8f,ys*1.8f);
        anm->scale_time(8,0,xs,ys);
    }
    else if (anm->interrupt == 10) { anm->frame = 1; anm->set_alpha(0); }
}

void asciiNum3(AnimScript* anm)
{
    float f1 = 27, f2 = 53;
    if (anm->frame == 0)
    {
        anm->set_sprite(asc239);
        anm->set_layer(GL_ L22);
        anm->set_pos(-150+96,116,0);
        anm->set_alpha(0);
    }
    else if (anm->frame == 20+f1)
    {
        anm->alpha_time(8,0,255);
        anm->pos_time(10,4,-150+96,132,0);
    }
    else if (anm->frame == 30+f1)
    {
        anm->pos_time(10,1,-150+96,116,0);
        anm->set_color(255,255,255);
    }
    else if (anm->frame == 32+f1 || anm->frame == 36+f1 || anm->frame == 40+f1 || anm->frame == 44+f1 || anm->frame == 48+f1 || anm->frame == 52+f1) anm->set_color(128,128,128);
    else if (anm->frame == 34+f1 || anm->frame == 38+f1 || anm->frame == 42+f1 || anm->frame == 46+f1 || anm->frame == 50+f1 || anm->frame == 54+f1) anm->set_color(255,255,255);
    else if (anm->frame == 54+f1+f2) anm->scale_time(20,4,1,0);
    else if (anm->frame == 74+f1+f2) anm->destroy();
}
void asciiNum4(AnimScript* anm)
{
    float f1 = 24, f2 = 56;
    if (anm->frame == 0)
    {
        anm->set_sprite(asc239);
        anm->set_layer(GL_ L22);
        anm->set_pos(-138+96,116,0);
        anm->set_alpha(0);
    }
    else if (anm->frame == 20+f1)
    {
        anm->alpha_time(8,0,255);
        anm->pos_time(10,4,-138+96,132,0);
    }
    else if (anm->frame == 30+f1)
    {
        anm->pos_time(10,1,-138+96,116,0);
        anm->set_color(255,255,255);
    }
    else if (anm->frame == 32+f1 || anm->frame == 36+f1 || anm->frame == 40+f1 || anm->frame == 44+f1 || anm->frame == 48+f1 || anm->frame == 52+f1) anm->set_color(128,128,128);
    else if (anm->frame == 34+f1 || anm->frame == 38+f1 || anm->frame == 42+f1 || anm->frame == 46+f1 || anm->frame == 50+f1 || anm->frame == 54+f1) anm->set_color(255,255,255);
    else if (anm->frame == 54+f1+f2) anm->scale_time(20,4,1,0);
    else if (anm->frame == 74+f1+f2) anm->destroy();
}
void asciiNum5(AnimScript* anm)
{
    float f1 = 18, f2 = 62;
    if (anm->frame == 0)
    {
        anm->set_sprite(asc239);
        anm->set_layer(GL_ L22);
        anm->set_pos(-122+96,116,0);
        anm->set_alpha(0);
    }
    else if (anm->frame == 20+f1)
    {
        anm->alpha_time(8,0,255);
        anm->pos_time(10,4,-122+96,132,0);
    }
    else if (anm->frame == 30+f1)
    {
        anm->pos_time(10,1,-122+96,116,0);
        anm->set_color(255,255,255);
    }
    else if (anm->frame == 32+f1 || anm->frame == 36+f1 || anm->frame == 40+f1 || anm->frame == 44+f1 || anm->frame == 48+f1 || anm->frame == 52+f1) anm->set_color(128,128,128);
    else if (anm->frame == 34+f1 || anm->frame == 38+f1 || anm->frame == 42+f1 || anm->frame == 46+f1 || anm->frame == 50+f1 || anm->frame == 54+f1) anm->set_color(255,255,255);
    else if (anm->frame == 54+f1+f2) anm->scale_time(20,4,1,0);
    else if (anm->frame == 74+f1+f2) anm->destroy();
}
void asciiNum6(AnimScript* anm)
{
    float f1 = 15, f2 = 65;
    if (anm->frame == 0)
    {
        anm->set_sprite(asc239);
        anm->set_layer(GL_ L22);
        anm->set_pos(-110+96,116,0);
        anm->set_alpha(0);
    }
    else if (anm->frame == 20+f1)
    {
        anm->alpha_time(8,0,255);
        anm->pos_time(10,4,-110+96,132,0);
    }
    else if (anm->frame == 30+f1)
    {
        anm->pos_time(10,1,-110+96,116,0);
        anm->set_color(255,255,255);
    }
    else if (anm->frame == 32+f1 || anm->frame == 36+f1 || anm->frame == 40+f1 || anm->frame == 44+f1 || anm->frame == 48+f1 || anm->frame == 52+f1) anm->set_color(128,128,128);
    else if (anm->frame == 34+f1 || anm->frame == 38+f1 || anm->frame == 42+f1 || anm->frame == 46+f1 || anm->frame == 50+f1 || anm->frame == 54+f1) anm->set_color(255,255,255);
    else if (anm->frame == 54+f1+f2) anm->scale_time(20,4,1,0);
    else if (anm->frame == 74+f1+f2) anm->destroy();
}
void asciiNum7(AnimScript* anm)
{
    float f1 = 12, f2 = 68;
    if (anm->frame == 0)
    {
        anm->set_sprite(asc239);
        anm->set_layer(GL_ L22);
        anm->set_pos(-98+96,116,0);
        anm->set_alpha(0);
    }
    else if (anm->frame == 20+f1)
    {
        anm->alpha_time(8,0,255);
        anm->pos_time(10,4,-98+96,132,0);
    }
    else if (anm->frame == 30+f1)
    {
        anm->pos_time(10,1,-98+96,116,0);
        anm->set_color(255,255,255);
    }
    else if (anm->frame == 32+f1 || anm->frame == 36+f1 || anm->frame == 40+f1 || anm->frame == 44+f1 || anm->frame == 48+f1 || anm->frame == 52+f1) anm->set_color(128,128,128);
    else if (anm->frame == 34+f1 || anm->frame == 38+f1 || anm->frame == 42+f1 || anm->frame == 46+f1 || anm->frame == 50+f1 || anm->frame == 54+f1) anm->set_color(255,255,255);
    else if (anm->frame == 54+f1+f2) anm->scale_time(20,4,1,0);
    else if (anm->frame == 74+f1+f2) anm->destroy();
}
void asciiNum8(AnimScript* anm)
{
    float f1 = 6, f2 = 74;
    if (anm->frame == 0)
    {
        anm->set_sprite(asc239);
        anm->set_layer(GL_ L22);
        anm->set_pos(-82+96,116,0);
        anm->set_alpha(0);
    }
    else if (anm->frame == 20+f1)
    {
        anm->alpha_time(8,0,255);
        anm->pos_time(10,4,-82+96,132,0);
    }
    else if (anm->frame == 30+f1)
    {
        anm->pos_time(10,1,-82+96,116,0);
        anm->set_color(255,255,255);
    }
    else if (anm->frame == 32+f1 || anm->frame == 36+f1 || anm->frame == 40+f1 || anm->frame == 44+f1 || anm->frame == 48+f1 || anm->frame == 52+f1) anm->set_color(128,128,128);
    else if (anm->frame == 34+f1 || anm->frame == 38+f1 || anm->frame == 42+f1 || anm->frame == 46+f1 || anm->frame == 50+f1 || anm->frame == 54+f1) anm->set_color(255,255,255);
    else if (anm->frame == 54+f1+f2) anm->scale_time(20,4,1,0);
    else if (anm->frame == 74+f1+f2) anm->destroy();
}
void asciiNum9(AnimScript* anm)
{
    float f1 = 3, f2 = 77;
    if (anm->frame == 0)
    {
        anm->set_sprite(asc239);
        anm->set_layer(GL_ L22);
        anm->set_pos(-70+96,116,0);
        anm->set_alpha(0);
    }
    else if (anm->frame == 20+f1)
    {
        anm->alpha_time(8,0,255);
        anm->pos_time(10,4,-70+96,132,0);
    }
    else if (anm->frame == 30+f1)
    {
        anm->pos_time(10,1,-70+96,116,0);
        anm->set_color(255,255,255);
    }
    else if (anm->frame == 32+f1 || anm->frame == 36+f1 || anm->frame == 40+f1 || anm->frame == 44+f1 || anm->frame == 48+f1 || anm->frame == 52+f1) anm->set_color(128,128,128);
    else if (anm->frame == 34+f1 || anm->frame == 38+f1 || anm->frame == 42+f1 || anm->frame == 46+f1 || anm->frame == 50+f1 || anm->frame == 54+f1) anm->set_color(255,255,255);
    else if (anm->frame == 54+f1+f2) anm->scale_time(20,4,1,0);
    else if (anm->frame == 74+f1+f2) anm->destroy();
}
void asciiNum10(AnimScript* anm)
{
    float f1 = 0, f2 = 80;
    if (anm->frame == 0)
    {
        anm->set_sprite(asc239);
        anm->set_layer(GL_ L22);
        anm->set_pos(-58+96,116,0);
        anm->set_alpha(0);
    }
    else if (anm->frame == 20+f1)
    {
        anm->alpha_time(8,0,255);
        anm->pos_time(10,4,-58+96,132,0);
    }
    else if (anm->frame == 30+f1)
    {
        anm->pos_time(10,1,-58+96,116,0);
        anm->set_color(255,255,255);
    }
    else if (anm->frame == 32+f1 || anm->frame == 36+f1 || anm->frame == 40+f1 || anm->frame == 44+f1 || anm->frame == 48+f1 || anm->frame == 52+f1) anm->set_color(128,128,128);
    else if (anm->frame == 34+f1 || anm->frame == 38+f1 || anm->frame == 42+f1 || anm->frame == 46+f1 || anm->frame == 50+f1 || anm->frame == 54+f1) anm->set_color(255,255,255);
    else if (anm->frame == 54+f1+f2) anm->scale_time(20,4,1,0);
    else if (anm->frame == 74+f1+f2) anm->destroy();
}
void asciiNum11(AnimScript* anm)
{
    float f1 = 21, f2 = 59;
    if (anm->frame == 0)
    {
        anm->set_sprite(asc253);
        anm->set_layer(GL_ L22);
        anm->set_pos(-126+96,116,0);
        anm->set_alpha(0);
    }
    else if (anm->frame == 20+f1)
    {
        anm->alpha_time(8,0,255);
        anm->pos_time(10,4,-126+96,132,0);
    }
    else if (anm->frame == 30+f1)
    {
        anm->pos_time(10,1,-126+96,116,0);
        anm->set_color(255,255,255);
    }
    else if (anm->frame == 32+f1 || anm->frame == 36+f1 || anm->frame == 40+f1 || anm->frame == 44+f1 || anm->frame == 48+f1 || anm->frame == 52+f1) anm->set_color(128,128,128);
    else if (anm->frame == 34+f1 || anm->frame == 38+f1 || anm->frame == 42+f1 || anm->frame == 46+f1 || anm->frame == 50+f1 || anm->frame == 54+f1) anm->set_color(255,255,255);
    else if (anm->frame == 54+f1+f2) anm->scale_time(20,4,1,0);
    else if (anm->frame == 74+f1+f2) anm->destroy();
}
void asciiNum12(AnimScript* anm)
{
    float f1 = 9, f2 = 71;
    if (anm->frame == 0)
    {
        anm->set_sprite(asc253);
        anm->set_layer(GL_ L22);
        anm->set_pos(-86+96,116,0);
        anm->set_alpha(0);
    }
    else if (anm->frame == 20+f1)
    {
        anm->alpha_time(8,0,255);
        anm->pos_time(10,4,-86+96,132,0);
    }
    else if (anm->frame == 30+f1)
    {
        anm->pos_time(10,1,-86+96,116,0);
        anm->set_color(255,255,255);
    }
    else if (anm->frame == 32+f1 || anm->frame == 36+f1 || anm->frame == 40+f1 || anm->frame == 44+f1 || anm->frame == 48+f1 || anm->frame == 52+f1) anm->set_color(128,128,128);
    else if (anm->frame == 34+f1 || anm->frame == 38+f1 || anm->frame == 42+f1 || anm->frame == 46+f1 || anm->frame == 50+f1 || anm->frame == 54+f1) anm->set_color(255,255,255);
    else if (anm->frame == 54+f1+f2) anm->scale_time(20,4,1,0);
    else if (anm->frame == 74+f1+f2) anm->destroy();
}

void asciiLoadP1(AnimScript* anm)
{
    if (anm->frame == 0)
    {
        anm->set_sprite(asc290);
        anm->set_layer(GL_ L30);
        anm->set_pos(0,0,0.01f);
        anm->set_alpha(0);
        anm->alpha_time(8,0,255);
    }
    else if (anm->frame == 20 || anm->frame == 60) {anm->frame =20; anm->alpha_time(20,9,255);}
    else if (anm->frame == 40) anm->alpha_time(20,9,128);
    else if (anm->frame == 91) anm->destroy();
    if (anm->interrupt == 1) {anm->frame =61; anm->alpha_time(30,0,0);}
}

void asciiLoadP2(AnimScript* anm)
{
    if (anm->frame == 0)
    {
        anm->set_sprite(asc291);
        anm->set_layer(GL_ L30);
        anm->set_pos(256,-32,0);
        anm->set_alpha(0);
    }
    else if (anm->frame == 8) 
    {
        anm->pos_time(4,4,96,-32,0);
        anm->alpha_time(8,0,255);
    }
    else if (anm->frame == 38 || anm->frame == 98) {anm->frame = 38; anm->alpha_time(30,9,255);}
    else if (anm->frame == 68) anm->alpha_time(30,9,128);
    else if (anm->frame == 129) anm->destroy();
    if (anm->interrupt == 1)
    {
        anm->frame = 99;
        anm->pos_time(30,4,240,-32,0);
        anm->alpha_time(30,0,0);
    }
}
#include <math/Random.h>
void asciiLoadP3(AnimScript* anm)
{
    if (anm->frame == 0)
    {
        anm->set_sprite(asc292);
        anm->set_layer(GL_ L30);
        anm->set_blendmode(1);
        float F0 = Random::Floatm11()*192+32;
        float F1 = Random::Floatm11()*32-64;
        float F2 = Random::Floatm11()*64+F0;
        float F3 = Random::Floatm11()*32+96;
        anm->set_pos(F0,-F1,0.02f);
        anm->pos_time(120,0,F2,-F3,0.02f);
        F0 = Random::Float01()*0.8f+0.2f;
        anm->set_scale(F0,F0);
        anm->set_rot(Random::Angle(),Random::Angle(),Random::Angle());
        anm->rot_vel(Random::Angle()/80.f,Random::Angle()/80.f,Random::Angle()/80.f);
        anm->set_alpha(0);
        anm->alpha_time(10,0,255);
        anm->set_color((uint8_t)(Random::Float01()*192.f+63.f),0,0);
    }
    else if (anm->frame == 110) anm->alpha_time(10,0,0);
    else if (anm->frame == 120 || anm->frame == 131) anm->destroy();
    if (anm->interrupt == 1)
    {
        anm->frame = 121;
        anm->alpha_time(10,0,0);
    }
}

void asciiLoad(AnimScript* anm)
{
    if (anm->frame == 0) 
    {
        anm->visible(false);
        anm->set_sprite(1);anm->set_layer(1);
    }
    else if (anm->frame == 1 || anm->frame == 5)
    {
        if (anm->frame == 1) {anm->create_child(asciiLoadP1);anm->create_child(asciiLoadP2);}
        anm->frame = 1;
        anm->create_child(asciiLoadP3);
    }
    else if (anm->frame == 16) anm->destroy();
    if (anm->interrupt == 1) anm->frame = 6;
}

void asciiLoadEff(AnimScript* anm)
{
    if (anm->frame == 0)
    {
        anm->set_sprite(asc292);
        anm->set_layer(GL_ L30);
        anm->set_color(255,1,64);
        float F0 = Random::Float01()*1280, F1 = Random::Float01()*960+256;
        float F2 = Random::Float01()*256+F0, F3 = Random::Float01()*256+384+F1;
        anm->set_pos(F0,F1,0.5f);
        anm->pos_time(300,0,F2,F3,0.5f);
        F0 = Random::Float01()*0.8f+0.2f;
        anm->set_scale(F0,F0);
        anm->set_rot(Random::Angle(),Random::Angle(),Random::Angle());
        anm->rot_vel(Random::Angle()/80.f,Random::Angle()/80.f,Random::Angle()/80.f);
        anm->set_alpha(0);
        anm->alpha_time(30,0,128);
    }
    else if (anm->frame == 290 || anm->interrupt == 1) {anm->frame = 290; anm->alpha_time(10,0,0);}
    else if (anm->frame == 300) anm->destroy();
}

void asciiLoadEffMake(AnimScript* anm)
{
    if (anm->frame == 0) anm->visible(false);
    else if (anm->frame == 1 || anm->frame == 4)
    {
        anm->frame = 1;
        for (int i = 0; i < 16; i++) anm->create_child(asciiLoadEff);
    }
    else if (anm->frame == 15) anm->destroy();
    if (anm->interrupt == 1) anm->frame = 5;
}
