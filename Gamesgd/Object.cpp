#include "Object.h"
#include "TextureControl.h"

Object::Object(const char* texturesheet, SDL_Renderer* rend)
{
	renderer = rend;
	objTexture = TextureControl::LoadTexture(texturesheet);
}

void Object::Update()
{
	xpos = 0;
	ypos = 0;

	srcRect.h = 32;
	srcRect.w = 32;
	srcRect.x = 0;
	srcRect.y = 0;

	destRect.x = xpos;
	destRect.y = ypos;
	destRect.w = srcRect.w * 2;
	destRect.h = srcRect.h * 2;

}

void Object::Render()
{
	SDL_RenderCopy(renderer, objTexture, &srcRect, &destRect);
}
