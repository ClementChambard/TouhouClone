#include "AnmPl00.h"

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

std::vector<void(*)(AnimScript*)> AnmPl00::buletsanms;

void AnmPl00::Init()
{
    int t = NSEngine::TextureManager::RegisterTexture("assets/textures/player/pl00.png");
    sp0 = GS_ AddSprite(t,0,0,32,48);
    sp1 = GS_ AddSprite(t,32,0,32,48);
    sp2 = GS_ AddSprite(t,64,0,32,48);
    sp3 = GS_ AddSprite(t,96,0,32,48);
    sp4 = GS_ AddSprite(t,128,0,32,48);
    sp5 = GS_ AddSprite(t,160,0,32,48);
    sp6 = GS_ AddSprite(t,192,0,32,48);
    sp7 = GS_ AddSprite(t,224,0,32,48);
    sp8 = GS_ AddSprite(t,0,48,32,48);
    sp9 = GS_ AddSprite(t,32,48,32,48);
    sp10 = GS_ AddSprite(t,64,48,32,48);
    sp11 = GS_ AddSprite(t,96,48,32,48);
    sp12 = GS_ AddSprite(t,128,48,32,48);
    sp13 = GS_ AddSprite(t,160,48,32,48);
    sp14 = GS_ AddSprite(t,192,48,32,48);
    sp15 = GS_ AddSprite(t,224,48,32,48);
    sp16 = GS_ AddSprite(t,0,96,32,48);
    sp17 = GS_ AddSprite(t,32,96,32,48);
    sp18 = GS_ AddSprite(t,64,96,32,48);
    sp19 = GS_ AddSprite(t,96,96,32,48);
    sp20 = GS_ AddSprite(t,128,96,32,48);
    sp21 = GS_ AddSprite(t,160,96,32,48);
    sp22 = GS_ AddSprite(t,192,96,32,48);
    sp23 = GS_ AddSprite(t,224,96,32,48);
    sp24 = GS_ AddSprite(t,192,144,64,16);
    sp25 = GS_ AddSprite(t,192,160,64,16);
    sp26 = GS_ AddSprite(t,64,176,64,16);
    sp27 = GS_ AddSprite(t,128,176,64,16);
    sp28 = GS_ AddSprite(t,16,144,16,16);
    sp29 = GS_ AddSprite(t,32,144,16,16);
    sp30 = GS_ AddSprite(t,48,144,16,16);
    sp31 = GS_ AddSprite(t,96,192,32,32); //36
    sp32 = GS_ AddSprite(t,128,192,32,32);
    sp33 = GS_ AddSprite(t,160,192,32,32);
    sp34 = GS_ AddSprite(t,192,192,32,32);
    sp35 = GS_ AddSprite(t,224,192,32,32);
    sp36 = GS_ AddSprite(t,64,224,32,32);
    sp37 = GS_ AddSprite(t,96,224,32,32);
    sp38 = GS_ AddSprite(t,128,224,32,32);
    sp39 = GS_ AddSprite(t,160,224,32,32);
    sp40 = GS_ AddSprite(t,192,224,32,32);
    sp41 = GS_ AddSprite(t,96,144,16,16);

    buletsanms.push_back(pl00Bullet0);
    buletsanms.push_back(pl00Bullet1);
    buletsanms.push_back(pl00Bullet1);
    buletsanms.push_back(pl00Bullet2);
}

void pl00Center(AnimScript* anm)
{
    if (anm->frame == 0 || anm->frame == 40)
    {
        anm->frame = 0;
        anm->set_layer(GL_ L14);
        anm->set_sprite(sp0);
    }
    else if (anm->frame == 5) anm->set_sprite(sp1);
    else if (anm->frame == 10) anm->set_sprite(sp2);
    else if (anm->frame == 15) anm->set_sprite(sp3);
    else if (anm->frame == 20) anm->set_sprite(sp4);
    else if (anm->frame == 25) anm->set_sprite(sp5);
    else if (anm->frame == 30) anm->set_sprite(sp6);
    else if (anm->frame == 35) anm->set_sprite(sp7);
}

void pl00ToLeft(AnimScript* anm)
{
    if (anm->frame == 0)
    {
        anm->set_layer(GL_ L14);
        anm->set_sprite(sp8);
    }
    else if (anm->frame == 1) anm->set_sprite(sp9);
    else if (anm->frame == 2) anm->set_sprite(sp10);
    else if (anm->frame == 3) anm->set_sprite(sp11);
    else if (anm->frame == 4 || anm->frame == 23) {anm->set_sprite(sp12); anm->frame = 4;}
    else if (anm->frame == 9) anm->set_sprite(sp13);
    else if (anm->frame == 14) anm->set_sprite(sp14);
    else if (anm->frame == 19) anm->set_sprite(sp15);
}

void pl00FromLeft(AnimScript* anm)
{
    if (anm->frame == 0)
    {
        anm->set_layer(GL_ L14);
        anm->set_sprite(sp11);
    }
    else if (anm->frame == 1) anm->set_sprite(sp10);
    else if (anm->frame == 2) anm->set_sprite(sp9);
    else if (anm->frame == 3) anm->set_sprite(sp8);
    else if (anm->frame == 4 || anm->frame == 44) {anm->set_sprite(sp0); anm->frame = 4;}
    else if (anm->frame == 9) anm->set_sprite(sp1);
    else if (anm->frame == 14) anm->set_sprite(sp2);
    else if (anm->frame == 19) anm->set_sprite(sp3);
    else if (anm->frame == 24) anm->set_sprite(sp4);
    else if (anm->frame == 29) anm->set_sprite(sp5);
    else if (anm->frame == 34) anm->set_sprite(sp6);
    else if (anm->frame == 39) anm->set_sprite(sp7);
}

void pl00ToRight(AnimScript* anm)
{
    if (anm->frame == 0)
    {
        anm->set_layer(GL_ L14);
        anm->set_sprite(sp16);
    }
    else if (anm->frame == 1) anm->set_sprite(sp17);
    else if (anm->frame == 2) anm->set_sprite(sp18);
    else if (anm->frame == 3) anm->set_sprite(sp19);
    else if (anm->frame == 4 || anm->frame == 23) {anm->set_sprite(sp20); anm->frame = 4;}
    else if (anm->frame == 9) anm->set_sprite(sp21);
    else if (anm->frame == 14) anm->set_sprite(sp22);
    else if (anm->frame == 19) anm->set_sprite(sp23);
}

void pl00FromRight(AnimScript* anm)
{
    if (anm->frame == 0)
    {
        anm->set_layer(GL_ L14);
        anm->set_sprite(sp19);
    }
    else if (anm->frame == 1) anm->set_sprite(sp18);
    else if (anm->frame == 2) anm->set_sprite(sp17);
    else if (anm->frame == 3) anm->set_sprite(sp16);
    else if (anm->frame == 4 || anm->frame == 44) {anm->set_sprite(sp0); anm->frame = 4;}
    else if (anm->frame == 9) anm->set_sprite(sp1);
    else if (anm->frame == 14) anm->set_sprite(sp2);
    else if (anm->frame == 19) anm->set_sprite(sp3);
    else if (anm->frame == 24) anm->set_sprite(sp4);
    else if (anm->frame == 29) anm->set_sprite(sp5);
    else if (anm->frame == 34) anm->set_sprite(sp6);
    else if (anm->frame == 39) anm->set_sprite(sp7);
}

void pl00Bullet0(AnimScript* anm)
{
    if (anm->frame == 0 || anm->frame == 2)
    {
        if (anm->frame == 0)
        {
            anm->set_layer(GL_ L13);
            anm->set_alpha(160);
        }
        anm->frame = 0;
        anm->set_sprite(sp24);
    }
    else if (anm->frame == 1) anm->set_sprite(sp25);
    else if (anm->frame == 13) anm->set_sprite(sp29);
    else if (anm->frame == 23) anm->set_sprite(sp30);
    else if (anm->frame == 33) anm->destroy();
    if (anm->interrupt == 2)
    {
        anm->frame = 3;
        anm->set_layer(GL_ L15);
        anm->set_blendmode(1);
        anm->set_sprite(sp28);
        anm->set_alpha(192);
        anm->alpha_time(30,0,0);
    }
}
#include <math/Random.h>
void pl00Bullet1(AnimScript* anm)
{
    if (anm->frame == 0 || anm->frame == 2)
    {
        if (anm->frame == 0)
        {
            anm->set_layer(GL_ L13);
            anm->set_alpha(64);
            anm->alpha_time(6,0,255);
            anm->set_scale(0.2f,1.f);
            anm->scale_time(8,0,2.f,1.f);
        }
        anm->frame = 0;
        anm->set_sprite(sp26);
    }
    else if (anm->frame == 1) anm->set_sprite(sp27);
    else if (anm->frame == 13) anm->alpha_time(10,0,0);
    else if (anm->frame == 23) anm->destroy();
    if (anm->interrupt == 2)
    {
        anm->frame = 3;
        anm->set_layer(GL_ L15);
        anm->set_blendmode(1);
        anm->set_sprite(sp26);
        anm->set_alpha(192);
        anm->set_rot(0,0,Random::Angle()/10);
    }
}

void pl00Bullet2(AnimScript* anm)
{
    if (anm->frame == 0 || anm->frame == 4) {
        if (anm->frame == 0)
        {
            anm->set_layer(GL_ L13);
            anm->set_alpha(160);
        }
        anm->frame = 0;
        anm->set_sprite(sp39);
    }
    if (anm->frame == 2) anm->set_sprite(sp40);
    if (anm->frame == 8) anm->set_sprite(sp32);
    if (anm->frame == 11) anm->set_sprite(sp33);
    if (anm->frame == 14) anm->set_sprite(sp34);
    if (anm->frame == 17) anm->set_sprite(sp35);
    if (anm->frame == 20) anm->set_sprite(sp36);
    if (anm->frame == 23) anm->set_sprite(sp37);
    if (anm->frame == 26) anm->set_sprite(sp38);
    if (anm->frame == 29) anm->destroy();
    if (anm->interrupt == 2)
    {
        anm->set_layer(GL_ L15);
        anm->set_blendmode(1);
        anm->set_sprite(31);
        anm->frame = 5;
    }
}

void pl00Option(AnimScript* anm)
{
    if (anm->frame == 0 || anm->interrupt == 2)
    {
        if (anm->frame == 0) anm->set_alpha(0);
        else anm->set_alpha(255);
        anm->set_layer(GL_ L14);
        anm->set_blendmode(1);
        anm->frame = 0;
        anm->set_scale(0,0);
        anm->scale_time(10,4,1.4f,1.4f);
        anm->set_sprite(sp41);
        anm->rot_vel(0,0,-PI/10.f);
    }
    if (anm->frame == 10) anm->scale_time(6,1,1,1);
    if (anm->frame == 16)
    {
        anm->rot_vel(0,0,-PI/30.f);
        anm->set_layer(GL_ L14);
        anm->set_blendmode(0);
    }
    if (anm->frame == 17) anm->frame = 16;
    if (anm->interrupt == 3) 
    {
        anm->scale_time(20,4,0,0);
        anm->frame = 16;
    }
    if (anm->interrupt == 1)
    {
        anm->set_layer(GL_ L14);
        anm->set_blendmode(1);
        anm->scale_time(20,4,0,3);
        anm->frame = 18;
    }
    if (anm->frame == 38) anm->set_alpha(0);
}

void pl00OptionFP(AnimScript* anm)
{
    if (anm->frame == 0 || anm->interrupt == 2)
    {
        anm->set_alpha(0);
        if (anm->frame == 0)
        {
            anm->set_sprite(sp41);
            anm->set_scale(0,0);
            anm->set_layer(GL_ L13);
            anm->set_blendmode(1);
            anm->rot_vel(0,0,PI/30.f);
        }
        else
            anm->scale_time(10,0,1.5f,1.5f);
        anm->alpha_time(10,0,128);
        anm->frame = 0;
    }
    if (anm->frame == 1) anm->frame = 0;
    if (anm->interrupt == 3) anm->scale_time(20,4,0,0);
    if (anm->interrupt == 1) anm->set_alpha(0);
}

void pl00Dead(AnimScript* anm)
{
    if (anm->frame == 0)
    {
        anm->set_layer(GL_ L14);
        anm->set_sprite(sp0);
        anm->set_color(60,0,255);
        anm->alpha_time(30,0,0);
    }
    else if (anm->frame == 30) anm->destroy();
}
