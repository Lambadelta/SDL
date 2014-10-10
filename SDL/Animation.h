#ifndef ANIMATION_H
#define ANIMATION_H

#include <SDL.h>

class Animation
{
public:
	int iMaxFrames;
	bool bfluctuate;

	Animation();

	void onAnimation();
	void setFrameRate(int iRate);
	void setCurrentFrame(int iFrame);
	int GetCurrentFrame();
protected:
	int iCurrentFrame;
	int iFrameIncrement;
	int iFrameRate;
	long lPastTime;
};


#endif
