#include "AnmEnemy.h"
#include <NSEngine.h>

namespace enm {

    int s0;
    int s1;
    int s2;
    int s3;
    int s4;
    int s5;
    int s6;
    int s7;
    int s8;
    int s9;
    int s10;
    int s11;
    int s12;
    int s13;
    int s14;
    int s15;
    int s16;
    int s17;
    int s18;
    int s19;
    int s20;
    int s21;
    int s22;
    int s23;
    int s24;
    int s25;
    int s26;
    int s27;
    int s28;
    int s29;
    int s30;
    int s31;
    int s32;
    int s33;
    int s34;
    int s35;
    int s36;
    int s37;
    int s38;
    int s39;
    int s40;
    int s41;
    int s42;
    int s43;
    int s44;
    int s45;
    int s46;
    int s47;
    int s48;
    int s49;
    int s50;
    int s51;
    int s52;
    int s53;
    int s54;
    int s55;
    int s56;
    int s57;
    int s58;
    int s59;
    int s60;
    int s61;
    int s62;
    int s63;
    int s64;
    int s65;
    int s66;
    int s67;
    int s68;
    int s69;
    int s70;
    int s71;
    int s72;
    int s73;
    int s74;
    int s75;
    int s76;
    int s77;
    int s78;
    int s79;
    int s80;
    int s81;
    int s82;
    int s83;
    int s84;
    int s85;
    int s86;
    int s87;
    int s88;
    int s89;
    int s90;
    int s91;
    int s92;
    int s93;
    int s94;
    int s95;
    int s96;
    int s97;
    int s98;
    int s99;
    int s100;
    int s101;
    int s102;
    int s103;
    int s104;
    int s105;
    int s106;
    int s107;
    int s108;
    int s109;
    int s110;
    int s111;
    int s112;
    int s113;
    int s114;
    int s115;
    int s116;
    int s117;
    int s118;
    int s119;
    int s120;
    int s121;
    int s122;
    int s123;
    int s124;
    int s125;
    int s126;
    int s127;
    int s128;
    int s129;
    int s130;
    int s131;
    int s132;
    int s133;
    int s134;
    int s135;
    int s136;
    int s137;
    int s138;
    int s139;
    int s140;
    int s141;
    int s142;
    int s143;
    int s144;
    int s145;
    int s146;
    int s147;
    int s148;
    int s149;
    int s150;
    int s151;
    int s152;
    int s153;
    int s154;
    int s155;
    int s156;
    int s157;
    int s158;
    int s159;
    int s160;
    int s161;
    int s162;
    int s163;
    int s164;
    int s165;
    int s166;
    int s167;
    int s168;
    int s169;
    int s170;
    int s171;
    int s172;
    int s173;
    int s174;
    int s175;
    int s176;
    int s177;
    int s178;
    int s179;
    int s180;
    int s181;
    int s182;
    int s183;
    int s184;
    int s185;
    int s186;
    int s187;
    int s188;
    int s189;
    int s190;
    int s191;
    int s192;
    int s193;
    int s194;
    int s195;
    int s196;
    int s197;
    int s198;
    int s199;
    int s200;
    int s201;
    int s202;
    int s203;
    int s204;
    int s205;
    int s206;
    int s207;
    int s208;
    int s209;
    int s210;
    int s211;
    int s212;
    int s213;
    int s214;
    int s215;
    int s216;
    int s217;
    int s218;
    int s219;
}

void AnmEnemy::Init()
{
    int t = NSEngine::TextureManager::RegisterTexture("assets/textures/ennemy/enemy.png");

    enm::s0  = GS_ AddSprite(t,  0,320,32,32);
    enm::s1  = GS_ AddSprite(t, 32,320,32,32);
    enm::s2  = GS_ AddSprite(t, 64,320,32,32);
    enm::s3  = GS_ AddSprite(t, 96,320,32,32);
    enm::s4  = GS_ AddSprite(t,128,320,32,32);
    enm::s5  = GS_ AddSprite(t,160,320,32,32);
    enm::s6  = GS_ AddSprite(t,192,320,32,32);
    enm::s7  = GS_ AddSprite(t,224,320,32,32);
    enm::s8  = GS_ AddSprite(t,256,320,32,32);
    enm::s9  = GS_ AddSprite(t,288,320,32,32);
    enm::s10 = GS_ AddSprite(t,320,320,32,32);
    enm::s11 = GS_ AddSprite(t,352,320,32,32);
    enm::s12 = GS_ AddSprite(t,  0,352,32,32);
    enm::s13 = GS_ AddSprite(t, 32,352,32,32);
    enm::s14 = GS_ AddSprite(t, 64,352,32,32);
    enm::s15 = GS_ AddSprite(t, 96,352,32,32);
    enm::s16 = GS_ AddSprite(t,128,352,32,32);
    enm::s17 = GS_ AddSprite(t,160,352,32,32);
    enm::s18 = GS_ AddSprite(t,192,352,32,32);
    enm::s19 = GS_ AddSprite(t,224,352,32,32);
    enm::s20 = GS_ AddSprite(t,256,352,32,32);
    enm::s21 = GS_ AddSprite(t,288,352,32,32);
    enm::s22 = GS_ AddSprite(t,320,352,32,32);
    enm::s23 = GS_ AddSprite(t,352,352,32,32);
    enm::s24 = GS_ AddSprite(t,  0,384,32,32);
    enm::s25 = GS_ AddSprite(t, 32,384,32,32);
    enm::s26 = GS_ AddSprite(t, 64,384,32,32);
    enm::s27 = GS_ AddSprite(t, 96,384,32,32);
    enm::s28 = GS_ AddSprite(t,128,384,32,32);
    enm::s29 = GS_ AddSprite(t,160,384,32,32);
    enm::s30 = GS_ AddSprite(t,192,384,32,32);
    enm::s31 = GS_ AddSprite(t,224,384,32,32);
    enm::s32 = GS_ AddSprite(t,256,384,32,32);
    enm::s33 = GS_ AddSprite(t,288,384,32,32);
    enm::s34 = GS_ AddSprite(t,320,384,32,32);
    enm::s35 = GS_ AddSprite(t,352,384,32,32);
    enm::s36 = GS_ AddSprite(t,  0,416,32,32);
    enm::s37 = GS_ AddSprite(t, 32,416,32,32);
    enm::s38 = GS_ AddSprite(t, 64,416,32,32);
    enm::s39 = GS_ AddSprite(t, 96,416,32,32);
    enm::s40 = GS_ AddSprite(t,128,416,32,32);
    enm::s41 = GS_ AddSprite(t,160,416,32,32);
    enm::s42 = GS_ AddSprite(t,192,416,32,32);
    enm::s43 = GS_ AddSprite(t,224,416,32,32);
    enm::s44 = GS_ AddSprite(t,256,416,32,32);
    enm::s45 = GS_ AddSprite(t,288,416,32,32);
    enm::s46 = GS_ AddSprite(t,320,416,32,32);
    enm::s47 = GS_ AddSprite(t,352,416,32,32);
    enm::s48 = GS_ AddSprite(t,  0,  0,48,32);
    enm::s49 = GS_ AddSprite(t, 48,  0,48,32);
    enm::s50 = GS_ AddSprite(t, 96,  0,48,32);
    enm::s51 = GS_ AddSprite(t,144,  0,48,32);
    enm::s52 = GS_ AddSprite(t,  0, 32,48,32);
    enm::s53 = GS_ AddSprite(t, 48, 32,48,32);
    enm::s54 = GS_ AddSprite(t, 96, 32,48,32);
    enm::s55 = GS_ AddSprite(t,144, 32,48,32);
    enm::s56 = GS_ AddSprite(t,  0, 64,48,32);
    enm::s57 = GS_ AddSprite(t, 48, 64,48,32);
    enm::s58 = GS_ AddSprite(t, 96, 64,48,32);
    enm::s59 = GS_ AddSprite(t,144, 64,48,32);
    enm::s60 = GS_ AddSprite(t,  0, 96,48,32);
    enm::s61 = GS_ AddSprite(t, 48, 96,48,32);
    enm::s62 = GS_ AddSprite(t, 96, 96,48,32);
    enm::s63 = GS_ AddSprite(t,144, 96,48,32);
    enm::s64 = GS_ AddSprite(t,  0,128,48,32);
    enm::s65 = GS_ AddSprite(t, 48,128,48,32);
    enm::s66 = GS_ AddSprite(t, 96,128,48,32);
    enm::s67 = GS_ AddSprite(t,144,128,48,32);
    enm::s68 = GS_ AddSprite(t,  0,160,48,32);
    enm::s69 = GS_ AddSprite(t, 48,160,48,32);
    enm::s70 = GS_ AddSprite(t, 96,160,48,32);
    enm::s71 = GS_ AddSprite(t,144,160,48,32);
    enm::s72 = GS_ AddSprite(t,320,  0,48,48);
    enm::s73 = GS_ AddSprite(t,368,  0,48,48);
    enm::s74 = GS_ AddSprite(t,416,  0,48,48);
    enm::s75 = GS_ AddSprite(t,464,  0,48,48);
    enm::s76 = GS_ AddSprite(t,320, 48,48,48);
    enm::s77 = GS_ AddSprite(t,368, 48,48,48);
    enm::s78 = GS_ AddSprite(t,416, 48,48,48);
    enm::s79 = GS_ AddSprite(t,464, 48,48,48);
    enm::s80 = GS_ AddSprite(t,320, 96,48,48);
    enm::s81 = GS_ AddSprite(t,368, 96,48,48);
    enm::s82 = GS_ AddSprite(t,416, 96,48,48);
    enm::s83 = GS_ AddSprite(t,464, 96,48,48);
    enm::s84 = GS_ AddSprite(t,320,144,48,48);
    enm::s85 = GS_ AddSprite(t,368,144,48,48);
    enm::s86 = GS_ AddSprite(t,416,144,48,48);
    enm::s87 = GS_ AddSprite(t,464,144,48,48);
    enm::s88 = GS_ AddSprite(t,320,192,48,48);
    enm::s89 = GS_ AddSprite(t,368,192,48,48);
    enm::s90 = GS_ AddSprite(t,416,192,48,48);
    enm::s91 = GS_ AddSprite(t,464,192,48,48);
    enm::s92 = GS_ AddSprite(t,320,240,48,48);
    enm::s93 = GS_ AddSprite(t,368,240,48,48);
    enm::s94 = GS_ AddSprite(t,416,240,48,48);
    enm::s95 = GS_ AddSprite(t,464,240,48,48);
    enm::s96 = GS_ AddSprite(t,  0,448,64,64);
    enm::s97 = GS_ AddSprite(t, 64,448,64,64);
    enm::s98 = GS_ AddSprite(t,128,448,64,64);
    enm::s99 = GS_ AddSprite(t,192,448,64,64);
    enm::s100= GS_ AddSprite(t,256,448,64,64);
    enm::s101= GS_ AddSprite(t,320,448,64,64);
    enm::s102= GS_ AddSprite(t,384,448,64,64);
    enm::s103= GS_ AddSprite(t,448,448,64,64);
    enm::s104= GS_ AddSprite(t,384,320,64,64);
    enm::s105= GS_ AddSprite(t,448,320,64,64);
    enm::s106= GS_ AddSprite(t,384,384,64,64);
    enm::s107= GS_ AddSprite(t,448,384,64,64);
    enm::s108= GS_ AddSprite(t,  0,288,32,32);
    enm::s109= GS_ AddSprite(t, 32,288,32,32);
    enm::s110= GS_ AddSprite(t, 64,288,32,32);
    enm::s111= GS_ AddSprite(t, 96,288,32,32);
    enm::s112= GS_ AddSprite(t,128,256,32,32);
    enm::s113= GS_ AddSprite(t,160,256,32,32);
    enm::s114= GS_ AddSprite(t,192,256,32,32);
    enm::s115= GS_ AddSprite(t,224,256,32,32);
    enm::s116= GS_ AddSprite(t,128,288,32,32);
    enm::s117= GS_ AddSprite(t,160,288,32,32);
    enm::s118= GS_ AddSprite(t,192,288,32,32);
    enm::s119= GS_ AddSprite(t,224,288,32,32);

    t = NSEngine::TextureManager::RegisterTexture("assets/textures/ennemy/enemy2.png");

    enm::s120= GS_ AddSprite(t,  0,  0,32,32);
    enm::s121= GS_ AddSprite(t, 32,  0,32,32);
    enm::s122= GS_ AddSprite(t, 64,  0,32,32);
    enm::s123= GS_ AddSprite(t, 96,  0,32,32);
    enm::s124= GS_ AddSprite(t,128,  0,32,32);
    enm::s125= GS_ AddSprite(t,160,  0,32,32);
    enm::s126= GS_ AddSprite(t,192,  0,32,32);
    enm::s127= GS_ AddSprite(t,224,  0,32,32);
    enm::s128= GS_ AddSprite(t,  0, 32,32,32);
    enm::s129= GS_ AddSprite(t, 32, 32,32,32);
    enm::s130= GS_ AddSprite(t, 64, 32,32,32);
    enm::s131= GS_ AddSprite(t, 96, 32,32,32);
    enm::s132= GS_ AddSprite(t,128, 32,32,32);
    enm::s133= GS_ AddSprite(t,160, 32,32,32);
    enm::s134= GS_ AddSprite(t,192, 32,32,32);
    enm::s135= GS_ AddSprite(t,224, 32,32,32);
    enm::s136= GS_ AddSprite(t,  0, 64,32,32);
    enm::s137= GS_ AddSprite(t, 32, 64,32,32);
    enm::s138= GS_ AddSprite(t, 64, 64,32,32);
    enm::s139= GS_ AddSprite(t, 96, 64,32,32);
    enm::s140= GS_ AddSprite(t,128, 64,32,32);
    enm::s141= GS_ AddSprite(t,160, 64,32,32);
    enm::s142= GS_ AddSprite(t,192, 64,32,32);
    enm::s143= GS_ AddSprite(t,224, 64,32,32);
    enm::s144= GS_ AddSprite(t,  0, 96,32,32);
    enm::s145= GS_ AddSprite(t, 32, 96,32,32);
    enm::s146= GS_ AddSprite(t, 64, 96,32,32);
    enm::s147= GS_ AddSprite(t, 96, 96,32,32);
    enm::s148= GS_ AddSprite(t,128, 96,32,32);
    enm::s149= GS_ AddSprite(t,160, 96,32,32);
    enm::s150= GS_ AddSprite(t,192, 96,32,32);
    enm::s151= GS_ AddSprite(t,224, 96,32,32);

    t = NSEngine::TextureManager::RegisterTexture("assets/textures/ennemy/enemy_aura.png");

    enm::s152= GS_ AddSprite(t,  0,  0,48,48);
    enm::s153= GS_ AddSprite(t, 48,  0,48,48);
    enm::s154= GS_ AddSprite(t, 96,  0,48,48);
    enm::s155= GS_ AddSprite(t,144,  0,48,48);
    enm::s156= GS_ AddSprite(t,192,  0,48,48);
    enm::s157= GS_ AddSprite(t,240,  0,48,48);
    enm::s158= GS_ AddSprite(t,288,  0,48,48);
    enm::s159= GS_ AddSprite(t,336,  0,48,48);

    t = NSEngine::TextureManager::RegisterTexture("assets/textures/ennemy/enemy5.png");

    enm::s160= GS_ AddSprite(t,  0,  0,32,32);
    enm::s161= GS_ AddSprite(t, 32,  0,32,32);
    enm::s162= GS_ AddSprite(t, 64,  0,32,32);
    enm::s163= GS_ AddSprite(t, 96,  0,32,32);
    enm::s164= GS_ AddSprite(t,128,  0,32,32);
    enm::s165= GS_ AddSprite(t,160,  0,32,32);
    enm::s166= GS_ AddSprite(t,192,  0,32,32);
    enm::s167= GS_ AddSprite(t,224,  0,32,32);
    enm::s168= GS_ AddSprite(t,256,  0,32,32);
    enm::s169= GS_ AddSprite(t,288,  0,32,32);
    enm::s170= GS_ AddSprite(t,320,  0,32,32);
    enm::s171= GS_ AddSprite(t,352,  0,32,32);
    enm::s172= GS_ AddSprite(t,  0, 32,32,32);
    enm::s173= GS_ AddSprite(t, 32, 32,32,32);
    enm::s174= GS_ AddSprite(t, 64, 32,32,32);
    enm::s175= GS_ AddSprite(t, 96, 32,32,32);
    enm::s176= GS_ AddSprite(t,128, 32,32,32);
    enm::s177= GS_ AddSprite(t,160, 32,32,32);
    enm::s178= GS_ AddSprite(t,192, 32,32,32);
    enm::s179= GS_ AddSprite(t,224, 32,32,32);
    enm::s180= GS_ AddSprite(t,256, 32,32,32);
    enm::s181= GS_ AddSprite(t,288, 32,32,32);
    enm::s182= GS_ AddSprite(t,320, 32,32,32);
    enm::s183= GS_ AddSprite(t,352, 32,32,32);
    enm::s184= GS_ AddSprite(t,  0, 64,32,32);
    enm::s185= GS_ AddSprite(t, 32, 64,32,32);
    enm::s186= GS_ AddSprite(t, 64, 64,32,32);
    enm::s187= GS_ AddSprite(t, 96, 64,32,32);
    enm::s188= GS_ AddSprite(t,128, 64,32,32);
    enm::s189= GS_ AddSprite(t,160, 64,32,32);
    enm::s190= GS_ AddSprite(t,192, 64,32,32);
    enm::s191= GS_ AddSprite(t,224, 64,32,32);
    enm::s192= GS_ AddSprite(t,256, 64,32,32);
    enm::s193= GS_ AddSprite(t,288, 64,32,32);
    enm::s194= GS_ AddSprite(t,320, 64,32,32);
    enm::s195= GS_ AddSprite(t,352, 64,32,32);
    enm::s196= GS_ AddSprite(t,  0, 96,32,32);
    enm::s197= GS_ AddSprite(t, 32, 96,32,32);
    enm::s198= GS_ AddSprite(t, 64, 96,32,32);
    enm::s199= GS_ AddSprite(t, 96, 96,32,32);
    enm::s200= GS_ AddSprite(t,128, 96,32,32);
    enm::s201= GS_ AddSprite(t,160, 96,32,32);
    enm::s202= GS_ AddSprite(t,192, 96,32,32);
    enm::s203= GS_ AddSprite(t,224, 96,32,32);
    enm::s204= GS_ AddSprite(t,256, 96,32,32);
    enm::s205= GS_ AddSprite(t,288, 96,32,32);
    enm::s206= GS_ AddSprite(t,320, 96,32,32);
    enm::s207= GS_ AddSprite(t,352, 96,32,32);
    enm::s208= GS_ AddSprite(t,  0,128,64,64);
    enm::s209= GS_ AddSprite(t, 64,128,64,64);
    enm::s210= GS_ AddSprite(t,128,128,64,64);
    enm::s211= GS_ AddSprite(t,192,128,64,64);
    enm::s212= GS_ AddSprite(t,256,128,64,64);
    enm::s213= GS_ AddSprite(t,320,128,64,64);
    enm::s214= GS_ AddSprite(t,384,128,64,64);
    enm::s215= GS_ AddSprite(t,448,128,64,64);
    enm::s216= GS_ AddSprite(t,384,  0,64,64);
    enm::s217= GS_ AddSprite(t,448,  0,64,64);
    enm::s218= GS_ AddSprite(t,384, 64,64,64);
    enm::s219= GS_ AddSprite(t,448, 64,64,64);
}

void Enm0p1(AnimScript* anm)
{
    if (anm->frame == 0)
    {
        anm->set_layer(GL_ L8);
        anm->set_sprite(enm::s0);
    }
    else if (anm->frame == 5) anm->offset_sprite(1);
    else if (anm->frame == 10) anm->offset_sprite(1);
    else if (anm->frame == 15) anm->offset_sprite(1);
    else if (anm->frame == 20) { anm->offset_sprite(-3); anm->frame = 0; }
}
void Enm0p2(AnimScript* anm)
{
    if (anm->frame == 0)
    {
        anm->flip_x();
        anm->set_layer(GL_ L8);
        anm->set_sprite(enm::s4);
    }
    else if (anm->frame == 4) anm->offset_sprite(1);
    else if (anm->frame == 8) anm->offset_sprite(1);
    else if (anm->frame == 12) anm->offset_sprite(1);
    else if (anm->frame == 17) anm->offset_sprite(1);
    else if (anm->frame == 22) anm->offset_sprite(1);
    else if (anm->frame == 27) anm->offset_sprite(1);
    else if (anm->frame == 32) anm->offset_sprite(1);
    else if (anm->frame == 35) { anm->offset_sprite(-3); anm->frame = 17; }
}
void Enm0p3(AnimScript* anm)
{
    if (anm->frame == 0)
    {
        anm->set_layer(GL_ L8);
        anm->set_sprite(enm::s4);
    }
    else if (anm->frame == 4) anm->offset_sprite(1);
    else if (anm->frame == 8) anm->offset_sprite(1);
    else if (anm->frame == 12) anm->offset_sprite(1);
    else if (anm->frame == 17) anm->offset_sprite(1);
    else if (anm->frame == 22) anm->offset_sprite(1);
    else if (anm->frame == 27) anm->offset_sprite(1);
    else if (anm->frame == 32) anm->offset_sprite(1);
    else if (anm->frame == 35) { anm->offset_sprite(-3); anm->frame = 17; }
}
void Enm0p4(AnimScript* anm)
{
    if (anm->frame == 0)
    {
        anm->flip_x();
        anm->set_layer(GL_ L8);
        anm->set_sprite(enm::s7);
    }
    else if (anm->frame == 4) anm->offset_sprite(-1);
    else if (anm->frame == 8) anm->offset_sprite(-1);
    else if (anm->frame == 12) anm->offset_sprite(-1);
    else if (anm->frame == 17) anm->offset_sprite(-4);
    else if (anm->frame == 22) anm->offset_sprite(1);
    else if (anm->frame == 27) anm->offset_sprite(1);
    else if (anm->frame == 32) anm->offset_sprite(1);
    else if (anm->frame == 37) { anm->offset_sprite(-3); anm->frame = 17; }
}
void Enm0p5(AnimScript* anm)
{
    if (anm->frame == 0)
    {
        anm->set_layer(GL_ L8);
        anm->set_sprite(enm::s7);
    }
    else if (anm->frame == 4) anm->offset_sprite(-1);
    else if (anm->frame == 8) anm->offset_sprite(-1);
    else if (anm->frame == 12) anm->offset_sprite(-1);
    else if (anm->frame == 17) anm->offset_sprite(-4);
    else if (anm->frame == 22) anm->offset_sprite(1);
    else if (anm->frame == 27) anm->offset_sprite(1);
    else if (anm->frame == 32) anm->offset_sprite(1);
    else if (anm->frame == 37) { anm->offset_sprite(-3); anm->frame = 17; }
}

void EnmB(AnimScript* anm)
{
    if (anm->frame == 0 || anm->frame == 40)
    {
        if (anm->frame == 0)
        {
            anm->set_layer(GL_ L7);
            anm->set_sprite(enm::s108);
            anm->set_blendmode(1);
            anm->rot_vel(0,0,PI/10.f);
            anm->set_alpha(128);
            anm->set_scale(0,0);
        }
        anm->frame = 0;
        anm->scale_time(20,9,1.4f,1.4f);
    }
    else if (anm->frame == 20) anm->scale_time(20,9,1,1);
}
void EnmBfade(AnimScript* anm)
{
    if (anm->frame == 0)
    {
        anm->set_layer(GL_ L7);
        anm->set_sprite(enm::s108);
        anm->set_blendmode(1);
        anm->rot_vel(0,0,PI/10.f);
        anm->set_alpha(0);
        anm->alpha_time(76,0,192);
        anm->set_scale(4,4);
        anm->scale_time(76,0,1,1);
    }
    else if (anm->frame == 76 || anm->frame == 116) { anm->frame = 76; anm->scale_time(20,9,1.4f,1.4f); }
    else if (anm->frame == 20) anm->scale_time(20,9,1,1);
}

int Enm1(int offset, bool fade)
{
    int i = AnmManager::newAnim(fade?Enm1Fp1:Enm1p1,-1,1);
    AnmManager::anim(i)->offset_sprite(offset);
    int i1 = AnmManager::anim(i)->create_child(Enm1p2,1); AnmManager::anim(i1)->offset_sprite(offset);
    int i2 = AnmManager::anim(i)->create_child(Enm1p3,1); AnmManager::anim(i2)->offset_sprite(offset);
    return i;
}

void Enm1p1(AnimScript* anm)
{
    if (anm->frame == 0)
    {
        anm->set_layer(GL_ L8);
        anm->set_sprite(enm::s112);
        anm->colorizeChildren(1);
    }
    else anm->frame = 0;
}
void Enm1p2(AnimScript* anm)
{
    if (anm->frame == 0)
    {
        anm->set_layer(GL_ L9);
        anm->set_sprite(enm::s116);
        anm->rot_vel(0,0,-0.19634955f);
    }
    else anm->frame = 0;
}
void Enm1p3(AnimScript* anm)
{
    if (anm->frame == 0)
    {
        anm->set_layer(GL_ L9);
        anm->set_sprite(enm::s116);
        anm->rot_vel(0,0,0.09817477f);
        anm->set_blendmode(1);
        anm->set_scale(1.5,1.5);
    }
    else anm->frame = 0;
}
void Enm1Fp1(AnimScript* anm)
{
    if (anm->frame == 0)
    {
        anm->set_layer(GL_ L8);
        anm->set_sprite(enm::s112);
        anm->colorizeChildren(1);
        anm->set_color(32,32,32);
        anm->color_time(90,0,128,128,128);
        anm->set_scale(.2f,.2f);
        anm->scale_time(90,1,1,1);
    }
    else if (anm->frame == 90) anm->set_color(255,255,255);
    else if (anm->frame == 91) anm->frame = 90;
}

#include <math/Random.h>

void Enm2PU(AnimScript* anm)
{
    if (anm->frame == 0)
    {
        anm->set_layer(GL_ L9);
        anm->set_blendmode(1);
        anm->set_sprite(enm::s120 + rand()%8);
        anm->set_pos(Random::Floatm11()*8.f,-Random::Float01()*8.f+4,0);
        anm->pos_time(10,0,Random::Floatm11()*8.f,Random::Float01()*16.f+16,0);
        anm->set_scale(.5,.5);
        anm->scale_time(10,1,0,0);
    }
    else if (anm->frame == 10) anm->destroy();
}
void Enm2PD(AnimScript* anm)
{
    if (anm->frame == 0)
    {
        anm->set_layer(GL_ L9);
        anm->set_blendmode(1);
        anm->set_sprite(enm::s120 + rand()%8);
        anm->set_pos(Random::Floatm11()*8.f,-Random::Float01()*8.f+4,0);
        anm->pos_time(10,0,Random::Floatm11()*8.f,-Random::Float01()*16.f-16,0);
        anm->set_scale(.5,.5);
        anm->scale_time(10,1,0,0);
    }
    else if (anm->frame == 10) anm->destroy();
}

void Enm2U(AnimScript* anm)
{
    if (anm->frame == 0)
    {
        anm->set_layer(GL_ L9);
        anm->set_scale(0,0);
        anm->scale_time(6,4,2,2);
        anm->set_sprite(enm::s120);
    }
    else if (anm->frame == 3) anm->offset_sprite(1);
    else if (anm->frame == 6) 
    {
        anm->offset_sprite(1);
        anm->scale_time(6,1,1,1);
    }
    else if (anm->frame == 9) anm->offset_sprite(1);
    else if (anm->frame == 12) anm->offset_sprite(-3);
    else if (anm->frame == 15) anm->offset_sprite(1);
    else if (anm->frame == 18) anm->offset_sprite(1);
    else if (anm->frame == 21) anm->offset_sprite(1);
    else if (anm->frame == 24) anm->offset_sprite(1);
    else if (anm->frame == 27) anm->offset_sprite(1);
    else if (anm->frame == 30) anm->offset_sprite(1);
    else if (anm->frame == 33) anm->offset_sprite(1);
    else if (anm->frame == 36) { anm->frame = 12; anm->offset_sprite(-7);}
    if (anm->frame >= 12)
    {
        int offset = anm->spr_()-enm::s120;
        AnmManager::anim(anm->create_child(Enm2PU,1))->offset_sprite(offset);
    }
}
void Enm2D(AnimScript* anm)
{
    if (anm->frame == 0)
    {
        anm->set_layer(GL_ L9);
        anm->set_scale(0,0);
        anm->scale_time(6,4,2,2);
        anm->set_sprite(enm::s120);
    }
    else if (anm->frame == 3) anm->offset_sprite(1);
    else if (anm->frame == 6) 
    {
        anm->offset_sprite(1);
        anm->scale_time(6,1,1,1);
    }
    else if (anm->frame == 9) anm->offset_sprite(1);
    else if (anm->frame == 12) anm->offset_sprite(-3);
    else if (anm->frame == 15) anm->offset_sprite(1);
    else if (anm->frame == 18) anm->offset_sprite(1);
    else if (anm->frame == 21) anm->offset_sprite(1);
    else if (anm->frame == 24) anm->offset_sprite(1);
    else if (anm->frame == 27) anm->offset_sprite(1);
    else if (anm->frame == 30) anm->offset_sprite(1);
    else if (anm->frame == 33) anm->offset_sprite(1);
    else if (anm->frame == 36) { anm->frame = 12; anm->offset_sprite(-7);}
    if (anm->frame >= 12)
    {
        int offset = anm->spr_()-enm::s120;
        AnmManager::anim(anm->create_child(Enm2PD,1))->offset_sprite(offset);
    }
}

int EnmAura(float size, int coltype, int r, int g, int b)
{
    int i = AnmManager::newAnim(EnmAuraP1);
    AnmManager::anim(i)->set_scale(size,size);
    if (coltype&1)
    {
        int c = AnmManager::anim(i)->create_child(EnmAuraP2);
        AnmManager::anim(c)->set_color(255-r,255-g,255-b);
    }
    if (coltype&2)
    {
        int c = AnmManager::anim(i)->create_child(EnmAuraP3);
        AnmManager::anim(c)->set_color(r,g,b);
    }
    return i;
}

void EnmAuraP1(AnimScript* anm)
{
    if (anm->frame == 0)
    {
        anm->visible(false);
        anm->set_pos(0,8,0);
    }
}
void EnmAuraP2(AnimScript* anm)
{
    if (anm->frame == 0 || anm->frame == 40)
    {
        if (anm->frame == 0)
        {
            anm->set_layer(GL_ L6);
            anm->set_blendmode(2);
            anm->set_scale(1.1f,1.1f);
        }
        anm->set_sprite(enm::s152);
        anm->frame = 0;
    }
    else if (anm->frame == 5) anm->set_sprite(enm::s153);
    else if (anm->frame == 10) anm->set_sprite(enm::s154);
    else if (anm->frame == 15) anm->set_sprite(enm::s155);
    else if (anm->frame == 20) anm->set_sprite(enm::s156);
    else if (anm->frame == 25) anm->set_sprite(enm::s157);
    else if (anm->frame == 30) anm->set_sprite(enm::s158);
    else if (anm->frame == 35) anm->set_sprite(enm::s159);
}
void EnmAuraP3(AnimScript* anm)
{
    if (anm->frame == 0 || anm->frame == 40)
    {
        if (anm->frame == 0)
        {
            anm->set_layer(GL_ L6);
            anm->set_blendmode(1);
        }
        anm->set_sprite(enm::s152);
        anm->frame = 0;
    }
    else if (anm->frame == 5) anm->set_sprite(enm::s153);
    else if (anm->frame == 10) anm->set_sprite(enm::s154);
    else if (anm->frame == 15) anm->set_sprite(enm::s155);
    else if (anm->frame == 20) anm->set_sprite(enm::s156);
    else if (anm->frame == 25) anm->set_sprite(enm::s157);
    else if (anm->frame == 30) anm->set_sprite(enm::s158);
    else if (anm->frame == 35) anm->set_sprite(enm::s159);
}
