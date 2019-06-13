
#ifndef POMODORO_H
#define POMODORO_H

#include <windows.h>
#include <mmsystem.h>
#include <iostream>
#include <thread>

#include "Timer.h"


#define STUDY_MUSIC "assets/Canon.wav"
#define REST_MUSIC "assets/Canon.wav"
#define BOOM_SND "assets/boom.wav"
#define ALARM "assets/analog-watch-alarm_daniel-simion.wav"

#define STUDY_TIME 10*1000
#define REST_TIME 5*1000

using namespace std;

class Pomodoro
{
public:
	Pomodoro();
	Pomodoro(LPCTSTR studyMusicF, LPCTSTR restMusicF, LPCTSTR alarmF);
	~Pomodoro();

	void Run();
	char GetInput();
	
private:
	LPCSTR studyMusicF;
	LPCSTR restMusicF;
	LPCSTR alarmF;
	Timer timer;
	//std::thread input;
};






#endif