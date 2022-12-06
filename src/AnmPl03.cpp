#include "AnmPl03.h"
#include <NSEngine.h>

namespace pl3 {
int sp0;
int sp1;
int sp2;
int sp3;
int sp4;
int sp5;
int sp6;
int sp7;
int sp8;
int sp9;
int sp10;
int sp11;
int sp12;
int sp13;
int sp14;
int sp15;
int sp16;
int sp17;
int sp18;
int sp19;
int sp20;
int sp21;
int sp22;
int sp23;
int sp24;
int sp25;
int sp26;
int sp27;
int sp28;
int sp29;
int sp30;
int sp31;
int sp32;
int sp33;
int sp34;
int sp35;
int sp36;
int sp37;
int sp38;
int sp39;
int sp40;
int sp41;
int sp42;
}

void AnmPl03::Init()
{
    int t = NSEngine::TextureManager::RegisterTexture("assets/textures/player/pl03.png");
    pl3::sp0 = GS_ AddSprite(t,1,1,30,46);
    pl3::sp1 = GS_ AddSprite(t,33,1,30,46);
    pl3::sp2 = GS_ AddSprite(t,65,1,30,46);
    pl3::sp3 = GS_ AddSprite(t,97,1,30,46);
    pl3::sp4 = GS_ AddSprite(t,129,1,30,46);
    pl3::sp5 = GS_ AddSprite(t,161,1,30,46);
    pl3::sp6 = GS_ AddSprite(t,193,1,30,46);
    pl3::sp7 = GS_ AddSprite(t,225,1,30,46);
    pl3::sp8 = GS_ AddSprite(t,1,49,30,46);
    pl3::sp9 = GS_ AddSprite(t,33,49,30,46);
    pl3::sp10 = GS_ AddSprite(t,65,49,30,46);
    pl3::sp11 = GS_ AddSprite(t,97,49,30,46);
    pl3::sp12 = GS_ AddSprite(t,129,49,30,46);
    pl3::sp13 = GS_ AddSprite(t,161,49,30,46);
    pl3::sp14 = GS_ AddSprite(t,193,49,30,46);
    pl3::sp15 = GS_ AddSprite(t,225,49,30,46);
    pl3::sp16 = GS_ AddSprite(t,1,97,30,46);
    pl3::sp17 = GS_ AddSprite(t,33,97,30,46);
    pl3::sp18 = GS_ AddSprite(t,65,97,30,46);
    pl3::sp19 = GS_ AddSprite(t,97,97,30,46);
    pl3::sp20 = GS_ AddSprite(t,129,97,30,46);
    pl3::sp21 = GS_ AddSprite(t,161,97,30,46);
    pl3::sp22 = GS_ AddSprite(t,193,97,30,46);
    pl3::sp23 = GS_ AddSprite(t,225,97,30,46);
    pl3::sp24 = GS_ AddSprite(t,0,144,32,16);
    pl3::sp25 = GS_ AddSprite(t,32,144,32,16);
    pl3::sp26 = GS_ AddSprite(t,64,144,32,16);
    pl3::sp27 = GS_ AddSprite(t,96,144,32,16);
    pl3::sp28 = GS_ AddSprite(t,0,160,64,32);
    pl3::sp29 = GS_ AddSprite(t,64,160,64,32);
    pl3::sp30 = GS_ AddSprite(t,128,160,64,32);
    pl3::sp31 = GS_ AddSprite(t,192,160,64,32);
    pl3::sp32 = GS_ AddSprite(t,0,192,48,32);
    pl3::sp33 = GS_ AddSprite(t,128,144,16,16);
    pl3::sp34 = GS_ AddSprite(t,144,144,16,16);
    pl3::sp35 = GS_ AddSprite(t,160,144,16,16);
    pl3::sp36 = GS_ AddSprite(t,176,144,16,16);
    pl3::sp37 = GS_ AddSprite(t,64,192,64,64);
    pl3::sp38 = GS_ AddSprite(t,128,192,64,64);
    pl3::sp39 = GS_ AddSprite(t,192,192,64,64);
    pl3::sp40 = GS_ AddSprite(t,192,144,16,16);
    pl3::sp41 = GS_ AddSprite(t,208,144,16,16);
    pl3::sp42 = GS_ AddSprite(t,224,144,16,16);

}

void pl03Center(AnimScript* anm)
{
    if (anm->frame == 0)
    {
        anm->set_layer(GL_ L14);
        anm->set_sprite(pl3::sp0);
    }
    else if (anm->frame == 5) anm->set_sprite(pl3::sp1);
    else if (anm->frame == 10) anm->set_sprite(pl3::sp2);
    else if (anm->frame == 15) anm->set_sprite(pl3::sp3);
    else if (anm->frame == 20) anm->set_sprite(pl3::sp4);
    else if (anm->frame == 25) anm->set_sprite(pl3::sp5);
    else if (anm->frame == 30) anm->set_sprite(pl3::sp6);
    else if (anm->frame == 35) anm->set_sprite(pl3::sp7);
    else if (anm->frame == 40) anm->set_sprite(pl3::sp6);
    else if (anm->frame == 45) anm->set_sprite(pl3::sp5);
    else if (anm->frame == 50) anm->set_sprite(pl3::sp4);
    else if (anm->frame == 55) anm->set_sprite(pl3::sp3);
    else if (anm->frame == 60) anm->set_sprite(pl3::sp2);
    else if (anm->frame == 65) anm->set_sprite(pl3::sp1);
    else if (anm->frame == 70) {anm->set_sprite(pl3::sp0); anm->frame = 0;}
}

void pl03ToLeft(AnimScript* anm)
{
    if (anm->frame == 0)
    {
        anm->set_layer(GL_ L14);
        anm->set_sprite(pl3::sp8);
    }
    else if (anm->frame == 1) anm->set_sprite(pl3::sp9);
    else if (anm->frame == 2) anm->set_sprite(pl3::sp10);
    else if (anm->frame == 3) anm->set_sprite(pl3::sp11);
    else if (anm->frame == 4 || anm->frame == 23) {anm->set_sprite(pl3::sp12); anm->frame = 4;}
    else if (anm->frame == 9) anm->set_sprite(pl3::sp13);
    else if (anm->frame == 14) anm->set_sprite(pl3::sp14);
    else if (anm->frame == 19) anm->set_sprite(pl3::sp15);
}

void pl03FromLeft(AnimScript* anm)
{
    if (anm->frame == 0)
    {
        anm->set_layer(GL_ L14);
        anm->set_sprite(pl3::sp11);
    }
    else if (anm->frame == 1) anm->set_sprite(pl3::sp10);
    else if (anm->frame == 2) anm->set_sprite(pl3::sp9);
    else if (anm->frame == 3) anm->set_sprite(pl3::sp8);
    else if (anm->frame == 4) {anm->frame = 0; anm->SetScript(pl03Center);}
}

void pl03ToRight(AnimScript* anm)
{
    if (anm->frame == 0)
    {
        anm->set_layer(GL_ L14);
        anm->set_sprite(pl3::sp16);
    }
    else if (anm->frame == 1) anm->set_sprite(pl3::sp17);
    else if (anm->frame == 2) anm->set_sprite(pl3::sp18);
    else if (anm->frame == 3) anm->set_sprite(pl3::sp19);
    else if (anm->frame == 4 || anm->frame == 23) {anm->set_sprite(pl3::sp20); anm->frame = 4;}
    else if (anm->frame == 9) anm->set_sprite(pl3::sp21);
    else if (anm->frame == 14) anm->set_sprite(pl3::sp22);
    else if (anm->frame == 19) anm->set_sprite(pl3::sp23);
}

void pl03FromRight(AnimScript* anm)
{
    if (anm->frame == 0)
    {
        anm->set_layer(GL_ L14);
        anm->set_sprite(pl3::sp19);
    }
    else if (anm->frame == 1) anm->set_sprite(pl3::sp18);
    else if (anm->frame == 2) anm->set_sprite(pl3::sp17);
    else if (anm->frame == 3) anm->set_sprite(pl3::sp16);
    else if (anm->frame == 4) { anm->frame = 0; anm->SetScript(pl03Center); }
}

void pl03Bullet0(AnimScript* anm)
{
    if (anm->frame == 0)
    {
        anm->set_layer(GL_ L13);
        anm->set_sprite(pl3::sp24);
    } else if (anm->frame == 1) anm->frame = 0;
    else if (anm->frame == 2) anm->set_sprite(pl3::sp25);
    else if (anm->frame == 5) anm->set_sprite(pl3::sp26);
    else if (anm->frame == 8) anm->set_sprite(pl3::sp27);
    else if (anm->frame == 10) anm->destroy();
    if (anm->interrupt == 2)
    {
        anm->frame = 1;
        anm->set_layer(GL_ L15);
        anm->set_blendmode(1);
        anm->set_alpha(192);
    }
}

#include <math/Random.h>
void pl03Bullet1(AnimScript* anm)
{
    if (anm->frame == 0)
    {
        anm->set_layer(GL_ L13);
        anm->set_alpha(32);
        anm->alpha_time(6,0,192);
        anm->set_scale(0,0.5);
        anm->set_color(128,255,255);
        anm->color_time(6,0,255,128,255);
        anm->scale_time(8,0,.8f,.8f);
        anm->set_sprite(pl3::sp28);
    } else if (anm->frame == 1) anm->frame = 0;
    else if (anm->frame == 2) anm->set_sprite(pl3::sp29);
    else if (anm->frame == 5) anm->set_sprite(pl3::sp30);
    else if (anm->frame == 8) anm->set_sprite(pl3::sp31);
    else if (anm->frame == 11) anm->destroy();
    if (anm->interrupt == 2)
    {
        anm->frame = 1;
        anm->set_layer(GL_ L15);
        anm->set_blendmode(1);
    }
}

void pl03Bullet2(AnimScript* anm)
{
    if (anm->frame == 0) 
    {
        anm->set_layer(GL_ L13);
        anm->set_alpha(192);
        anm->set_sprite(pl3::sp32);
    } else if (anm->frame == 1) anm->frame = 0;
    else if (anm->frame == 4) anm->destroy();
    if (anm->interrupt == 2)
    {
        anm->set_layer(GL_ L15);
        anm->set_blendmode(1);
        anm->frame = 1;
    }
}

void pl03Option(AnimScript* anm)
{
    if (anm->frame == 0) 
    {
        anm->set_layer(GL_ L14);
        anm->set_sprite(pl3::sp33);
        anm->set_alpha(0);
    } else if (anm->frame == 1) anm->frame = 0;
    if (anm->frame == 74 || anm->interrupt == 2) 
    {
        anm->set_alpha(255);
        anm->frame = 2;
        if (anm->interrupt == 2)
        {
            anm->set_blendmode(0);
            anm->set_scale(0,0);
            anm->scale_time(10,4,1.f,1.f);
        }
        anm->set_sprite(pl3::sp33);
    }
    else if (anm->frame == 62) anm->set_sprite(pl3::sp34);
    else if (anm->frame == 64) anm->set_sprite(pl3::sp35);
    else if (anm->frame == 68) anm->set_sprite(pl3::sp36);
    
    if (anm->interrupt == 3) 
    {
        anm->scale_time(20,4,0,0);
        anm->frame = 0;
    }
    if (anm->interrupt == 1)
    {
        anm->set_blendmode(1);
        anm->scale_time(20,4,0,3);
        anm->frame = 0;
    }
}

void pl03OptionFP(AnimScript* anm)
{
    if (anm->frame == 0) 
    {
        anm->set_layer(GL_ L13);
        anm->set_sprite(pl3::sp33);
        anm->set_alpha(0);
        anm->set_blendmode(1);
    } else if (anm->frame == 1) anm->frame = 0;
    if (anm->frame == 74 || anm->interrupt == 2) 
    {
        anm->set_alpha(255);
        anm->frame = 2;
        if (anm->interrupt == 2)
        {
            anm->set_scale(0,0);
            anm->scale_time(10,4,1.5f,1.5f);
        }
        anm->set_sprite(pl3::sp33);
    }
    else if (anm->frame == 62) anm->set_sprite(pl3::sp34);
    else if (anm->frame == 64) anm->set_sprite(pl3::sp35);
    else if (anm->frame == 68) anm->set_sprite(pl3::sp36);
    
    if (anm->interrupt == 3) 
    {
        anm->scale_time(20,4,0,0);
        anm->frame = 0;
    }
    if (anm->interrupt == 1)
    {
        anm->scale_time(20,4,0,3);
        anm->frame = 0;
    }
}

void pl03Dead(AnimScript* anm)
{
    if (anm->frame == 0)
    {
        anm->set_layer(GL_ L14);
        anm->set_sprite(pl3::sp0);
        anm->set_color(60,0,255);
        anm->alpha_time(30,0,0);
    }
    else if (anm->frame == 30) anm->destroy();
}
