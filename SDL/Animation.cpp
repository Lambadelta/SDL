#include "Animation.h"

Animation::Animation()
{
	iCurrentFrame = 0;
	iMaxFrames = 0;
	iFrameIncrement = 1;

	iFrameRate = 100;
	lPastTime = 0;

	bfluctuate = false;
}

void Animation::onAnimation()
{
	if (lPastTime + iFrameRate > SDL_GetTicks())
	{
		return;
	}

	lPastTime = SDL_GetTicks();
	iCurrentFrame += iFrameIncrement;

	if (bfluctuate)
	{
		if (iFrameIncrement > 0)
		{
			if (iCurrentFrame >= iMaxFrames)
			{
				iFrameIncrement = -iFrameIncrement;
			}
			else
			{
				if (iCurrentFrame <= 0)
				{
					iCurrentFrame = 0;
				}
			}
		}
	}
}

void Animation::setFrameRate(int iRate)
{
	iFrameRate = iRate;
}

void Animation::setCurrentFrame(int iFrame)
{
	if (iFrame < 0 || iFrame >= iMaxFrames)
	{
		return;
	}

	iCurrentFrame = iFrame;
}

int Animation::GetCurrentFrame()
{
	return iCurrentFrame;
}
