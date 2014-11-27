#include "Player.h"


Player::Player(Rect v1, Rect sr1, float s) : Entity()
{
	EntitySurface = NULL;
	EntityTexture = NULL;
	DescRect.x = v1.f_x;
	DescRect.y = v1.f_y;
	DescRect.w = v1.f_w;
	DescRect.h = v1.f_h;
	SrcRect.x = sr1.f_x;
	SrcRect.y = sr1.f_y;
	SrcRect.w = sr1.f_w;
	SrcRect.h = sr1.f_h;
	fSpeed = s;
}

Player::~Player()
{

}

void Player::callMoveUp(bool canMove, Timer* PlayerAnim, Time dt)
{
	if (canMove == true && PlayerAnim->expiredTimer())
	{
		SrcRect.y = 44;
		SrcRect.x += 22;
		if (SrcRect.x >= 66)
		{
			SrcRect.x = 0;
		}
		DescRect.y -= fSpeed /** dt.getDelta()*/;
	}
}

void Player::callMoveLeft(bool canMove, Timer* PlayerAnim, Time dt)
{
	if (canMove == true && PlayerAnim->expiredTimer())
	{
		SrcRect.y = 66;
		SrcRect.x += 22;
		if (SrcRect.x >= 66)
		{
			SrcRect.x = 0;
		}
		DescRect.x -= fSpeed /** dt.getDelta()*/;
	}
}

void Player::callMoveRight(bool canMove, Timer* PlayerAnim, Time dt)
{
	if (canMove == true && PlayerAnim->expiredTimer())
	{
		SrcRect.y = 22;
		SrcRect.x += 22;
		if (SrcRect.x >= 66)
		{
			SrcRect.x = 0;
		}
		DescRect.x += fSpeed /** dt.getDelta()*/;
	}

}

void Player::callMoveDown(bool canMove, Timer* PlayerAnim, Time dt)
{
	if (canMove == true && PlayerAnim->expiredTimer())
	{
		SrcRect.y = 0;
		SrcRect.x += 22;
		if (SrcRect.x >= 66)
		{
			SrcRect.x = 0;
		}
		DescRect.y += fSpeed /** dt.getDelta()*/;
	}
}
