#include "Object.h"
#include "TextureControl.h"

const int gravity = 5;
bool isJumping = false;
bool isOnTheGround = true;
const int hamsterybottom = 484;

Object::Object(const char* texturesheet, SDL_Renderer* rend, int x, int y)
{
	renderer = rend;
	objTexture = TextureControl::LoadTexture(texturesheet);
	
	xpos = x;
	ypos = y;
}

void Object::Update()
{
	if (isJumping)
	{
		ypos -= gravity;
	}
	else
	{
		ypos += gravity;
	}

	if (ypos >= hamsterybottom)
	{
		ypos = hamsterybottom;
		isOnTheGround = true;
	}

	if (ypos <= hamsterybottom - 96)
	{
		isJumping = false;
	}

	Draw();
}

void Object::Draw()
{
	srcRect.h = 96;
	srcRect.w = 96;
	srcRect.x = 0;
	srcRect.y = 0;

	destRect.x = xpos;
	destRect.y = ypos;
	destRect.w = srcRect.w * 2;
	destRect.h = srcRect.h * 2;
}

void Object::UpdatePizza()
{
	srcRect.h = 64;
	srcRect.w = 64;
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

void Object::Jump()
{
	if (isOnTheGround && !isJumping)
	{
		isJumping = true;
		isOnTheGround = false;
	}

	
}




