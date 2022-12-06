#include "AnmEffects.h"
#include <NSEngine.h>

int spr0;  //switch
int spr1;  //line
int spr2;
int spr3;
int spr4;
int spr5;
int spr6;
int spr7;  //base
//base until 22 but unused
int spr23; //slow
int spr24;
int spr25; //deadcircle
int spr26; 
int spr27;
int spr28;
int spr29; //maple
int spr30;
int spr31;
int spr32;
int spr33; //magicsquare
int spr34; //aura
int spr35;
int spr36;
int spr37;
int spr38;
int spr39;
//effectlinegoast useless?
int spr41; //breakwave
int spr42;
int spr43;
int spr44;
int spr45;
int spr46;
int spr47;
int spr48;
int spr49;
int spr50;
int spr51;
int spr52;
int spr53; //splash
int spr54;
int spr55;
int spr56;
int spr57;
int spr58;
int spr59;
int spr60;
int spr61;
int spr62; //charge
int spr63; //switchbg

bool AnmEffects::isInit = false;
void AnmEffects::Init()
{
    if (isInit) return;

    int tex_eff_switch = NSEngine::TextureManager::RegisterTexture("assets/textures/effect/eff_switch.png");
    spr0 = GS_ AddSprite(tex_eff_switch,0,1,128,128);
    int tex_line = NSEngine::TextureManager::RegisterTexture("assets/textures/effect/eff_line.png");
    spr1 = GS_ AddSprite(tex_line,65,0,14,128);
    spr2 = GS_ AddSprite(tex_line,81,0,14,128);
    spr3 = GS_ AddSprite(tex_line,49,0,14,128);
    spr4 = GS_ AddSprite(tex_line,49,0,14,128);
    spr5 = GS_ AddSprite(tex_line,33,0,14,295);
    spr6 = GS_ AddSprite(tex_line,97,0,15,448);
    int tex_base = NSEngine::TextureManager::RegisterTexture("assets/textures/effect/eff_base.png");
    spr7 = GS_ AddSprite(tex_base,0,0,16,16);

    int tex_slow = NSEngine::TextureManager::RegisterTexture("assets/textures/effect/eff_sloweffect.png");
    spr23 = GS_ AddSprite(tex_slow,0,0,64,64);
    spr24 = GS_ AddSprite(tex_slow,64,0,64,64);
    int tex_deadcircle = NSEngine::TextureManager::RegisterTexture("assets/textures/effect/eff_deadcircle.png");
    spr25 = GS_ AddSprite(tex_deadcircle,0,0,64,64);
    spr26 = GS_ AddSprite(tex_deadcircle,0,64,64,64);
    spr27 = GS_ AddSprite(tex_deadcircle,64,0,64,64);
    spr28 = GS_ AddSprite(tex_deadcircle,64,64,64,64);
    int tex_maple = NSEngine::TextureManager::RegisterTexture("assets/textures/effect/eff_maple.png");
    spr29 = GS_ AddSprite(tex_maple,0,0,32,32);
    spr30 = GS_ AddSprite(tex_maple,32,0,32,32);
    spr31 = GS_ AddSprite(tex_maple,0,32,32,32);
    spr32 = GS_ AddSprite(tex_maple,32,32,32,32);
    int tex_magic_square = NSEngine::TextureManager::RegisterTexture("assets/textures/effect/eff_magicsquare.png");
    spr33 = GS_ AddSprite(tex_magic_square,0,0,256,256);
    int tex_aura = NSEngine::TextureManager::RegisterTexture("assets/textures/effect/eff_aura.png");
    spr34 = GS_ AddSprite(tex_aura,0,0,48,48);
    spr35 = GS_ AddSprite(tex_aura,48,0,48,48);
    spr36 = GS_ AddSprite(tex_aura,96,0,8,8);
    spr37 = GS_ AddSprite(tex_aura,104,0,8,8);
    spr38 = GS_ AddSprite(tex_aura,112,0,8,8);
    spr39 = GS_ AddSprite(tex_aura,120,0,8,8);
    //linegoast
    int tex_breakwave = NSEngine::TextureManager::RegisterTexture("assets/textures/effect/eff_breakwave2.png");
    spr41 = GS_ AddSprite(tex_breakwave,0,0,160,80);
    spr42 = GS_ AddSprite(tex_breakwave,160,0,160,80);
    spr43 = GS_ AddSprite(tex_breakwave,320,0,160,80);
    spr44 = GS_ AddSprite(tex_breakwave,0,80,160,80);
    spr45 = GS_ AddSprite(tex_breakwave,160,80,160,80);
    spr46 = GS_ AddSprite(tex_breakwave,320,80,160,80);
    spr47 = GS_ AddSprite(tex_breakwave,0,160,160,80);
    spr48 = GS_ AddSprite(tex_breakwave,160,160,160,80);
    spr49 = GS_ AddSprite(tex_breakwave,320,160,160,80);
    spr50 = GS_ AddSprite(tex_breakwave,0,240,160,80);
    spr51 = GS_ AddSprite(tex_breakwave,160,240,160,80);
    spr52 = GS_ AddSprite(tex_breakwave,320,240,160,80);

    int tex_splash = NSEngine::TextureManager::RegisterTexture("assets/textures/effect/eff_splash.png");
    spr53 = GS_ AddSprite(tex_splash,0,0,96,16);
    spr54 = GS_ AddSprite(tex_splash,0,16,96,16);
    spr55 = GS_ AddSprite(tex_splash,0,32,96,16);
    spr56 = GS_ AddSprite(tex_splash,0,48,96,16);
    spr57 = GS_ AddSprite(tex_splash,0,64,96,16);
    spr58 = GS_ AddSprite(tex_splash,0,80,96,16);
    spr59 = GS_ AddSprite(tex_splash,0,96,96,16);
    spr60 = GS_ AddSprite(tex_splash,0,112,96,16);
    spr61 = GS_ AddSprite(tex_splash,0,128,96,16);
    isInit = true;

    int tex_charge = NSEngine::TextureManager::RegisterTexture("assets/textures/effect/eff_charge.png");
    spr62 = GS_ AddSprite(tex_charge,0,0,32,32);
}

#include <math/math.h>
#include <math/Random.h>

int spellcardDuration = 600;
void setSpellcardDuration(int t) { spellcardDuration = t; }
void effectSpellcardRingP1(AnimScript* anm)
{
    if (anm->frame == 0)
    {
        anm->set_sprite(spr2);
        anm->set_layer(GL_ L5);
        anm->set_blendmode(1);
        anm->set_alpha(255);
        anm->set_pos(0,0,32);
        anm->alpha_time(8,0,128);
        anm->rot_vel(0,0,PI/10.f);
        anm->set_rot(3,PI2,0);
        anm->set_scale(16,16);
        anm->scale_time(40,4,16,320);
        anm->special_draw(1);
    }
    else if (anm->frame == 40)
    {
        anm->scale_time(40,1,16,172);
        anm->rot_vel(0,0,-0.10471976f);
    }
    else if (anm->frame == 80)
    {
        anm->scale_time(spellcardDuration,0,16.f,14.f);
        anm->rot_vel(0,0,-0.05235988f);
    }
    else if (anm->frame == 80+spellcardDuration) anm->alpha_time(20,0,0);
    else if (anm->frame == 100+spellcardDuration) anm->destroy();
}
void effectSpellcardRingP2(AnimScript* anm)
{
    if (anm->frame == 0)
    {
        anm->set_sprite(spr3);
        anm->set_layer(GL_ L5);
        anm->set_blendmode(1);
        anm->set_alpha(255);
        anm->set_pos(0,0,32);
        anm->alpha_time(8,0,128);
        anm->rot_vel(0,0,-PI/10.f);
        anm->set_rot(3,PI2,0);
        anm->set_scale(128,16);
        anm->scale_time(80,9,16,160);
        anm->special_draw(1);
    }
    else if (anm->frame == 80)
    {
        anm->scale_time(spellcardDuration,0,14.f,16.f);
        anm->rot_vel(0,0,0.06283186f);
    }
    else if (anm->frame == 80+spellcardDuration) anm->alpha_time(20,0,0);
    else if (anm->frame == 100+spellcardDuration) anm->destroy();
}
void effectSpellcardRing(AnimScript* anm)
{
    if (anm->frame == 0)
    {
        anm->set_layer(GL_ L5); anm->set_sprite(spr1);
        anm->set_alpha(0); anm->visible(false);
        anm->create_child(effectSpellcardRingP1);
        anm->create_child(effectSpellcardRingP2);
    }
    else if (anm->frame == 101+spellcardDuration) anm->destroy();
}
void effectSpellcardAttackP1(AnimScript* anm)
{
    if (anm->frame == 0)
    {
        anm->set_sprite(spr6);
        anm->set_layer(GL_ L5);
        anm->set_blendmode(1);
        anm->set_scale(1,1);
        anm->set_rot(0,0,-1.0471976f);
        anm->scroll_y(0.01f);
        anm->set_alpha(0);
        anm->alpha_time(20,0,128);
    }
    else if (anm->frame == 120) anm->alpha_time(20,0,0);
    else if (anm->frame == 140) anm->destroy();
}
void effectSpellcardAttackP2(AnimScript* anm)
{
    if (anm->frame == 0)
    {
        anm->set_sprite(spr6);
        anm->set_layer(GL_ L5);
        anm->set_blendmode(1);
        anm->set_scale(1,1);
        anm->set_rot(0,0,-1.0471976f);
        anm->scroll_y(-0.01f);
        anm->set_alpha(0);
        anm->alpha_time(20,0,128);
    }
    else if (anm->frame == 120) anm->alpha_time(20,0,0);
    else if (anm->frame == 140) anm->destroy();
}
void effectSpellcardAttackP3(AnimScript* anm)
{
    if (anm->frame == 0)
    {
        anm->set_sprite(spr6);
        anm->set_layer(GL_ L5);
        anm->set_blendmode(1);
        anm->set_pos(128,-384,9);
        anm->set_rot(8,PI2,0);
        anm->rot_vel(0,0,0.02617994f);
        anm->set_scale(16,128);
        anm->set_alpha(0);
        anm->alpha_time(20,0,128);
        anm->special_draw(1);
    }
    else if (anm->frame == 120) anm->alpha_time(20,0,0);
    else if (anm->frame == 140) anm->destroy();
}
void effectSpellcardAttackP4(AnimScript* anm)
{
    if (anm->frame == 0)
    {
        anm->set_sprite(spr6);
        anm->set_layer(GL_ L5);
        anm->set_blendmode(1);
        anm->set_pos(128,-384,9);
        anm->set_rot(8,PI2,0);
        anm->rot_vel(0,0,-0.02617994f);
        anm->set_scale(16,160);
        anm->set_alpha(0);
        anm->alpha_time(20,0,128);
        anm->special_draw(1);
    }
    else if (anm->frame == 120) anm->alpha_time(20,0,0);
    else if (anm->frame == 140) anm->destroy();
}
void effectSpellcardAttackP5(AnimScript* anm)
{
    if (anm->frame == 0)
    {
        anm->set_sprite(spr6);
        anm->set_layer(GL_ L5);
        anm->set_blendmode(1);
        anm->set_pos(128,-384,9);
        anm->set_rot(8,PI2,0);
        anm->rot_vel(0,0,-0.02617994f);
        anm->set_scale(16,192);
        anm->set_alpha(0);
        anm->alpha_time(20,0,128);
        anm->special_draw(1);
    }
    else if (anm->frame == 120) anm->alpha_time(20,0,0);
    else if (anm->frame == 140) anm->destroy();
}
void effectSpellcardAttackP6(AnimScript* anm)
{
    if (anm->frame == 0)
    {
        anm->set_sprite(spr6);
        anm->set_layer(GL_ L5);
        anm->set_blendmode(1);
        anm->set_pos(-128,-64,9);
        anm->set_rot(8,PI2,0);
        anm->rot_vel(0,0,-0.02617994f);
        anm->set_scale(16,96);
        anm->set_alpha(0);
        anm->alpha_time(20,0,128);
        anm->special_draw(1);
    }
    else if (anm->frame == 120) anm->alpha_time(20,0,0);
    else if (anm->frame == 140) anm->destroy();
}
void effectSpellcardAttack(AnimScript* anm)
{
    if (anm->frame == 0)
    {
        anm->set_alpha(0);
        anm->create_child(effectSpellcardAttackP3);
        anm->create_child(effectSpellcardAttackP4);
        anm->create_child(effectSpellcardAttackP5);
        anm->create_child(effectSpellcardAttackP6);
        float F0 = -48.f;
        for (int i = 5; i > 0; i--)
        {
            int a = anm->create_child(effectSpellcardAttackP1);
            AnmManager::anim(a)->set_pos(0,F0,0);
            F0 -= 32;
            a = anm->create_child(effectSpellcardAttackP2);
            AnmManager::anim(a)->set_pos(0,F0,0);
            F0 -= 32;
        }
    }
    else if (anm->frame == 140) anm->destroy();
}
void effectBase1(AnimScript* anm)
{
    if (anm->frame == 0 || anm->frame == 16)
    {
        if (anm->frame == 0)
        {
            anm->set_sprite(spr7);
            anm->set_layer(GL_ L18);
            anm->set_blendmode(1);
            anm->set_alpha(244);
            anm->alpha_time(40,0,130);
            anm->set_color(255,255,255);
            int I0 = rand()%80+20;
            anm->color_time(80,0,rand()%128+128,I0,I0);
        } anm->frame = 0;
        anm->scale_time(4,1,0.75f,0.75f);
    }
    else if (anm->frame == 4) anm->scale_time(4,4,0.5f,0.5f);
    else if (anm->frame == 8) anm->scale_time(4,1,0.75f,0.75f);
    else if (anm->frame == 12) anm->scale_time(4,4,1,1);
    else if (anm->frame == 24) anm->destroy();
}
void effectBase2(AnimScript* anm)
{
    if (anm->frame == 0)
    {
        anm->set_sprite(spr7);
        anm->set_layer(GL_ L18);
        anm->set_blendmode(1);
        anm->set_alpha(244);
        anm->set_color(64,64,255);
        anm->set_scale(.5f,.5f);
        anm->scale_time(110,0,.1f,.1f);
        float f2 = Random::Angle();
        float f0 = sin(f2);
        float f1 = cos(f2);
        f2 = Random::Float01()*64.f+64.f;
        f0 *= f2; f1*= f2;
        anm->pos_time(70,4,f0,f1,0);
    }
    else if (anm->frame == 110) anm->destroy();
}
void effectBase3(AnimScript* anm)
{
    if (anm->frame == 0)
    {
        anm->set_sprite(spr7);
        anm->set_layer(GL_ L20);
        anm->set_blendmode(1);
        anm->set_alpha(128);
        anm->set_color(255,0,0);
        int I0 = rand()%15+20;
        float f0 = Random::Float01()+0.4f;
        anm->set_scale(f0,f0);
        f0 = Random::Angle();
        float f1 = cos(f0);
        float f2 = sin(f0);
        f0 = Random::Float01()*128.f;
        f1*=f0;f2*=f0;
        anm->set_pos(f1,f2,0);
        anm->pos_time(I0,4,0,0,0);
        anm->scale_time(I0,4,0,0);
    }
    else if (anm->frame == 15) anm->destroy();
}
void effectBase4(AnimScript* anm)
{
    if (anm->frame == 0)
    {
        anm->set_sprite(spr7);
        anm->set_layer(GL_ L18);
        anm->set_blendmode(1);
        anm->set_alpha(128);
        anm->set_color(255,192,128);
        anm->set_scale(.7,.7);
        anm->scale_time(12,1,0,0);
        float f0 = Random::Float01()*16+48;
        float f1 = Random::Angle();
        anm->pos_time(12,4,f0*cos(f1),f0*sin(f1),0);
    }
    else if (anm->frame == 12) anm->destroy();
}

void effectExplodeLarge(AnimScript* anm)
{
    if (anm->frame == 0)
    {
        anm->set_sprite(spr25);
        anm->set_layer(GL_ L20);
        anm->set_scale(.5,.5);
        anm->scale_time(30,4,5.5,5.5);
        anm->alpha_time(30,4,0);
        AnmManager::UpdateChild(AnmManager::newAnim(effectExplodeNeg2),anm->x_(true),anm->y_(true),0,0,0,0,1,1,1);
    }
    if (anm->frame < 16)
    {
        AnmManager::UpdateChild(AnmManager::newAnim(effectExplodeP1),anm->x_(true),anm->y_(true),0,0,0,0,anm->xs_(),anm->ys_(),1);
        AnmManager::UpdateChild(AnmManager::newAnim(effectExplodeP1),anm->x_(true),anm->y_(true),0,0,0,0,anm->xs_(),anm->ys_(),1);
        AnmManager::UpdateChild(AnmManager::newAnim(effectExplodeP1),anm->x_(true),anm->y_(true),0,0,0,0,anm->xs_(),anm->ys_(),1);
    }
    if (anm->frame == 81) anm->destroy();
}
void effectExplode(AnimScript* anm)
{
    if (anm->frame == 0)
    {
        anm->visible(false);
    }
    if (anm->frame < 8)
    {
        anm->create_child(effectExplodeP1);
        anm->create_child(effectExplodeP1);
        anm->create_child(effectExplodeP2);
    }
    if (anm->frame == 31) anm->destroy();
}
void effectExplodeP1(AnimScript* anm)
{
    if (anm->frame == 0)
    {
        anm->set_sprite(spr7);
        anm->set_layer(GL_ L20);
        anm->set_blendmode(1);
        anm->set_alpha(255);
        float F0 = Random::Float01()*3+1;
        anm->set_scale(F0,F0);
        anm->set_color(255,128,255);
        int t = rand()%15+20;
        anm->color_time(t,0,255,0,0);
        F0 = Random::Angle(); float F1 = Random::Float01()*256;
        anm->pos_time(t,4,F1*cos(F0),F1*sin(F0),0);
        anm->scale_time(t,4,0,0);
    }
    else if (anm->frame == 36) anm->destroy();
}
void effectExplodeP2(AnimScript* anm)
{
    if (anm->frame == 0)
    {
        anm->set_sprite(spr7);
        anm->set_layer(GL_ L20);
        anm->set_blendmode(2);
        anm->set_alpha(255);
        float F0 = Random::Float01()*3+1;
        anm->set_scale(F0,F0);
        anm->set_color(128,255,128);
        int t = rand()%15+20;
        anm->color_time(t,0,0,0,255);
        F0 = Random::Angle(); float F1 = Random::Float01()*256;
        anm->pos_time(t,4,F1*cos(F0),F1*sin(F0),0);
        anm->scale_time(t,4,0,0);
    }
    else if (anm->frame == 36) anm->destroy();
}
void effectExplodeNeg1(AnimScript* anm)
{
    if (anm->frame == 0)
    {
        anm->visible(false);
        anm->create_child(effectExplodeNegP);
    }
    else if (anm->frame == 5)
    {
        int a = anm->create_child(effectExplodeNegP);
        AnmManager::anim(a)->set_pos(0,32,0);
        AnmManager::anim(a)->pos_time(20,2,0,0,0);
        a = anm->create_child(effectExplodeNegP);
        AnmManager::anim(a)->set_pos(0,-32,0);
        AnmManager::anim(a)->pos_time(20,2,0,0,0);
        a = anm->create_child(effectExplodeNegP);
        AnmManager::anim(a)->set_pos(32,0,0);
        AnmManager::anim(a)->pos_time(20,2,0,0,0);
        a = anm->create_child(effectExplodeNegP);
        AnmManager::anim(a)->set_pos(-32,0,0);
        AnmManager::anim(a)->pos_time(20,2,0,0,0);
    }
    else if (anm->frame == 25) anm->create_child(effectExplodeNegP);
    else if (anm->frame == 75) anm->destroy();
}
void effectExplodeNeg2(AnimScript* anm)
{
    if (anm->frame == 0)
    {
        anm->visible(false);
        anm->create_child(effectExplodeNegP);
    }
    else if (anm->frame == 5)
    {
        int a = anm->create_child(effectExplodeNegP);
        AnmManager::anim(a)->set_pos(0,32,0);
        a = anm->create_child(effectExplodeNegP);
        AnmManager::anim(a)->set_pos(0,-32,0);
        a = anm->create_child(effectExplodeNegP);
        AnmManager::anim(a)->set_pos(32,0,0);
        a = anm->create_child(effectExplodeNegP);
        AnmManager::anim(a)->set_pos(-32,0,0);
    }
    else if (anm->frame == 25) anm->create_child(effectExplodeNegP);
    else if (anm->frame == 75) anm->destroy();
}
void effectExplodeNegP(AnimScript* anm)
{
    if (anm->frame == 0)
    {
        anm->set_layer(GL_ L21); //6 ?
        anm->set_blendmode(4);
        anm->special_draw(4);
        anm->set_alpha(1);
        anm->scroll_x(255);
        anm->set_scale(1,50);
        anm->scale_time(50,2,600,50);
        anm->set_color(255,255,255);
        anm->rot_vel(255,255,255);
    }
    else if (anm->frame == 1) anm->frame = 0;
}

void createeffexplode(float x, float y, float a, int t)
{
    int r,g,b;
    switch (t){
        case 0:case 4:r=255;g=0;b=0;break;
        case 2:case 6:r=64;g=64;b=255;break;
        case 3:case 7:r=0;g=255;b=0;break;
        case 1:case 5:r=160;g=160;b=0;break;
    }
    effectBreakWave(a,x,y,1,r,g,b);
    switch (t){
        case 0:case 4:r=192;g=0;b=0;break;
        case 2:case 6:r=96;g=96;b=255;break;
        case 3:case 7:r=0;g=192;b=0;break;
        case 1:case 5:r=160;g=160;b=48;break;
    }
    int anm;
    if (t<4) 
    {
        anm = AnmManager::newAnim(effectExplodeEnemyP1,-1,1);
        AnmManager::UpdateChild(anm,x,y,0,0,0,a,1,1,1);
        AnmManager::anim(anm)->offset_sprite(t);
    }
    for (int i = 0; i < 11*(t<4?1:.5); i++)
    {
        anm = AnmManager::newAnim(effectExplodeEnemyP3);
        AnmManager::UpdateChild(anm,x,y,0,0,0,a,1,1,1);
        AnmManager::anim(anm)->set_color(r,g,b);
    }
    for (int i = 0; i < 4*(t<4?1:.5); i++)
    {
        anm = AnmManager::newAnim(effectExplodeEnemyP2);
        AnmManager::UpdateChild(anm,x,y,0,0,0,a,1,1,1);
        AnmManager::anim(anm)->set_color(r,g,b);
        AnmManager::anim(anm)->set_color2(r,g,b);
    }
}
void effectExplodeEnemy(float x, float y, float a, char colors)
{
    NSEngine::AudioEngine::PlaySound(gameassets::se_enep00);
    if (colors&0b00000001) createeffexplode(x,y,a,0);
    if (colors&0b00000010) createeffexplode(x,y,a,2);
    if (colors&0b00000100) createeffexplode(x,y,a,3);
    if (colors&0b00001000) createeffexplode(x,y,a,1);
    if (colors&0b00010000) createeffexplode(x,y,a,4);
    if (colors&0b00100000) createeffexplode(x,y,a,6);
    if (colors&0b01000000) createeffexplode(x,y,a,7);
    if (colors&0b10000000) createeffexplode(x,y,a,5);
}
void effectExplodeEnemyP1(AnimScript* anm)
{
    if (anm->frame == 0)
    {
        anm->set_layer(GL_ L20);
        anm->set_sprite(spr25);
        anm->set_blendmode(1);
        anm->set_rot(0,0,Random::Angle()/10);
        anm->set_scale(.5,.5);
        anm->scale_time(30,6,.1,4.5);
        anm->alpha_time(30,4,0);
    }
    else if (anm->frame == 30) anm->destroy();
}
void effectExplodeEnemyP2(AnimScript* anm)
{
    if (anm->frame == 0)
    {
        anm->set_layer(GL_ L20);
        anm->set_scale(1,36);
        anm->set_blendmode(1);
        anm->special_draw(5);
        anm->scale_time(30,4,Random::Float01()*48+48,36);
        float aa = Random::Angle()*0.3;
        anm->pos_time(30,5,32*cos(aa),32*sin(aa),0);
        anm->alpha2_time(30,1,0);
    }
    else if (anm->frame == 30) anm->destroy();
}
void effectExplodeEnemyP3(AnimScript* anm)
{
    if (anm->frame == 0)
    {
        anm->set_layer(GL_ L20);
        anm->set_blendmode(1);
        anm->set_sprite(spr30);
        anm->set_alpha(128);
        anm->set_rot(Random::Angle(),Random::Angle(),Random::Angle());
        anm->rot_vel(Random::Angle()/60.f,Random::Angle()/60.f,Random::Angle()/60.f);
        float F0 = Random::Angle()/4;//+%REG[10026]
        float F1 = Random::Float01()*256-32;
        int I0 = rand()%60+30;
        anm->pos_time(I0,4,F1*cos(F0),F1*sin(F0),F1);
        anm->scale_time(I0,1,0,0);
    }
    else if (anm->frame == 91) anm->destroy();
}

void effectExplodeMapleBig(float x, float y, float s, int n, int n2, int t)
{
    for (int i = 0; i < n2; i++)
        for (int j = 0; j < n; j++)
        {
            NSEngine::ScheduleTask(i*t,[x,y,s](){
                int a = AnmManager::newAnim(effectExplodeMapleBigP);
                AnmManager::UpdateChild(a,x,y,0,0,0,0,s,s,1);
            });
        }
}

void effectExplodeMapleBigP(AnimScript* anm)
{
    if (anm->frame == 0)
    {
        anm->set_sprite(spr30);
        anm->set_layer(GL_ L20);
        anm->set_blendmode(1);
        anm->set_rot(Random::Angle(),Random::Angle(),Random::Angle());
        anm->rot_vel(Random::Angle()/32.f,Random::Angle()/32.f,Random::Angle()/32.f);
        anm->color_time(90,0,255,32,32);
        float F0 = Random::Float01()*3+1;
        anm->set_scale(F0,F0);
        F0 = Random::Angle(); float F1 = Random::Floatm11()*128+192;
        anm->pos_time(90,4,F1*cos(F0),F1*sin(F0),Random::Floatm11()*512);
        anm->set_alpha(0);
        anm->alpha_time(30,4,128);
    }
    else if (anm->frame == 60)
    {
        anm->alpha_time(30,1,0);
        anm->scale_time(30,1,0,0);
    }
    else if (anm->frame == 90) anm->destroy();
}

void effectSlow1(AnimScript* anm)
{
    if (anm->frame == 0)
    {
        anm->set_layer(GL_ L18);
        anm->set_sprite(spr23);
        anm->set_alpha(0);
        anm->alpha_time(6,0,255);
        anm->set_scale(2.3f,2.3f);
        anm->scale_time(18,4,1.0f,1.0f);
        anm->set_rot(0.f,0.f,-PI);
        anm->rot_time(18,4,0.0f,0.0f,PI);
    }
    else if (anm->frame == 18) anm->rot_vel(0.0f,0.0f,0.10471976f);
    else if (anm->frame == 19) anm->frame = 18;
    else if (anm->frame == 28) anm->destroy();
    if (anm->interrupt == 1)
    {
        anm->scale_time(8,4,0.0f,0.0f);
        anm->frame = 20;
    }
}

void effectSlow2(AnimScript* anm)
{
    if (anm->frame == 0)
    {
        anm->set_layer(GL_ L18);
        anm->set_sprite(spr23);
        anm->set_scale(0.3f,0.3f);
        anm->scale_time(12,4,1.0f,1.0f);
        anm->set_rot(0.0f,0.0f,PI);
        anm->rot_time(18,4,0.0f,0.0f,-PI);
        anm->create_child(effectSlow1);
    }
    else if (anm->frame == 18) anm->rot_vel(0.0f,0.0f,-0.05235988f);
    else if (anm->frame == 19) anm->frame = 18;
    else if (anm->frame == 28) anm->destroy();
    if (anm->interrupt == 1)
    {
        anm->scale_time(8,4,0.0f,0.0f);
        anm->frame = 20;
    }
}

void effectSlow3(AnimScript* anm)
{
    if (anm->frame == 0)
    {
        anm->set_layer(GL_ L6);
        anm->set_blendmode(2);
        anm->set_sprite(spr24);
        anm->set_alpha(0);
        anm->alpha_time(30,0,96);
        anm->set_scale(4.3f,4.3f);
        anm->scale_time(12,4,2.0f,2.0f);
        anm->rot_vel(0.0f,0.0f,0.017453292f);
    }
    else if (anm->frame == 2) anm->frame = 1;
    else if (anm->frame == 15) anm->destroy();
    if (anm->interrupt == 1)
    {
        anm->alpha_time(12,0,0);
        anm->frame = 3;
    }
}

void effectMaple(float x, float y, float s, char type,int r1, int g1, int b1, int r2, int b2, int g2)
{
    //0 0 t2 t1 t4 t3 t2 t1
    if (type&0b00110000)
    {
        int a = AnmManager::newAnim(type&0b00100000?effectMapleP6:effectMapleP5,-1,1);
        AnmManager::anim(a)->set_color(r1,g1,b1);
        AnmManager::anim(a)->set_color2(r2,g2,b2);
        AnmManager::UpdateChild(a,x,y,0,0,0,0,s,s,1);
    }
    //if (!(type&0b00001111)) return;
    if (type&0b00000001)
    {
        for (int i = 0; i < 60; i+=2)
        {
            NSEngine::ScheduleTask(i,[x,y,s](){
                AnmManager::UpdateChild(AnmManager::newAnim(effectMapleP1),x,y,0,0,0,0,s,s,1);
            });
        }
        return;
    }
    for (int i = 0; i < 30; i++)
    {
        NSEngine::ScheduleTask(i,[x,y,s,type](){
            int a = AnmManager::newAnim(type&0b00000011?(type&0b00000001?effectMapleP1:effectMapleP2):(type&0b00000100?effectMapleP3:effectMapleP4),-1,1);
            AnmManager::UpdateChild(a,x,y,0,0,0,0,s,s,1);
        });
    }
}
void effectMapleP1(AnimScript* anm)
{
    if (anm->frame == 0)
    {
        anm->set_sprite(spr30);
        anm->set_layer(GL_ L6);
        anm->set_blendmode(1);
        anm->set_alpha(0);
        anm->alpha_time(30,4,128);
        anm->set_rot(Random::Angle(), Random::Angle(), Random::Angle());
        anm->rot_vel(Random::Angle()/32.f,Random::Angle()/32.f,Random::Angle()/32.f);
        float F0 = Random::Float01()*3+1;
        anm->set_scale(F0,F0); F0 = Random::Angle();
        anm->set_pos(cos(F0)*256,sin(F0)*256,Random::Floatm11()*256);
        anm->pos_time(60,4,0,0,0);
    }
    else if (anm->frame == 30)
    {
        anm->alpha_time(30,3,0);
        anm->scale_time(30,3,0,0);
    }
    else if (anm->frame == 60) anm->destroy();
}
void effectMapleP2(AnimScript* anm)
{
    if (anm->frame == 0)
    {
        anm->set_sprite(spr30);
        anm->set_layer(GL_ L20);
        anm->set_blendmode(1);
        anm->set_alpha(0);
        anm->alpha_time(20,4,128);
        anm->set_rot(Random::Angle(), Random::Angle(), Random::Angle());
        anm->rot_vel(Random::Angle()/32.f,Random::Angle()/32.f,Random::Angle()/32.f);
        float F0 = Random::Float01()*3+2;
        anm->set_scale(F0,F0); F0 = Random::Angle();
        anm->set_pos(cos(F0)*256,sin(F0)*256,Random::Floatm11()*256);
        anm->pos_time(40,4,0,0,0);
    }
    else if (anm->frame == 20)
    {
        anm->alpha_time(20,1,0);
        anm->scale_time(20,1,0,0);
    }
    else if (anm->frame == 40) anm->destroy();
}
void effectMapleP3(AnimScript* anm)
{
    if (anm->frame == 0)
    {
        anm->set_sprite(spr30);
        anm->set_layer(GL_ L20);
        anm->set_blendmode(1);
        anm->set_alpha(0);
        anm->alpha_time(20,4,128);
        anm->set_rot(Random::Angle(), Random::Angle(), Random::Angle());
        anm->rot_vel(Random::Angle()/32.f,Random::Angle()/32.f,Random::Angle()/32.f);
        float F0 = Random::Float01()*3+2;
        anm->set_scale(F0,F0); F0 = Random::Angle();
        anm->set_pos(0,0,0);
        anm->pos_time(40,4,cos(F0)*256,sin(F0)*256,Random::Floatm11()*256);
    }
    else if (anm->frame == 20)
    {
        anm->alpha_time(20,3,0);
        anm->scale_time(20,3,0,0);
    }
    else if (anm->frame == 40) anm->destroy();
}
void effectMapleP4(AnimScript* anm)
{
    if (anm->frame == 0)
    {
        anm->visible(false);
        anm->set_sprite(spr30);
        anm->set_layer(GL_ L30);
        anm->set_blendmode(1);
        anm->set_alpha(0);
        anm->alpha_time(20,4,128);
        anm->set_rot(Random::Angle(), Random::Angle(), Random::Angle());
        anm->rot_vel(Random::Angle()/32.f,Random::Angle()/32.f,Random::Angle()/32.f);
        float F0 = Random::Float01()*3+2;
        anm->set_scale(F0,F0); F0 = Random::Angle();
        anm->set_pos(0,0,0);
        anm->pos_time(40,4,cos(F0)*256,sin(F0)*256,Random::Floatm11()*256);
    }
    else if (anm->frame == 20)
    {
        anm->alpha_time(20,3,0);
        anm->scale_time(20,3,0,0);
    }
    else if (anm->frame == 40) anm->destroy();
}
void effectMapleP5(AnimScript* anm)
{
    if (anm->frame == 0)
    {
        anm->set_layer(GL_ L20);
        anm->special_draw(4);
        anm->set_blendmode(1);
        anm->set_scale(256,36);
        anm->set_alpha2(1);
        anm->set_alpha(0);
        anm->alpha2_time(40,0,255);
        anm->scale_time(40,0,0,36);
    }
    else if (anm->frame == 40) anm->destroy();
}
void effectMapleP6(AnimScript* anm)
{
    if (anm->frame == 0)
    {
        anm->set_layer(GL_ L20);
        anm->special_draw(4);
        anm->set_blendmode(1);
        anm->set_scale(0,36);
        anm->set_alpha2(255);
        anm->set_alpha(0);
        anm->alpha2_time(40,0,1);
        anm->scale_time(40,0,384,36);
    }
    else if (anm->frame == 40) anm->destroy();
}

void effectMaple3D1(AnimScript* anm)
{
    if (anm->frame == 0)
    {
        anm->set_sprite(spr29);
        anm->set_layer(GL_ L2);
        anm->set_alpha(0);
        anm->alpha_time(30,0,64);
        anm->rot_vel(Random::Floatm11()*PI/64.f,Random::Floatm11()*PI/64.f,Random::Floatm11()*PI/64.f);
        float F0 = Random::Float01()+.1;
        anm->set_scale(F0,F0);
        anm->set_color(255,128+rand()%128,255);
        glm::vec3 p = NSEngine::engineData::cam3d->getLook() * 400.f + NSEngine::engineData::cam3d->getPosition();
        p.x += Random::Floatm11() * 100;
        p.y += Random::Float01()*400+130;
        anm->set_pos(p.x,p.y,p.z);
        p.x-=Random::Floatm11()*50;
        p.y-=Random::Float01()*50+50;
        F0 = p.z-Random::Float01()*40-30;
        anm->pos_time(300,9,p.x,p.y,F0);
    }
    else if (anm->frame == 200) anm->alpha_time(100,0,0);
    else if (anm->frame == 300) anm->destroy();
}
void effectMaple3D2(AnimScript* anm)
{
    if (anm->frame == 0)
    {
        anm->set_sprite(spr31);
        anm->set_blendmode(1);
        anm->set_layer(GL_ L2);
        anm->set_alpha(0);
        anm->alpha_time(30,0,64);
        anm->rot_vel(Random::Floatm11()*PI/64.f,Random::Floatm11()*PI/64.f,Random::Floatm11()*PI/64.f);
        float F0 = Random::Float01()*0.45+.1;
        anm->set_scale(F0,F0);
        anm->set_color(255,128+rand()%128,8);
        glm::vec3 p = NSEngine::engineData::cam3d->getLook() * 600.f + NSEngine::engineData::cam3d->getPosition();
        p.x += Random::Floatm11() * 200 + 100;
        p.y += Random::Floatm11() * 200 + 50;
        p.z -= 180;
        anm->set_pos(p.x,p.y,p.z);
        p.x-=Random::Floatm11()*10;
        p.y-=Random::Float01()*10;
        F0 = p.z-Random::Float01()*40-100;
        anm->pos_time(500,9,p.x,p.y,F0);
    }
    else if (anm->frame == 400) anm->alpha_time(100,0,0);
    else if (anm->frame == 500) anm->destroy();
}
void effectMaple3D3(AnimScript* anm)
{
    if (anm->frame == 0)
    {
        anm->set_sprite(spr29);
        anm->set_layer(GL_ L2);
        anm->set_alpha(0);
        anm->alpha_time(30,0,64);
        anm->set_rot(Random::Angle(),Random::Angle(),Random::Angle());
        anm->rot_vel(Random::Floatm11()*PI/256.f,Random::Floatm11()*PI/256.f,Random::Floatm11()*PI/256.f);
        float F0 = Random::Float01()*.1+0.5;
        anm->set_scale(F0,F0);
        glm::vec3 p = NSEngine::engineData::cam3d->getLook() * 600.f + NSEngine::engineData::cam3d->getPosition();
        p.x += Random::Floatm11() * 150;
        p.y += Random::Floatm11() * 250+10;
        p.z -= 180.f;
        anm->set_pos(p.x,p.y,p.z);
        F0 = Random::Floatm11()*10;
        p.x+=F0;
        F0+=p.z;
        anm->pos_time(300,9,p.x,p.y,F0);
    }
    else if (anm->frame == 200) anm->alpha_time(100,0,0);
    else if (anm->frame == 300) anm->destroy();
}
void effectMaple3D4(AnimScript* anm)
{
    if (anm->frame == 0)
    {
        anm->set_sprite(spr32);
        anm->set_blendmode(1);
        anm->set_layer(GL_ L2);
        anm->set_alpha(0);
        anm->alpha_time(30,0,64);
        anm->rot_vel(Random::Floatm11()*PI/64.f,Random::Floatm11()*PI/64.f,Random::Floatm11()*PI/64.f);
        float F0 = Random::Float01()*.45+.3;
        anm->set_scale(F0,F0);
        F0 = 128+rand()%128;
        anm->set_color(F0,F0,255);
        F0 = Random::Float01()*200+200;
        glm::vec3 p = NSEngine::engineData::cam3d->getLook() * F0 + NSEngine::engineData::cam3d->getPosition();
        p.x += Random::Floatm11() * 150;
        p.y += Random::Floatm11() * 150;
        p.z += F0 = Random::Floatm11() * 100;
        anm->set_pos(p.x,p.y,p.z);
        p.x*=1.5;
        p.y*=1.5;
        F0 += p.z;
        anm->pos_time(300,21,p.x,p.y,F0);
    }
    else if (anm->frame == 40) anm->alpha_time(60,0,0);
    else if (anm->frame == 100) anm->destroy();
}
void effectMaple3D5(AnimScript* anm)
{
    if (anm->frame == 0)
    {
        anm->set_sprite(spr7);
        anm->set_layer(GL_ L2);
        anm->set_alpha(0);
        anm->alpha_time(30,0,64);
        anm->set_blendmode(1);
        anm->set_color(128,128,255);
        anm->color_time(120,0,255,128,128);
        anm->scale_time(240,1,0,0);
        anm->rot_vel(Random::Floatm11()*PI/64.f,Random::Floatm11()*PI/64.f,Random::Floatm11()*PI/64.f);
        float F0 = Random::Float01()*200+800;
        glm::vec3 p = NSEngine::engineData::cam3d->getLook() * F0 + NSEngine::engineData::cam3d->getPosition();
        p.x += Random::Floatm11() * 500;
        p.y += Random::Floatm11() * 500 + 100;
        p.z += Random::Floatm11()*10+300;
        anm->set_pos(p.x,p.y,p.z);
        p.x+=Random::Floatm11()*150;
        F0 = p.z-600;
        anm->pos_time(240,9,p.x,p.y,F0);
    }
    else if (anm->frame == 180) anm->alpha_time(60,0,0);
    else if (anm->frame == 240) anm->destroy();
}
void effectMaple3D6(AnimScript* anm)
{
    if (anm->frame == 0)
    {
        anm->set_sprite(spr7);
        anm->set_blendmode(1);
        anm->set_layer(GL_ L2);
        anm->set_alpha(0);
        anm->set_color(128,128,128);
        anm->color_time(120,0,128,128,128);
        anm->scale_time(240,1,0,0);
        anm->alpha_time(30,0,64);
        anm->rot_vel(Random::Floatm11()*PI/64.f,Random::Floatm11()*PI/64.f,Random::Floatm11()*PI/64.f);
        glm::vec3 p = NSEngine::engineData::cam3d->getLook() * 800.f + NSEngine::engineData::cam3d->getPosition();
        p.x += Random::Floatm11() * 64;
        p.z += Random::Floatm11() * 64;
        anm->set_pos(p.x,p.y,p.z);
        p.y-=600;
        anm->pos_time(300,9,p.x,p.y,p.z);
    }
    else if (anm->frame == 180) anm->alpha_time(60,0,0);
    else if (anm->frame == 240) anm->destroy();
}

void effectMagicSquare1(AnimScript* anm)
{
    if (anm->frame == 0)
    {
        anm->set_sprite(spr33);
        anm->set_layer(GL_ L6);
        anm->set_blendmode(1);
        anm->set_rot(0.7853982f,0.7853982f,-PI);
        anm->rot_time(60,4,-0.34906584f,0.5235988f,PI);
        anm->set_alpha(128);
        anm->set_scale(0,0);
        anm->scale_time(60,4,1,1);
    }
    if (anm->frame == 60) anm->rot_vel(0,0,-0.01308997f);
    if (anm->frame == 61) anm->frame = 60;
}

void effectMagicSquare2(AnimScript* anm)
{
    if (anm->frame == 0)
    {
        anm->set_sprite(spr33);
        anm->set_layer(GL_ L18);
        anm->set_blendmode(1);
        anm->set_scale(2,2);
        anm->scale_time(20,4,0,0);
    }
    if (anm->frame == 20) anm->destroy();
}


std::vector<NSEngine::Color> auracolors = {
    {128, 32,128,255}, {128,  0,128,0},
    {128, 32, 32,255}, {128,  0,  0,0},
    { 32, 32,160,255}, {  0,  0,160,0},
    { 32,128,128,255}, {  0,128,128,0},
    { 32,128, 32,255}, {  0,128,  0,0},
    {128,128, 32,255}, {128,128,  0,0},
    {160,128, 32,255}, {160,128,  0,0},
    {128,128,144,255}, {128,128,160,0}
};
NSEngine::Color caura1 = auracolors[0], caura2 = auracolors[1];
void setAuraColor(int i) { caura1 = auracolors[(2*i)%16]; caura2 = auracolors[(2*i+1)%16]; }
void effectAuraP1(AnimScript* anm)
{
    if (anm->frame == 0)
    {
        anm->set_sprite(spr34);
        anm->set_layer(GL_ L6);
        anm->set_blendmode(1);
        anm->set_pos(Random::Floatm11()*4,24,0);
        float f0 = Random::Float01()*0.7+1;
        anm->set_scale(f0,0);
        anm->set_color(caura1.r,caura1.g,caura1.b);
        anm->scale_time(30,4,f0,Random::Float01()*0.5+1.9f);
        anm->alpha_time(30,1,0);
    }
    else if (anm->frame == 30) anm->destroy();
}
void effectAuraP2(AnimScript* anm)
{
    if (anm->frame == 0)
    {
        anm->set_sprite(spr35);
        anm->set_layer(GL_ L3);
        anm->set_blendmode(1);
        anm->set_rot(0,0,Random::Angle());
        float f0 = Random::Float01()*0.7+1.6;
        anm->set_scale(f0,f0);
        anm->set_color(caura2.r,caura2.g,caura2.b);
        anm->scale_time(30,4,0.7f,0.7f);
        anm->set_alpha(0);
        anm->alpha_time(30,4,255);
    }
    else if (anm->frame == 30) anm->destroy();
}
void effectAuraP3(AnimScript* anm)
{
    if (anm->frame == 0)
    {
        anm->set_sprite(spr35);
        anm->set_layer(GL_ L6);
        anm->set_blendmode(1);
        anm->set_rot(0,0,Random::Angle());
        anm->set_color(255,255,255);
        float f0 = Random::Float01()*0.7f+2.0f;
        anm->set_scale(f0,f0);
        anm->scale_time(30,4,1.2,1.2);
        anm->set_alpha(0);
        anm->alpha_time(30,4,64);
    }
    else if (anm->frame == 30) anm->destroy();
}
void effectAura(AnimScript* anm)
{
    if (anm->frame == 0 || anm->frame == 6)
    {
        if (anm->frame == 0)
        {
            anm->set_alpha(0);
            anm->set_sprite(spr35); anm->set_layer(0);
        }
        anm->frame = 0;
        anm->create_child(effectAuraP1);
    }
    else if (anm->frame == 3) anm->create_child(effectAuraP2);
    else if (anm->frame == 4) anm->create_child(effectAuraP3);
    else if (anm->frame == 37) anm->destroy();
    if (anm->interrupt == 1) anm->frame = 7;
}

void effectAura3Dleaf1(AnimScript* anm)
{
    if (anm->frame == 0)
    {
        int I0 = rand() % 4;
        anm->set_sprite(I0+spr36);
        anm->set_layer(GL_ L2); //layer 2
        anm->set_blendmode(1);
        anm->rot_vel(0,0,Random::Angle()/32.f);
        anm->set_scale(1.5f,1.5f);
        I0 = Random::Float01() * 255;
        anm->set_color(255,I0,0);
        glm::vec3 p = NSEngine::engineData::cam3d->getLook() * 400.f + NSEngine::engineData::cam3d->getPosition();
        float F3 = Random::Floatm11() * 200.0f;
        p.x += F3; F3 = Random::Floatm11() * 200.0f;
        p.y += F3-200.f;
        anm->set_alpha(0);
        anm->alpha_time(30,0,64);
        anm->set_pos(p.x,p.y,p.z);
        F3 = Random::Floatm11() * 50.0f; p.x += F3;
        F3 = Random::Floatm11() * 60.0f; p.y += F3 + 160.f;
        anm->pos_time(200,0,p.x,p.y,p.z);
    }
    else if (anm->frame == 100) anm->alpha_time(100,0,0);
    else if (anm->frame == 200) anm->destroy();
        
}

void effectAura3Dleaf2(AnimScript* anm)
{
    if (anm->frame == 0)
    {
        int I0 = rand() % 4;
        anm->set_sprite(I0+spr36);
        anm->set_layer(GL_ L30); //layer 2
        anm->set_blendmode(1);
        anm->rot_vel(0,0,Random::Angle()/32.f);
        anm->set_scale(1.5f,1.5f);
        I0 = Random::Float01() * 255;
        anm->set_color(255,I0,0);
        float F1 = NSEngine::engineData::cam3d->getLook().y * 400.f + NSEngine::engineData::cam3d->getPosition().y + 1100.f;
        F1 = (int)F1 - (int)F1%768;
        I0 = rand()%2;
        float F0 = Random::Floatm11() * 64.f + I0?-176.f:176.f;
        anm->set_alpha(0);
        anm->alpha_time(30,0,255);
        anm->set_pos(F0,F1,100.f);
        F0 += Random::Float01() * I0?64.f:-64.f;
        F1 += Random::Floatm11()*120.f;
        float F2 = 100.f * Random::Float01();
        anm->pos_time(200,0,F0,F1,F2);
    }
    else if (anm->frame == 100) anm->alpha_time(100,0,0);
    else if (anm->frame == 200) anm->destroy();
        
}

void effectBreakWave(float a, float x, float y, float s, int r, int g, int b, int n)
{
    float xx = math::lengthdir_x(32,a);
    float yy = math::lengthdir_y(32,a);
    float f0 = 0;
    float f1 = 0;
    float al = PI/10;
    for (int i = 0; i < n; i++)
    {

        NSEngine::ScheduleTask(i*7,[a,x,y,s,r,g,b,f0,f1,al](){
            
                int anm = AnmManager::newAnim(effectBreakWaveP,-1,1);
                AnimScript* as = AnmManager::anim(anm);
                float rr = Random::Float01()*16; float aa = Random::Angle();
                float xx = math::lengthdir_y(rr,aa); float yy = math::lengthdir_y(rr,aa);
                as->set_pos(24+f0+xx,f1+yy,0);
                as->set_color(r,g,b);
                as->set_rot(Random::Floatm11()*al,0,Random::Floatm11()*al);
                AnmManager::UpdateChild(anm,x,y,0,0,0,a,s,s,1);
        });
        f0 += xx;
        f1 += yy;
        al*=1.3;
    }
}

void effectBreakWaveP(AnimScript* anm)
{
    if (anm->frame == 0)
    {
        anm->set_layer(GL_ L21);
        anm->set_sprite(spr41);
        anm->set_pos(48,0,0);
        anm->set_scale(.75,rand()%2==0?.75:-.75);
    }
    else if (anm->frame == 24) anm->destroy();
    if (anm->frame > 0 && anm->frame%2 == 0) anm->offset_sprite(1);
}

void effectSplash(AnimScript* anm)
{
    if (anm->frame == 0)
    {
        anm->set_pos(48,0,0);
        anm->set_layer(GL_ L19);
        anm->set_blendmode(1);
        anm->set_sprite(spr53);
        anm->scale_time(20,0,2.0f,2.0f);
        anm->pos_time(20,0,96,0,0);
    }
    else if (anm->frame == 2) anm->set_sprite(spr54);
    else if (anm->frame == 4) anm->set_sprite(spr55);
    else if (anm->frame == 6) anm->set_sprite(spr56);
    else if (anm->frame == 8) anm->set_sprite(spr57);
    else if (anm->frame == 10) anm->set_sprite(spr58);
    else if (anm->frame == 12) anm->set_sprite(spr59);
    else if (anm->frame == 14) anm->set_sprite(spr60);
    else if (anm->frame == 16) anm->set_sprite(spr61);
    else if (anm->frame == 18) anm->destroy();
}

void effectCharge(float a, float x, float y, int r, int g, int b, int speed, bool reverse)
{
    std::function<void(void)> f = [r,g,b,x,y,a,speed,reverse] () {
        int anm = AnmManager::newAnim(effectChargeP1,-1,true);
        AnimScript* as = AnmManager::anim(anm);
        as->set_color(r,g,b);
        as->set_pos(Random::Floatm11()*100,-300+Random::Float01()*100,speed);
        AnmManager::UpdateChild(anm,x,y,0,0,0,a,1,1,1,1+reverse);
        anm = AnmManager::newAnim(effectChargeP1,-1,true);
        as = AnmManager::anim(anm);
        as->set_color(r,g,b);
        as->set_pos(Random::Floatm11()*100,-300+Random::Float01()*100,speed);
        AnmManager::UpdateChild(anm,x,y,0,0,0,a,1,1,1,1+reverse);
        anm = AnmManager::newAnim(effectChargeP2,-1,true);
        as = AnmManager::anim(anm);
        as->set_color(255-r,255-g,255-b);
        as->set_pos(Random::Floatm11()*100,-300+Random::Float01()*100,speed);
        AnmManager::UpdateChild(anm,x,y,0,0,0,a,1,1,1,1+reverse);
    };
    for (int i = 0; i < speed; i++)
    {
        NSEngine::ScheduleTask(i,f);
    }
    static int src = NSEngine::AudioEngine::CreateSource();
    NSEngine::AudioEngine::PlaySoundAtSource(src,gameassets::se_ch02);
}
void effectChargeP1(AnimScript* anm)
{
    if (anm->frame == 0)
    {
        anm->set_layer(GL_ L7);
        if (rand()%32==0) anm->set_layer(GL_ L11);
        anm->set_blendmode(2);
        anm->set_sprite(spr62);
        anm->set_scale(.6,.6);
        anm->set_pos(Random::Floatm11()*50,-300+Random::Floatm11()*50,0);
    }
    else if (anm->frame == anm->z_()) anm->x_time(anm->z_(),1,Random::Floatm11()*20);
    else if (anm->frame == 2*anm->z_()+10) anm->alpha_time(10,0,0);
    else if (anm->frame == 2*anm->z_()+20) anm->destroy();
    if (anm->interrupt == 1)
    {
        anm->alpha_time(10,0,80);
        anm->scale_time(2*anm->z_(),0,2.4,2.4);
        anm->y_time(2*anm->z_(),9,Random::Floatm11()*20);
        anm->x_time(anm->z_(),4,100+Random::Floatm11()*40);
    }
    if (anm->interrupt == 2)
    {
        anm->alpha_time(10,0,80);
        anm->scale_time(2*anm->z_(),0,2.4,2.4);
        anm->y_time(2*anm->z_(),9,Random::Floatm11()*20);
        anm->x_time(anm->z_(),4,-100+Random::Floatm11()*40);
    }
}
void effectChargeP2(AnimScript* anm)
{
    if (anm->frame == 0)
    {
        anm->set_layer(GL_ L6);
        if (rand()%32==0) anm->set_layer(GL_ L11);
        anm->set_blendmode(1);
        anm->set_sprite(spr62);
        anm->set_scale(2,2);
        anm->set_pos(Random::Floatm11()*50,-300+Random::Floatm11()*50,0);
    }
    else if (anm->frame == anm->z_()) anm->x_time(anm->z_(),1,Random::Floatm11()*20);
    else if (anm->frame == 2*anm->z_()+10) anm->alpha_time(10,0,0);
    else if (anm->frame == 2*anm->z_()+20) anm->destroy();
    if (anm->interrupt == 1)
    {
        anm->alpha_time(40,0,96);
        anm->scale_time(2*anm->z_(),0,1,1);
        anm->y_time(2*anm->z_(),9,Random::Floatm11()*20);
        anm->x_time(anm->z_(),4,100+Random::Floatm11()*40);
    }
    if (anm->interrupt == 2)
    {
        anm->alpha_time(10,0,80);
        anm->scale_time(2*anm->z_(),0,2.4,2.4);
        anm->y_time(2*anm->z_(),9,Random::Floatm11()*20);
        anm->x_time(anm->z_(),4,-100+Random::Floatm11()*40);
    }
}
