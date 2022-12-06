#ifndef TIMER
#define TIMER

class Timer {
    public:
        static void SetTime(float t);
        static void ShowTime(bool b, bool spell = false);
        static void ShowCardScore(int score);
        static void ShowTimeScore(float time, float bestTime = 99.99f);

        static void Update();

        static bool Timeout();

    private:
        static void interruptAll(int i);
        static float time;
        static bool show;
        static int nb1, nb2, nb3, nb4, dot;
};

#endif
