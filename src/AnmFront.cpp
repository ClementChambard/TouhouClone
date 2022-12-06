#include "AnmFront.h"
#include <NSEngine.h>
#include <math/math.h>
#include <math/Random.h>

int frt0;
int frt1;
int frt2;
int frt3;
int frt4;
int frt5;
int frt6;
int frt7;
int frt8;
int frt9;
int frt10;
int frt11;
int frt12;
int frt13;
int frt14;
int frt15;
int frt16;
int frt17;
int frt18;
int frt19;
int frt20;
int frt21;
int frt22;
int frt23;
int frt24;
int frt25;
int frt26;
int frt27;
int frt28;
int frt29;
int frt30;
int frt31;
int frt32;
int frt33;
int frt34;
int frt35;
int frt36;
int frt37;
int frt38;
int frt39;
int frt40;
int frt41;
int frt42;
int frt43;
int frt44;
int frt45;
int frt46;
int frt47;
int frt48;
int frt49;
int frt50;
int frt51;
int frt52;
int frt53;
int frt54;
int frt55;
int frt56;
int frt57;
int frt58;
int frt59;
int frt60;
int frt61;
int frt62;
int frt63;
int frt64;
int frt65;

int frt81;

int frt89;
int frt90;
int frt91;
int frt92;
int frt93;
int frt94;
int frt95;
int frt96;
int frt97;
int frt98;
int frt99;
int frt100;
int frt101;
int frt102;
int frt103;
int frt104;
int frt105;
int frt106;
int frt107;

int frt148;
int frt149;
int frt150;

bool AnmFront::isinit = false;
void AnmFront::Init()
{
    if (isinit) return;
    int tex_front0 = NSEngine::TextureManager::RegisterTexture("assets/textures/front/front00.png");
    frt0 = GS_ AddSprite(tex_front0,0,0,64,960);        //border
    frt1 = GS_ AddSprite(tex_front0,64,0,448,960);
    frt2 = GS_ AddSprite(tex_front0,0,960,768,32);
    frt3 = GS_ AddSprite(tex_front0,0,992,768,32);
    frt4 = GS_ AddSprite(tex_front0,512,0,144,36);      //texts
    frt5 = GS_ AddSprite(tex_front0,512,36,144,36);
    frt6 = GS_ AddSprite(tex_front0,512,72,144,36);
    frt7 = GS_ AddSprite(tex_front0,512,108,144,36);
    frt8 = GS_ AddSprite(tex_front0,656,0,176,36);
    frt9 = GS_ AddSprite(tex_front0,656,36,160,36);
    frt10 = GS_ AddSprite(tex_front0,656,72,160,36);
    frt11 = GS_ AddSprite(tex_front0,656,108,144,36);
    frt12 = GS_ AddSprite(tex_front0,832,0,32,40);      //life hearts
    frt13 = GS_ AddSprite(tex_front0,864,0,32,40);
    frt14 = GS_ AddSprite(tex_front0,896,0,32,40);
    frt15 = GS_ AddSprite(tex_front0,928,0,32,40);
    frt16 = GS_ AddSprite(tex_front0,960,0,32,40);
    frt17 = GS_ AddSprite(tex_front0,992,0,32,40);
    frt18 = GS_ AddSprite(tex_front0,832,40,32,40);     //spell stars
    frt19 = GS_ AddSprite(tex_front0,864,40,32,40);
    frt20 = GS_ AddSprite(tex_front0,896,40,32,40);
    frt21 = GS_ AddSprite(tex_front0,928,40,32,40);
    frt22 = GS_ AddSprite(tex_front0,960,40,32,40);
    frt23 = GS_ AddSprite(tex_front0,992,40,32,40);
    frt24 = -1;//GS_ AddSprite(tex_front0,672,40,32,40); //??? empty
    frt25 = GS_ AddSprite(tex_front0,768,992,16,16);    //red 9 slices tl
    frt26 = GS_ AddSprite(tex_front0,784,992,16,16);            // t
    frt27 = GS_ AddSprite(tex_front0,800,992,16,16);            // tr
    frt28 = GS_ AddSprite(tex_front0,768,1008,16,16);           // bl
    frt29 = GS_ AddSprite(tex_front0,784,1008,16,16);           // b
    frt30 = GS_ AddSprite(tex_front0,800,1008,16,16);           // br
    frt31 = GS_ AddSprite(tex_front0,768,1000,16,16);           // l
    frt32 = GS_ AddSprite(tex_front0,800,1000,16,16);           // r
    frt33 = -1;//GS_ AddSprite(tex_front0,928,320,96,704); //??? empty
    frt34 = -1;//GS_ AddSprite(tex_front0,512,160,32,32); //??? empty
    frt35 = GS_ AddSprite(tex_front0,544,160,16,18);    //text nb
    frt36 = GS_ AddSprite(tex_front0,560,160,16,18);    //text nb
    frt37 = GS_ AddSprite(tex_front0,576,160,16,18);    //text nb
    frt38 = GS_ AddSprite(tex_front0,592,160,16,18);    //text nb
    frt39 = GS_ AddSprite(tex_front0,608,160,16,18);    //text nb
    frt40 = GS_ AddSprite(tex_front0,624,160,16,18);    //text nb
    frt41 = GS_ AddSprite(tex_front0,640,160,16,18);    //text nb
    frt42 = GS_ AddSprite(tex_front0,656,160,16,18);    //text nb
    frt43 = GS_ AddSprite(tex_front0,672,160,16,18);    //text nb
    frt44 = GS_ AddSprite(tex_front0,688,160,16,18);    //text nb
    frt45 = GS_ AddSprite(tex_front0,704,160,16,18);    //text slash
    frt46 = GS_ AddSprite(tex_front0,720,160,64,18);    //text failed
    frt47 = GS_ AddSprite(tex_front0,784,160,22,24);    //star nb of lifebars
    frt48 = GS_ AddSprite(tex_front0,512,192,512,64);    //get spellcard bonus
    frt48 = GS_ AddSprite(tex_front0,512,192,512,64);    //fail spellcard bonus
    frt49 = GS_ AddSprite(tex_front0,512,772,320,64);    //fail spellcard bonus
    frt50 = GS_ AddSprite(tex_front0,512,320,320,64);    //full power
    frt51 = GS_ AddSprite(tex_front0,512,384,192,64);    //high score
    frt52 = GS_ AddSprite(tex_front0,512,448,192,64);    //extend
    frt53 = GS_ AddSprite(tex_front0,512,512,384,64);    //item get border line text
    frt54 = GS_ AddSprite(tex_front0,512,256,512,64);    //challenge next stage
    frt55 = GS_ AddSprite(tex_front0,528,576,224,16);    //item get border line line
    frt56 = GS_ AddSprite(tex_front0,512,608,160,32);    //EASY
    frt57 = GS_ AddSprite(tex_front0,512,640,160,32);    //NORMAL
    frt58 = GS_ AddSprite(tex_front0,512,672,160,32);    //HARD
    frt59 = GS_ AddSprite(tex_front0,512,704,160,32);    //LUNATIC
    frt60 = GS_ AddSprite(tex_front0,512,736,160,32);    //EXTRA
    frt61 = GS_ AddSprite(tex_front0,672,736,192,32);    //OVERDRIVE
    frt62 = -1;//GS_ AddSprite(tex_front0,770,962,16,16); //??? empty
    frt63 = -1;//GS_ AddSprite(tex_front0,864,960,64,64); //??? empty
    frt64 = GS_ AddSprite(tex_front0,512,832,512,128);   //big disabled
    frt65 = GS_ AddSprite(tex_front0,672,608,128,64);    //spellcard time result
    //66 a 80 : trucs de th13
    frt81 = GS_ AddSprite(tex_front0,928,992,96,32);     //enemy location
    //82 a 87 : trucs de HSIFS
 
    int t = NSEngine::TextureManager::RegisterTexture("assets/textures/front/front01.png");
    frt89 = GS_ AddSprite(t,0,0,512,256);
    frt90 = GS_ AddSprite(t,192,32,512,896);

    t = NSEngine::TextureManager::RegisterTexture("assets/textures/ascii/pause.png");
    frt91 = GS_ AddSprite(t,0,0,512,64);
    frt92 = GS_ AddSprite(t,0,64,512,64);
    frt93 = GS_ AddSprite(t,0,128,512,64);
    frt94 = GS_ AddSprite(t,0,192,512,64);
    frt95 = GS_ AddSprite(t,0,256,512,64);
    frt96 = GS_ AddSprite(t,0,320,512,64);
    frt97 = GS_ AddSprite(t,0,384,512,64);
    frt98 = GS_ AddSprite(t,0,448,512,64);
    frt99 = GS_ AddSprite(t,0,512,512,64);
    frt100 = GS_ AddSprite(t,0,576,512,64);
    frt101 = GS_ AddSprite(t,0,640,512,64);
    frt102 = GS_ AddSprite(t,0,704,512,64);

    t = NSEngine::TextureManager::RegisterTexture("assets/textures/ascii/pause_title.png");
    frt103 = GS_ AddSprite(t,0,0,192,64);
    frt104 = GS_ AddSprite(t,0,64,192,64);
    frt105 = GS_ AddSprite(t,0,128,192,64);
    frt106 = GS_ AddSprite(t,0,192,192,64);

    t = NSEngine::TextureManager::RegisterTexture("assets/textures/ascii/pause_back.png");
    frt107 = GS_ AddSprite(t,0,0,96,448);

    t = NSEngine::TextureManager::RegisterTexture("assets/textures/front/lifebar.png");
    frt148 = GS_ AddSprite(t,0,0,8,32);
    frt149 = GS_ AddSprite(t,12,0,4,32);
    frt150 = GS_ AddSprite(t,20,0,6,12);
    isinit = true;
}

void frontAll(AnimScript* anm)
{
    if (anm->frame == 0)
    {
        anm->create_child(frontBgP1);
        anm->create_child(frontBgP2);
        anm->create_child(frontBgP3);
        anm->create_child(frontBgP4);
        anm->create_child(frontRecP1);
        anm->create_child(frontRecP2);
        anm->create_child(frontRecP3);
        anm->create_child(frontRecP4);
        anm->create_child(frontRecP5);
        anm->create_child(frontRecP6);
        anm->create_child(frontRecP7);
        anm->create_child(frontRecP8);
        anm->create_child(frontRecP9);
        anm->create_child(frontRecP10);
        anm->create_child(frontRecP11);
        anm->create_child(frontRecP12);
        anm->create_child(frontRecP13);
        anm->create_child(frontRecP14);
        anm->create_child(frontTxtP1);
        anm->create_child(frontTxtP2);
        anm->create_child(frontTxtP3);
        anm->create_child(frontTxtP4);
        anm->create_child(frontTxtP5);
        anm->create_child(frontTxtP6);
        anm->create_child(frontTxtP7);
        anm->create_child(frontTxtP8);
        anm->create_child(frontTxtP9);
        anm->create_child(frontILine);
    }
    else anm->frame = 0;
}

void frontPoly(AnimScript* anm)
{
    //???????
}

void frontBgP1(AnimScript* anm)
{
    if (anm->frame == 0)
    {
        anm->set_scale(.5,.5);
        anm->set_sprite(frt0);
        anm->set_layer(GL_ L25);
        anm->set_pos(-304,0,0);
    }
    else anm->frame = 0;
}
void frontBgP2(AnimScript* anm)
{
    if (anm->frame == 0)
    {
        anm->set_scale(.5,.5);
        anm->set_sprite(frt1);
        anm->set_layer(GL_ L25);
        anm->set_pos(208,0,0);
    }
    else anm->frame = 0;
}
void frontBgP3(AnimScript* anm)
{
    if (anm->frame == 0)
    {
        anm->set_scale(.5,.5);
        anm->set_sprite(frt2);
        anm->set_layer(GL_ L25);
        anm->set_pos(-96,232,0);
    }
    else anm->frame = 0;
}
void frontBgP4(AnimScript* anm)
{
    if (anm->frame == 0)
    {
        anm->set_scale(.5,.5);
        anm->set_sprite(frt3);
        anm->set_layer(GL_ L25);
        anm->set_pos(-96,-232,0);
    }
    else anm->frame = 0;
}

void frontTxtP1(AnimScript* anm)
{
    if (anm->frame == 0)
    {
        anm->set_scale(.5,.5);
        anm->set_sprite(frt4);
        anm->set_layer(GL_ L25);
        anm->set_color(255,255,255);
        anm->set_pos(144,189,0);
        anm->set_alpha(0);
    }
    else if (anm->frame == 20) anm->alpha_time(20,0,255);
    else if (anm->frame == 21) anm->frame = 20;
}
void frontTxtP2(AnimScript* anm)
{
    if (anm->frame == 0)
    {
        anm->set_scale(.5,.5);
        anm->set_sprite(frt5);
        anm->set_layer(GL_ L25);
        anm->set_pos(144,167,0);
        anm->set_alpha(0);
    }
    else if (anm->frame == 30) anm->alpha_time(20,0,255);
    else if (anm->frame == 31) anm->frame = 30;
}
void frontTxtP3(AnimScript* anm)
{
    if (anm->frame == 0)
    {
        anm->set_scale(.5,.5);
        anm->set_sprite(frt6);
        anm->set_layer(GL_ L25);
        anm->set_pos(144,135,0);
        anm->set_alpha(0);
    }
    else if (anm->frame == 40) anm->alpha_time(20,0,255);
    else if (anm->frame == 41) anm->frame = 40;
}
void frontTxtP4(AnimScript* anm)
{
    if (anm->frame == 0)
    {
        anm->set_scale(.5,.5);
        anm->set_sprite(frt7);
        anm->set_layer(GL_ L25);
        anm->set_pos(224,119,0);
        anm->set_alpha(0);
    }
    else if (anm->frame == 40) anm->alpha_time(20,0,255);
    else if (anm->frame == 41) anm->frame = 40;
}
void frontTxtP5(AnimScript* anm)
{
    if (anm->frame == 0)
    {
        anm->set_scale(.5,.5);
        anm->set_sprite(frt8);
        anm->set_layer(GL_ L25);
        anm->set_pos(152,97,0);
        anm->set_alpha(0);
    }
    else if (anm->frame == 50) anm->alpha_time(20,0,255);
    else if (anm->frame == 51) anm->frame = 50;
}
void frontTxtP6(AnimScript* anm)
{
    if (anm->frame == 0)
    {
        anm->set_scale(.5,.5);
        anm->set_sprite(frt7);
        anm->set_layer(GL_ L25);
        anm->set_pos(224,81,0);
        anm->set_alpha(0);
    }
    else if (anm->frame == 50) anm->alpha_time(20,0,255);
    else if (anm->frame == 51) anm->frame = 50;
}
void frontTxtP7(AnimScript* anm)
{
    if (anm->frame == 0)
    {
        anm->set_scale(.5,.5);
        anm->set_sprite(frt11);
        anm->set_layer(GL_ L25);
        anm->set_pos(160,49,0);
        anm->set_alpha(0);
    }
    else if (anm->frame == 60) anm->alpha_time(20,0,255);
    else if (anm->frame == 61) anm->frame = 60;
}
void frontTxtP8(AnimScript* anm)
{
    if (anm->frame == 0)
    {
        anm->set_scale(.5,.5);
        anm->set_sprite(frt10);
        anm->set_layer(GL_ L25);
        anm->set_pos(164,27,0);
        anm->set_alpha(0);
    }
    else if (anm->frame == 70) anm->alpha_time(20,0,255);
    else if (anm->frame == 71) anm->frame = 70;
}
void frontTxtP9(AnimScript* anm)
{
    if (anm->frame == 0)
    {
        anm->set_scale(.5,.5);
        anm->set_sprite(frt9);
        anm->set_layer(GL_ L25);
        anm->set_pos(164,5,0);
        anm->set_alpha(0);
    }
    else if (anm->frame == 80) anm->alpha_time(20,0,255);
    else if (anm->frame == 81) anm->frame = 80;
}

void frontDisabled(AnimScript* anm)
{
    if (anm->frame == 0)
    {
        anm->set_scale(.5,.5);
        anm->set_layer(GL_ L25);
        anm->set_sprite(frt64);
        anm->set_alpha(0);
        anm->set_pos(202.5,132,0);
    }
    else if (anm->frame == 80) anm->alpha_time(20,0,255);
    else if (anm->frame == 81) anm->frame = 80;
}

void frontRecP1(AnimScript* anm)
{
    if (anm->frame == 0)
    {
        anm->set_layer(GL_ L25);
        anm->set_blendmode(1);
        anm->special_draw(6);
        anm->set_scale(0,2);
        anm->set_color(160,96,96);
        anm->set_color2(160,96,96);
        anm->set_alpha(0);
        anm->set_alpha2(0);
        anm->set_pos(204,182,0);
        anm->alpha_time(60,0,255);
    }
    else if (anm->frame == 30) {anm->scale_time(30,4,96,2); anm->pos_time(30,4,252,182,0);}
    else if (anm->frame == 31) anm->frame = 30;
    else if (anm->frame == 61) anm->destroy();
    if (anm->interrupt == 6) {anm->frame = 31; anm->scale_time(30,4,96,0);}
    else if (anm->interrupt == 1) anm->frame = 46;
}
void frontRecP2(AnimScript* anm)
{
    if (anm->frame == 0)
    {
        anm->set_layer(GL_ L25);
        anm->set_blendmode(1);
        anm->special_draw(6);
        anm->set_scale(0,2);
        anm->set_color(160,96,96);
        anm->set_color2(160,96,96);
        anm->set_alpha(0);
        anm->set_alpha2(0);
        anm->set_pos(204,182,0);
        anm->alpha_time(60,0,255);
    }
    else if (anm->frame == 30) {anm->scale_time(30,4,-96,2); anm->pos_time(30,4,156,182,0);}
    else if (anm->frame == 31) anm->frame = 30;
    else if (anm->frame == 61) anm->destroy();
    if (anm->interrupt == 6) {anm->frame = 31; anm->scale_time(30,4,96,0);}
    else if (anm->interrupt == 1) anm->frame = 46;
}
void frontRecP3(AnimScript* anm)
{
    if (anm->frame == 0)
    {
        anm->set_layer(GL_ L25);
        anm->set_blendmode(1);
        anm->special_draw(6);
        anm->set_scale(0,2);
        anm->set_color(160,255,176);
        anm->set_color2(160,255,176);
        anm->set_alpha(0);
        anm->set_alpha2(0);
        anm->set_pos(204,160,0);
        anm->alpha_time(60,0,255);
    }
    else if (anm->frame == 40) {anm->scale_time(30,4,96,2); anm->pos_time(30,4,252,160,0);}
    else if (anm->frame == 41) anm->frame = 40;
    else if (anm->frame == 71) anm->destroy();
    if (anm->interrupt == 6) {anm->frame = 41; anm->scale_time(30,4,96,0);}
    else if (anm->interrupt == 1) anm->frame = 56;
}
void frontRecP4(AnimScript* anm)
{
    if (anm->frame == 0)
    {
        anm->set_layer(GL_ L25);
        anm->set_blendmode(1);
        anm->special_draw(6);
        anm->set_scale(0,2);
        anm->set_color(160,255,176);
        anm->set_color2(160,255,176);
        anm->set_alpha(0);
        anm->set_alpha2(0);
        anm->set_pos(204,160,0);
        anm->alpha_time(60,0,255);
    }
    else if (anm->frame == 40) {anm->scale_time(30,4,-96,2); anm->pos_time(30,4,156,160,0);}
    else if (anm->frame == 41) anm->frame = 40;
    else if (anm->frame == 71) anm->destroy();
    if (anm->interrupt == 6) {anm->frame = 41; anm->scale_time(30,4,96,0);}
    else if (anm->interrupt == 1) anm->frame = 56;
}
void frontRecP5(AnimScript* anm)
{
    if (anm->frame == 0)
    {
        anm->set_layer(GL_ L25);
        anm->set_blendmode(1);
        anm->special_draw(6);
        anm->set_scale(0,2);
        anm->set_color(255,32,255);
        anm->set_color2(255,32,255);
        anm->set_alpha(0);
        anm->set_alpha2(0);
        anm->set_pos(204,112,0);
        anm->alpha_time(60,0,255);
    }
    else if (anm->frame == 50) {anm->scale_time(30,4,96,2); anm->pos_time(30,4,252,112,0);}
    else if (anm->frame == 51) anm->frame = 50;
    else if (anm->frame == 81) anm->destroy();
    if (anm->interrupt == 6) {anm->frame = 51; anm->scale_time(30,4,96,0);}
    else if (anm->interrupt == 1) anm->frame = 66;
}
void frontRecP6(AnimScript* anm)
{
    if (anm->frame == 0)
    {
        anm->set_layer(GL_ L25);
        anm->set_blendmode(1);
        anm->special_draw(6);
        anm->set_scale(0,2);
        anm->set_color(255,32,255);
        anm->set_color2(255,32,255);
        anm->set_alpha(0);
        anm->set_alpha2(0);
        anm->set_pos(204,112,0);
        anm->alpha_time(60,0,255);
    }
    else if (anm->frame == 50) {anm->scale_time(30,4,-96,2); anm->pos_time(30,4,156,112,0);}
    else if (anm->frame == 51) anm->frame = 50;
    else if (anm->frame == 81) anm->destroy();
    if (anm->interrupt == 6) {anm->frame = 51; anm->scale_time(30,4,96,0);}
    else if (anm->interrupt == 1) anm->frame = 66;
}
void frontRecP7(AnimScript* anm)
{
    if (anm->frame == 0)
    {
        anm->set_layer(GL_ L25);
        anm->set_blendmode(1);
        anm->special_draw(6);
        anm->set_scale(0,2);
        anm->set_color(64,255,64);
        anm->set_color2(64,255,64);
        anm->set_alpha(0);
        anm->set_alpha2(0);
        anm->set_pos(204,74,0);
        anm->alpha_time(60,0,255);
    }
    else if (anm->frame == 60) {anm->scale_time(30,4,96,2); anm->pos_time(30,4,252,74,0);}
    else if (anm->frame == 61) anm->frame = 60;
    else if (anm->frame == 91) anm->destroy();
    if (anm->interrupt == 6) {anm->frame = 61; anm->scale_time(30,4,96,0);}
    else if (anm->interrupt == 1) anm->frame = 76;
}
void frontRecP8(AnimScript* anm)
{
    if (anm->frame == 0)
    {
        anm->set_layer(GL_ L25);
        anm->set_blendmode(1);
        anm->special_draw(6);
        anm->set_scale(0,2);
        anm->set_color(64,255,64);
        anm->set_color2(64,255,64);
        anm->set_alpha(0);
        anm->set_alpha2(0);
        anm->set_pos(204,74,0);
        anm->alpha_time(60,0,255);
    }
    else if (anm->frame == 60) {anm->scale_time(30,4,-96,2); anm->pos_time(30,4,156,74,0);}
    else if (anm->frame == 61) anm->frame = 60;
    else if (anm->frame == 91) anm->destroy();
    if (anm->interrupt == 6) {anm->frame = 61; anm->scale_time(30,4,96,0);}
    else if (anm->interrupt == 1) anm->frame = 76;
}
void frontRecP9(AnimScript* anm)
{
    if (anm->frame == 0)
    {
        anm->set_layer(GL_ L25);
        anm->set_blendmode(1);
        anm->special_draw(6);
        anm->set_scale(0,2);
        anm->set_color(255,64,64);
        anm->set_color2(255,64,64);
        anm->set_alpha(0);
        anm->set_alpha2(0);
        anm->set_pos(220,42,0);
        anm->alpha_time(60,0,255);
    }
    else if (anm->frame == 70) {anm->scale_time(30,4,96,2); anm->pos_time(30,4,268,42,0);}
    else if (anm->frame == 71) anm->frame = 70;
    else if (anm->frame == 101) anm->destroy();
    if (anm->interrupt == 6) {anm->frame = 71; anm->scale_time(30,4,96,0);}
    else if (anm->interrupt == 1) anm->frame = 86;
}
void frontRecP10(AnimScript* anm)
{
    if (anm->frame == 0)
    {
        anm->set_layer(GL_ L25);
        anm->set_blendmode(1);
        anm->special_draw(6);
        anm->set_scale(0,2);
        anm->set_color(255,64,64);
        anm->set_color2(255,64,64);
        anm->set_alpha(0);
        anm->set_alpha2(0);
        anm->set_pos(220,42,0);
        anm->alpha_time(60,0,255);
    }
    else if (anm->frame == 70) {anm->scale_time(30,4,-96,2); anm->pos_time(30,4,172,42,0);}
    else if (anm->frame == 71) anm->frame = 70;
    else if (anm->frame == 101) anm->destroy();
    if (anm->interrupt == 6) {anm->frame = 71; anm->scale_time(30,4,96,0);}
    else if (anm->interrupt == 1) anm->frame = 86;
}
void frontRecP11(AnimScript* anm)
{
    if (anm->frame == 0)
    {
        anm->set_layer(GL_ L25);
        anm->set_blendmode(1);
        anm->special_draw(6);
        anm->set_scale(0,2);
        anm->set_color(64,64,255);
        anm->set_color2(64,64,255);
        anm->set_alpha(0);
        anm->set_alpha2(0);
        anm->set_pos(220,20,0);
        anm->alpha_time(60,0,255);
    }
    else if (anm->frame == 80) {anm->scale_time(30,4,96,2); anm->pos_time(30,4,268,20,0);}
    else if (anm->frame == 81) anm->frame = 80;
    else if (anm->frame == 111) anm->destroy();
    if (anm->interrupt == 6) {anm->frame = 81; anm->scale_time(30,4,96,0);}
    else if (anm->interrupt == 1) anm->frame = 96;
}
void frontRecP12(AnimScript* anm)
{
    if (anm->frame == 0)
    {
        anm->set_layer(GL_ L25);
        anm->set_blendmode(1);
        anm->special_draw(6);
        anm->set_scale(0,2);
        anm->set_color(64,64,255);
        anm->set_color2(64,64,255);
        anm->set_alpha(0);
        anm->set_alpha2(0);
        anm->set_pos(220,20,0);
        anm->alpha_time(60,0,255);
    }
    else if (anm->frame == 80) {anm->scale_time(30,4,-96,2); anm->pos_time(30,4,172,20,0);}
    else if (anm->frame == 81) anm->frame = 80;
    else if (anm->frame == 111) anm->destroy();
    if (anm->interrupt == 6) {anm->frame = 81; anm->scale_time(30,4,96,0);}
    else if (anm->interrupt == 1) anm->frame = 96;
}
void frontRecP13(AnimScript* anm)
{
    if (anm->frame == 0)
    {
        anm->set_layer(GL_ L25);
        anm->set_blendmode(1);
        anm->special_draw(6);
        anm->set_scale(0,2);
        anm->set_color(64,64,64);
        anm->set_color2(64,64,64);
        anm->set_alpha(0);
        anm->set_alpha2(0);
        anm->set_pos(220,-2,0);
        anm->alpha_time(60,0,255);
    }
    else if (anm->frame == 90) {anm->scale_time(30,4,96,2); anm->pos_time(30,4,268,-2,0);}
    else if (anm->frame == 91) anm->frame = 90;
    else if (anm->frame == 121) anm->destroy();
    if (anm->interrupt == 6) {anm->frame = 91; anm->scale_time(30,4,96,0);}
    else if (anm->interrupt == 1) anm->frame = 106;
}
void frontRecP14(AnimScript* anm)
{
    if (anm->frame == 0)
    {
        anm->set_layer(GL_ L25);
        anm->set_blendmode(1);
        anm->special_draw(6);
        anm->set_scale(0,2);
        anm->set_color(64,64,64);
        anm->set_color2(64,64,64);
        anm->set_alpha(0);
        anm->set_alpha2(0);
        anm->scroll_x(0);
        anm->set_pos(220,-2,0);
        anm->alpha_time(60,0,255);
    }
    else if (anm->frame == 90) {anm->scale_time(30,4,-96,2); anm->pos_time(30,4,172,-2,0);}
    else if (anm->frame == 91) anm->frame = 90;
    else if (anm->frame == 121) anm->destroy();
    if (anm->interrupt == 6) {anm->frame = 91; anm->scale_time(30,4,96,0);}
    else if (anm->interrupt == 1) anm->frame = 106;
}

void frontHeart(AnimScript* anm)
{
    if (anm->frame == 0)
    {
        anm->set_scale(.5f,.5f);
        anm->set_layer(GL_ L26);
        anm->set_sprite(frt12);
        anm->set_pos(202,134,0);
        anm->set_alpha(0);
    }
    else if (anm->frame == 60) anm->alpha_time(40,0,255);
    else if (anm->frame == 61) anm->frame = 60;
    if (anm->interrupt == 2) {anm->set_sprite(frt17); anm->set_color(255,255,255);}
    else if (anm->interrupt == 3) {anm->set_sprite(frt12); anm->set_color(255,255,255);}
    else if (anm->interrupt == 7) anm->set_sprite(frt12);
    else if (anm->interrupt == 8) {anm->set_sprite(frt13); anm->set_color(128,128,255);}
    else if (anm->interrupt == 9) {anm->set_sprite(frt14); anm->set_color(128,128,255);}
    else if (anm->interrupt == 10) {anm->set_sprite(frt15); anm->set_color(144,144,255);}
    else if (anm->interrupt == 11) {anm->set_sprite(frt16); anm->set_color(160,160,255);}
    else if (anm->interrupt == 12) {anm->set_sprite(frt17); anm->set_color(192,192,255);}
}
void frontSpell(AnimScript* anm)
{
    if (anm->frame == 0)
    {
        anm->set_scale(.5f,.5f);
        anm->set_layer(GL_ L26);
        anm->set_sprite(frt18);
        anm->set_pos(202,96,0);
        anm->set_alpha(0);
    }
    else if (anm->frame == 60) anm->alpha_time(40,0,255);
    else if (anm->frame == 61) anm->frame = 60;
    if (anm->interrupt == 2) {anm->set_sprite(frt23); anm->set_color(255,255,255);}
    else if (anm->interrupt == 3) {anm->set_sprite(frt18); anm->set_color(255,255,255);}
    else if (anm->interrupt == 7) anm->set_sprite(frt18);
    else if (anm->interrupt == 8) {anm->set_sprite(frt19); anm->set_color(128,128,255);}
    else if (anm->interrupt == 9) {anm->set_sprite(frt20); anm->set_color(128,128,255);}
    else if (anm->interrupt == 10) {anm->set_sprite(frt21); anm->set_color(144,144,255);}
    else if (anm->interrupt == 11) {anm->set_sprite(frt22); anm->set_color(160,160,255);}
    else if (anm->interrupt == 12) {anm->set_sprite(frt23); anm->set_color(192,192,255);}
}

void frontSCNumP1(AnimScript* anm)
{
    if (anm->frame == 0)
    {
        anm->set_sprite(frt35);
        anm->set_scale(.5,.5);
        anm->set_layer(GL_ L19);
        anm->set_pos(47,240-4-35,0);    //8nums espaces de 7  puis 2 a +95 et 2 a +116
        anm->set_alpha(0);
    }
    else if (anm->frame == 90) anm->alpha_time(20,0,255);
    else if (anm->frame == 91) anm->frame = 90;
    if (anm->interrupt == 3) anm->alpha_time(8,1,32);
    else if (anm->interrupt == 2) anm->alpha_time(8,1,255);
}
void frontSCNumP2(AnimScript* anm)
{
    if (anm->frame == 0)
    {
        anm->set_sprite(frt45);
        anm->set_scale(.5,.5);
        anm->set_layer(GL_ L19);
        anm->set_pos(156,240-4-35,0);
        anm->set_alpha(0);
    }
    else if (anm->frame == 90) anm->alpha_time(20,0,255);
    else if (anm->frame == 91) anm->frame = 90;
    if (anm->interrupt == 3) anm->alpha_time(8,1,32);
    else if (anm->interrupt == 2) anm->alpha_time(8,1,255);
}
void frontSCFail(AnimScript* anm)
{
    if (anm->frame == 0)
    {
        anm->set_sprite(frt46);
        anm->set_scale(.5,.5);
        anm->set_layer(GL_ L19);
        anm->set_pos(71,240-4-35,0);
        anm->set_alpha(255);
    }
    else if (anm->frame == 1) anm->frame = 0;
    if (anm->interrupt == 3) anm->alpha_time(8,1,32);
    else if (anm->interrupt == 2) anm->alpha_time(8,1,255);
}

void frontSCGetB(AnimScript* anm)
{
    if (anm->frame == 0)
    {
        anm->set_layer(GL_ L22);
        anm->set_sprite(frt48);
        anm->set_pos(0,144,0);
        anm->set_scale(.5,.5);
        anm->set_color(255,255,255);
    }
    else if (anm->frame == 2 || anm->frame == 6 || anm->frame == 10 || anm->frame == 14 || anm->frame == 18 || anm->frame == 22) anm->set_color(128,128,128);
    else if (anm->frame == 4 || anm->frame == 8 || anm->frame == 12 || anm->frame == 16 || anm->frame == 20 || anm->frame == 24) anm->set_color(255,255,255);
    else if (anm->frame == 134) anm->scale_time(20,4,.5,0);
    else if (anm->frame == 154) anm->destroy();
}
void frontSCFailB(AnimScript* anm)
{
    if (anm->frame == 0)
    {
        anm->set_layer(GL_ L22);
        anm->set_sprite(frt49);
        anm->set_pos(0,112,0);
        anm->set_scale(.5,0);
        anm->scale_time(10,4,.5,.5);
    }
    else if (anm->frame == 90) anm->alpha_time(10,0,0);
    else if (anm->frame == 110) anm->destroy();
}

void frontFullPower(AnimScript* anm)
{
    if (anm->frame == 0)
    {
        anm->set_layer(GL_ L22);
        anm->set_sprite(frt50);
        anm->set_pos(0,112,0);
        anm->set_scale(.5,0);
        anm->scale_time(10,4,.5,.5);
    }
    else if (anm->frame == 90) anm->alpha_time(10,0,0);
    else if (anm->frame == 110) anm->destroy();
}
void frontHighScore(AnimScript* anm)
{
    if (anm->frame == 0)
    {
        anm->set_layer(GL_ L22);
        anm->set_sprite(frt51);
        anm->set_pos(0,112,0);
        anm->set_scale(.5,0);
        anm->scale_time(10,4,.5,.5);
    }
    else if (anm->frame == 90) anm->alpha_time(10,0,0);
    else if (anm->frame == 110) anm->destroy();
}
void frontExtend(AnimScript* anm)
{
    if (anm->frame == 0)
    {
        anm->set_layer(GL_ L22);
        anm->set_sprite(frt52);
        anm->set_pos(0,112,0);
        anm->set_scale(.5,0);
        anm->scale_time(10,4,.5,.5);
    }
    else if (anm->frame == 90) anm->alpha_time(10,0,0);
    else if (anm->frame == 110) anm->destroy();
}

void frontILineP1(AnimScript* anm)
{
    if (anm->frame == 0)
    {
        anm->set_layer(GL_ L22);
        anm->set_blendmode(1);
        anm->special_draw(6);
        anm->set_scale(-512+128,0);
        anm->set_color(255,128,0);
        anm->set_color2(255,128,0);
        anm->set_alpha(1);
        anm->set_alpha2(0);
        anm->set_pos(128-32,-32,0);
    }
    else if (anm->frame == 60) { anm->scale_time(10,4,-512+128,4); anm->alpha2_time(10,4,64); }
    else if (anm->frame == 68 || anm->frame == 84 || anm->frame == 100 || anm->frame == 116 || anm->frame == 132 || anm->frame == 148 || anm->frame == 164 || anm->frame == 180) anm->set_color2(255,128,0);
    else if (anm->frame == 76 || anm->frame == 92 || anm->frame == 108 || anm->frame == 124 || anm->frame == 140 || anm->frame == 156 || anm->frame == 172 || anm->frame == 188) anm->set_color2(255,255,255);
    else if (anm->frame == 198) anm->destroy();
    if (anm->frame == 188) {anm->alpha2_time(10,0,0); anm->alpha_time(10,0,0);}
}
void frontILineP2(AnimScript* anm)
{
    if (anm->frame == 0)
    {
        anm->set_layer(GL_ L22);
        anm->set_blendmode(1);
        anm->special_draw(6);
        anm->set_scale(512-128,0);
        anm->set_color(255,128,0);
        anm->set_color2(255,128,0);
        anm->set_alpha(1);
        anm->set_alpha2(0);
        anm->set_pos(-128+32,-32,0);
    }
    else if (anm->frame == 60) { anm->scale_time(10,4,512-128,4); anm->alpha2_time(10,4,64); }
    else if (anm->frame == 68 || anm->frame == 84 || anm->frame == 100 || anm->frame == 116 || anm->frame == 132 || anm->frame == 148 || anm->frame == 164 || anm->frame == 180) anm->set_color2(255,128,0);
    else if (anm->frame == 76 || anm->frame == 92 || anm->frame == 108 || anm->frame == 124 || anm->frame == 140 || anm->frame == 156 || anm->frame == 172 || anm->frame == 188) anm->set_color2(255,255,255);
    else if (anm->frame == 198) anm->destroy();
    if (anm->frame == 188) {anm->alpha2_time(10,0,0); anm->alpha_time(10,0,0);}
} 
void frontILine(AnimScript* anm)
{
    if (anm->frame == 0)
    {
        anm->set_layer(GL_ L22);
        anm->set_blendmode(1);
        anm->set_sprite(frt53);
        anm->create_child(frontILineP1);   
        anm->create_child(frontILineP2);  
        anm->set_pos(0,152,0);
        anm->set_alpha(0);
        anm->set_scale(.5,0);
    }
    else if (anm->frame == 60) { anm->scale_time(10,4,.5,.5); anm->alpha_time(10,4,192); }
    else if (anm->frame == 68 || anm->frame == 84 || anm->frame == 100 || anm->frame == 116 || anm->frame == 132 || anm->frame == 148 || anm->frame == 164 || anm->frame == 180) anm->set_color(255,128,0);
    else if (anm->frame == 76 || anm->frame == 92 || anm->frame == 108 || anm->frame == 124 || anm->frame == 140 || anm->frame == 156 || anm->frame == 172 || anm->frame == 188) anm->set_color(255,255,255);
    else if (anm->frame == 198) anm->destroy();
    if (anm->frame == 188) anm->alpha_time(10,0,0);
}

void frontBossStar(AnimScript* anm)
{
    if (anm->frame == 0 || anm->frame == 31)
    {
        if (anm->frame == 0)
        {
            anm->set_layer(GL_ L22);
            anm->set_sprite(frt47);
            anm->set_pos(-376/2, 224-9,0); //+10 horizontalement
        }
        anm->set_scale(.5,.5);
        anm->set_alpha(0);
    }
    if (anm->frame == 1) anm->frame = 0;
    else if (anm->frame == 60) anm->alpha_time(20,0,255);
    else if (anm->frame == 61) anm->frame = 60;
    else if (anm->frame == 81) anm->destroy();
    if (anm->interrupt == 4) anm->frame = 30;
    else if (anm->interrupt == 3) anm->alpha_time(8,1,32);
    else if (anm->interrupt == 2) anm->alpha_time(8,1,255);
    else if (anm->interrupt == 1) { anm->scale_time(20,4,1,1); anm->alpha_time(20,0,0); anm->frame = 0; }
}

void frontDifficulty1(AnimScript* anm)
{
    if (anm->frame == 0)
    {
        anm->set_layer(GL_ L22);
        anm->set_sprite(frt56);
        anm->set_alpha(0);
        anm->alpha_time(10,0,255);
        anm->set_scale(.5,0);
        anm->scale_time(10,4,.5,.5);
        anm->set_pos(0,218,0);
    }
    else if (anm->frame == 154) anm->scale_time(10,4,.5,0);
    else if (anm->frame == 164) anm->destroy();
    if (anm->frame%8==0&&anm->frame<=64) anm->set_color(255,255,255);
    else if (anm->frame%8==4&&anm->frame<=64) anm->set_color(128,128,128);

}

void frontDifficulty2(AnimScript* anm)
{
    if (anm->frame == 0)
    {
        anm->set_layer(GL_ L26);
        anm->set_sprite(frt56);
        anm->set_pos(208,208,0);
        anm->set_alpha(0);
    }
    else if (anm->frame == 160)
    {
        anm->alpha_time(20,0,255);
        anm->set_scale(.5,0);
        anm->scale_time(10,4,.5,.5);
    }
    else if (anm->frame == 161) anm->frame = 160;
    else if (anm->frame == 169) anm->destroy();
    if (anm->interrupt == 1)
    {
        anm->frame = 161;
        anm->scale_time(10,4,.5,0);
        anm->alpha_time(8,0,0);
    }
}

void frontSCTime(AnimScript* anm)
{
    if (anm->frame == 0)
    {
        anm->set_layer(GL_ L22);
        anm->set_sprite(frt65);
        anm->set_pos(-142+96,88,0);
        anm->set_scale(.5,.5);
        anm->set_alpha(0);
    }
    else if (anm->frame == 30) anm->alpha_time(20,0,255);
    else if (anm->frame == 140) anm->alpha_time(20,0,0);
    else if (anm->frame == 170) anm->destroy();
}

void frontEnemy(AnimScript* anm)
{
    if (anm->frame == 0)
    {
        anm->set_sprite(frt81);
        anm->set_layer(GL_ L29);
        anm->set_scale(.5,.5);
        anm->set_pos(-96,-232,0);
    }
    else if (anm->frame == 1) anm->frame = 0;
    else if (anm->frame == 17 || anm->frame == 28 || anm->frame == 32) { anm->set_color(0,0,0); }
    else if (anm->frame == 19) { anm->frame = 1; anm->set_color(255,255,255); }
    else if (anm->frame == 30) { anm->frame = 19; anm->set_color(255,255,255); }
    else if (anm->frame == 34) { anm->frame = 30; anm->set_color(255,255,255); }
    if (anm->interrupt == 7) anm->frame = 1;
    else if (anm->interrupt == 8) anm->frame = 19;
    else if (anm->interrupt == 9) anm->frame = 30;
    else if (anm->interrupt == 10) { anm->frame = 0; anm->set_color(255,255,255); }
}

void front120(AnimScript* anm)
{
    if (anm->frame == 0)
    {
        anm->set_sprite(frt89);
        anm->set_pos(0,6,0);
        anm->set_layer(GL_ L22);
        anm->set_alpha(0);
    }
    else if (anm->frame == 20) anm->alpha_time(20,0,255);
    else if (anm->frame == 21) anm->frame = 20;
    else if (anm->frame == 81) anm->destroy();
    if (anm->interrupt == 1) { anm->frame = 21; anm->alpha_time(60,0,20); }
}

void front121(AnimScript* anm)
{
    if (anm->frame == 0)
    {
        //////???????////
    }
}

void frontPauseBack1(AnimScript* anm)
{
    if (anm->frame == 0)
    {
        anm->IsGui(true);
        anm->set_sprite(frt107);
        anm->set_pos(-24,-64,0);
        anm->set_scale(.5,.5);
        anm->pos_time(8,4,0,-112,0);
        anm->set_layer(GL_ L25);
        anm->set_color(78,211,172);
        anm->alpha_time(10,0,192);
        anm->set_rot(0,0,0.1308997f);
    }
    else if (anm->frame == 1 || anm->frame == 120) { anm->frame = 1; anm->rot_time(60,9,0,0,0.08181231f);}
    else if (anm->frame == 60) anm->rot_time(60,9,0,0,0.17998707f);
    else if (anm->frame == 129) anm->destroy();
    if (anm->interrupt == 14)
    {
        anm->pos_time(8,4,192,-112,0);
        anm->color_time(8,4,255,32,32);
    }
    else if (anm->interrupt >= 7 && anm->interrupt <= 11)
    {
        anm->alpha_time(10,0,192);
        anm->pos_time(8,4,0,-112,0);
        anm->color_time(8,4,78,211,172);
    }
    else if (anm->interrupt == 1)
    {
        anm->frame = 121;
        anm->pos_time(8,4,-24,-112,0);
        anm->alpha_time(8,0,0);
    }
}

void frontPauseBack2(AnimScript* anm)
{
    if (anm->frame == 0)
    {
        anm->IsGui(true);
        anm->set_sprite(frt107);
        anm->set_pos(-24,-64,0);
        anm->set_scale(.5,.5);
        anm->pos_time(8,4,0,-112,0);
        anm->set_layer(GL_ L25);
        anm->set_color(255,32,32);
        anm->alpha_time(10,0,192);
        anm->set_rot(0,0,0.1308997f);
    }
    else if (anm->frame == 1 || anm->frame == 120) { anm->frame = 1; anm->rot_time(60,9,0,0,0.08181231f);}
    else if (anm->frame == 60) anm->rot_time(60,9,0,0,0.17998707f);
    else if (anm->frame == 129) anm->destroy();
    if (anm->interrupt == 14) anm->pos_time(8,4,192,-112,0);
    else if (anm->interrupt >= 7 && anm->interrupt <= 11)
    {
        anm->alpha_time(10,0,192);
        anm->pos_time(8,4,0,-112,0);
    }
    else if (anm->interrupt == 1)
    {
        anm->frame = 121;
        anm->pos_time(8,4,-24,-112,0);
        anm->alpha_time(8,0,0);
    }
}

void frontPauseTitle12(AnimScript* anm)
{
    if (anm->frame == 0)
    {
        anm->IsGui(true);
        anm->set_sprite(frt103);
        anm->set_scale(.5,.5);
        anm->set_layer(GL_ L29);
        anm->set_alpha(0);
        anm->alpha_time(8,4,255);
        anm->set_pos(0,0,0);
        anm->pos_time(8,4,0,-12,0);
    } else if (anm->frame == 1) anm->frame = 0;
    else if (anm->frame == 11) anm->destroy();
    if (anm->interrupt == 2) anm->pos_time(8,4,0,-12,0);
    else if (anm->interrupt == 14)
    {
        anm->color_time(10,0,32,32,32);
        anm->alpha_time(10,0,128);
    }
    else if (anm->interrupt >=7 && anm->interrupt <= 11)
    {
        anm->alpha_time(10,0,255);
        anm->color_time(10,0,255,255,255);
    }
    else if (anm->interrupt == 1)
    {
        anm->pos_time(8,4,0,0,0);
        anm->alpha_time(8,0,0);
        anm->frame = 1;
    }
}

void frontPauseOption1(AnimScript* anm)
{
    if (anm->frame == 0)
    {
        anm->IsGui(true);
        anm->set_scale(.5,.5);
        anm->set_sprite(frt91);
        anm->set_pos(24,-64,0);
        anm->set_layer(GL_ L30);
        anm->set_alpha(0);
        anm->set_color(64,64,64);
        anm->x_time(8,4,-8);
    } else if (anm->frame == 1) anm->frame = 0;
    else if (anm->frame == 3) anm->x_time(2,4,-12);
    else if (anm->frame == 5) anm->x_time(2,4,-8);
    else if (anm->frame == 7) anm->x_time(2,4,-12);
    else if (anm->frame == 8 || anm->frame == 88) { anm->frame = 8; anm->color_time(40,9,255,128,128);}
    else if (anm->frame == 48) anm->color_time(40,9,255,255,255);
    else if (anm->frame == 98) anm->destroy();
    else if (anm->frame > 98)
    {
        if (anm->frame == 138) anm->frame = 0;
        else if (anm->frame % 4 == 0) anm->set_color(255,255,255);
        else if (anm->frame % 2 == 0) anm->set_color(64,64,64);
    }
    if (anm->interrupt == 7)
    {
        anm->set_color(255,192,192);
        anm->alpha_time(5,4,255);
        anm->x_time(2,4,-8);
        anm->frame = 1;
    }
    else if (anm->interrupt == 17)
    {
        anm->frame = 7;
        anm->x_time(4,4,-8);
        anm->alpha_time(5,4,255);
    }
    else if (anm->interrupt == 3)
    {
        anm->x_time(5,4,-8);
        anm->alpha_time(5,4,255);
        anm->color_time(5,9,96,96,96);
        anm->frame = 0;
    }
    else if (anm->interrupt == 4)
    {
        anm->alpha_time(10,0,255);   
    }
    else if (anm->interrupt == 5)
    {
        anm->alpha_time(10,0,64);   
    }
    else if (anm->interrupt == 6)
    {
        anm->color_time(1,0,64,64,64);
        anm->frame = 98;
    }
    else if (anm->interrupt == 1)
    {
        anm->x_time(10,4,24);
        anm->alpha_time(10,0,0);
        anm->frame = 88;
    }
    else if (anm->interrupt >= 14 && anm->interrupt <= 16)
    {
        anm->frame = 0; anm->alpha_time(10,0,64);
    }
}

void frontPauseTitle3(AnimScript* anm)
{
    if (anm->frame == 0)
    {
        anm->IsGui(true);
        anm->set_sprite(frt100);
        anm->set_pos(160,-48,0);
        anm->set_scale(.5,.5);
        anm->set_alpha(0);
        anm->alpha_time(8,4,255);
        anm->pos_time(8,4,160,-60,0);
        anm->set_layer(GL_ L29);
    } else if (anm->frame == 1) anm->frame = 0;
    else if (anm->frame == 9) anm->destroy();
    if (anm->interrupt == 1 || (anm->interrupt >=7 && anm->interrupt <= 11))
    {
        anm->frame = 1;
        anm->pos_time(8,4,160,-48,0);
        anm->alpha_time(8,0,0);
    }
}

void frontPauseOption2(AnimScript* anm)
{
    if (anm->frame == 0)
    {
        anm->IsGui(true);
        anm->set_scale(.5,.5);
        anm->set_sprite(frt91);
        anm->set_pos(216,-98,0);
        anm->set_layer(GL_ L30);
        anm->set_alpha(0);
        anm->set_color(64,64,64);
        anm->x_time(8,4,184);
    } else if (anm->frame == 1) anm->frame = 0;
    else if (anm->frame == 3) anm->x_time(2,4,184);
    else if (anm->frame == 5) anm->x_time(2,4,177);
    else if (anm->frame == 7) anm->x_time(2,4,180);
    else if (anm->frame == 8 || anm->frame == 88) { anm->frame = 8; anm->color_time(40,9,255,128,128);}
    else if (anm->frame == 48) anm->color_time(40,9,255,255,255);
    else if (anm->frame == 98) anm->destroy();
    else if (anm->frame > 98)
    {
        if (anm->frame == 138) anm->frame = 0;
        else if (anm->frame % 4 == 0) anm->set_color(255,255,255);
        else if (anm->frame % 2 == 0) anm->set_color(64,64,64);
    }
    if (anm->interrupt == 7)
    {
        anm->set_color(255,192,192);
        anm->alpha_time(5,4,255);
        anm->x_time(2,4,180);
        anm->frame = 1;
    }
    else if (anm->interrupt == 17)
    {
        anm->frame = 7;
        anm->x_time(4,4,184);
        anm->alpha_time(5,4,255);
    }
    else if (anm->interrupt == 3)
    {
        anm->x_time(5,4,184);
        anm->alpha_time(5,4,255);
        anm->color_time(5,9,96,96,96);
        anm->frame = 0;
    }
    else if (anm->interrupt == 6)
    {
        anm->color_time(1,0,64,64,64);
        anm->frame = 98;
    }
    else if (anm->interrupt == 1)
    {
        anm->x_time(10,4,216);
        anm->alpha_time(10,0,0);
        anm->frame = 88;
    }
}

void frontLifebarP1(AnimScript* anm)
{
    if (anm->frame == 0)
    {
        anm->set_layer(GL_ L22);
        anm->set_sprite(frt148);
        anm->special_draw(1);
        anm->set_pos(0,0,38);
        anm->set_scale(4,56);
        anm->set_rot(1,PI2,PI1_2);
    }
    else if (anm->frame == 1) anm->frame = 0;
    else if (anm->frame == 21) anm->destroy();
    if (anm->interrupt == 3)
        anm->alpha_time(10,0,64);
    else if (anm->interrupt == 2)
        anm->alpha_time(10,0,255);
    else if (anm->interrupt == 1)
    {
        anm->alpha_time(20,0,0);
        anm->frame = 1;
    }
}

void frontLifebarP2(AnimScript* anm)
{
    if (anm->frame == 0)
    {
        anm->set_layer(GL_ L22);
        anm->set_sprite(frt149);
        anm->special_draw(1);
        anm->set_pos(0,0,38);
        anm->set_scale(1,58);
        anm->set_rot(1,PI2,PI1_2);
    }
    else if (anm->frame == 1) anm->frame = 0;
    else if (anm->frame == 21) anm->destroy();
    if (anm->interrupt == 3)
        anm->alpha_time(10,0,64);
    else if (anm->interrupt == 2)
        anm->alpha_time(10,0,255);
    else if (anm->interrupt == 1)
    {
        anm->alpha_time(20,0,0);
        anm->frame = 1;
    }
}

void frontLifebarP3(AnimScript* anm)
{
    if (anm->frame == 0)
    {
        anm->set_layer(GL_ L22);
        anm->set_sprite(frt149);
        anm->special_draw(1);
        anm->set_pos(0,0,38);
        anm->set_scale(1,54);
        anm->set_rot(1,PI2,PI1_2);
    }
    else if (anm->frame == 1) anm->frame = 0;
    else if (anm->frame == 21) anm->destroy();
    if (anm->interrupt == 3)
        anm->alpha_time(10,0,64);
    else if (anm->interrupt == 2)
        anm->alpha_time(10,0,255);
    else if (anm->interrupt == 1)
    {
        anm->alpha_time(20,0,0);
        anm->frame = 1;
    }
}

void frontLifebarP4(AnimScript* anm)
{
    if (anm->frame == 0)
    {
        anm->set_pos(0,56,0);
        anm->set_scale(.5,.5);
        anm->set_layer(GL_ L23);
        anm->set_sprite(frt150);
    }
    else if (anm->frame == 1) anm->frame = 0;
    else if (anm->frame == 21) anm->destroy();
    if (anm->interrupt == 3) anm->alpha_time(10,0,64);
    else if (anm->interrupt == 2) anm->alpha_time(10,0,255);
    else if (anm->interrupt == 1)
    {
        anm->alpha_time(20,0,0);
        anm->frame = 1;
    }
}
