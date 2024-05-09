#ifndef  game_h
#define game_h

#include <SDL.h>
#undef main // Brak redefinicji f main, aby usun�� problem z odpaleniem okna na windowsie
#include <iostream>

class Game {

public:
    Game();
    ~Game();

    void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
    void handleEvents();
    void update();
    void render();
    void clean();

    bool running() { return isRunning; }

private:
    int cnt = 0;
    bool isRunning;
    SDL_Window* window;
    SDL_Renderer* renderer;

};
#endif // ! gra_hpp#pragma once
