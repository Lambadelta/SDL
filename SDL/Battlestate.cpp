#include "BattleState.h"

BattleState::BattleState(Manager* GSManager, SDL_Renderer* Renderer, Player* player, Trainer* trainer) : Gamestate(GSManager,Renderer)
{
	renderer = Renderer;
	PEntity = player;
	TEntity = trainer;
	Wild = NULL;
	GymBattle = false;
	BattleTheme = Mix_LoadMUS("Asset/Music/LeaderTheme.wav");
	init();
}
BattleState::BattleState(Manager* GSManager, SDL_Renderer* Renderer, Player* player, Moemon* wildMoemon) : Gamestate(GSManager, Renderer)
{
	renderer = Renderer;
	PEntity = player;
	Wild = new MoeMonStorage();
	GymBattle = false;
	Wild->add(wildMoemon, wildMoemon->getLevel());
	BattleTheme = Mix_LoadMUS("Asset/Music/WildBattle.wav");
	TEntity = new Trainer(Wild, "", renderer);
	init();
}

BattleState::BattleState(Manager* GSManager, SDL_Renderer* Renderer, Player* player, Trainer* trainer, bool gymLeader) : Gamestate(GSManager, Renderer)
{
	renderer = Renderer;
	PEntity = player;
	TEntity = trainer;
	GymBattle = gymLeader;
	BattleTheme = Mix_LoadMUS("Asset/Music/LeaderTheme.wav");
	init();
}

BattleState::~BattleState()
{
	Mix_FreeMusic(BattleTheme);
	delete PlayerAnim;
	delete Backgrounds;
	delete Menu;
	delete HealthBars;
	delete Health;
	TMenu.clear();
	TSMenu.clear();
}

void BattleState::init()
{
	PlayerAnim = new Timer(2.5);
	Name = "Battle";
	Backgrounds = new Background("Asset/Maps/Background.png", renderer);
	Menu = new Background("Asset/Menus/MenuBackground.png", renderer);
	HealthBars = new Background("Asset/Menus/HealthBars.png", renderer);
	Health = new Background("Asset/Menus/Healthbar.png", renderer);
	Mix_PlayMusic(BattleTheme, -1);
	Mix_VolumeMusic(30);
	PEMoemonNum = 0;
	TEMoemonNum = 0;
	MBattleMenu = true;
	PlayerTurn = true;
	textInit();
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
				if (MBattleMenu == false)
				{
					MenuSelection += 2;
					if (MenuSelection >= 4)
					{
						MenuSelection -= 2;
					}
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
				if (MBattleMenu == true)
				{
					MenuSelection = 1;
				}
				if (MBattleMenu == false)
				{
					MenuSelection += 1;
					if (MenuSelection > 3)
					{
						MenuSelection -= 1;
					}
				}
				break;
			case SDLK_a:
				if (MBattleMenu == true)
				{
					MenuSelection = 0;
				}
				if (MBattleMenu == false)
				{
					MenuSelection -= 1;
					if (MenuSelection < 0)
					{
						MenuSelection += 1;
					}
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
	THealthBar = { 50, 55, (TEntity->getBag()->get(TEMoemonNum)->getHPPercentage() * 1.58), 12 };
	PHealthBar = { 460, 333, (PEntity->getBag()->get(PEMoemonNum)->getHPPercentage() * 1.58), 12 };
}

void BattleState::draw()
{
	checkPDefeat();
	SDL_Rect descRect = { 0, 0, 640, 480 };
	SDL_Rect dummyRect = {0,0,320,100};
	SDL_Rect dummyHealth = { 0, 0, 158, 12 };
	SDL_Rect menuRect = { 320, 380, 320, 100 };
	SDL_Rect ETrainerM = { 400, 74, (64 * 3), (64 * 3) };

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
		HealthBars->callDraw(renderer, HealthBars->getTexture(), descRect, descRect);
		TEntity->getBag()->get(TEMoemonNum)->callDraw(renderer);
		PEntity->getBag()->get(PEMoemonNum)->callDraw(renderer);

		TEntity->getBag()->get(TEMoemonNum)->getTextName()->setRect(TNameLoc);
		PEntity->getBag()->get(PEMoemonNum)->getTextName()->setRect(PNameLoc);
		TEntity->getBag()->get(TEMoemonNum)->getTextName()->callDraw(renderer);
		PEntity->getBag()->get(PEMoemonNum)->getTextName()->callDraw(renderer);
	
		TEntity->getBag()->get(TEMoemonNum)->getTextLevel()->setRect(TLevelLoc);
		PEntity->getBag()->get(PEMoemonNum)->getTextLevel()->setRect(PLevelLoc);
		TEntity->getBag()->get(TEMoemonNum)->getTextLevel()->callDraw(renderer);
		PEntity->getBag()->get(PEMoemonNum)->getTextLevel()->callDraw(renderer);

		Health->callDraw(renderer, Health->getTexture(), THealthBar, dummyHealth);
		Health->callDraw(renderer, Health->getTexture(), PHealthBar, dummyHealth);
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
		/*PEntity->getBag()->get(PEMoemonNum)->getLearnedSkills()->useSkill(MenuSelection);*/
	}
}

void BattleState::textInit()
{
	TNameLoc = { 15, 15, TEntity->getBag()->get(TEMoemonNum)->getTextName()->getWidth(), TEntity->getBag()->get(TEMoemonNum)->getTextName()->getHeight() };
	PNameLoc = { 360, 290, PEntity->getBag()->get(PEMoemonNum)->getTextName()->getWidth(), PEntity->getBag()->get(PEMoemonNum)->getTextName()->getHeight() };
	TLevelLoc = { 240, 15, TEntity->getBag()->get(TEMoemonNum)->getTextLevel()->getWidth(), TEntity->getBag()->get(TEMoemonNum)->getTextLevel()->getHeight() };
	PLevelLoc = { 590, 290, PEntity->getBag()->get(PEMoemonNum)->getTextLevel()->getWidth(), PEntity->getBag()->get(PEMoemonNum)->getTextLevel()->getHeight() };
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

	SDL_Rect skill1 = { 313, 405, 0, 0 };

	SDL_Rect skill2 = { 475, 405, 0, 0 };

	SDL_Rect skill3 = { 313, 445, 0, 0 };

	SDL_Rect skill4 = { 475, 445, 0, 0 };

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

bool BattleState::useSkill()
{
		
		if (PlayerTurn == true)
		{
			/*
			The damage is calculated through this slightly altered Pokemon Damage Formula
			Damage = (((2 * Level) + 10) / 20) * (Enemey Defese / Player Attack) * (Skill Base Attack) * Modifier))

			Formula was found here : http://bulbapedia.bulbagarden.net/wiki/Damage
			*/
			float Modifier = (STAB() * 1.0f * 1.5f * PlayerAnim->randNum(1, 2));
			float damage = ((((2.0f * PEntity->getBag()->get(PEMoemonNum)->getLevel()) + 10.0f) / 200.0f) *
				(PEntity->getBag()->get(PEMoemonNum)->getAttack() / TEntity->getBag()->get(TEMoemonNum)->getDefense()) *
				(PEntity->getBag()->get(PEMoemonNum)->getLearnedSkills()->getSkill(MenuSelection)->getAttack()) * Modifier);

			TEntity->getBag()->get(TEMoemonNum)->setHealth((damage / 1.5f));
			std::cout << "You deal : " << damage << std::endl << "Enemy Health is :" << TEntity->getBag()->get(TEMoemonNum)->getHealth() << std::endl;
			PlayerTurn = false;
			checkTDefeat();
			if (PlayerTurn == false)
			{
				useSkill();
			}
			else
			{
				return false;
			}
		}
		else
		{
			AI();
			float Modifier = (STAB() * 1.0f * 1.5f * PlayerAnim->randNum(1, 2));
			float Enemydamage = ((((2.0f * TEntity->getBag()->get(TEMoemonNum)->getLevel()) + 10.0f) / 200.0f) *
				(PEntity->getBag()->get(PEMoemonNum)->getDefense() / TEntity->getBag()->get(TEMoemonNum)->getAttack()) *
				(TEntity->getBag()->get(TEMoemonNum)->getLearnedSkills()->getSkill(EnemySelection)->getAttack()) * Modifier);
			PEntity->getBag()->get(PEMoemonNum)->setHealth(Enemydamage / 2);
			std::cout << "Your dealt : " << Enemydamage << std::endl << "Your Health is : " << PEntity->getBag()->get(PEMoemonNum)->getHealth() << std::endl;
			checkPDefeat();
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

void BattleState::checkPDefeat()
{
	if (PEntity->getBag()->get(PEMoemonNum)->getHealth() <= 0)
	{
		if (PEntity->getStorageSize() > (PEMoemonNum + 1))
		{
			PEMoemonNum += 1;
			textInit();

		}
		else
		{
			if (GymBattle == true)
			{
				GSManager->Change(new Creditsstate(GSManager, renderer));
			}
			else
			{
				GSManager->Change(new Titlestate(GSManager, renderer));
			}
		}


	}

}

void BattleState::checkTDefeat()
{
	if (TEntity->getBag()->get(TEMoemonNum)->getHealth() <= 0)
	{
		if (TEntity->getStorageSize() > (TEMoemonNum + 1))
		{
			TEMoemonNum += 1;
			PEntity->getBag()->get(PEMoemonNum)->addEXP((TEntity->getBag()->get(TEMoemonNum)->getLevel() / PEntity->getBag()->get(PEMoemonNum)->getLevel()) * 10);
			PlayerTurn = true;
		
		}
		else
		{
			TEntity->setDefeated(true);
			PEntity->getBag()->get(PEMoemonNum)->addEXP((TEntity->getBag()->get(TEMoemonNum)->getLevel() / PEntity->getBag()->get(PEMoemonNum)->getLevel()) * 10);
			if (GymBattle == true)
			{
				GSManager->Change(new Creditsstate(GSManager, renderer));
			}
			else
			{
				GSManager->RemoveLast();
			}
		}
	}
}



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