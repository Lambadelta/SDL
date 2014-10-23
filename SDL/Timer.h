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
	Uint32 iStartTick;
	Uint32 iPausedTick;
	Uint32 iLastTick;

	float fDelta;
	bool bPaused;
	bool bStart;
};

#endif