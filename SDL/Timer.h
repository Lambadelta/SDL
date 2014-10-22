#ifndef TIMER_H
#define TIMER_H

#include <SDL.h>

class Timer
{
public:
	Timer();
	~Timer();

	void callStart();
	void callPause();
	void callUnpause();
	void callStop();
	
	float getDelta();
	void updateTime();

	bool isPaused();
	bool isStarted();

private:
	int iStartTick;
	int iPausedTick;
	int iLastTick;

	float fDelta;
	bool bPaused;
	bool bStart;
};

#endif