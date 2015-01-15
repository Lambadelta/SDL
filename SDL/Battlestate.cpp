#include "BattleState.h"

BattleState::BattleState(Manager* GSManager, SDL_Renderer* Renderer, Player* player, Trainer* trainer) : Gamestate(GSManager,Renderer)
{
	renderer = Renderer;
	PEntity = player;
	TEntity = trainer;
	PlayerAnim = new Timer(2.5);
	Name = "Battle";
	Backgrounds = new Background("Asset/Background.png", renderer);
	Menu = new Background("Asset/MenuBackground.png", renderer);
	BattleTheme = Mix_LoadMUS("Asset/Music/LeaderTheme.wav");
	Mix_PlayMusic(BattleTheme, -1);
	TEntity->getStorage()->get(0)->setEnemy();
	textManager = new Text();
	textManager->create("Frostlass Used Shadow Punch! It was super effective.",renderer);
	MBattleMenu = true;
	textInit();
}

BattleState::~BattleState()
{

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
				GSManager->RemoveLast();
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

	TEntity->getStorage()->get(0)->setDescRect(ETrainerM);
	Backgrounds->callDraw(renderer, Backgrounds->getTexture(), descRect, descRect);
	
	if (AnimationCount <= 5)
	{
		PEntity->battleAnimation(PlayerAnim, dt, renderer, AnimationCount);
	}
	if (AnimationCount > 5)
	{
		Menu->callDraw(renderer, Menu->getTexture(), menuRect, dummyRect);
		TEntity->getStorage()->get(0)->callDraw(renderer);
		PEntity->getBag()->get(0)->callDraw(renderer);
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
				Mix_HaltMusic();
				GSManager->RemoveLast();
			}
		}
	}
	if (MBattleMenu == false)
	{
		PEntity->getBag()->get(0)->getLearnedSkills()->useSkill(MenuSelection);
	}
}

void BattleState::textInit()
{
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
	skill1->create(PEntity->getBag()->get(0)->getLearnedSkills()->getSkill(0)->getName(), renderer);
	skill1->setRect(tempskill1);
	Text* skill2 = new Text();
	SDL_Rect tempskill2 = { 470, 405, 0, 0 };
	skill2->create(PEntity->getBag()->get(0)->getLearnedSkills()->getSkill(1)->getName(), renderer);
	skill2->setRect(tempskill2);
	Text* skill3 = new Text();
	SDL_Rect tempskill3 = { 350, 445, 0, 0 };
	skill3->create(PEntity->getBag()->get(0)->getLearnedSkills()->getSkill(2)->getName(), renderer);
	skill3->setRect(tempskill3);
	Text* skill4 = new Text();
	SDL_Rect tempskill4 = { 470, 445, 0, 0 };
	skill4->create(PEntity->getBag()->get(0)->getLearnedSkills()->getSkill(3)->getName(), renderer);
	skill4->setRect(tempskill4);
	TSMenu.push_back(skill1);
	TSMenu.push_back(skill2);
	TSMenu.push_back(skill3);
	TSMenu.push_back(skill4);

}
