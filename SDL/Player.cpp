#include "Player.h"


Player::Player(SourceRect v1, SourceRect sr1, float s) : Entity()
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

void Player::callMove(SDL_Keycode move, Time &time, Timer* Anim)
{
	Anim->updateTimer(time.getDelta());
		switch (move)
		{
		case SDLK_w:
			if (Anim->expiredTimer())
			{
				SrcRect.y = 44;
				SrcRect.x += 22;
				if (SrcRect.x >= 66)
				{
					SrcRect.x = 0;
				}
				DescRect.y -= fSpeed * time.getDelta();
				Anim->updateTimer(time.getDelta());
				std::cout << "W is pressed\n";
			}
			break;
		case SDLK_s:
			if (Anim->expiredTimer())
			{
				SrcRect.y = 0;
				SrcRect.x += 22;
				if (SrcRect.x >= 66)
				{
					SrcRect.x = 0;
				}
				DescRect.y += fSpeed * time.getDelta();
				std::cout << "S is pressed\n";
				Anim->updateTimer(time.getDelta());
			}
			break;
		case SDLK_d:
			if (Anim->expiredTimer())
			{
				SrcRect.y = 22;
				SrcRect.x += 22;
				if (SrcRect.x >= 66)
				{
					SrcRect.x = 0;
				}
				DescRect.x += fSpeed * time.getDelta();
				std::cout << "D is pressed\n";
				Anim->updateTimer(time.getDelta());
			}
			break;
		case SDLK_a:
			if (Anim->expiredTimer())
			{
				SrcRect.y = 66;
				SrcRect.x += 22;
				if (SrcRect.x >= 66)
				{
					SrcRect.x = 0;
				}
				DescRect.x -= fSpeed * time.getDelta();
				std::cout << "A is pressed\n";
				Anim->updateTimer(time.getDelta());
			}
			break;
		case SDLK_k:
			std::cout <<"delta is: "<< time.getDelta() << "\n";
			std::cout <<"animation time is: "<< Anim->debug() << "\n";
			break;
		}
}

/* Methods to add or subtract from the life of the player*/
void Player::addLives(int life)
{
	iLives += life;
}
void Player::subLives(int damage)
{
	iLives -= damage;
}

/*Method to get the current life of the player*/
int Player::getLives()
{
	return iLives;
}
