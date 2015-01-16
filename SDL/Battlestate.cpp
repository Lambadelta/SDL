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
	TEntity->getBag()->get(0)->setEnemy();
	TEntity->getBag()->get(1)->setEnemy();
	textManager = new Text();
	textManager->create("Frostlass Used Shadow Punch! It was super effective.",renderer);
	MBattleMenu = true;
	textInit();
}

BattleState::~BattleState()
{
	Mix_HaltMusic();
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
		PEMoemonNum = +1;
		textInit();
	}
	if (TEntity->getBag()->get(TEMoemonNum)->getHealth() <= 0)
	{
		if (sizeof(TEntity->getBag()) > (TEMoemonNum))
		{
			TEMoemonNum = +1;
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


	Text* skill1 = new Text();
	SDL_Rect tempskill1 = { 350, 405, 0, 0 };
	skill1->create(PEntity->getBag()->get(PEMoemonNum)->getLearnedSkills()->getSkill(0)->getName(), renderer);
	skill1->setRect(tempskill1);
	Text* skill2 = new Text();
	SDL_Rect tempskill2 = { 470, 405, 0, 0 };
	skill2->create(PEntity->getBag()->get(PEMoemonNum)->getLearnedSkills()->getSkill(1)->getName(), renderer);
	skill2->setRect(tempskill2);
	Text* skill3 = new Text();
	SDL_Rect tempskill3 = { 350, 445, 0, 0 };
	skill3->create(PEntity->getBag()->get(PEMoemonNum)->getLearnedSkills()->getSkill(2)->getName(), renderer);
	skill3->setRect(tempskill3);
	Text* skill4 = new Text();
	SDL_Rect tempskill4 = { 470, 445, 0, 0 };
	skill4->create(PEntity->getBag()->get(PEMoemonNum)->getLearnedSkills()->getSkill(3)->getName(), renderer);
	skill4->setRect(tempskill4);
	TSMenu.push_back(skill1);
	TSMenu.push_back(skill2);
	TSMenu.push_back(skill3);
	TSMenu.push_back(skill4);

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