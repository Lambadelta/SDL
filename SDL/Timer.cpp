#include "timer.h"


Timer::Timer(float ms)
{
	if (ms < 0)
	{
		initialTime = 0;
	}
	else
	{
		initialTime = ms;
	}

	currentTime = initialTime;

}
Timer::~Timer()
{

}

void Timer::updateTimer(float DeltaTime)
{
	if (currentTime > 0)
	{
		currentTime -= DeltaTime;
	}
	else
	{
		currentTime = initialTime;
	}
}

bool Timer::expiredTimer()
{
	if (currentTime <= 0)
	{
		return (true);
	}
	else
	{
		return (false);
	}
}

int Timer::debug()
{
	return currentTime;
}
