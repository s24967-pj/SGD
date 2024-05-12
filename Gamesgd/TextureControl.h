#include "game.h"

class TextureControl
{
public:
	static SDL_Texture* LoadTexture(const char* fileName);
	static void Drawing(SDL_Texture* tex, SDL_Rect src, SDL_Rect dest);
};
