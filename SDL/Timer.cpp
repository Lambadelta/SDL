#include "Timer.h"

Timer::Timer()
{
	iStartTime = 0;
	iPausedTime = 0;

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

	iStartTime = SDL_GetTicks();
	iPausedTime = 0;

}
void Timer::callPause()
{
	if (bStart == true && bPaused == false)
	{
		bPaused = true;

		iPausedTime = SDL_GetTicks() - iStartTime;
		iStartTime = 0;
	}
}

void Timer::callUnpause()
{
	if (bStart == false && bPaused == true)
	{
		bPaused = false;

		iStartTime = SDL_GetTicks() - iStartTime;
		iPausedTime = 0;
	}
}

void Timer::callStop()
{

}

int Timer::getTime()
{
	int iTime = 0;

	if (bStart == true)
	{
		if (bPaused == true)
		{
			iTime = iPausedTime;
		}
		else
		{
			iTime = (iStartTime - iPausedTime) / 1000;
			iPausedTime = iStartTime;
		}
	}

	return iTime;
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