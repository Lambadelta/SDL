//#include "EventHandler.h"
//
//
//EventHandler::EventHandler()
//{
//	PlayerAnim = new Timer(0.8);
//}
//
//EventHandler::~EventHandler()
//{
//
//}
//
//void EventHandler::updateTime(Time dt)
//{
//	PlayerAnim->updateTimer(dt.getDelta());
//}
//
//void EventHandler::runKeyboard(SDL_Keycode move, Player* Trainer, Time dt)
//{
//	switch (move)
//	{
//	case SDLK_w:
//		Trainer->callMoveUp(true, PlayerAnim, dt);
//		break;
//	case SDLK_s:
//		Trainer->callMoveDown(true, PlayerAnim, dt);
//		break;
//	case SDLK_d:
//		Trainer->callMoveRight(true, PlayerAnim, dt);
//		break;
//	case SDLK_a:
//		Trainer->callMoveLeft(true, PlayerAnim, dt);
//		break;
//	case SDLK_k:
//		printf("%f \n", dt.getDelta());
//		break;
//	}
//}
