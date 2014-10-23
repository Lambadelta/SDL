#include "Player.h"


Player::Player(Vec2 v1, SourceRect sr1, float s) : Entity(v1,sr1,s)
{
	EntitySurface = NULL;
	EntityTexture = NULL;
	DescRect.x = v1.f_x;
	DescRect.y = v1.f_y;
	SrcRect.x = sr1.f_x;
	SrcRect.y = sr1.f_y;
	SrcRect.w = sr1.f_w;
	SrcRect.h = sr1.f_h;
	fSpeed = s;
}

Player::~Player()
{

}

void Player::callMove(char* input, Timer time)
{

	if (input == "UP")
	{
		bMoveUp = true;
	}
	else
	{
		if (input == "DOWN")
		{
			bMoveDown = true;
		}
		else
		{
			if (input == "LEFT")
			{
				bMoveLeft = true;
			}
			else
			{
				if (input == "RIGHT")
				{
					bMoveRight = true;
				}
				else
				{
					if (input == "")
					{
						bMoveUp = false;
						bMoveDown = false;
						bMoveRight = false;
						bMoveLeft = false;
					}
				}
			}
		}
	}

	{
		if (bMoveUp == true)
		{
			DescRect.y -= fSpeed * time.getDelta();
		}
		else
		{
			std::cout << "Stop Moving Up\n";
		}
		if (bMoveDown == true)
		{
			DescRect.y += fSpeed * time.getDelta();
		}
		else
		{
			std::cout << "Stop Moving Down\n";
		}
		if (bMoveLeft == true)
		{
			DescRect.x -= fSpeed * time.getDelta();
		}
		else
		{
			std::cout << "Stop Moving Left\n";
		}
		if (bMoveRight == true)
		{
			DescRect.x += fSpeed * time.getDelta();
		}
		else
		{
			std::cout << "Stop Moving Right\n";
		}
	}
}
