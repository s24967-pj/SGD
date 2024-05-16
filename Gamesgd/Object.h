#include "game.h"


class Object 
{
public:
	Object(const char* texturesheet, SDL_Renderer* rend, int x, int y);
	~Object();

	void UpdateHamster();
	void Render();
	void MoveRight();
	void MoveLeft();
	void Fall();
	void Jump();
	void Draw();
	void DrawBush();
	int GetX();
	int GetY();
	void Stop();

private:
	int xpos;
	int ypos;

	SDL_Texture* objTexture;
	SDL_Rect srcRect, destRect;
	SDL_Renderer* renderer;

	
};


