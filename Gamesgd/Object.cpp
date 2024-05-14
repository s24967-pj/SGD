#include "Object.h"
#include "TextureControl.h"

Object::Object(const char* texturesheet, SDL_Renderer* rend, int x, int y)
{
	renderer = rend;
	objTexture = TextureControl::LoadTexture(texturesheet);
	
	xpos = x;
	ypos = y;
}

void Object::Update()
{
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

void Object::MoveRight()
{
	xpos++;
}

void Object::MoveLeft()
{
	xpos--;
}

void Object::Fall()
{
	ypos++;
}
