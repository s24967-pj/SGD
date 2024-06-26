#ifndef  game_h //zabezpieczenie aby klasa nie kompilowala sie wiele razy
#define game_h

#include <SDL.h>
#include <SDL_image.h> 
#undef main // Brak redefinicji f main, aby usunac problem z odpaleniem okna na windowsie
#include <iostream>

class Game 
{

public:
    Game();
    ~Game();

    void init(const char* title, int width, int height, bool fullscreen);
    void handleEvents();
    void update();
    void render();
    void clean();
    
    static SDL_Renderer *renderer;


    bool running() 
    { 
        return isRunning; 
    }

    int index = 0; //uzywany do zmiany kostiumow

private:
    
    bool isRunning;
    SDL_Window* window;

    void GameReset();
};
#endif // ! gra_hpp#pragma once
