#ifndef STG01
#define STG01

#include "AnmSt01.h"

struct stgQuad {
    float x = 0.f, y = 0.f, z = 0.f;
    void (*anm_script)(AnimScript*);
};

struct stgEntrie {
    float x = 0.f, y = 0.f, z = 0.f;
    float w = 1024.f, h = 512.f;
    std::vector<stgQuad> quads;
};

struct stgFace {
    float x = 0.f, y = 0.f, z = 0.f;
    stgEntrie* ent;
    bool onScreen = false;
    std::vector<int> anms;
    void Init();
    void Destroy();
    bool InRange(float x, float y, float z);
};

class Stg01 {
    public:
        static void Init(int difficulty);
        static void UnInit();
        static void Update();
    private:
        static int frame;
        static int interrupt;
        static std::vector<int> anms;
        static std::vector<stgFace> faces;
};

#endif
