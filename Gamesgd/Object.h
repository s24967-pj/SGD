#include "game.h"


class Object 
{
public:
	Object(const char* texturesheet, SDL_Renderer* rend);
	~Object();

	void Update();
	void Render();
private:
	int xpos;
	int ypos;

	SDL_Texture* objTexture;
	SDL_Rect srcRect, destRect;
	SDL_Renderer* renderer;
};
