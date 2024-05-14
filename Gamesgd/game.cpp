#include "game.h"
#include "TextureControl.h"
#include "Map.h"
#include "Object.h"
#include "Entity.h"
#include "Component.h"


SDL_Texture* playerTexture;
SDL_Rect srcR, destR;
Object* hamster;
Map* map;
SDL_Renderer* Game::renderer = nullptr;

Manager manager;
auto& newPlayer(manager.addEntity());


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

    hamster = new Object("assets/hamster.png", renderer);
    map = new Map();

    newPlayer.addComponent<PositionComponent>();

}

void Game::handleEvents()
{
    SDL_Event event;
    SDL_PollEvent(&event);
    switch (event.type) 
    {
    case SDL_QUIT:
        isRunning = false;
        break;

    default:
        break;
    }
}

void Game::update()
{
    hamster->Update();
    manager.update();

    std::cout << newPlayer.getComponent<PositionComponent>().x() << ", " <<
        newPlayer.addComponent<PositionComponent>().y() << std::endl;
}

void Game::render()
{
    SDL_RenderClear(renderer);
    //dodajemy tekstury, wyzsze background, nizsze blizej
    map->DrawMap();
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
