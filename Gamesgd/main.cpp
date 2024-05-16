#include "game.h"

Game* game = nullptr;

int main(int argc, const char* argv[]) 
{
    const int FPS = 60; //tworzenie fpsow
    const int frameDelay = 1000 / FPS;
    const int changeCount = 5;

    Uint32 frameStart;
    int frameTime;
    float frame = 0.f;
    float frameSpeed = 0.4f;

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

        frame += frameSpeed;
        if (frame > changeCount)
        {
            frame -= changeCount;
            game-> index++;

            if (game->index >= 2) { game->index = 0; }
        }
    }
    game->clean();
    return 0;
}