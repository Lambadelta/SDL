#include "EventHandler.h"


EventHandler::EventHandler()
{
}

EventHandler::~EventHandler()
{
}


void EventHandler::onEvent(SDL_Event* Event)
{

if (Event->type == SDL_WINDOWEVENT)
	{
		switch (Event->window.event)
		{

		case SDL_WINDOWEVENT_CLOSE:
			SDL_Log("Window %d closed", Event->window.windowID);
			break;
		case SDL_QUIT:
			SDL_Log("Program %d quit", Event->window.event);
			break;
		default:
			SDL_Log("Window %d got unknown event %d",
				Event->window.windowID, Event->window.event);
			break;
		}
	}
}
void EventHandler::onKeyUp()
{

}
void EventHandler::onKeyDown()
{

}
void EventHandler::onKeyLeft()
{

}
void EventHandler::onKeyRight()
{

}
void EventHandler::onKeyE()
{

}
void EventHandler::onKeySpace()
{

}
void EventHandler::onKeyEsc()
{

}
void EventHandler::onExit()
{

}

