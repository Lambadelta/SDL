#ifndef TIMER_H
#define TIMER_H

class Timer
{
public:
	Timer(float ms);
	~Timer();

	void updateTimer(float DeltaTime);
	bool expiredTimer();
	int debug();

private:

	 float initialTime;
	 float currentTime;
};

#endif