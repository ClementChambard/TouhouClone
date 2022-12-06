#ifndef COLLISIONMANAGER
#define COLLISIONMANAGER

#include <vector>

class CollisionManager {
    private: struct CollisionBox;
    public:

        static void Init();
        static void Cleanup()
        {
            delete[] EnemyHitbox;
            delete[] PlayerHitbox;
            delete[] EnemyHurtbox;
        }
        static void Reset();
        static void Update();

        static void PlayerBox(float x, float y, float radius = -1, float grazeRadius = -1);

        static int NewEnemyHitbox(float x, float y, float radius);
        static int NewPlayerHitbox(float x, float y, float radius, float damage);
        static int NewEnemyHurtbox(float x, float y, float radius);

        static void destroyEnemyHitbox(int i);
        static void destroyPlayerHitbox(int i);
        static void destroyEnemyHurtbox(int i);

        static void MoveBox(int type, int i, float x, float y);

        static int closestBox(int type, float x, float y);
        static void boxPosition(int type, int i, float& x, float& y);

        static CollisionBox box(int type, int i);

        static bool IsActive(int type, int i);
        static bool IsHit(int type, int i, float &damage);

        static void DEBUG_DRAW_BOXES();

    private:
        struct CollisionBox
        {
            bool active = false;
            bool grazed = false;
            bool iscolliding = false;
            float x = 0, y = 0, r = 0;
            float damage = 0;
            float lasthitangle = 0;
        };

        static float playerBoxX;
        static float playerBoxY;
        static float playerBoxR;
        static float playerGBoxR;

        static int pos1,pos2,pos3;

        static CollisionBox* EnemyHitbox;
        static CollisionBox* PlayerHitbox;
        static CollisionBox* EnemyHurtbox;
};

#endif
