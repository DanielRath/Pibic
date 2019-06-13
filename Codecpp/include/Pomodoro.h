
#ifndef POMODORO_H
#define POMODORO_H

#include <windows.h>
#include <mmsystem.h>
#include <iostream>
#include <thread>

#include "Timer.h"


#define STUDY_MUSIC "assets/boom.wav"
#define REST_MUSIC "assets/boom.wav"
#define ALARM "assets/analog-watch-alarm_daniel-simion.wav"


class Pomodoro
{
public:
	Pomodoro();
	Pomodoro(std::string studyMusicF, std::string restMusicF, std::string alarmF);
	~Pomodoro();

	void Run();
	char GetInput();
	
private:
	std::string studyMusicF;
	std::string restMusicF;
	std::string alarmF;
	Timer timer;
	//std::thread input;
};






#endif