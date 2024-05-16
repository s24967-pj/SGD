#include "game.h"
#include "TextureControl.h"
#include "Map.h"
#include "Object.h"



SDL_Texture* playerTexture;
SDL_Rect srcR, destR;
Object* hamster;
Object* bush;
Map* map;
SDL_Renderer* Game::renderer = nullptr;



Game::Game()
{}
Game::~Game()
{}

void Game::init(const char* title, int width, int height, bool fullscreen)
{
    int flags = 0;
    if (fullscreen)
    {
        flags = SDL_WINDOW_FULLSCREEN;

    }

    if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, flags);
        renderer = SDL_CreateRenderer(window, -1, 0);
        if (renderer)
        {
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        }

        isRunning = true;
    }
    else
    {
        isRunning = false;
    }

    hamster = new Object("assets/hamster.png", renderer, 0, 484);
    bush = new Object("assets/bush.png", renderer, 500, 464);
    map = new Map();
}

void Game::handleEvents()
{
    SDL_Event event;
    const Uint8* keystates = SDL_GetKeyboardState(NULL);
    SDL_PollEvent(&event);
    switch (event.type) 
    {
        case SDL_QUIT:
            isRunning = false;
            break;

        default:
            break;
    }

    if (keystates[SDL_SCANCODE_DOWN])
    {
        hamster->MoveRight();
    }
    else if (keystates[SDL_SCANCODE_UP])
    {
        hamster->Jump();
    }
}

void Game::update()
{
    hamster->UpdateHamster();
    
     bush->MoveLeft();    
     bush->DrawBush(); 
}


void Game::render()
{
    SDL_RenderClear(renderer);
    //dodajemy tekstury, wyzsze background, nizsze blizej
    map->DrawMap();
    bush->Render();
    hamster->Render();
    SDL_RenderPresent(renderer);
}

void Game::clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout << "Game clean" << std::endl;
}
