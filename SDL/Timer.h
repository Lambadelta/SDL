#ifndef TIMER_H
#define TIMER_H

class Timer
{
public:
	Timer(int ms);
	~Timer();

	void updateTimer(float DeltaTime);
	bool expiredTimer();
	int debug();

private:

	unsigned int initialTime;
	unsigned int currentTime;
};

#endif