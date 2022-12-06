#ifndef GAMEINPUTS
#define GAMEINPUTS

#include <vector>
#include <InputManager.h>
#include <Keys.h>

class GameInputs {

    public: 
        static std::vector<int> keys;
};


#define KEYDOWN(x) Inputs::Keyboard().Down(GameInputs::keys[x])
#define KEYUP(x) Inputs::Keyboard().Up(GameInputs::keys[x])
#define KEYPRESSED(x) Inputs::Keyboard().Pressed(GameInputs::keys[x])
#define KEYRELEASED(x) Inputs::Keyboard().Released(GameInputs::keys[x])

#define K_UP 0
#define K_DOWN 1
#define K_LEFT 2
#define K_RIGHT 3
#define K_SHOOT 4
#define K_FOCUS 5
#define K_SPELL 6
#define K_SPECIAL 7
#define K_CONFIRM 8
#endif
