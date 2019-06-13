#ifndef TIMER_H
#define TIMER_H

#include <time.h>

class Timer
{
public:
	Timer();
	~Timer();
	
	void Restart();
	clock_t GetTime();
	void Update();

private:
	clock_t time;
	clock_t offset;
};






#endif