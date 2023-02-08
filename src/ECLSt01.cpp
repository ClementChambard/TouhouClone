#include "ECLSt01.h"
#include "AnmSt01.h"
#include "ECLMacros.h"
#include "AnmEnemy.h"

namespace ST01
{

    ECLSUB(GirlA01_at)
    {
        NewBulletHandler(bh)
        {
            bh = Bul_ AddHandler();
            Bul_ etAim(bh,0);
            Bul_ etSprite(bh,4,6);
            Bul_ etCount(bh,1,1);
            Bul_ etAngle(bh,0,0);
            Bul_ etSpeed(bh,d4(1.5,1.5,3,4),1);
            Bul_ etEx(bh,0,2,1,0,0,0,0,0,0,0);
        }

        if (subframe > d4(90,90,20,0))
        {
            fFrame(d4(120,120,60,60))
                ECLRETURN;
            mModFrame(d4(30,30,20,12))
                Bul_ etOn(bh, Enm_ pos.x, Enm_ pos.y);
            eFrame
        }
    }

    ECLSUB(GirlA01)
    {
        fFrame(1)
            Enm_ setHitbox(16);
            Enm_ setHurtbox(24);
            Enm_ setSpeed(-1.5707964f+Random::Floatm11()*0.34906584f,1);
        mFrame(30)
            ITP_ (&Enm_ speed.y, Enm_ speed.y, d2(-3.f, -4.f), 0, 120, false);
            if (Ecl_ difficulty > 1) Sub_ Async(GirlA01_at);
        eFrame

        CheckLimitsDelete
        if (Enm_ life <= 0) 
        {
            Enm_ Die();
            Sub_ Delete();
            ECLRETURN;
        }
    }

    ECLSUB(GirlRedA01)
    {
        fFrame(0)
            Enm_ dieAnim = 0b00000001;
            Enm_ baseItemDrop = 0;
            subanm = new THAnim(Enm0p1,Enm0p2,Enm0p4,Enm0p3,Enm0p5);
            subanm->Offset(12);
            Sub_ changeSub(GirlA01);
        eFrame
    }

    ECLSUB(GirlBlueA01)
    {
        fFrame(0)
            Enm_ dieAnim = 0b00000010;
            Enm_ baseItemDrop = 1;
            subanm = new THAnim(Enm0p1,Enm0p2,Enm0p4,Enm0p3,Enm0p5);
            Sub_ changeSub(GirlA01);
        eFrame
    }

    ECLSUB(GirlB01_at)
    {
        NewBulletHandler(bh)
        {
            bh = Bul_ AddHandler();
            Bul_ etAim(bh,0);
            Bul_ etSprite(bh,6,6);
            Bul_ etCount(bh,d4(1,1,3,3),1);
            Bul_ etAngle(bh,0,0.05235988f);
            Bul_ etSpeed(bh,d4(1.2f,1.8f,3.2f,4.2f),1);
            Bul_ etEx(bh,0,2,1,0,0,0,0,0,0,0);
            Bul_ etEx(bh,0,1,0,0,0,0,0,0,0,0);
        }

        fFrame(120)
            Bul_ etOn(bh,Enm_ pos.x, Enm_ pos.y);
        mFrame(140)
            Bul_ etOn(bh,Enm_ pos.x, Enm_ pos.y);
            if (Ecl_ difficulty < 3) ECLRETURN;
        mFrame(160)
            Bul_ etOn(bh,Enm_ pos.x, Enm_ pos.y);
        mFrame(180)
            Bul_ etOn(bh,Enm_ pos.x, Enm_ pos.y);
        mFrame(200)
            Bul_ etOn(bh,Enm_ pos.x, Enm_ pos.y);
            ECLRETURN;
        eFrame
    }

    ECLSUB(GirlB01)
    {
        fFrame(0)
            Enm_ anm0 = new THAnim(Enm0p1,Enm0p2,Enm0p4,Enm0p3,Enm0p5);
            Enm_ anm0->Offset(48);
            Enm_ anmSlots.push_back(EnmAura(1,3,255,64,64));
            Enm_ baseItemDrop = 1;
            Enm_ BonusDrop(1,2);
            Enm_ BonusDrop(0,2);
            Enm_ DropAera(24);
            Enm_ dieAnim = 0b00000010;
            Enm_ setHitbox(24);
            Enm_ setHurtbox(32);
            Enm_ setSpeed(-PI1_2,4.3f);
            Enm_ SpeedTime(80,4,-PI1_2,0);
            if (Ecl_ difficulty > 0) Sub_ Async(GirlB01_at);
        mFrame(80)
            float a = math::point_direction(Enm_ pos.x, Enm_ pos.y, Ple_ x, Ple_ y);
            Enm_ setSpeed(a,0);
            Enm_ SpeedTime(80,1,a,1);
        eFrame

        CheckLimitsDelete
        if (Enm_ life <= 0)
        {
            Enm_ Die();
            Sub_ Delete();
            ECLRETURN;
        }
    }

    ECLSUB(GirlA02_at)
    {
        NewBulletHandler(bh)
        {
            bh = Bul_ AddHandler();
            Bul_ etAim(bh,0);
            Bul_ etSprite(bh,4,6);
            Bul_ etCount(bh,1,1);
            Bul_ etAngle(bh,0,0.05235988f);
            Bul_ etSpeed(bh,d4(1.5,1.5,2,3),1);
            Bul_ etEx(bh,0,2,1,0,0,0,0,0,0,0);
        }

        fFrame(0)
            VAR(0) = rand()%(d4(180,180,180,30))+30;
        mFrame(VAR(0))
            Bul_ etOn(bh, Enm_ pos.x, Enm_ pos.y);
            if (Ecl_ difficulty < 2) ECLRETURN;
            Wait(d4(30,30,20,10));
        mFrame(VAR(0)+1)
            Bul_ etOn(bh, Enm_ pos.x, Enm_ pos.y);
            Wait(d4(30,30,20,10));
        mFrame(VAR(0)+2)
            Bul_ etOn(bh, Enm_ pos.x, Enm_ pos.y);
            Wait(d4(30,30,20,10));
        mFrame(VAR(0)+3)
            Bul_ etOn(bh, Enm_ pos.x, Enm_ pos.y);
            ECLRETURN;
        eFrame
    }

    ECLSUB(GirlA02)
    {
        fFrame(1)
            ECLVARS(1);
            Enm_ setHitbox(16);
            Enm_ setHurtbox(24);
            Enm_ setSpeed(-PI1_2,3);
        mFrame(30)
            if (Ecl_ difficulty > 1) Sub_ Async(GirlA02_at);
            Enm_ SpeedTime(30,0,0,2);
        mFrame(150)
            Enm_ SpeedTime(30,0,-PI1_2,2);
        mFrame(180)
            Enm_ SpeedTime(30,0,PI,2);
        mFrame(240)
            Enm_ SpeedTime(60,0,PI,3);
        eFrame

        CheckLimitsDelete
        if (Enm_ life <= 0)
        {
            Enm_ Die();
            Sub_ Delete();
            ECLRETURN;
        }
    }

    ECLSUB(GirlRedA02)
    {
        fFrame(0)
            Enm_ anm0 = new THAnim(Enm0p1,Enm0p2,Enm0p4,Enm0p3,Enm0p5);
            Enm_ anm0->Offset(12);
            Enm_ baseItemDrop = 1;
            Enm_ dieAnim = 0b00000001;
            Sub_ changeSub(GirlA02);
        eFrame
    }

    ECLSUB(GirlBlueA02)
    {
        fFrame(0)
            Enm_ anm0 = new THAnim(Enm0p1,Enm0p2,Enm0p4,Enm0p3,Enm0p5);
            Enm_ baseItemDrop = 0;
            Enm_ dieAnim = 0b00000010;
            Sub_ changeSub(GirlA02);
        eFrame
    }

    ECLSUB(GirlA03)
    {
        fFrame(1)
            Enm_ setHitbox(16);
            Enm_ setHurtbox(24);
            Enm_ setSpeed(-PI1_2+Random::Floatm11()*0.34906584f,1);
        mFrame(30);
            ITP_ (&Enm_ speed.y, Enm_ speed.y, -2.8f, 0, 60, false);
        eFrame

        CheckLimitsDelete
        if (Enm_ life <= 0)
        {
            Enm_ Die();
            Sub_ Delete();
            ECLRETURN;
        }
    }

    ECLSUB(GirlRedA03)
    {
        fFrame(0)
            Enm_ anm0 = new THAnim(Enm0p1,Enm0p2,Enm0p4,Enm0p3,Enm0p5);
            Enm_ anm0->Offset(12);
            Enm_ baseItemDrop = 1;
            Enm_ dieAnim = 0b00000001;
            Sub_ changeSub(GirlA03);
        eFrame
    }

    ECLSUB(GirlBlueA03)
    {
        fFrame(0)
            Enm_ anm0 = new THAnim(Enm0p1,Enm0p2,Enm0p4,Enm0p3,Enm0p5);
            Enm_ baseItemDrop = 0;
            Enm_ dieAnim = 0b00000010;
            Sub_ changeSub(GirlA03);
        eFrame
    }

    ECLSUB(GirlC01_at)
    {
        NewBulletHandler(bh)
        {
            bh = Bul_ AddHandler();
            Bul_ etAim(bh,1);
            Bul_ etSprite(bh,8,6);
            Bul_ etCount(bh,d4(1,3,3,5),d4(1,2,3,4));
            Bul_ etAngle(bh, -PI1_2, 0.7853982f);
            Bul_ etSpeed(bh,d4(1.3,1.6,2.6,3.6),1);
            Bul_ etEx(bh,0,2,1,0,0,0,0,0,0,0);
        }
 
        fFrame(0)
        mFrame(d4(120,180,240,180)) ECLRETURN;
        mModFrame(d4(60,60,60,30)) Bul_ etOn(bh, Enm_ pos.x, Enm_ pos.y);
        eFrame

    }

    ECLSUB(GirlC01)
    {
        fFrame(0)
            Enm_ dieAnim = 0b00000101;
            Enm_ anm0 = new THAnim(Enm0p1,Enm0p2,Enm0p4,Enm0p3,Enm0p5);
            Enm_ anm0->Offset(84);
            Enm_ anmSlots.push_back(EnmAura(1,3,255,64,64));
            Enm_ baseItemDrop = 1;
            Enm_ BonusDrop(1,2);
            Enm_ BonusDrop(0,2);
            Enm_ setHitbox(24);
            Enm_ setHurtbox(32);
            if (Enm_ pos.x > 0.f) Enm_ mirror = true;
            Enm_ setSpeed(-PI1_2,2);
            Enm_ SpeedTime(80,1,-1.3744467f,0.5f);
            Sub_ Async(GirlC01_at);
        eFrame

        CheckLimitsDelete
        if (Enm_ life <= 0.f)
        {
            Enm_ Die();
            Sub_ Delete();
            ECLRETURN;
        }
    }

    ECLSUB(Phantom01_at)
    {
        NewBulletHandler(bh)
        {
            bh = Bul_ AddHandler();
            Bul_ etAim(bh,1);
            Bul_ etSprite(bh,5,4);
            Bul_ etCount(bh,d4(1,1,2,1),d4(1,1,1,4));
            Bul_ etSpeed(bh,d4(1,0.01,1,4),1);
            //Bul_ etSound(bh,gameassets::se_tan00,-1);
            Bul_ etEx(bh,0,2,1,0,0,0,0,0,0,0);
            Bul_ etEx(bh,0,8,80,0,0,0,d2(0.0125,0.0375),0,0,0);
            Bul_ etEx(bh,0,EX_ACCEL_F,40,0,0,0,0.1,0,0,0);
        }

        fFrame(0)
        mFrame(d4(60,600,400,300)) ECLRETURN;
        mModFrame(d4(60,60,40,30))
            Bul_ etAngle(bh,math::point_direction(0,0,Enm_ speed.x,Enm_ speed.y),0.17453292f);
            Bul_ etOn(bh, Enm_ pos.x, Enm_ pos.y);
        eFrame
    }

    ECLSUB(Phantom01)
    {
        fFrame(0)
            Enm_ anmSlots.push_back(Anm_ newAnim(Enm2U,-1,1));
            Anm_ anim(Enm_ anmSlots[0])->offset_sprite(16);
            //Snd_ PlaySound(gameassets::se_boon00);
            Enm_ setHurtbox(28);
            Enm_ setHitbox(16);
            Enm_ baseItemDrop = 1;
            Enm_ dieAnim = 0b00000010;
            float f0 = Sub_ vars==nullptr?-PI1_2:VAR(0);
            Enm_ setSpeed(f0,0);
            Enm_ SpeedTime(60,3,f0,2);
            //ellipse ???
            Sub_ Async(Phantom01_at);
        eFrame

        CheckLimitsDelete
        if (Enm_ life <= 0)
        {
            Enm_ Die();
            Sub_ Delete();
            ECLRETURN;
        }
    }

    ECLSUB(Cir00_at)
    {
        static int fram;

        NewBulletHandler(bh)
        {
            fram = d4(rand()%200,rand()%200,rand()%10,rand()%10);
            bh = Bul_ AddHandler();
            Bul_ etAim(bh, 0);
            Bul_ etSprite(bh,5,4);
            Bul_ etCount(bh,1,d4(1,1,1,2));
            Bul_ etAngle(bh,0,0);
            Bul_ etSpeed(bh,d4(1,1,3,4),1);
            //Bul_ etSound(bh,gameassets::se_tan00,-1);
            Bul_ etEx(bh,0,2,1,0,0,0,0,0,0,0);
        }

        if (subframe >= fram)
        {
        fFrame(fram+40*(d4(1,1,2,3)))
            ECLRETURN;
        mModFrame(40)
            Bul_ etOn(bh,Enm_ pos.x, Enm_ pos.y);
        eFrame
        }
    }

    ECLSUB(Cir00)
    {
        fFrame(0)
            Enm_ dieAnim = 0b00000100;
            Enm_ baseItemDrop = 1;
            Enm_ setHurtbox(28);
            Enm_ setHitbox(16);
            Enm_ setSpeed(-2.7488935f + (0.17453292f*Random::Floatm11()), 3.f);
            Enm_ anmSlots.push_back(Enm1(1,0));
            if (Ecl_ difficulty != 0) Sub_ Async(Cir00_at);
        eFrame

        CheckLimitsDelete
        if (Enm_ life <= 0)
        {
            Enm_ Die();
            Sub_ Delete();
            ECLRETURN;
        }
    }

    ECLSUB(GirlC02_at)
    {
        NewBulletHandler(bh)
        {
            bh = Bul_ AddHandler();
            Bul_ etAim(bh,0);
            Bul_ etSprite(bh,8,6);
            Bul_ etCount(bh,1,d2(4,8));
            Bul_ etAngle(bh, 0, 0.7853982f);
            Bul_ etSpeed(bh,d4(1.6,2.6,3.4,2.6),1);
            Bul_ etEx(bh,0,2,1,0,0,0,0,0,0,0);
        }

        if (subframe > 60)
        {
            fFrame(d4(120,300,420,300))
                ECLRETURN;
            mModFrame(d4(60,120,90,20))
                Bul_ etOn(bh, Enm_ pos.x, Enm_ pos.y);
            eFrame
        }
    }

    ECLSUB(GirlC02)
    {
        fFrame(0)
            subanm = new THAnim(Enm0p1,Enm0p2,Enm0p4,Enm0p3,Enm0p5);
            subanm->Offset(84);
            Enm_ baseItemDrop = 0;
            Enm_ BonusDrop(1,2);
            Enm_ BonusDrop(0,2);
            Enm_ DropAera(24);
            Enm_ dieAnim = 0b00000101;
            Enm_ setHurtbox(32);
            Enm_ setHitbox(24);
            //Enm_ mirror = rand()%2;
            Enm_ setSpeed(-1.5707964f,2.0f);
            Enm_ SpeedTime(80,1,-1.3744467f,1.0f);
            Sub_ Async(GirlC02_at);
        eFrame
        
        CheckLimitsDelete
        if (Enm_ life <= 0)
        {
            Enm_ Die();
            Sub_ Delete();
            ECLRETURN;
        }
    }

    ECLSUB(GirlD01_at)
    {
        NewBulletHandler(bh)
        {
            bh = Bul_ AddHandler();
            Bul_ etAim(bh,9);
            Bul_ etSprite(bh,7,13);
            Bul_ etCount(bh,d4(6,10,12,14),d4(3,5,7,7));
            Bul_ etAngle(bh,0,0.05235988f);
            Bul_ etSpeed(bh,d4(1.6,1.6,2.6,2.6),d4(1.4,1.4,1.9,1.9));
        }

        fFrame(0)
        mFrame(d4(120,120,240,300)) ECLRETURN;
        mModFrame(60) Bul_ etOn(bh, Enm_ pos.x, Enm_ pos.y);
        eFrame
    }

    ECLSUB(GirlD01)
    {
        fFrame(0)
            Enm_ anm0 = new THAnim(Enm0p1,Enm0p2,Enm0p4,Enm0p3,Enm0p5);
            Enm_ anm0->Offset(96);
            Enm_ anmSlots.push_back(EnmAura(1,3,255,64,64));
            Enm_ dieAnim = 0b00000111;
            Enm_ baseItemDrop = 1;
            Enm_ BonusDrop(1,3);
            Enm_ BonusDrop(0,6);
            Enm_ setHitbox(24);
            Enm_ setHurtbox(32);
            Enm_ setSpeed(-PI1_2,3);
            Enm_ SpeedTime(60,1,-PI1_2,0);
            Sub_ Async(GirlD01_at);
        mFrame(80)
            Enm_ SpeedTime(120,1,-PI1_2,0.5f);
        eFrame

        CheckLimitsDelete
        if (Enm_ life <= 0)
        {
            Enm_ Die();
            Sub_ Delete();
            ECLRETURN;
        }
    }

    ECLSUB(GirlD02_at)
    {
        NewBulletHandler(bh)
        {
            bh = Bul_ AddHandler();
            Bul_ etAim(bh,10);
            Bul_ etSprite(bh,7,2);
            Bul_ etCount(bh,d4(4,8,12,16),d4(5,5,7,9));
            Bul_ etAngle(bh,0,0.05235988f);
            Bul_ etSpeed(bh,d4(1.3,2,3,4),d4(1,1.6,2.4,1.6));
            Bul_ etEx(bh,0,2,1,0,0,0,0,0,0,0);
        }

        fFrame(0)
            if (Sub_ vars == nullptr) ECLVARS(3);
            VAR(1) = 0; VAR(2) = 2;
            subframe = 999;
            Wait(60);
        mFrame(1)
            Bul_ etAngle(bh,VAR(1),0.05235988f);
            VAR(1) += VAR(0);
            Bul_ etOn(bh, Enm_ pos.x, Enm_ pos.y);
            Wait(73);
        mFrame(2)
            Bul_ etAngle(bh,VAR(1),0.05235988f);
            VAR(1) += VAR(0);
            Bul_ etOn(bh, Enm_ pos.x, Enm_ pos.y);
            Wait(93);
            subframe = 999;
        mFrame(1000)
            if (VAR(2)--) subframe = 0;
            else ECLRETURN;
        eFrame
    }

    ECLSUB(GirlD02)
    {
        fFrame(0)
            Enm_ anm0 = new THAnim(Enm0p1,Enm0p2,Enm0p4,Enm0p3,Enm0p5);
            Enm_ anm0->Offset(96);
            Enm_ anmSlots.push_back(EnmAura(1,3,255,64,64));
            Enm_ dieAnim = 0b00000111;
            Enm_ baseItemDrop = 1;
            Enm_ BonusDrop(1,6);
            Enm_ BonusDrop(0,6);
            Enm_ setHitbox(24);
            Enm_ setHurtbox(32);
            Enm_ setSpeed(-PI1_2,3);
            Enm_ SpeedTime(60,1,-PI1_2,0);
            Sub_ Async(GirlD02_at);
        mFrame(240)
            Enm_ SpeedTime(120,1,-PI1_2,-1);
        eFrame

        CheckLimitsDelete
        if (Enm_ life <= 0)
        {
            Enm_ Die();
            Sub_ Delete();
            ECLRETURN;
        }
    }

    ECLSUB(MainSub00)
    {
    
        if (subframe < 195 && subframe%15==0)
        {
            float xx = 120-20*subframe/15.f;
            Ecl_ enmCreate(GirlRedA01,xx-60,-32,60,1000,1);   
            Ecl_ enmCreate(GirlBlueA01,xx,-20,60,1000,1);   
            Ecl_ enmCreate(GirlRedA01,xx+60,-8,60,1000,1);   
        }
        else if (subframe == 490) { ECLRETURN; }
        else if (subframe > 385 && subframe%15==0)
        {
            float xx = -120+40*(subframe-385)/15.f;
            Ecl_ enmCreate(GirlRedA01,xx-60,-32,60,1000,1);   
            Ecl_ enmCreate(GirlBlueA01,xx,-20,60,1000,1);   
            Ecl_ enmCreate(GirlRedA01,xx,-8,60,1000,1);   
        }

    }

    ECLSUB(MainSub01)
    {
        fFrame(0)
            Ecl_ enmCreate(GirlB01, 128.0f, -24.0f, 400, 1000, 1);
            Ecl_ enmCreate(GirlB01, -128.0f, -24.0f, 400, 1000, 1);
        mFrame(60)
            Ecl_ enmCreate(GirlB01, 48.0f, -24.0f, 400, 1000, 1);
        mFrame(120)
            Ecl_ enmCreate(GirlB01, -64.0f, -24.0f, 400, 1000, 1);
        mFrame(180)
            Ecl_ enmCreate(GirlB01, 160.0f, -24.0f, 400, 1000, 1);
        mFrame(240)
            Ecl_ enmCreate(GirlB01, -32.0f, -24.0f, 400, 1000, 1);
        mFrame(300)
            Ecl_ enmCreate(GirlB01, -190.0f, -24.0f, 400, 1000, 1);
        mFrame(360)
            Ecl_ enmCreate(GirlB01, 0.0f, -24.0f, 400, 1000, 1);
        mFrame(420)
            ECLRETURN;
        eFrame
    }
    
    ECLSUB(MainSub01b)
    {
        if (subframe < 195 && subframe%15==0)
        {
            float xx = -120+20*subframe/15.f;
            Ecl_ enmCreate(GirlBlueA01,xx,-20,60,1000,1);   
        }
        else if (subframe == 300) { ECLRETURN; }
        else if (subframe >= 195 && subframe%15==0)
        {
            float xx = 120-40*(subframe-195)/15.f;
            Ecl_ enmCreate(GirlRedA01,xx+60,-8,60,1000,1);   
        }
    }

    ECLSUB(MainSub02b)
    {
        fFrame(0)
            Ecl_ enmCreate(GirlC01, 120.0f, -24.0f, 500, 1000, 1);
        mFrame(130)
            Ecl_ enmCreate(GirlC01, -60.0f, -24.0f, 500, 1000, 1);
        mFrame(260)
            Ecl_ enmCreate(GirlC01,  60.0f, -24.0f, 500, 1000, 1);
        mFrame(390)
            Ecl_ enmCreate(GirlC01, -120.0f, -24.0f, 500, 1000, 1);
        mFrame(520)
            Ecl_ enmCreate(GirlC01, 160.0f, -24.0f, 500, 1000, 1);
            Ecl_ enmCreate(GirlC01, -160.0f, -24.0f, 500, 1000, 1);
        mFrame(650)
            ECLRETURN;
        eFrame
    }

    ECLSUB(MainSub02)
    {
        fFrame(0)
            Ecl_ newSub(MainSub02b);
        mFrame(390)
            ECLRETURN;
        oModFrame(15)
            if (subframe % 2)
                Ecl_ enmCreate(GirlRedA02, -120.0f, -24.0f, 100, 1000, 1);
            else
                Ecl_ enmCreate(GirlBlueA02, -120.0f, -24.0f, 100, 1000, 1);
        eFrame
    }

    ECLSUB(MainSub03)
    {
        fFrame(0)
            ECLVARS(7);
            Wait(100);
        mFrame(1)
            VAR(4) = 4;
            subframe = 1000;
        mFrame(2)
            VAR(2) = 2.356194f;
            VAR(3) = 32.f;
            VAR(0) = -120.f;
            VAR(5) = 10;
            subframe = 998;
            Wait(80);
        mFrame(3)
            int i = Ecl_ enmCreateF(Phantom01,VAR(0),32.0f,120,1000,1);
            if (i != -1)
            {
                Ecl_ Sub(i)->vars = new float[1]; Ecl_ Sub(i)->vars[0] = -VAR(2);
            }
            VAR(2) -= 0.20944f;
            VAR(0) += 24.f;
            Wait(4);
            subframe = 998;
        mFrame(4)
            Wait(80);
            VAR(2) = 0.7853982f;
            VAR(3) = 32.f;
            VAR(0) = 120.f;
            VAR(6) = 10;
            subframe = 999;
        mFrame(5)
            int i = Ecl_ enmCreateF(Phantom01,VAR(0),32.0f,120,1000,1);
            if (i != -1)
            {
                Ecl_ Sub(i)->vars = new float[1]; Ecl_ Sub(i)->vars[0] = -VAR(2); 
            }
            VAR(2) += 0.20944f;
            VAR(0) -= 24.f;
            Wait(4);
            subframe = 999;
        mFrame(999)
            if (VAR(5)--) subframe = 2;
            else subframe = 3;
        mFrame(1000)
            if (VAR(6)--) subframe = 4;
        mFrame(1001)
            if (VAR(4)--) subframe = 1;
            else Wait(50);
        mFrame(1002) ECLRETURN;
        eFrame
    }

    ECLSUB(MainSub04)
    {
        fFrame(0)
            Ecl_ enmCreate(GirlD01,100.f,-24.f,600,1000,1);
            Ecl_ enmCreate(GirlD01,-100.f,-24.f,600,1000,1);
        mFrame(300)
            Ecl_ enmCreate(GirlD01,100.f,-24.f,600,1000,1);
            Ecl_ enmCreate(GirlD01,-100.f,-24.f,600,1000,1);
        mFrame(360)
            ECLRETURN;
        eFrame
    }

    ECLSUB(MainSub05)
    {
        fFrame(0)
            ECLVARS(3);
            VAR(0) = -120.f;
            VAR(1) = 8;
            Wait(180);
            subframe = 999;
        mFrame(1)
            Ecl_ enmCreate(GirlRedA03,VAR(0)-60.f,-32.f,40,1000,1);
            Ecl_ enmCreate(GirlBlueA03,VAR(0),-20.f,40,1000,1);
            VAR(0) += 24.f;
            Wait(25);
            subframe = 999;
        mFrame(2)
            Wait(120);
            VAR(2) = 8;
            subframe = 1000;
        mFrame(3)
            Ecl_ enmCreate(GirlRedA03,VAR(0)-60.f,-32.f,40,1000,1);
            Ecl_ enmCreate(GirlBlueA03,VAR(0),-20.f,40,1000,1);
            VAR(0) -= 24.f;
            Wait(25);
            subframe = 1000;
        mFrame(1000)
            if (VAR(1)--) subframe = 0;
            else subframe = 1;
        mFrame(1001)
            if (VAR(2)--) subframe = 2;
            else ECLRETURN;
        eFrame
    }

    ECLSUB(MainSub06b)
    {
        fFrame(300)
            Ecl_ enmCreate(GirlC02,-96,-32,800,1000,1);
        mFrame(600)
            Ecl_ enmCreate(GirlC02,-96,-32,800,1000,1);
        mFrame(900)
            Ecl_ enmCreate(GirlC02,-96,-32,800,1000,1);
            ECLRETURN;
        eFrame
    }

    ECLSUB(MainSub07)
    {
        fFrame(0)
            int i = Ecl_ enmCreate(GirlD02,0.0f,-24.0f,2200,1000,1);
            Ecl_ Sub(i)->vars = new float[3]; Ecl_ Sub(i)->vars[0] = 0.261799f;
        mFrame(347)
            int i = Ecl_ enmCreate(GirlD02,80.0f,-24.0f,2200,1000,1);
            Ecl_ Sub(i)->vars = new float[3]; Ecl_ Sub(i)->vars[0] = 0.261799f;
            i = Ecl_ enmCreate(GirlD02,-80.0f,-24.0f,2200,1000,1);
            Ecl_ Sub(i)->vars = new float[3]; Ecl_ Sub(i)->vars[0] = 0.261799f;
        mFrame(407)
            ECLRETURN;
        eFrame
    }

    ECLSUB(MainSub06)
    {
        fFrame(0)
            Sub_ Async(MainSub06b);
        mFrame(60*22)
            ECLRETURN;
        oModFrame(22)
            Ecl_ enmCreate(Cir00,224,Random::Float01()*224-48,60,1000,1);
            if (Ecl_ difficulty > 1) Ecl_ enmCreateM(Cir00,224,Random::Float01()*224-48,60,1000,1);
        eFrame
    }

    ECLSUB(MBoss1_at)
    {
        NewBulletHandler(bh1)
        {
            bh1 = Bul_ AddHandler();
            Bul_ etAim(bh1,1);
            Bul_ etSprite(bh1,8,10);
            Bul_ etCount(bh1,d4(4,4,4,6),VAR(0));
            Bul_ etAngle(bh1,-PI1_2,0.6981317f);
            Bul_ etSpeed(bh1,d4(1.5f,2.5f,3.5f,4.1f), 1);
            Bul_ etEx(bh1,0,2,1,0,0,0,0,0,0,0);
            Bul_ etEx(bh1,0,1,0,0,0,0,0,0,0,0);
        }
        NewBulletHandler(bh2)
        {
            bh2 = Bul_ AddHandler();
            Bul_ etAim(bh2,1);
            Bul_ etSprite(bh2,d4(4,4,18,32),d4(10,10,5,2));
            Bul_ etCount(bh2,1,1);
            Bul_ etAngle(bh2,-PI1_2,0.6981317f);
            Bul_ etSpeed(bh2,d4(1.5f,1.5f,2.5f,4.1f), 1);
            Bul_ etEx(bh2,0,2,1,0,0,0,0,0,0,0);
            Bul_ etEx(bh2,0,1,0,0,0,0,0,0,0,0);
        }

        fFrame(0)
            subanm->PlayAnimSP();
        oModFrame(6)
            if (subframe < 30)
            {
                Bul_ etAngle(bh1,-PI1_2,VAR(1));
                VAR(1)+=VAR(2);
                Bul_ etOn(bh1, Enm_ pos.x, Enm_ pos.y);
            }
            else
            {
                if (Ecl_ difficulty != 0) Bul_ etOn(bh2, Enm_ pos.x, Enm_ pos.y);
            }
        mFrame(d3(59,59,65))
            subanm->Reset();
            ECLRETURN;
        eFrame

    }

    ECLSUB(MBossDead)
    {
        fFrame(1)
            if (Ecl_ difficulty < 2)
            Ecl_ etBreak(Enm_ pos.x, Enm_ pos.y, !Tim_ Timeout(),10);
            else if (Tim_ Timeout()) Bul_ etClear();
            else Bul_ etCancel();
            if (Ecl_ CAPTURE) Enm_ baseItemDrop = 5;
            else Enm_ baseItemDrop = -1;
            Enm_ BonusDrop(0,d4(20,20,20,30));
            Enm_ BonusDrop(1,10);
            Enm_ DropAera(48);
            Enm_ DropAll();
            Enm_ ClearDrops();
            effectExplodeMapleBig(Enm_ pos.x, Enm_ pos.y, 1, 120, 2, 1);
            Sub_ flagSet(3);
            Anm_ UpdateChild(Anm_ newAnim(effectExplode),Enm_ pos.x, Enm_ pos.y,0,0,0,0,1,1,1);
            //Snd_ PlaySound(gameassets::se_enep01);
            Ecl_ SetBoss(nullptr);
            Tim_ ShowTime(0);
        mFrame(121)
            Sub_ flagSet(16);
            Enm_ MovePosTime(60,4,192,-32);
        mFrame(181)
            ECLRETURN;
        eFrame
    }

    ECLSUB(MBossEscape)
    {
        fFrame(1)
            Bul_ etClear();
            Sub_ flagSet(16);
            Enm_ MovePosTime(60,4,0,-32);
            Ecl_ SetBoss(nullptr);
            Tim_ ShowTime(0);
        mFrame(61)
            ECLRETURN;
        eFrame
    }

    ECLSUB(MBoss1)
    {
        static int fram;
        fFrame(0)
            Ecl_ CAPTURE = true;
            fram = d3(120,120,60);
            effectCharge(-1.04f,0,224-128,255,255,128,45,1);
            effectCharge(-.52,0,224-128,255,255,128,45,1);
            effectCharge(0,0,224-128,255,128,255,45,1);
        nFrame2(80,80+2*fram)
            VAR(0) = d4(3,4,5,6);
            VAR(1) = 1.3962634f;
            VAR(2) = -0.29670596f;
            Sub_ Async(MBoss1_at);
        mFrame(80+fram)
            Enm_ MoveRand(60,4,30);
        eFrame
        
        InterruptLife(0,MBossDead);
        InterruptTime(1020,MBossEscape);
    }

    ECLSUB(MBoss)
    {
        fFrame(0)
            Bul_ etClear();
            Bul_ ClearHandlers();
            ECLVARS(3);
            Ecl_ SetBoss(thisSub);
            Tim_ SetTime(17);
            Tim_ ShowTime(1);
            subanm = new THAnim(st01E1,st01E2,st01E4,st01E3,st01E5,st01E6);
            Enm_ SetLife(5200);
            Enm_ MovePos(192,-64);
            Enm_ MovePosTime(100,4,0,128);
            Enm_ setHurtbox(48);
            Enm_ setHitbox(40);
        mFrame(40)
            Enm_ MoveLimit(0,128,280,256);
            Sub_ Sync(MBoss1);
        mFrame(42)
            Sub_ Delete(); ECLRETURN;
        eFrame

    }

    ECLSUB(Boss1_at)
    {
        NewBulletHandler(bh)
        {
            bh = Bul_ AddHandler();
            Bul_ etAim(bh,AIM_ST);
            Bul_ etSprite(bh,8,10);
            Bul_ etSpeed(bh,d4(1.5f,2.5f,2.5f,4.1f),3);
            Bul_ etCount(bh,6,3);
            Bul_ etEx(bh,0,1,0,0,0,0,0,0,0,0);
            Bul_ etEx(bh,0,2,1,0,0,0,0,0,0,0);
            Bul_ etAngle(bh,1.5707964f, 0.6981317f);
        }

        fFrame(0)
            VAR(3) = d4(7,10,11,11);
            subanm->PlayAnimSP();
        mFrame(10*VAR(3)) 
            subanm->Reset();
            ECLRETURN;
        oModFrame(10)
            Bul_ etAngle(bh, -1.5707964f, VAR(1));
            VAR(1)+=VAR(2);
            Bul_ etOn(bh,Enm_ pos.x,Enm_ pos.y);
        eFrame
    }

    ECLSUB(Boss2_at)
    {
        NewBulletHandler(bh)
        {
            bh = Bul_ AddHandler();
            Bul_ etAim(bh,AIM_ST);
            Bul_ etSprite(bh,8,10);
            Bul_ etSpeed(bh,d2(1.5f,2.5f),3);
            Bul_ etCount(bh,6,VAR(0));
            Bul_ etEx(bh,0,1,0,0,0,0,0,0,0,0);
            Bul_ etEx(bh,0,2,1,0,0,0,0,0,0,0);
            Bul_ etAngle(bh,1.5707964f, 0.6981317f);
        }

        fFrame(0)
            VAR(3) = d2(7,10);
            subanm->PlayAnimSP();
        mFrame(10*VAR(3)) 
            subanm->Reset();
            ECLRETURN;
        oModFrame(10)
            Bul_ etAngle(bh, -1.5707964f, VAR(1));
            VAR(1)+=VAR(2);
            Bul_ etOn(bh,Enm_ pos.x,Enm_ pos.y);
        eFrame
    }

    ECLSUB(Boss1_at2)
    {
        static int fram = d4(60,60,30,30);
        
        NewBulletHandler(bh)
        {
            bh = Bul_ AddHandler();
            Bul_ etAim(bh,AIM_ST_RING);
            Bul_ etSprite(bh,4,6);
            Bul_ etCount(bh,1,d4(1,1,1,2));
            Bul_ etAngle(bh,-1.5707964f ,0.034906585f);
            Bul_ etSpeed(bh,d3(1,1,2),.8);
            Bul_ etEx(bh,0,2,1,0,0,0,0,0,0,0);
            fram = d4(60,60,30,30);
        }

        gFrame2(60,60+fram)
            float a = Random::Angle(); float d = 128* Random::Float01();
            Bul_ etOn(bh,Enm_ pos.x+math::lengthdir_x(d,a),Enm_ pos.y+math::lengthdir_y(d,a)*.4f);
        eFrame
    }

    ECLSUB(BossCard1_at)
    {
        NewBulletHandler(bh)
        {
            bh = Bul_ AddHandler();
            Bul_ etAim(bh,1);
            Bul_ etSprite(bh,8,10);
            Bul_ etCount(bh,6,3);
            Bul_ etSpeed(bh,d2(1.5f,2.5f),3);
            Bul_ etEx(bh,0,2,1,0,0,0,0,0,0,0);
            Bul_ etEx(bh,0,1,0,0,0,0,0,0,0,0);
            VAR(2) = d4(7,10,11,11);
        }

        fFrame(0)
            subanm->PlayAnimSP();
        mFrame(VAR(2)*10)
            subanm->Reset();
            ECLRETURN;
        oModFrame(10)
            Bul_ etAngle(bh,-PI1_2,VAR(0));
            VAR(0)+=VAR(1);
            Bul_ etOn(bh,Enm_ pos.x,Enm_ pos.y);
        eFrame
    }

    ECLSUB(BossCard1_at2)
    {
        static int fram = 60;
        
        NewBulletHandler(bh)
        {
            fram = d3(60,60,30);
            bh = Bul_ AddHandler();
            Bul_ etAim(bh,3);
            Bul_ etSprite(bh,4,6);
            Bul_ etCount(bh,1,d4(1,1,2,3));
            Bul_ etAngle(bh,-PI1_2,0.034906585f);
            Bul_ etSpeed(bh,d4(1,1,2,3),.8f);
            Bul_ etEx(bh,0,2,1,0,0,0,0,0,0,0);
        }

        gFrame2(60,60+fram)
            float a = Random::Angle(); float d = Random::Float01()*128.f;
            Bul_ etOn(bh,Enm_ pos.x+math::lengthdir_x(d,a),Enm_ pos.y+math::lengthdir_y(d,a)*.4f);
        eFrame
    }

    ECLSUB(BossCard2_at)
    {
        NewBulletHandler(bh1)
        {
            bh1 = Bul_ AddHandler();
            Bul_ etAim(bh1,1);
            Bul_ etSprite(bh1,8,13);
            //Bul_ etSound(bh1,gameassets::se_kira00,gameassets::se_kira00);
            Bul_ etCount(bh1,1,d4(1,1,2,3));
            Bul_ etAngle(bh1,-1.5707964f,0.6981317f);
            Bul_ etSpeed(bh1,2.1f,1.5f);
            Bul_ etEx(bh1,0,2,1,0,0,0,0,0,0,0);
            Bul_ etEx(bh1,0,256,180,0,0,0,0,0,0,0);
            Bul_ etEx(bh1,0,8,120,0,0,0,0.017453292f,0,0,0);
            Bul_ etEx(bh1,0,16,60,2,0,0,-1.5707964f,2,0,0);
        }
        NewBulletHandler(bh2)
        {
            bh2 = Bul_ AddHandler();
            Bul_ etAim(bh2,1);
            Bul_ etSprite(bh2,8,13);
            //Bul_ etSound(bh2,gameassets::se_kira00,gameassets::se_kira00);
            Bul_ etCount(bh2,1,d4(1,1,2,3));
            Bul_ etAngle(bh2,1.5707964f,0.6981317f);
            Bul_ etSpeed(bh2,2.1f,1.5f);
            Bul_ etEx(bh2,0,2,1,0,0,0,0,0,0,0);
            Bul_ etEx(bh2,0,256,180,0,0,0,0,0,0,0);
            Bul_ etEx(bh2,0,8,120,0,0,0,-0.017453292f,0,0,0);
            Bul_ etEx(bh2,0,16,60,2,0,0,1.5707964f,2,0,0);
            VAR(0) = d4(6,10,10,10);
        }

        fFrame(0)
            subanm->PlayAnimSP();
            VAR(1) = -2.748894f;
        mFrame(VAR(0) * (d2(7,5)))
            subanm->Reset();
            ECLRETURN;
        oModFrame(d2(7,5))
            if (Ple_ y > Enm_ pos.y)
            {
                Bul_ etAngle(bh1,VAR(1),0.17453292f);
                Bul_ etAngle(bh2,(PI-VAR(1)),0.17453292f);
            }
            else
            {
                Bul_ etAngle(bh1,(PI+VAR(1)),0.17453292f);
                Bul_ etAngle(bh2,(PI2-VAR(1)),0.17453292f);
            }
            VAR(1)-=d2(0.418879f,0.244346f);
            Bul_ etOn(bh1,Enm_ pos.x,Enm_ pos.y);
            Bul_ etOn(bh2,Enm_ pos.x,Enm_ pos.y);
        eFrame
    }

    ECLSUB(BossCard2_at2)
    {
        static int fram = d4(60,60,30,20);

        NewBulletHandler(bh)
        {
            fram = d4(60,60,30,20);
            bh = Bul_ AddHandler();
            Bul_ etAim(bh,0);
            Bul_ etSprite(bh,20,1);
            //Bul_ etSound(bh,gameassets::se_kira00,gameassets::se_kira00);
            Bul_ etCount(bh,1,1);
            Bul_ etAngle(bh,0,0.08726646f);
            Bul_ etSpeed(bh,0.01,0.8);
            Bul_ etEx(bh,0,2,1,0,0,0,0,0,0,0);
            Bul_ etEx(bh,0,4,120,0,0,0,0.016666667f,0,0,0);
        }

        gFrame2(60,60+fram)
            float a = Random::Angle(); float d = Random::Float01()*128;
            Bul_ etOn(bh,Enm_ pos.x+math::lengthdir_x(d,a),Enm_ pos.y+math::lengthdir_y(d,a)*.4f);
        eFrame
    }

    ECLSUB(Boss2_at2)
    {
        static int fr = d4(60,60,30,20);

        NewBulletHandler(bh)
        {
            fr = d4(60,60,30,20);
            bh = Bul_ AddHandler();
            Bul_ etAim(bh,0);
            Bul_ etSprite(bh,4,2);
            //Bul_ etSound(bh,gameassets::se_kira00,gameassets::se_kira00);
            Bul_ etCount(bh,d4(1,1,3,5),1);
            Bul_ etAngle(bh,0,0.12217305f);
            Bul_ etSpeed(bh,1,0.8f);
            Bul_ etEx(bh,0,2,1,0,0,0,0,0,0,0);
            Bul_ etEx(bh,0,4,120,0,0,0,0.016666667f,0,0,0);
        }

        gFrame2(60,60+fr)
            float a = Random::Angle(), d = Random::Float01()*128;
            Bul_ etOn(bh,Enm_ pos.x+math::lengthdir_x(d,a),Enm_ pos.y+math::lengthdir_y(d,a)*.4f);
        eFrame
    }

    ECLSUB(BossDead)
    {
        fFrame(1)
            Ecl_ etBreak(Enm_ pos.x, Enm_ pos.y, !Tim_ Timeout(),10);
            Enm_ baseItemDrop = Ecl_ CAPTURE ? 5 : -1;
            Enm_ BonusDrop(0,40);
            Enm_ BonusDrop(1,15);
            Enm_ DropAera(64);
            Enm_ DropAll();
            Enm_ ClearDrops();
            CollisionManager::destroyEnemyHurtbox(Enm_ hurtBox);
            //Snd_ PlaySound(gameassets::se_enep01);
            Enm_ MoveRand(60,0,24);
            Tim_ ShowTime(false);
        mFrame(61)
            //Snd_ PlaySound(gameassets::se_enep01);
            Ecl_ SetBoss(nullptr);
            //screen shake
            effectExplodeMapleBig(Enm_ pos.x,Enm_ pos.y,1,180,2,2);
            Anm_ UpdateChild(Anm_ newAnim(effectExplodeNeg2),Enm_ pos.x,Enm_ pos.y,0,0,0,0,1,1,1);
            ECLRETURN;
        eFrame
    }

    ECLSUB(BossEscape)
    {
        fFrame(1)
            Tim_ ShowTime(false);
            Enm_ MovePosTime(60,4,-224,-6);
            Bul_ etClear();
            Ecl_ SetBoss(nullptr);
        mFrame(60)
            ECLRETURN;
        eFrame
    }

    ECLSUB(BossCard2)
    {
        fFrame(1)
            if (Tim_ Timeout()) Bul_ etClear();
            else 
            {
                Bul_ etCancel();
                Enm_ baseItemDrop = Ecl_ CAPTURE ? 5 : -1;
                Enm_ DropAll();
            }
            Ecl_ CAPTURE = true;
            //Enm_ hitsound = gameassets::se_damage00;
            Ecl_ thebossanms.ClearSections();
            //Snd_ PlaySound(gameassets::se_tan00);
            Enm_ MovePosTime(60,4,0,128);
            Enm_ MoveLimit(0,128,240,64);
            Enm_ SetLife(1700,0);
            Crt_ Start(st01CT,1500,1);
            effectMaple(0,135,1,0b00010010,255,80,80,255,0,0);
        mFrame2(90,190)
            if (subframe == 90)
                Sub_ Async(BossCard2_at2);
            subframe = 90;
            Sub_ Async(BossCard2_at);
        mFrame(130)
            Enm_ MoveRand(60,4,30);
        eFrame

        InterruptLife(0,BossDead);
        InterruptTime(1500,BossEscape);
    }

    ECLSUB(Boss2)
    {
        fFrame(1)
            if (Tim_ Timeout()) Bul_ etClear();
            else 
            {
                Bul_ etCancel();
                Enm_ baseItemDrop = Ecl_ CAPTURE ? 5 : -1;
                Enm_ BonusDrop(0,40);
                Enm_ BonusDrop(1,10);
                Enm_ DropAera(64);
                Enm_ DropAll();
                Enm_ ClearDrops();
            }
            Tim_ SetTime(25);
            Ecl_ CAPTURE = true;
            //Enm_ hitsound = gameassets::se_damage00;
            //setInvuln(120);
            Enm_ invFrame = 120;
            Enm_ SetLife(9700);
            Ecl_ thebossanms.AddSection(1700);
            subanm->Reset();
            Ecl_ thebossanms.Stars(0);
            //Snd_ PlaySound(gameassets::se_tan00);
            Enm_ MoveLimit(0,128,240,64);
            //Snd_ PlaySound(gameassets::se_ch02);
            effectMaple(Enm_ pos.x,Enm_ pos.y,1,0b00010010,80,80,255,40,40,255);
        mFrame(91)
            //Snd_ PlaySound(gameassets::se_enep02);
            effectMaple(Enm_ pos.x,Enm_ pos.y,1,0b00100100,255,80,255,255,0,255);
        mFrame2(120,300)
            if (subframe == 120)
            {
                VAR(0) = 4;
                Sub_ Async(Boss2_at2);
            }
            subframe = 120;
            VAR(1) = 1.3264502f; VAR(2) = -0.12915437f;
            Sub_ Async(Boss2_at);
        mFrame(240)
            Enm_ MoveRand(60,4,30);
        eFrame

        //if (subhp < 3000) Enm_ hitsound = gameassets::se_damage01;
        
        Interrupt(1700,1500,BossCard2);
    }

    ECLSUB(BossCard1)
    {
        fFrame(1)
            if (Tim_ Timeout()) Bul_ etClear();
            else 
            {
                Bul_ etCancel();
                Enm_ baseItemDrop = Ecl_ CAPTURE ? 5 : -1;
                Enm_ DropAll();
            }
            Ecl_ CAPTURE = true;
            Tim_ SetTime(25);
            Ecl_ thebossanms.ClearSections();
            //Enm_ hitsound = gameassets::se_damage00;
            Enm_ SetLife(1700,0);
            subanm->Reset();
            Enm_ MovePosTime(60,4,0,128);
            Enm_ MoveLimit(0,128,240,64);
            //Snd_ PlaySound(gameassets::se_tan00);
            Crt_ Start(st01CT,1500,0);
            effectMaple(0,135,1,0b00010010,255,80,80,255,0,0);
        mFrame2(91,191)
            if (subframe == 91) Sub_ Async(BossCard1_at2);
            subframe = 91;
            VAR(0) = 1.3264502f; VAR(1) = -0.12217305f;
            Sub_ Async(BossCard1_at);
        mFrame(131)
            Enm_ MoveRand(60,4,30);
        eFrame

        //if (subhp < 250) Enm_ hitsound = gameassets::se_damage01;

        Interrupt(0,1500,Boss2);
    }

    ECLSUB(Boss1)
    {
        fFrame(0)
            Tim_ SetTime(25);
            Ecl_ CAPTURE = true;
            //Enm_ hitsound = gameassets::se_damage00;
            Bul_ ClearHandlers();
            Tim_ ShowTime(true);
            Ecl_ thebossanms.AddSection(1700);//color -24448
            Ecl_ thebossanms.Stars(1);
            effectMaple(0,135,1,0b00010010,255,192,128,192,192,64);
            //Snd_ PlaySound(gameassets::se_ch02);
        mFrame(60)
            effectMaple(0,135,1,0b00100100,255,192,128,192,192,64);
            //Snd_ PlaySound(gameassets::se_enep02);
            VAR(0) = 3;
            Sub_ Async(Boss1_at2);
        nFrame2(61,241)
            VAR(1) = 1.3264502f;
            VAR(2) = -0.12217305f;
            Sub_ Async(Boss1_at);
        mFrame(181)
            Enm_ MoveRand(60,4,30);
        eFrame

        //if (subhp < 3000) Enm_ hitsound = gameassets::se_damage01;

        Interrupt(1700,1500,BossCard1);
    }

    ECLSUB(Boss)
    {
        fFrame(0)
            Enm_ MovePos(0,128);
            Enm_ invFrame = 120;
            Sub_ flagSet(3);
            effectCharge(-1.04,0,224-128,255,255,128,45,1);
            effectCharge(0,0,224-128,128,255,255,45,1);
            effectCharge(0,0,224-128,255,255,128,45,0);
            effectCharge(1.04,0,224-128,128,255,255,45,0);
            ECLVARS(7);
        mFrame(101)
            subanm = new THAnim(st01E1,st01E2,st01E4,st01E3,st01E5,st01E6);
            Sub_ flagClear(3);
            Sub_ flagSet(64);
            Ecl_ SetBoss(thisSub);
            Enm_ SetLife(9700);
            //dialogueWait();
        mFrame(200)
            Enm_ setHitbox(48);
            Enm_ setHurtbox(40);
            Enm_ MoveLimit(0,128,280,64);
            Sub_ endat->anmSlots.push_back(Anm_ newAnim(effectMagicSquare1));
            setAuraColor(1);
            Sub_ endat->anmSlots.push_back(Anm_ newAnim(effectAura));
            //fog(160,15732608);
            Sub_ Sync(Boss1);
   //         Snd_ StopMusic(gameassets::mus_st01);
   //         Snd_ PlayMusic(gameassets::mus_st01bs);
        mFrame(202) Sub_ Delete(); eFrame
    }

    ECLSUB(StageLogo)
    {
        fFrame(400)
            AnmManager::newAnim(st01Logo);
        mFrame(401)
            ECLRETURN;
        eFrame
    }

    ECLSUB(MainFront)
    {
        fFrame(0)
            Sub_ Sync(MainSub00);
        mFrame(60)
            Sub_ Sync(MainSub01);
            Sub_ Async(MainSub01b);
        mFrame(160)
            Sub_ Sync(MainSub02);
        mFrame(620)
            ECLRETURN;
        eFrame
    }

    ECLSUB(MainLatter)
    {
        fFrame(0)
            Sub_ Sync(MainSub03);
        mFrame(1)
            WaitBoss();
        mFrame(2)
            Sub_ Async(MainSub05);
            Sub_ Sync(MainSub04);
        mFrame(322)
            Sub_ Sync(MainSub06);
        mFrame(392)
            Sub_ Sync(MainSub07);
        mFrame(393)
            ECLRETURN;
        eFrame
    }

    ECLSUB(MainBoss)
    {
        //dialogue stuff
        fFrame(0)
            Ecl_ enmCreate(Boss,144.0f,-16.0f,40,1000,-1);
        eFrame
    }

    ECLSUB(Main)
    {
        fFrame(0)
            Ecl_ stage = 1;
 //           Snd_ PlayMusic(gameassets::mus_st01);
            Bul_ ClearHandlers();
            Sub_ Async(StageLogo);
        mFrame(60)
            Sub_ Sync(MainFront);
        mFrame(61)
            Ecl_ enmKillAll();
            Bul_ etClear();
        mFrame(62)
            Ecl_ enmCreate(MBoss,192.0f,-32.0f,40,1000,1);
        mFrame(222) 
            Sub_ Sync(MainLatter);
        mFrame(622)
            Ecl_ enmKillAll();
            Bul_ etClear();
            Sub_ Sync(MainBoss);
        eFrame
    }
}
