#include "AnmPl01.h"
#include <NSEngine.h>

namespace pl1 {
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
int sp43;
int sp44;
int sp45;
int sp46;
int sp47;
int sp48;
int sp49;
int sp50;
int sp51;
int sp52;
}

void AnmPl01::Init()
{
    int t = NSEngine::TextureManager::RegisterTexture("assets/textures/player/pl01.png");
    pl1::sp0 = GS_ AddSprite(t,1,1,30,46);
    pl1::sp1 = GS_ AddSprite(t,33,1,30,46);
    pl1::sp2 = GS_ AddSprite(t,65,1,30,46);
    pl1::sp3 = GS_ AddSprite(t,97,1,30,46);
    pl1::sp4 = GS_ AddSprite(t,129,1,30,46);
    pl1::sp5 = GS_ AddSprite(t,161,1,30,46);
    pl1::sp6 = GS_ AddSprite(t,193,1,30,46);
    pl1::sp7 = GS_ AddSprite(t,225,1,30,46);
    pl1::sp8 = GS_ AddSprite(t,1,49,30,46);
    pl1::sp9 = GS_ AddSprite(t,33,49,30,46);
    pl1::sp10 = GS_ AddSprite(t,65,49,30,46);
    pl1::sp11 = GS_ AddSprite(t,97,49,30,46);
    pl1::sp12 = GS_ AddSprite(t,129,49,30,46);
    pl1::sp13 = GS_ AddSprite(t,161,49,30,46);
    pl1::sp14 = GS_ AddSprite(t,193,49,30,46);
    pl1::sp15 = GS_ AddSprite(t,225,49,30,46);
    pl1::sp16 = GS_ AddSprite(t,1,97,30,46);
    pl1::sp17 = GS_ AddSprite(t,33,97,30,46);
    pl1::sp18 = GS_ AddSprite(t,65,97,30,46);
    pl1::sp19 = GS_ AddSprite(t,97,97,30,46);
    pl1::sp20 = GS_ AddSprite(t,129,97,30,46);
    pl1::sp21 = GS_ AddSprite(t,161,97,30,46);
    pl1::sp22 = GS_ AddSprite(t,193,97,30,46);
    pl1::sp23 = GS_ AddSprite(t,225,97,30,46);
    pl1::sp24 = GS_ AddSprite(t,1,145,30,14);
    pl1::sp25 = GS_ AddSprite(t,33,145,30,14);
    pl1::sp26 = GS_ AddSprite(t,65,145,30,14);
    pl1::sp27 = GS_ AddSprite(t,97,145,30,14);
    pl1::sp28 = GS_ AddSprite(t,0,177,512,16);
    pl1::sp29 = GS_ AddSprite(t,0,288,512,32);
    pl1::sp30 = GS_ AddSprite(t,48,192,32,32);
    pl1::sp31 = GS_ AddSprite(t,80,192,32,32);
    pl1::sp32 = GS_ AddSprite(t,0,192,48,16);
    pl1::sp33 = GS_ AddSprite(t,0,208,48,16);
    pl1::sp34 = GS_ AddSprite(t,1,225,30,30);
    pl1::sp35 = GS_ AddSprite(t,33,225,30,30);
    pl1::sp36 = GS_ AddSprite(t,65,225,30,30);
    pl1::sp37 = GS_ AddSprite(t,97,225,30,30);
    pl1::sp38 = GS_ AddSprite(t,129,225,30,30);
    pl1::sp39 = GS_ AddSprite(t,161,225,30,30);
    pl1::sp40 = GS_ AddSprite(t,193,225,30,30);
    pl1::sp41 = GS_ AddSprite(t,225,225,30,30);
    pl1::sp42 = GS_ AddSprite(t,128,192,64,32);
    pl1::sp43 = GS_ AddSprite(t,192,192,64,32);
    pl1::sp44 = GS_ AddSprite(t,1,257,30,30);
    pl1::sp45 = GS_ AddSprite(t,33,257,30,30);
    pl1::sp46 = GS_ AddSprite(t,65,257,30,30);
    pl1::sp47 = GS_ AddSprite(t,97,257,30,30);
    pl1::sp48 = GS_ AddSprite(t,129,257,30,30);
    pl1::sp49 = GS_ AddSprite(t,161,257,30,30);
    pl1::sp50 = GS_ AddSprite(t,193,257,30,30);
    pl1::sp51 = GS_ AddSprite(t,225,257,30,30);
    pl1::sp52 = GS_ AddSprite(t,64,160,16,16);

}

void pl01Center(AnimScript* anm)
{
    if (anm->frame == 0 || anm->frame == 40)
    {
        anm->frame = 0;
        anm->set_layer(GL_ L14);
        anm->set_sprite(pl1::sp0);
    }
    else if (anm->frame == 5) anm->set_sprite(pl1::sp1);
    else if (anm->frame == 10) anm->set_sprite(pl1::sp2);
    else if (anm->frame == 15) anm->set_sprite(pl1::sp3);
    else if (anm->frame == 20) anm->set_sprite(pl1::sp4);
    else if (anm->frame == 25) anm->set_sprite(pl1::sp5);
    else if (anm->frame == 30) anm->set_sprite(pl1::sp6);
    else if (anm->frame == 35) anm->set_sprite(pl1::sp7);
}

void pl01ToLeft(AnimScript* anm)
{
    if (anm->frame == 0)
    {
        anm->set_layer(GL_ L14);
        anm->set_sprite(pl1::sp8);
    }
    else if (anm->frame == 1) anm->set_sprite(pl1::sp9);
    else if (anm->frame == 2) anm->set_sprite(pl1::sp10);
    else if (anm->frame == 3) anm->set_sprite(pl1::sp11);
    else if (anm->frame == 4 || anm->frame == 23) {anm->set_sprite(pl1::sp12); anm->frame = 4;}
    else if (anm->frame == 9) anm->set_sprite(pl1::sp13);
    else if (anm->frame == 14) anm->set_sprite(pl1::sp14);
    else if (anm->frame == 19) anm->set_sprite(pl1::sp15);
}

void pl01FromLeft(AnimScript* anm)
{
    if (anm->frame == 0)
    {
        anm->set_layer(GL_ L14);
        anm->set_sprite(pl1::sp11);
    }
    else if (anm->frame == 1) anm->set_sprite(pl1::sp10);
    else if (anm->frame == 2) anm->set_sprite(pl1::sp9);
    else if (anm->frame == 3) anm->set_sprite(pl1::sp8);
    else if (anm->frame == 4) {anm->frame = 0; anm->SetScript(pl01Center);}
}

void pl01ToRight(AnimScript* anm)
{
    if (anm->frame == 0)
    {
        anm->set_layer(GL_ L14);
        anm->set_sprite(pl1::sp16);
    }
    else if (anm->frame == 1) anm->set_sprite(pl1::sp17);
    else if (anm->frame == 2) anm->set_sprite(pl1::sp18);
    else if (anm->frame == 3) anm->set_sprite(pl1::sp19);
    else if (anm->frame == 4 || anm->frame == 23) {anm->set_sprite(pl1::sp20); anm->frame = 4;}
    else if (anm->frame == 9) anm->set_sprite(pl1::sp21);
    else if (anm->frame == 14) anm->set_sprite(pl1::sp22);
    else if (anm->frame == 19) anm->set_sprite(pl1::sp23);
}

void pl01FromRight(AnimScript* anm)
{
    if (anm->frame == 0)
    {
        anm->set_layer(GL_ L14);
        anm->set_sprite(pl1::sp19);
    }
    else if (anm->frame == 1) anm->set_sprite(pl1::sp18);
    else if (anm->frame == 2) anm->set_sprite(pl1::sp17);
    else if (anm->frame == 3) anm->set_sprite(pl1::sp16);
    else if (anm->frame == 4) { anm->frame = 0; anm->SetScript(pl01Center); }
}


void pl01Bullet0(AnimScript* anm)
{
    if (anm->frame == 0)
    {
        anm->set_layer(GL_ L13);
        anm->set_sprite(pl1::sp24);
        anm->set_alpha(128);
    } else if (anm->frame == 1) anm->frame = 0;
    else if (anm->frame == 2) anm->set_sprite(pl1::sp25);
    else if (anm->frame == 12) anm->set_sprite(pl1::sp26);
    else if (anm->frame == 22) anm->set_sprite(pl1::sp27);
    else if (anm->frame == 32) anm->destroy();
    if (anm->interrupt == 2)
    {
        anm->frame = 1;
        anm->set_layer(GL_ L15);
        anm->set_blendmode(1);
        anm->set_alpha(192);
        anm->alpha_time(30,0,0);
    }
}

void pl01Bullet1p1(AnimScript* anm)
{
    if (anm->frame == 0 || anm->frame == 8)
    {
        if (anm->frame == 0)
        {
            anm->set_layer(GL_ L14);
            anm->set_alpha(224);
            anm->set_blendmode(1);
            anm->rot_vel(0,0,0.5067085f);
            anm->set_sprite(pl1::sp30);
        }
        anm->frame = 0;
        anm->scale_time(4,9,1,1);
    }
    else if (anm->frame == 4) anm->scale_time(4,9,.5f,.5f);
    else if (anm->frame == 16) anm->destroy();
    if (anm->interrupt == 1)
    {
        anm->scale_time(8,1,0,0);
        anm->frame = 8;
    }
}

void pl01Bullet1_1(AnimScript* anm)
{
    if (anm->frame == 0)
    {
        anm->create_child(pl01Bullet1p1);
        anm->set_layer(GL_ L15);
        anm->set_sprite(pl1::sp28);
        anm->set_alpha(160);
        anm->set_scale(1,0);
        anm->scale_time(4,1,1,1);
        anm->set_blendmode(1);
        anm->scroll_x(0.04761905f);
        anm->anchor(1,0);
    } else if (anm->frame == 1) anm->frame = 0;
    else if (anm->frame == 9) anm->destroy();
    if (anm->interrupt == 1)
    {
        anm->frame = 1;
        anm->scale_time(8,1,1,0);
    }
    else if (anm->interrupt == 2)
    {
        anm->color_time(8,0,64,64,255);
        anm->destroy();
    }
    else if (anm->interrupt == 3)
        anm->color_time(2,0,255,255,255);
}
void pl01Bullet1_2(AnimScript* anm)
{
    if (anm->frame == 0)
    {
        anm->create_child(pl01Bullet1p1);
        anm->set_layer(GL_ L15);
        anm->set_sprite(pl1::sp29);
        anm->set_alpha(220);
        anm->set_scale(1,0);
        anm->scale_time(4,1,1,1);
        anm->set_blendmode(1);
        anm->scroll_x(0.04761905f);
        anm->anchor(1,0);
    } else if (anm->frame == 1) anm->frame = 0;
    else if (anm->frame == 9) anm->destroy();
    if (anm->interrupt == 1)
    {
        anm->frame = 1;
        anm->scale_time(8,1,1,0);
    }
    else if (anm->interrupt == 2)
    {
        anm->color_time(8,0,160,160,255);
        anm->destroy();
    }
    else if (anm->interrupt == 3)
        anm->color_time(2,0,255,255,255);
}
void pl01Bullet1_3(AnimScript* anm)
{
    if (anm->frame == 0)
    {
        anm->create_child(pl01Bullet1p1);
        anm->set_layer(GL_ L13);
        anm->set_sprite(pl1::sp29);
        anm->set_alpha(192);
        anm->set_scale(4,0);
        anm->scale_time(4,1,4,4);
        anm->set_blendmode(1);
        anm->scroll_x(0.04761905f);
        anm->anchor(1,0);
    } else if (anm->frame == 1) anm->frame = 0;
    else if (anm->frame == 9) anm->destroy();
    if (anm->interrupt == 1)
    {
        anm->frame = 1;
        anm->scale_time(8,1,1,0);
    }
    else if (anm->interrupt == 2)
    {
        anm->color_time(8,0,160,160,255);
        anm->destroy();
    }
    else if (anm->interrupt == 3)
        anm->color_time(2,0,255,255,255);
}

void pl01Bullet1Hit(AnimScript* anm)
{
    if (anm->frame == 0)
    {
        anm->set_layer(GL_ L15);
        anm->set_sprite(pl1::sp31);
        anm->set_alpha(192);
        anm->set_blendmode(1);
        anm->alpha_time(20,0,0);
        anm->set_color(255,32,255);
        anm->color_time(20,0,32,32,255);
        anm->set_scale(1,1);
        anm->scale_time(20,1,0,0);
    }
    else if (anm->frame == 20) anm->destroy();
}

#include <math/Random.h>
void pl01Bullet2_1(AnimScript* anm)
{
    if (anm->frame == 0 || anm->frame == 8)
    {
        if (anm->frame == 0)
        {
            anm->set_layer(GL_ L13);
            anm->set_alpha(224);
        }
        anm->frame = 0;
        anm->set_sprite(pl1::sp32);
    }
    else if (anm->frame == 4) anm->set_sprite(pl1::sp33);
    else if (anm->frame > 8 && anm->frame < 15)
    {
        uint16_t a = AnmManager::newAnim(pl01Bullet2_1Hit);
        float F0 = Random::Angle(); float d = Random::Float01()*(anm->frame-8)*10;
        AnmManager::UpdateChild(a,anm->x_(1)+math::lengthdir_x(d,F0),anm->y_(1)+math::lengthdir_y(d,F0),0,0,0,0,1,1,1);
    }
    else if (anm->frame == 27) anm->destroy();
    if (anm->interrupt == 2)
    {
        anm->set_alpha(0);
        anm->frame = 8;
    }
}

void pl01Bullet2_1Hit(AnimScript* anm)
{
    if (anm->frame == 0)
    {
        anm->set_layer(GL_ L15);
        anm->set_alpha(244);
        anm->alpha_time(30,0,0);
        anm->set_scale(1,1);
        anm->scale_time(10,4,1.5,1.5);
        anm->set_rot(Random::Angle(), 0, Random::Angle());
        anm->set_blendmode(1);
        anm->set_sprite(pl1::sp34);
    }
    else if (anm->frame == 2) anm->set_sprite(pl1::sp35);
    else if (anm->frame == 4) anm->set_sprite(pl1::sp36);
    else if (anm->frame == 6) { anm->set_sprite(pl1::sp37); anm->set_blendmode(0); }
    else if (anm->frame == 8) anm->set_sprite(pl1::sp38);
    else if (anm->frame == 10) anm->set_sprite(pl1::sp39);
    else if (anm->frame == 12) anm->set_sprite(pl1::sp40);
    else if (anm->frame == 14) anm->set_sprite(pl1::sp41);
    else if (anm->frame == 16) anm->destroy();
}

void pl01Bullet2_2(AnimScript* anm)
{
    if (anm->frame == 0 || anm->frame == 8)
    {
        if (anm->frame == 0)
        {
            anm->set_layer(GL_ L13);
            anm->set_alpha(224);
        }
        anm->frame = 0;
        anm->set_sprite(pl1::sp42);
    }
    else if (anm->frame == 4) anm->set_sprite(pl1::sp43);
    else if (anm->frame > 8 && anm->frame < 18)
    {
        uint16_t a = AnmManager::newAnim(pl01Bullet2_2Hit);
        float F0 = Random::Angle(); float d = Random::Float01()*(anm->frame-8)*8;
        AnmManager::UpdateChild(a,anm->x_(1)+math::lengthdir_x(d,F0),anm->y_(1)+math::lengthdir_y(d,F0),0,0,0,0,1,1,1);
    }
    else if (anm->frame == 27) anm->destroy();
    if (anm->interrupt == 2)
    {
        anm->set_alpha(0);
        anm->frame = 8;
    }
}

void pl01Bullet2_2Hit(AnimScript* anm)
{
    if (anm->frame == 0)
    {
        anm->set_layer(GL_ L15);
        anm->set_alpha(244);
        anm->alpha_time(30,0,0);
        anm->set_scale(1,1);
        anm->scale_time(10,4,2,2);
        anm->set_rot(Random::Angle(), 0, Random::Angle());
        anm->set_blendmode(1);
        anm->set_sprite(pl1::sp44);
    }
    else if (anm->frame == 2) anm->set_sprite(pl1::sp45);
    else if (anm->frame == 4) anm->set_sprite(pl1::sp46);
    else if (anm->frame == 6) { anm->set_sprite(pl1::sp47); anm->set_blendmode(0); }
    else if (anm->frame == 8) anm->set_sprite(pl1::sp48);
    else if (anm->frame == 10) anm->set_sprite(pl1::sp49);
    else if (anm->frame == 12) anm->set_sprite(pl1::sp50);
    else if (anm->frame == 14) anm->set_sprite(pl1::sp51);
    else if (anm->frame == 16) anm->destroy();
}

void pl01Bullet2_3(AnimScript* anm)
{
    if (anm->frame == 0 || anm->frame == 8)
    {
        if (anm->frame == 0)
        {
            anm->set_layer(GL_ L13);
            anm->set_alpha(224);
        }
        anm->frame = 0;
        anm->set_sprite(pl1::sp42);
    }
    else if (anm->frame == 4) anm->set_sprite(pl1::sp43);
    else if (anm->frame > 8 && anm->frame < 22)
    {
        for (int i = 0; i < 3; i++)
        {
            uint16_t a = AnmManager::newAnim(pl01Bullet2_3Hit);
            float F0 = Random::Angle(); float d = Random::Float01()*(anm->frame-8)*3;
            AnmManager::UpdateChild(a,anm->x_(1)+math::lengthdir_x(d,F0),anm->y_(1)+math::lengthdir_y(d,F0),0,0,0,0,1,1,1);
        }
    }
    else if (anm->frame == 27) anm->destroy();
    if (anm->interrupt == 2)
    {
        anm->set_alpha(0);
        anm->frame = 8;
    }
}

void pl01Bullet2_3Hit(AnimScript* anm)
{
    if (anm->frame == 0)
    {
        anm->set_layer(GL_ L15);
        anm->set_alpha(244);
        anm->alpha_time(30,0,0);
        anm->set_scale(1,1);
        anm->scale_time(10,4,1.5,1.5);
        anm->set_rot(Random::Angle(), 0, Random::Angle());
        anm->set_blendmode(1);
        anm->set_sprite(pl1::sp44);
    }
    else if (anm->frame == 2) anm->set_sprite(pl1::sp45);
    else if (anm->frame == 4) anm->set_sprite(pl1::sp46);
    else if (anm->frame == 6) { anm->set_sprite(pl1::sp47); anm->set_blendmode(0); }
    else if (anm->frame == 8) anm->set_sprite(pl1::sp48);
    else if (anm->frame == 10) anm->set_sprite(pl1::sp49);
    else if (anm->frame == 12) anm->set_sprite(pl1::sp50);
    else if (anm->frame == 14) anm->set_sprite(pl1::sp51);
    else if (anm->frame == 16) anm->destroy();
}

void pl01Option(AnimScript* anm)
{
    if (anm->frame == 0) 
    {
        anm->set_layer(GL_ L14);
        anm->set_sprite(pl1::sp52);
        anm->set_alpha(0);
    } else if (anm->frame == 1) anm->frame = 0;
    if (anm->interrupt == 2) 
    {
        anm->set_alpha(255);
        anm->set_blendmode(1);
        anm->set_scale(0,0);
        anm->scale_time(10,4,1.4f,1.4f);
        anm->frame = 1;
    }
    else if (anm->frame == 11) anm->scale_time(6,1,1,1);
    else if (anm->frame == 17 || anm->frame == 47)
    {
        anm->frame = 17;
        anm->set_blendmode(0);
        anm->scale_time(15,9,.8f,.8f);
    }
    else if (anm->frame == 32) anm->scale_time(15,9,1.f,1.f);

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

void pl01OptionFP(AnimScript* anm)
{
    if (anm->frame == 0) 
    {
        anm->set_layer(GL_ L13);
        anm->set_sprite(pl1::sp52);
        anm->set_alpha(0);
        anm->set_blendmode(1);
    } else if (anm->frame == 1) anm->frame = 0;
    if (anm->interrupt == 2) 
    {
        anm->set_alpha(0);
        anm->set_scale(0,0);
        anm->scale_time(10,0,1.5f,1.5f);
        anm->alpha_time(10,0,128);
        anm->rot_vel(0,0,-0.10471976f);
    }
    
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

void pl01Dead(AnimScript* anm)
{
    if (anm->frame == 0)
    {
        anm->set_layer(GL_ L14);
        anm->set_sprite(pl1::sp0);
        anm->set_color(60,0,255);
        anm->alpha_time(30,0,0);
    }
    else if (anm->frame == 30) anm->destroy();
}
