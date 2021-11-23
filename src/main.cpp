#include "SDL2/SDL.h"
#include "../hdrs/Game.h"

// our Game object
Game* g_game = 0;

SDL_Window* g_pWindow = 0;
SDL_Renderer* g_pRenderer = 0;

bool Game::init(const char* title, int xpos, int ypos, int width, int height, int flags)
{
    // attempt to initalize SDL
    if(SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        std::cout << "SDL init success\n";
        // init the window
        m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, flags);

        if(m_pWindow != 0) // window init success
        {
            std::cout << "window creation success\n";
            m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);

            if(m_pRenderer != 0) // renderer init success
            {
                std::cout << "renderer creation success\n";
                SDL_SetRenderDrawColor(m_pRenderer,255,255,255,255);
            }
            else
            {
                std::cout << "renderer init fail\n";
                return false; // renderer init fail
            }
        }
        else
        {
            std::cout << "window init fail\n";
            return false; // window init fail
        }
    }
    else
    {
        std::cout << "SDL init fail\n";
        return false; // SDL init fail
    }

    std::cout << "init success\n";
    m_bRunning = true; // everything init'd successfully.
    start the main loop;

    return true;
}

int main(int argc, char* argv[])
{
    g_game = new Game();

    g_game->init("Monk's Quest", 100, 100, 640, 480, 0);

    while(g_game->running())
    {
        g_game->handleEvents();
        g_game->update();
        g_game->render();
    }
    g_game->clean();

    return 0;
}