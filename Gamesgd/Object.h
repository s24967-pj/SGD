#include "game.h"


class Object 
{
public:
	Object(const char* texturesheet, SDL_Renderer* rend, int x, int y);
	~Object();

	void Update();
	void Render();
	void MoveRight();
	void MoveLeft();
	void Fall();
private:
	int xpos;
	int ypos;

	SDL_Texture* objTexture;
	SDL_Rect srcRect, destRect;
	SDL_Renderer* renderer;
};
