#include "SDL2/SDL.h"

SDL_Window* g_pWindow = 0;
SDL_Renderer* g_pRenderer = 0;

int main(int argc, char* args[])
{
    // Let's initialize SDL
    if(SDL_Init(SDL_INIT_EVERYTHING) >= 0)
    {
        // This checks that we succesfully created our window:
        g_pWindow = SDL_CreateWindow("Monk's Quest", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN);

        // If we succesfully created our renderer within the window:
        if(g_pWindow != 0)
        {
            g_pRenderer = SDL_CreateRenderer(g_pWindow, -1, 0);
        }
    }
    else
    {
        return 1; // For some reason, we couldn't initialize SDL.
    }

    // Everything has succeeded, so let draw the window finally.

    // We'll set the renderer background to black. // This function expects RGBa as color values.
    SDL_SetRenderDrawColor(g_pRenderer, 0, 0, 0, 255);

    // Now let's clear the window to black.
    SDL_RenderClear(g_pRenderer);

    // And now to show the window.
    SDL_RenderPresent(g_pRenderer);

    // And now to set a delay before quitting
    SDL_Delay(10000);

    // Finally, to clean up SDL
    SDL_Quit();

    return 0;
}