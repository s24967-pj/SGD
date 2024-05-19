#include "game.h"

Game* game = nullptr;

int main(int argc, const char* argv[]) 
{
    const int FPS = 60; //tworzenie fpsow
    const int frameDelay = 1000 / FPS;
    const int frameChangeCount = 5;

    Uint32 frameStart;
    int frameTime;
    float frame = 0.f;
    float frameSpeed = 0.4f;

    game = new Game();
    game->init("Hamster_Runner", 800, 640, false);

    while (game->running()) 
    {
        frameStart = SDL_GetTicks(); //pobierasnie ilosci milisekund od kiedy gra zostala uruchomiona

        game->handleEvents();
        game->update();
        game->render();

        frameTime = SDL_GetTicks() - frameStart; //obliczenie ile trwal przebieg jednej petli gry

        if (frameDelay > frameTime) //sprawdzenie czy przebieg petli trwal mniej niz frame delay, dzieki temu na kazdym kompie petla bedzie trwala tyle samo
        {
            SDL_Delay(frameDelay - frameTime); //od tych 17ms odejmujemy ilosc trwania jednej petli
        }


        //zmiana indeksu razem z klatkami - do poruszania ptaka
        frame += frameSpeed;
        if (frame > frameChangeCount)
        {
            frame -= frameChangeCount;
            game-> index++;

            if (game->index >= 2) 
            {
                game->index = 0; 
            }
        }
    }
    game->clean();
    return 0;
}