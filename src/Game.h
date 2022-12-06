#ifndef GAME
#define GAME

#include <iostream>
#include <math.h>

#define HAS_TEXT_ANM
#include <NSEngine.h>

class Game {

public:

    Game();
    ~Game();

    void INIT();
    void GAMELOOP();
    void CLEAN();
    
    static int d;
    static bool menu;

private:
    NSEngine::Window window;

};

#endif
