#include "Game.h"
#include <stdio.h>

bool Game_Engine::init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen)
{
    int flags = fullscreen ? SDL_WINDOW_FULLSCREEN : 0;

    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        printf("Fallo de inicio de SDL\n");
        return false;
    }

    m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, flags);

    if (m_pWindow == 0)
    {
        printf("Fallo de inicio de la ventana\n");
        return false;
    }

    m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);

    if (m_pRenderer == 0)
    {
        printf(" Fallo de inicio del renderizador\n");
        return false;
    }

    printf("Se iniciaron los sistemas correctamente");
    SDL_SetRenderDrawColor(m_pRenderer, 255, 255, 255, 255);
    g_running = true;
    return true;
}

void Game_Engine::render()
{
    SDL_RenderClear(m_pRenderer);
    SDL_RenderPresent(m_pRenderer);
}

void Game_Engine::update()
{
    SDL_DestroyWindow(m_pWindow);
    SDL_DestroyRenderer(m_pRenderer);
    SDL_Quit();
}

void Game_Engine::handleEvents()
{
    SDL_Event event;
    if (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_QUIT:
            g_running = true;
            break;
        default:
            break;
        }
    }
}

void Game_Engine::clean()
{
    SDL_DestroyWindow(m_pWindow);
    SDL_DestroyRenderer(m_pRenderer);
    SDL_Quit();
}
