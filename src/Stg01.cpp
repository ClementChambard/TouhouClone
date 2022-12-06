#include "Stg01.h"
#include "ECLSt01.h"

void stgFace::Init()
{
    if (onScreen) return;
    onScreen = true;
    for (stgQuad q : ent->quads)
    {
        int a = AnmManager::newAnim(q.anm_script);
        AnmManager::UpdateChild(a,x+ent->x+q.x,y+ent->y+q.y,z+ent->z+q.z,0,0,0,1,1,true);
        anms.push_back(a);
    }
}

void stgFace::Destroy()
{
    if (!onScreen) return;
    for (int i : anms) AnmManager::deleteAnim(i);
    anms.clear();
}

bool stgFace::InRange(float x, float y, float z) {return true;}

stgEntrie entry1;

int Stg01::frame = 0;
int Stg01::interrupt = 0;
std::vector<stgFace> Stg01::faces;
std::vector<int> Stg01::anms;

void Stg01::Init(int difficulty)
{
    ECLManager::Init(ST01::Main);
    ECLManager::difficulty = difficulty;
    entry1.z = 300;
    entry1.quads.push_back({0,0,0,st01a});
    faces.push_back({0,-280,0,&entry1,false});
    faces.push_back({1024,-280,0,&entry1,false});
    faces.push_back({0,-792,0,&entry1,false});
    faces.push_back({1024,-792,0,&entry1,false});
    faces.push_back({0,-1304,0,&entry1,false});
    faces.push_back({1024,-1304,0,&entry1,false});
    faces.push_back({0,-1816,0,&entry1,false});
    faces.push_back({1024,-1816,0,&entry1,false});
    for (stgFace f : faces) if (f.InRange(0,0,0)) f.Init();
}

void Stg01::UnInit()
{
    frame = 0;
    faces.clear();
    anms.clear();
}

#include <NSEngine.h>
void Stg01::Update()
{
    ECLManager::Update();
    if (Inputs::Keyboard().Pressed(NSK_1)) { 
        frame = 0;
        for (int anm : anms) AnmManager::deleteAnim(anm);
        anms.clear();
    }
    if (Inputs::Keyboard().Pressed(NSK_2)) interrupt = 1;
    NSEngine::Camera3D* cam = NSEngine::engineData::cam3d;
    if (frame == 0)
    {
        cam->setUp(0.06f, -1.0f, 0.0f);
        cam->setFov(PI2/10.f);
        cam->setClearColor(0,0,176);
        cam->setFog(128,208,176,255,300.f,600.f);
        cam->FogTime(720,0,64,208,176,255,400.f, 1400.0f);
        cam->setPosition(0.0f, 200.0f, -400.0f);
        cam->PositionTime(700, 4, 0.0f, -312.0f, -250.0f);
        cam->setLook(30.0f,-180.0f,150.0f);
        cam->LookTime(700, 4, 60.0f, -140.0f, 150.0f);
    }
    else if (frame == 720 || frame == 1070 || frame == 1420 || frame == 1770)
    {
        cam->setPosition(0.0f, 200.0f, -250.0f);
        cam->PositionTime(350, 0, 0.0f, -312.0f, -250.0f);
    }
    else if (frame == 2120)
    {
        cam->setPosition(0.0f, 200.0f, -250.0f);
        anms.push_back(AnmManager::newAnim(st01c));
        anms.push_back(AnmManager::newAnim(st01b1));
        anms.push_back(AnmManager::newAnim(st01b2));
        cam->PositionTime(700, 0, -50.0f, -312.0f, -100.0f);
        cam->LookTime(700, 4, 0.0f, -140.0f, 40.0f);
        cam->FogTime(500, 0, 80, 80, 240, 255, 400.0f, 1000.0f);
    }
    else if (frame == 2720) cam->FogTime(50, 0, 255, 255, 255, 255, 400.0f, 1000.0f);
    else if (frame == 2770) cam->FogTime(50,0,2,208,208,255,800.0f, 1400.0f);
    else if (frame == 2820 || frame == 3520 || frame == 4220 || frame == 4920 || frame == 5621)
    {
        cam->setPosition(-50.0f, 200.0f, -100.0f);
        cam->PositionTime(700,0, 462.0f, -312.0f, -100.0f);
        //if (frame == 4220) distortion 1 
        if (frame == 4920) frame = 4220;
        if (frame == 5621) frame = 4921;
    }
    if (interrupt == 1)
    {
        frame = 4921;
        //distortion(1);
        anms.push_back(AnmManager::newAnim(st01c));
        anms.push_back(AnmManager::newAnim(st01b1));
        anms.push_back(AnmManager::newAnim(st01b2));
        cam->setPosition(-50.0f, 200.0f, -100.0f);
        cam->PositionTime(700,0, 462.0f, -312.0f, -100.0f);
        cam->setLook(0.0f, -140.0f, 40.0f);
        cam->LookTime(700,0,0.0f, -140.0f, 40.0f);
        cam->setFog(2,208,208,255,800.0f,1400.0f);
        cam->FogTime(700,0,2,208,208,255,800.0f,1400.0f);
        for (int i : anms) AnmManager::interrupt(i, 8);
    }
    frame++;
    interrupt = 0;
    for (int a : anms) AnmManager::UpdateChild(a,0,0,0,0,0,0,1,1,true);
}
