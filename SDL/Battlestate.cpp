#include "BattleState.h"

BattleState::BattleState(Manager* GSManager, SDL_Renderer* Renderer, Player* player, Trainer* trainer) : Gamestate(GSManager,Renderer)
{
	renderer = Renderer;
	PEntity = player;
	TEntity = trainer;
	PlayerAnim = new Timer(2.5);
	Name = "Battle";
	Backgrounds = new Background("Asset/Maps/Background.png", renderer);
	Menu = new Background("Asset/Menus/MenuBackground.png", renderer);
	BattleTheme = Mix_LoadMUS("Asset/Music/LeaderTheme.wav");
	Mix_PlayMusic(BattleTheme, -1);
	PEMoemonNum = 0;
	TEMoemonNum = 0;
	textManager = new Text();
	textManager->create("Frostlass Used Shadow Punch! It was super effective.",renderer);
	MBattleMenu = true;
	PlayerTurn = true;
	textInit();
}

BattleState::~BattleState()
{
	Mix_HaltMusic();
	delete PlayerAnim;
	delete Backgrounds;
	delete Menu;
	delete textManager;
	TMenu.clear();
	TSMenu.clear();
}

bool BattleState::EventHandle()
{
	SDL_Event eve;
	while (SDL_PollEvent(&eve))
	{
		switch (eve.type)
		{
		case SDL_QUIT:
			break;
		case SDL_KEYDOWN:
			switch (eve.key.keysym.sym)
			{
			case SDLK_ESCAPE:
				if (MBattleMenu == true)
				{
					GSManager->RemoveLast();
				}
				else
				{
					MBattleMenu = true;
				}
			case SDLK_w:
				MenuSelection -= 2;
				if (MenuSelection <= -1)
				{
					MenuSelection +=2;
				}
				break;
			case SDLK_s:
				MenuSelection += 2;
				if (MenuSelection >= 4)
				{
					MenuSelection -=2;
				}
				break;
			case SDLK_RETURN:
				if (MBattleMenu == false)
				{
				useSkill();
				}
				menu();
				
				break;
			case SDLK_d:
				MenuSelection += 1;
				if (MenuSelection >= 4)
				{
					MenuSelection -= 1;
				}
				break;
			case SDLK_a:
				MenuSelection -= 1;
				if (MenuSelection <= -1)
				{
					MenuSelection += 1;
				}
				break;
			case SDLK_k:
				TEntity->getBag()->get(TEMoemonNum)->setHealth(40000);
				break;
			}
		}
	}
	return true;
}

void BattleState::update(float deltat)
{
	dt = deltat;
	PlayerAnim->updateTimer(dt);
	if (PEntity->getBag()->get(PEMoemonNum)->getHealth() <= 0)
	{
		if (PEntity->getStorageSize() > (PEMoemonNum + 1))
		{
			PEMoemonNum += 1;
			textInit();
		}
		else
		{
			GSManager->RemoveLast();
		}
		
		
	}
	if (TEntity->getBag()->get(TEMoemonNum)->getHealth() <= 0)
	{
		if (TEntity->getStorageSize() > (TEMoemonNum + 1))
		{
			TEMoemonNum += 1;
		}
		else
		{
			GSManager->RemoveLast();
		}
	}
	

}

void BattleState::draw()
{
	
	SDL_Rect descRect;
	descRect.x = 0;
	descRect.y = 0;
	descRect.w = 640;
	descRect.h = 480;
	SDL_Rect dummyRect = {0,0,320,100};
	SDL_Rect menuRect = { 320, 380, 320, 100 };
	SDL_Rect ETrainerM;

	ETrainerM.x = 400;
	ETrainerM.y = 74;
	ETrainerM.w = (64 * 3);
	ETrainerM.h = (64 * 3);

	TEntity->getBag()->get(TEMoemonNum)->setDescRect(ETrainerM);
	Backgrounds->callDraw(renderer, Backgrounds->getTexture(), descRect, descRect);
	
	if (AnimationCount <= 5)
	{
		TEntity->BattleAnimation(renderer);
		PEntity->battleAnimation(PlayerAnim, dt, renderer, AnimationCount);
		
	}
	if (AnimationCount > 5)
	{
		Menu->callDraw(renderer, Menu->getTexture(), menuRect, dummyRect);
		TEntity->getBag()->get(TEMoemonNum)->callDraw(renderer);
		PEntity->getBag()->get(PEMoemonNum)->callDraw(renderer);
		SDL_SetRenderDrawColor(renderer, 255, 0, 0, 0);
		if (MBattleMenu == true)
		{
			for (unsigned int i = 0; i < TMenu.size(); i++)
			{
				TMenu[i]->callDraw(renderer);
			}	
		
		SDL_RenderDrawRect(renderer, &TMenu[MenuSelection]->getRect());
		
		}
		if (MBattleMenu == false)
		{
			for (unsigned int j = 0; j <= TMenu.size()+1; )
			{
				TSMenu[j]->callDraw(renderer);
				j++;
			}
			SDL_RenderDrawRect(renderer, &TSMenu[MenuSelection]->getRect());
		}
		SDL_SetRenderDrawColor(renderer, 0x0, 0x0, 0x0, 0x0);
		//textManager->callDraw(renderer);
		
		
	}
}

void BattleState::menu()
{
	if (MBattleMenu == true)
	{
		if (MenuSelection == 0)
		{
			MBattleMenu = false;
		}
		else
		{
			if (MenuSelection == 1)
			{
				GSManager->RemoveLast();
			}
		}
	}
	if (MBattleMenu == false)
	{
		PEntity->getBag()->get(PEMoemonNum)->getLearnedSkills()->useSkill(MenuSelection);
	}
}

void BattleState::textInit()
{
	TMenu.clear();
	TSMenu.clear();
	Text* temp = new Text();
	temp->create("Fight", renderer);
	SDL_Rect temprec = { 370, 400, 0, 0 };
	temp->setRect(temprec);
	Text* temp1 = new Text();
	temp1->create("Run", renderer);
	SDL_Rect temprec1 = { 520, 400, 0, 0 };
	temp1->setRect(temprec1);
	TMenu.push_back(temp);
	TMenu.push_back(temp1);

	SDL_Rect skill1 = { 350, 405, 0, 0 };

	SDL_Rect skill2 = { 465, 405, 0, 0 };

	SDL_Rect skill3 = { 350, 445, 0, 0 };

	SDL_Rect skill4 = { 465, 445, 0, 0 };

	for (int i = 0; i < sizeof(PEntity->getBag()->get(PEMoemonNum)->getLearnedSkills()); i++)
	{
		if (i == 0)
		{
			PEntity->getBag()->get(PEMoemonNum)->getLearnedSkills()->getSkill(i)->getText()->setRect(skill1);
		}
		else
		{
			if (i == 1)
			{
				PEntity->getBag()->get(PEMoemonNum)->getLearnedSkills()->getSkill(i)->getText()->setRect(skill2);
			}
			else
			{
				if (i == 2)
				{
					PEntity->getBag()->get(PEMoemonNum)->getLearnedSkills()->getSkill(i)->getText()->setRect(skill3);
				}
				else
				{
					PEntity->getBag()->get(PEMoemonNum)->getLearnedSkills()->getSkill(i)->getText()->setRect(skill4);
				}
			}

		}
		TSMenu.push_back(PEntity->getBag()->get(PEMoemonNum)->getLearnedSkills()->getSkill(i)->getText());
	}

	
}

void BattleState::useSkill()
{
		
		if (PlayerTurn == true)
		{
			/*
			The damage is calculated through this slightly altered Pokemon Damage Formula
			Damage = (((2 * Level) + 10) / 20) * (Enemey Defese / Player Attack) * (Skill Base Attack) * Modifier))

			Formula was found here : http://bulbapedia.bulbagarden.net/wiki/Damage
			*/
			float Modifier = (STAB() * 1 * 2 * PlayerAnim->randNum(1, 2));
			float damage = ((((2.0f * PEntity->getBag()->get(PEMoemonNum)->getLevel()) + 10.0f) / 200.0f) *
				(PEntity->getBag()->get(PEMoemonNum)->getAttack() / TEntity->getBag()->get(TEMoemonNum)->getDefense()) *
				(PEntity->getBag()->get(PEMoemonNum)->getLearnedSkills()->getSkill(MenuSelection)->getAttack()) * Modifier);

			TEntity->getBag()->get(TEMoemonNum)->setHealth(damage);
			std::cout << "You deal : " << damage << std::endl << "Enemy Health is :" << TEntity->getBag()->get(TEMoemonNum)->getHealth() << std::endl;
			PlayerTurn = false;
			useSkill();
		}
		else
		{
			AI();
			float Modifier = (STAB() * 1.0f * 2.0f * PlayerAnim->randNum(1, 2));
			float Enemydamage = ((((2.0f * TEntity->getBag()->get(TEMoemonNum)->getLevel()) + 10.0f) / 200.0f) *
				(PEntity->getBag()->get(PEMoemonNum)->getDefense() / TEntity->getBag()->get(TEMoemonNum)->getAttack()) *
				(TEntity->getBag()->get(TEMoemonNum)->getLearnedSkills()->getSkill(EnemySelection)->getAttack()) * Modifier);
			PEntity->getBag()->get(PEMoemonNum)->setHealth(Enemydamage);
			std::cout << "Your dealt : " << Enemydamage << std::endl << "Your Health is : " << PEntity->getBag()->get(PEMoemonNum)->getHealth() << std::endl;
			PlayerTurn = true;
		}

}

float BattleState::STAB()
{
	if (PlayerTurn == true)
	{
		if (PEntity->getBag()->get(PEMoemonNum)->getType() == PEntity->getBag()->get(PEMoemonNum)->getLearnedSkills()->getSkill(MenuSelection)->getType())
		{
			return 1.5;
		}
		else
		{
			return 1;
		}
	}
	else
	{
		if (TEntity->getBag()->get(TEMoemonNum)->getType() == TEntity->getBag()->get(TEMoemonNum)->getLearnedSkills()->getSkill(EnemySelection)->getType())
		{
			return 1.5;
		}
		else
		{
			return 1;
		}
	}
}

void BattleState::AI()
{
	EnemySelection = PlayerAnim->randNum(0, TEntity->getStorageSize());
	if (EnemySelection > TEntity->getStorageSize())
	{
		AI();
	}
}

//TSMenu.push_back(PEntity->getBag()->get(PEMoemonNum)->getLearnedSkills()->getSkill(1)->getText());
	//TSMenu.push_back(PEntity->getBag()->get(PEMoemonNum)->getLearnedSkills()->getSkill(2)->getText());
	//TSMenu.push_back(PEntity->getBag()->get(PEMoemonNum)->getLearnedSkills()->getSkill(3)->getText());


/*
Create a skill function inside battle
Have it get the power, acc and name of skill.
Have it take away from the enemys health.
Load in new art asset (health bars)

To get percentage based bars its : Current Health / Max Health * 100;

Use this to create a rect that can scale to any max health, and show a percentage based version of the healthbar.
Have it play damage sound when low

Have text for skills stored inside skills themselves.
Have text for moemon name stored inside themselves.
Have text for trainers name stored inside itself.

*/