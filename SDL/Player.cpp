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

void Player::callMove(char* input, Time time)
{
	/*input check if
		
		Checking the input for which input has been pressed then assigning the correct 
		boolean to the appropriate variable.*/

	{
		if (input == "UP") //input check
		{
			bMoveUp = true;   //up is true
			SrcRect.y = 44;
			SrcRect.x += 22;
			if (SrcRect.x >= 66)
			{
				SrcRect.x = 0;
			}
		}
		if (input == "DOWN")
		{
			bMoveDown = true;  //down is true
			SrcRect.y = 0;
			SrcRect.x += 22;
			if (SrcRect.x >= 66)
			{
				SrcRect.x = 0;
			}
		}
		if (input == "LEFT")
		{
			bMoveLeft = true;  //left is true
			
		}
		if (input == "RIGHT")
		{
			bMoveRight = true;  //right is true
			SrcRect.y = 22;
			SrcRect.x += 22;
			if (SrcRect.x >= 66)
			{
				SrcRect.x = 0;
			}
		}
		/*if input is nothing then set everything to false.*/
		if (input == "")
		{
			bMoveUp = false;
			bMoveDown = false;
			bMoveRight = false;
			bMoveLeft = false;
		}
	}
	/*Movement if
	
		Checks the booleans for their corresponding direction waiting for when the button is pressed
		to start movement.*/

	{
		if (bMoveUp == true)
		{
			DescRect.y -= fSpeed * time.getDelta(); 
		}
		if (bMoveDown == true)
		{
			DescRect.y += fSpeed * time.getDelta();
		}
		if (bMoveLeft == true)
		{
			DescRect.x -= fSpeed * time.getDelta();
		}
		if (bMoveRight == true)
		{
			DescRect.x += fSpeed * time.getDelta();
		}
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
