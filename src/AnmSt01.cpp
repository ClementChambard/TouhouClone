#include "AnmSt01.h"
#include <TextureManager.h>
#include <math/math.h>
int sspr0;
int sspr1;
int sspr2;
int sspr3;

int espr0;
int espr1;
int espr2;
int espr3;
int espr4;
int espr5;
int espr6;
int espr7;
int espr8;
int espr9;
int espr10;
int espr11;
int espr12;
int espr13;
int espr14;
int espr15;
int espr16;
int espr17;
int espr18;
int espr19;
int espr20;
int espr21;
int espr22;
int espr34;
int espr35;
int espr36;
int espr39;

int lspr0;
int lspr1;
int lspr2;
int lspr3;

void AnmSt01::Init()
{
    int tex_sta = NSEngine::TextureManager::RegisterTexture("assets/textures/background/st01a.png");
    int tex_stc = NSEngine::TextureManager::RegisterTexture("assets/textures/background/st01c.png");
    int tex_stb = NSEngine::TextureManager::RegisterTexture("assets/textures/background/st01b.png");
    sspr0 = GS_ AddSprite(tex_sta,0,0,1024,512);
    sspr1 = GS_ AddSprite(tex_stb,0,0,1022,416);
    sspr2 = GS_ AddSprite(tex_stb,256,0,1022,416);
    sspr3 = GS_ AddSprite(tex_stc,0,0,640,416);
 
    int tex_enm01 = NSEngine::TextureManager::RegisterTexture("assets/textures/ennemy/enm1.png");
    espr0 = GS_ AddSprite(tex_enm01,0,0,80,96);
    espr1 = GS_ AddSprite(tex_enm01,80,0,80,96);
    espr2 = GS_ AddSprite(tex_enm01,160,0,80,96);
    espr3 = GS_ AddSprite(tex_enm01,240,0,80,96);
    espr4 = GS_ AddSprite(tex_enm01,320,0,80,96);
    espr5 = GS_ AddSprite(tex_enm01,400,0,80,96);
    espr6 = GS_ AddSprite(tex_enm01,0,96,80,96);
    espr7 = GS_ AddSprite(tex_enm01,80,96,80,96);
    espr8 = GS_ AddSprite(tex_enm01,160,96,80,96);
    espr9 = GS_ AddSprite(tex_enm01,240,96,80,96);
    espr10 = GS_ AddSprite(tex_enm01,320,96,80,96);
    espr11 = GS_ AddSprite(tex_enm01,400,96,80,96);
    espr12 = GS_ AddSprite(tex_enm01,0,192,80,96);
    espr13 = GS_ AddSprite(tex_enm01,80,192,80,96);
    espr14 = GS_ AddSprite(tex_enm01,160,192,80,96);
    espr15 = GS_ AddSprite(tex_enm01,240,192,80,96);
    espr16 = GS_ AddSprite(tex_enm01,320,192,80,96);
    espr17 = GS_ AddSprite(tex_enm01,400,192,80,96);

    int tex_cdbg0 = NSEngine::TextureManager::RegisterTexture("assets/textures/background/cardbg0.png");
    int tex_cdbg1 = NSEngine::TextureManager::RegisterTexture("assets/textures/background/cardbg1.png");
    int tex_faceCt = NSEngine::TextureManager::RegisterTexture("assets/textures/face/face01ct.png");
    espr34 = GS_ AddSprite(tex_cdbg0,0,0,384,448);
    espr35 = GS_ AddSprite(tex_cdbg0,64,128,384,448);
    espr36 = GS_ AddSprite(tex_cdbg1,64,128,384,448);
    espr39 = GS_ AddSprite(tex_faceCt,0,0,401,448);
    
    int tex_logo = NSEngine::TextureManager::RegisterTexture("assets/textures/front/logo/st01logo.png");
    lspr0 = GS_ AddSprite(tex_logo,0,0,512,64);
    lspr1 = GS_ AddSprite(tex_logo,0,64,288,48);
    lspr2 = GS_ AddSprite(tex_logo,0,112,144,144);
    lspr3 = GS_ AddSprite(tex_logo,256,112,256,32);

}

void st01a(AnimScript* anm)
{
    if (anm->frame == 0)
    {
        anm->set_layer(GL_ L1);
        anm->set_sprite(sspr0);
        anm->set_rot(PI,0.f,0.f);
        anm->set_alpha(255);
    }
}

void st01b1(AnimScript* anm)
{
    if (anm->frame == 0)
    {
        anm->set_layer(GL_ L3);
        anm->set_sprite(sspr1);
        anm->set_rot(0,0,0.2268928f);
        anm->set_pos(-60.0f, 160.0f, 0.0f);
        anm->scroll_x(-0.00018f);
        anm->set_alpha(0);
    }
    else if (anm->frame == 650) anm->alpha_time(50,0,255);
    else if (anm->frame == 710 || anm->interrupt == 8)
    {
        anm->set_alpha(255);
        anm->alpha_time(1,0,255);
    }
}

void st01b2(AnimScript* anm)
{
    if (anm->frame == 0)
    {
        anm->set_layer(GL_ L3);
        anm->set_sprite(sspr2);
        anm->set_rot(0,0,0.2268928f);
        anm->set_pos(-60.0f, 160.0f, 0.0f);
        anm->scroll_x(-0.00005f);
        anm->set_scale(0.9f,0.9f);
        anm->set_alpha(0);
    }
    else if (anm->frame == 650) anm->alpha_time(50,0,64);
    else if (anm->frame == 710 || anm->interrupt == 8)
    {
        anm->set_alpha(64);
        anm->alpha_time(1,0,64);
    }
}

void st01c(AnimScript* anm)
{
    if (anm->frame == 0)
    {
        anm->set_layer(GL_ L3);
        anm->set_sprite(sspr3);
        anm->set_rot(0,0,0.2268928f);
        anm->set_pos(-60.0f, 160.0f, 0.0f);
        anm->set_alpha(0);
    }
    else if (anm->frame == 650) anm->alpha_time(50,0,255);
    else if (anm->frame == 710 || anm->interrupt == 8)
    {
        anm->set_alpha(255);
        anm->alpha_time(1,0,255);
    }
}

void st01E1(AnimScript* anm)
{
    if (anm->frame == 0 || anm->frame == 140)
    {
        if (anm->frame == 0)
            anm->set_layer(GL_ L7);
        anm->frame = 0;
        anm->pos_time(70, 9, 0, -2, 0);
        anm->set_sprite(espr0);
    }
    else if (anm->frame == 35 || anm->frame == 105) anm->set_sprite(espr0);
    else if (anm->frame == 7 || anm->frame == 42 || anm->frame == 77 || anm->frame == 112) anm->set_sprite(espr1);
    else if (anm->frame == 14 || anm->frame == 49 || anm->frame == 84 || anm->frame == 119) anm->set_sprite(espr2);
    else if (anm->frame == 21 || anm->frame == 56 || anm->frame == 91 || anm->frame == 126) anm->set_sprite(espr3);
    else if (anm->frame == 63 || anm->frame == 98 || anm->frame == 133) anm->set_sprite(espr4);
    else if (anm->frame == 28) anm->set_sprite(espr5);
    else if (anm->frame == 70) 
    { 
        anm->set_sprite(espr0); 
        anm->pos_time(70,9,0,2,0); 
    }
}

void st01E2(AnimScript* anm)
{
    if (anm->frame == 0)
    {
        anm->flip_x();
        anm->set_layer(GL_ L7);
        anm->set_sprite(espr6);
    }
    else if (anm->frame == 6) anm->set_sprite(espr7);
    else if (anm->frame == 12) anm->set_sprite(espr8);
    else if (anm->frame == 18) anm->set_sprite(espr9);
    else if (anm->frame == 24) anm->set_sprite(espr10);
    else if (anm->frame == 30) anm->set_sprite(espr11);
    else if (anm->frame == 31) anm->frame = 7;
}

void st01E3(AnimScript* anm)
{
    if (anm->frame == 0)
    {
        anm->set_layer(GL_ L7);
        anm->set_sprite(espr6);
    }
    else if (anm->frame == 6) anm->set_sprite(espr7);
    else if (anm->frame == 12) anm->set_sprite(espr8);
    else if (anm->frame == 18) anm->set_sprite(espr9);
    else if (anm->frame == 24) anm->set_sprite(espr10);
    else if (anm->frame == 30) anm->set_sprite(espr11);
    else if (anm->frame == 31) anm->frame = 7;
}

void st01E4(AnimScript* anm)
{
    if (anm->frame == 0)
    {
        anm->flip_x();
        anm->set_layer(GL_ L7);
        anm->set_sprite(espr7);
    }
    if (anm->frame == 8) anm->set_sprite(espr6);
    if (anm->frame == 16)
    {
        anm->SetScript(st01E1);
        anm->frame = -1;
    }
}

void st01E5(AnimScript* anm)
{
    if (anm->frame == 0)
    {
        anm->set_layer(GL_ L7);
        anm->set_sprite(espr7);
    }
    if (anm->frame == 8) anm->set_sprite(espr6);
    if (anm->frame == 16) 
    {
        anm->SetScript(st01E1);
        anm->frame = -1;
    }
}

void st01E6(AnimScript* anm)
{
    if (anm->frame == 0 || anm->frame == 140)
    {
        if (anm->frame == 0)
            anm->set_layer(GL_ L7);
        anm->frame = 0;
        anm->pos_time(70, 9, 0, -2, 0);
        anm->set_sprite(espr12);
    }
    else if (anm->frame == 35 || anm->frame == 105) anm->set_sprite(espr12);
    else if (anm->frame == 7 || anm->frame == 42 || anm->frame == 77 || anm->frame == 112) anm->set_sprite(espr13);
    else if (anm->frame == 14 || anm->frame == 49 || anm->frame == 84 || anm->frame == 119) anm->set_sprite(espr14);
    else if (anm->frame == 21 || anm->frame == 56 || anm->frame == 91 || anm->frame == 126) anm->set_sprite(espr15);
    else if (anm->frame == 63 || anm->frame == 98 || anm->frame == 133) anm->set_sprite(espr16);
    else if (anm->frame == 28) anm->set_sprite(espr17);
    else if (anm->frame == 70) 
    { 
        anm->set_sprite(espr12); 
        anm->pos_time(70,9,0,2,0); 
    }
}

void st01CT(AnimScript* anm)
{
    if (anm->frame == 0)
    {
        anm->visible(false);
        anm->create_child(st01CTP1);
        anm->create_child(st01CTP4);
        anm->create_child(st01CTP3);
        anm->create_child(st01CTP2);
        anm->create_child(st01EFCT);
    }
    else if (anm->frame == 1) anm->frame = 0;
}

void st01CTP1(AnimScript* anm)
{
    if (anm->frame == 0)
    {
        anm->set_sprite(espr34);
        anm->set_layer(GL_ L4);
        anm->set_pos(0,-224,0);
        anm->set_alpha(0);
        anm->alpha_time(60,0,192);
        anm->set_color(64,128,64);
        anm->scroll_y(-0.00083333335f);
    }
    else if (anm->frame == 1) anm->frame = 0;
}

void st01CTP2(AnimScript* anm)
{
    if (anm->frame == 0)
    {
        anm->set_layer(GL_ L4);
        anm->set_sprite(espr34);
        anm->set_pos(0,-224,0);
        anm->set_alpha(0);
        anm->alpha_time(60,0,255);
        anm->set_color(128,32,96);
        anm->scroll_y(-0.0016666667f);
        anm->set_blendmode(2);
    }
    else if (anm->frame == 1) anm->frame = 0;
}

void st01CTP3(AnimScript* anm)
{
    if (anm->frame == 0)
    {
        anm->set_layer(GL_ L4);
        anm->set_sprite(espr36);
        anm->set_pos(0,-224,0);
        anm->set_alpha(0);
        anm->alpha_time(60,0,128);
        anm->scroll_x(0.0016666667f);
        anm->scroll_y(0.0016666667f);
    }
    else if (anm->frame == 1) anm->frame = 0;
}

void st01CTP4(AnimScript* anm)
{
    if (anm->frame == 0)
    {
        anm->set_layer(GL_ L4);
        anm->set_sprite(espr36);
        anm->set_pos(0,-224,0);
        anm->set_alpha(0);
        anm->alpha_time(60,0,128);
        anm->scroll_x(0.0049751243f);
        anm->scroll_y(0.003322259f);
        anm->set_blendmode(2);
    }
    else if (anm->frame == 1) anm->frame = 0;
}

void st01EFCT(AnimScript* anm)
{
    if (anm->frame == 0)
    {
        anm->set_layer(GL_ L6);
        anm->set_sprite(espr39);
        anm->set_pos(420,92-224,0);
        anm->set_color(0,0,0);
        anm->color_time(30,0,255,255,255);
        anm->pos_time(30,0,36,-4-224,0);
    }
    else if (anm->frame == 30) anm->pos_time(90,0,4,-20-224,0);
    else if (anm->frame == 120)
    {
        anm->pos_time(30,0,-380,-180-224,0);
        anm->color_time(30,0,0,0,0);
    }
    else if (anm->frame == 150) anm->destroy();
}

void st01Logo(AnimScript* anm)
{
    if (anm->frame == 0)
    {
        anm->visible(false);
        anm->set_pos(0,112,0);
        anm->set_scale(.5,.5);
        anm->create_child(st01LogoP2);
        anm->create_child(st01LogoP1);
        anm->create_child(st01LogoP3);
        anm->create_child(st01LogoP4);
    }
    else if (anm->frame == 480) anm->destroy();
}

void st01LogoP1(AnimScript* anm)
{
    if (anm->frame == 0)
    {
        anm->set_layer(GL_ L23);
        anm->set_sprite(lspr0);
        anm->set_pos(0,0,0);
        anm->set_alpha(0);
    }
    else if (anm->frame == 60)
        anm->alpha_time(50,0,255);
    else if (anm->frame == 320)
        anm->alpha_time(60,0,0);
    else if (anm->frame == 380)
        anm->destroy();
}
void st01LogoP2(AnimScript* anm)
{
    if (anm->frame == 0)
    {
        anm->set_layer(GL_ L23);
        anm->set_sprite(lspr2);
        anm->set_rot(PI,0,PI);
        anm->rot_time(230,4,0,0,0);
        anm->set_color(0,0,0);
        anm->color_time(230,4,255,255,255);
        anm->set_pos(0,-32,0);
        anm->pos_time(230,4,100,-32,0);
        anm->set_alpha(0);
        anm->alpha_time(60,0,255);
    }
    else if (anm->frame == 320)
        anm->alpha_time(60,0,0);
    else if (anm->frame == 380)
        anm->destroy();
}
void st01LogoP3(AnimScript* anm)
{
    if (anm->frame == 0)
    {
        anm->set_layer(GL_ L23);
        anm->set_sprite(lspr1);
        anm->set_pos(96,-50,0);
        anm->set_alpha(0);
    }
    else if (anm->frame == 180)
        anm->alpha_time(50,0,255);
    else if (anm->frame == 320)
        anm->alpha_time(60,0,0);
    else if (anm->frame == 380)
        anm->destroy();
}
void st01LogoP4(AnimScript* anm)
{
    if (anm->frame == 0)
    {
        anm->set_layer(GL_ L23);
        anm->set_sprite(lspr3);
        anm->set_pos(0,48,0);
        anm->set_alpha(0);
    }
    else if (anm->frame == 20)
        anm->alpha_time(60,0,255);
    else if (anm->frame == 320)
        anm->alpha_time(60,0,0);
    else if (anm->frame == 380)
        anm->destroy();
}
