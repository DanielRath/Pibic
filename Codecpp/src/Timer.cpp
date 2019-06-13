#include "Timer.h"


Timer::Timer(){
	time = 0;
	offset = 0;
}

Timer::~Timer(){}


void Timer::Restart(){
	time = 0;
	offset = clock();
}

clock_t Timer::GetTime(){
	return time;
}

void Timer::Update(){
	time = clock() - offset;
}