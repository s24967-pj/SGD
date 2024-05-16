#include "game.h"
#include "TextureControl.h"
#include "Map.h"
#include "Object.h"


bool gameOver = false;
SDL_Texture* playerTexture;
SDL_Rect srcR, destR;
Object* hamster;
Object* bush;
Object* bird;
Object* bird2;
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

    const char* ptagi[] = { "assets/birdup.png", "assets/birddown.png", 0 };
    const char* omiki[] = { "assets/hamster.png", 0, 0 };
    const char* brokuly[] = { "assets/bush.png", 0, 0 };

    hamster = new Object(omiki, renderer, 96, 464);
    bush = new Object(brokuly, renderer, 800, 464);
    bird = new Object(ptagi, renderer, 1200, 412);
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
    else if (keystates[SDL_SCANCODE_R]) 
    {
        gameOver = false;
        GameReset();
    }


  
}

void Game::GameReset() 
{
    bush->ResetBush();
    bird->ResetBird();
}

void Game::update()
{
    if (gameOver)
    {
        return;
    }
    int hamsterCollisionMargin = 110;
    int bushCollisionMargin = 65;

    if (hamster->GetX() + hamsterCollisionMargin >= bush->GetX() &&
        hamster->GetX() <= bush->GetX() + bushCollisionMargin)
    {
        if (hamster->GetY() >= 464 && hamster->GetY() <= 534)
        {
            gameOver = true;
            std::cout << "Kolizja!" << std::endl;
        }
    }
 
     hamster->UpdateHamster();
    
     bush->MoveLeft();    
     bush->DrawBush(); 

     
     bird->MoveLeft();
     
     bird->Draw();
      
}


void Game::render()
{
    SDL_RenderClear(renderer);
    //dodajemy tekstury, wyzsze background, nizsze blizej
    map->DrawMap();
    bird->Render(index);
    bush->Render(0);
    hamster->Render(0);
    SDL_RenderPresent(renderer);
}

void Game::clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout << "Game clean" << std::endl;
}


