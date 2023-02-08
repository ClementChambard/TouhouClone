#define SDL_MAIN_HANDLED
#define NS_PROJECT_FOLDER(x) "~/dev/touhou/ ## x ## "
#include "Game.h"

int main(int argc, const char * argv[])
{
    Game().run();
    return 0;
}
