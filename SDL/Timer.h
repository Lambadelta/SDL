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

	int getTime();

	bool isPaused();
	bool isStarted();

private:
	int iStartTime;
	int iPausedTime;

	bool bPaused;
	bool bStart;
};

#endif