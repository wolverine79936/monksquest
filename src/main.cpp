#include <iostream>
#include "SDL2/SDL.h"
#include "../hdrs/Game.h"

// our Game object
Game* g_game = 0;

int main(int argc, char* argv[])
{
     g_game = new Game();

     g_game->init("Monk's Quest", 100, 100, 640, 480, false);

    while(g_game->running())
    {
        g_game->handleEvents();
        g_game->update();
        g_game->render();
    }
     g_game->clean();

    return 0;
}