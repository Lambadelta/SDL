#include "Player.h"


Player::Player(Rect v1, Rect sr1, std::string path, SDL_Renderer* renderer) : Entity(path,renderer)
{
	DescRect.x = v1.f_x;
	DescRect.y = v1.f_y;
	DescRect.w = v1.f_w;
	DescRect.h = v1.f_h;
	SrcRect.x = sr1.f_x;
	SrcRect.y = sr1.f_y;
	SrcRect.w = sr1.f_w;
	SrcRect.h = sr1.f_h;
}

Player::~Player()
{

}

void Player::callMoveUp(bool canMove, Timer* AnimTime, int& mapy, int speed)
{
	if (canMove == true && AnimTime->expiredTimer())
	{
		SrcRect.y = 100;
		SrcRect.x += 50;
		if (SrcRect.x >= 150)
		{
			SrcRect.x = 0;
		}
		mapy -= speed;
		AnimTime->resetTimer();
	}
}

void Player::callMoveLeft(bool canMove, Timer* AnimTime, int& mapx, int speed)
{
	if (canMove == true && AnimTime->expiredTimer())
	{
		SrcRect.y = 50;
		SrcRect.x += 50;
		if (SrcRect.x >= 150)
		{
			SrcRect.x = 0;
		}
		mapx -= speed;
		AnimTime->resetTimer();
	}
}

void Player::callMoveRight(bool canMove, Timer* AnimTime, int& mapx, int speed)
{
	if (canMove == true && AnimTime->expiredTimer())
	{
		SrcRect.y = 150;
		SrcRect.x += 50;
		if (SrcRect.x >= 150)
		{
			SrcRect.x = 0;
		}
		mapx += speed;
		AnimTime->resetTimer();
	}

}

void Player::callMoveDown(bool canMove, Timer* AnimTime, int& mapy, int speed)
{
	if (canMove == true && AnimTime->expiredTimer())
	{
		SrcRect.y = 0;
		SrcRect.x += 50;
		if (SrcRect.x >= 150)
		{
			SrcRect.x = 0;
		}
		mapy += speed;
		AnimTime->resetTimer();
	}
}
void Player::callDraw(SDL_Renderer* Renderer)
{
	/*Coping the destination surface with the texture from the Source surface using the Rect data*/
	SDL_RenderCopy(Renderer, EntityTexture, &SrcRect, &DescRect);

}

Vec2 Player::XYpos()
{
	Vec2 XY;
	XY.f_x = DescRect.x;
	XY.f_y = DescRect.y;

	return XY;
}

int Player::rtnWidth()
{
	return DescRect.w;
}

int Player::rtnHeight()
{
	return DescRect.y;
}
