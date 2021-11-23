#include "SDL2/SDL.h"

#ifndef __Game__
#define __Game__

class Game
{
    public:

        Game() {};
        ~Game() {};

        // simply set the running variable to true
        void init();

        void render();
        void update();
        void handleEvents();
        void clean();

        // a function to access the private running variable
        bool running() { return m_bRunning; }

    private:

        SDL_Window* m_pWindow;
        SDL_Renderer* m_pRenderer;
        
        bool m_bRunning;
};

#endif /* defined(__Game__) */