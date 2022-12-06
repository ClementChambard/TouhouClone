#define SDL_MAIN_HANDLED
#define NS_PROJECT_FOLDER(x) "~/dev/touhou/ ## x ## "
#include "Game.h"

Game *game = nullptr;

int main(int argc, const char * argv[])
{
    game = new Game();

    game->INIT();
    game->GAMELOOP();
    game->CLEAN();

    return 0;
}
