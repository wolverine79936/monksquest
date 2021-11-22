#include "SDL2/SDL.h"

SDL_Window* g_pWindow = 0;
SDL_Renderer* g_pRenderer = 0;

int main(int argc, char* args[])
{
    // Let's initialize SDL
    if(SDL_Init(SDL_INIT_EVERYTHING) >= 0)
    {

    }
    else
    {
        
    }
    return 0;
}