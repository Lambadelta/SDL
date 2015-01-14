#include "Player.h"


Player::Player(Rect v1, Rect sr1, std::string path, SDL_Renderer* renderer) : Entity(path,renderer)
{
	DescRect.x = (int)v1.f_x;
	DescRect.y = (int)v1.f_y;
	DescRect.w = (int)v1.f_w;
	DescRect.h = (int)v1.f_h;
	SrcRect.x = (int)sr1.f_x;
	SrcRect.y = (int)sr1.f_y;
	SrcRect.w = (int)sr1.f_w;
	SrcRect.h = (int)sr1.f_h;
	SrcAnimRect.x = 0;
	SrcAnimRect.y = 0;
	SrcAnimRect.w = 115;
	SrcAnimRect.h = 100;
	loadIMGA("Asset/Entity/Player/PlayerBattleAnim.png", renderer);
	MoeBag = new MoeMonStorage();

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
	XY.f_x = (float)DescRect.x;
	XY.f_y = (float)DescRect.y;

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

void Player::battleAnimation(Timer* AnimTime, float dt, SDL_Renderer* renderer, int&i)
{
	
		if (AnimTime->expiredTimer())
		{
			callDrawAnimation(renderer);
			//SDL_RenderPresent(renderer);
			SrcAnimRect.x += 115;
			AnimTime->resetTimer();
			i++;
			if (SrcAnimRect.x >= 575)
			{
				SrcAnimRect.x = 0;
			}
		}
}

void Player::callDrawAnimation(SDL_Renderer* renderer)
{
	SDL_Rect DescAnimRect;
	DescAnimRect.x = 50;
	DescAnimRect.y = 180;
	DescAnimRect.w = (115 * 3);
	DescAnimRect.h = (100 * 3);
	SDL_RenderCopy(renderer, AnimaText, &SrcAnimRect, &DescAnimRect);
}

MoeMonStorage* Player::getBag()
{
	return MoeBag;
}
