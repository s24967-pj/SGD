#include "Object.h"
#include "TextureControl.h"

const int gravity = 5;
bool isAvoiding = false;
bool isJumping = false;
bool isOnTheGround = true;
const int hamsterybottom = 484;
const int stopedos = 0;

Object::Object(const char* texturesheet[2], SDL_Renderer* rend, int x, int y)
{
	renderer = rend;

	for (int i = 0; i < 2; i++)
	{
		if (texturesheet[i] != 0)
		{
			objTexture[i] = TextureControl::LoadTexture(texturesheet[i]);
		}
	}
	
	xpos = x;
	ypos = y;
}

void Object::UpdateHamster()
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

	if (ypos <= hamsterybottom - 96 * 1.5)
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

void Object::DrawBush()
{
	srcRect.h = 70;
	srcRect.w = 70;
	srcRect.x = 0;
	srcRect.y = 0;

	destRect.x = xpos;
	destRect.y = ypos;
	destRect.w = srcRect.w * 2;
	destRect.h = srcRect.h * 2;

}



void Object::Render(int texture)
{
	SDL_RenderCopy(renderer, objTexture[texture], &srcRect, &destRect);
}

void Object::MoveRight()
{
	xpos++;
}

void Object::MoveLeft()
{
	xpos -= 5;
	
	if (xpos <= -100)
	{
		xpos = 900;
	}

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

int Object::GetX()  {
	return xpos;
}

int Object::GetY() {
	return ypos;
}

void Object::ResetBush() {
	
	xpos = 800;
	ypos = 464;
	
}

void Object::ResetBird()
{
	xpos = 1200;
	ypos = 412;
}



