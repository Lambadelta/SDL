#include "Timer.h"

Timer::Timer()
{
	iStartTick = 0;
	iPausedTick = 0;
	iLastTick = 0;

	bPaused = false;
	bStart = false;
}
Timer::~Timer()
{

}

void Timer::callStart()
{
	bStart = true;
	bPaused = false;

	iStartTick = SDL_GetTicks();
	iPausedTick = 0;

}
void Timer::callPause()
{
	if (bStart == true && bPaused == false)
	{
		bPaused = true;

		iPausedTick = SDL_GetTicks() - iStartTick;
		iStartTick = 0;
	}
}

void Timer::callUnpause()
{
	if (bStart == false && bPaused == true)
	{
		bPaused = false;

		iStartTick = SDL_GetTicks() - iStartTick;
		iPausedTick = 0;
	}
}

void Timer::callStop()
{

}


float Timer::getDelta()
{
	return ((fDelta / 100));
}

void Timer::updateTime()
{
	if (bStart == true)
	{
		if (bPaused == true)
		{
			iLastTick = iPausedTick;
			fDelta = (iPausedTick - iLastTick);
		}
		else
		{
			
			iStartTick = SDL_GetTicks();
			fDelta = (iStartTick - iLastTick);
			iLastTick = iStartTick;
		}
	}

}

bool Timer::isPaused()
{
	return bPaused;
}

bool Timer::isStarted()
{
	return bStart;
}

/*16.7 Mil Seconds = 60 fps use SDL_Delay*/