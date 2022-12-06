#ifndef PICKUP
#define PICKUP

#include <iostream>

#define PICKUP_ACCEL -.2f
#define PICKUP_MAX_SPEED 2.5f
#define PICKUP_COLLECTED_ACCEL .4f
#define PICKUP_COLLECTED_MAX_SPEED 12.f

class Pickup {
    public:
        static void Init();
        static void Cleanup()
        {
            delete[] PickupPool;
            delete[] CancelPickupPool;
        }
        static void SpawnPickup(int type, float x, float y, float xto, float yto);
        static void SpawnCancelPickup(float x, float y);

        static void Update(float framespeed = 1.f);

        static void Collect_All();
        static void unCollect_All();
        static void Collect_All(int type);

        static void CreateCollectText(std::string text, float x, float y, int r = 255, int g = 255, int b = 255);

    private:

        static Pickup* PickupPool;
        static Pickup* CancelPickupPool;
        static int lastPickup;
        static int lastCancelPickup;
        void Pupdate(float framespeed = 1.f);
        int type = 0;
        float x = 0;
        float y = 0;
        float xto = 0;
        float yto = 0;
        bool collected = false;
        float ywhencollected = 0;
        bool active = false;
        float xstep = 0;
        float spd = 0;
        int anm = -1;
        Pickup();
};

#endif
