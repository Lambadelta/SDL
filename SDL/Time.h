#ifndef TIME_H
#define TIME_H

#include <SDL.h>

class Time
{
public:
	Time();
	~Time();

	void callStart();
	void callPause();
	void callUnpause();
	void callStop();
	
	float getDelta();
	void updateTime();

	bool isPaused();
	bool isStarted();

private:
	float iStartTick;
	float iPausedTick;
	float iLastTick;

	float fDelta;
	bool bPaused;
	bool bStart;
};

#endif