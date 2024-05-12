#include "game.h"

Game* game = nullptr;

int main(int argc, const char* argv[]) 
{
    const int FPS = 60; //tworzenie fpsow
    const int frameDelay = 1000 / FPS;

    Uint32 frameStart;
    int frameTime;


    game = new Game();
    game->init("BirchEnginde", 800, 640, false);

    while (game->running()) 
    {
        frameStart = SDL_GetTicks();

        game->handleEvents();
        game->update();
        game->render();

        frameTime = SDL_GetTicks() - frameStart;

        if (frameDelay > frameTime)
        {
            SDL_Delay(frameDelay - frameTime);
        }
    }
    game->clean();
    return 0;
}