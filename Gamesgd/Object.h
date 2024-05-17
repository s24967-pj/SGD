#include "game.h"


class Object 
{
public:
	Object(const char* texturesheet[2], SDL_Renderer* rend, int x, int y);
	~Object();

	bool isAvoiding;
	bool isOnTheGround;

	void UpdateHamster();
	void Render(int texture);
	void MoveRight();
	void MoveLeft();
	void Fall();
	void Jump();
	void Draw();
	void DrawBush();
	void MoveLeftBird();
	int GetX();
	int GetY();
	void ResetBush();
	void ResetBird();

private:
	int xpos;
	int ypos;

	SDL_Texture* objTexture[2];
	SDL_Rect srcRect, destRect;
	SDL_Renderer* renderer;

	
};


