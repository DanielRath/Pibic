#include "Pomodoro.h"

Pomodoro::Pomodoro(){
	studyMusicF = STUDY_MUSIC;
	restMusicF = REST_MUSIC;
	alarmF = ALARM;
	timer = Timer();
	//input = thread(GetInput());
}

Pomodoro::Pomodoro(std::string studyMusicF, std::string restMusicF, std::string alarmF){
	this->studyMusicF = studyMusicF;
	this->restMusicF = restMusicF;
	this->alarmF = alarmF;
	timer = Timer();
	//input = thread(GetInput());
}




Pomodoro::~Pomodoro(){
	//input.join();
}




void Pomodoro::Run(){
	//std::thread input (&Pomodoro::GetInput,this);
	//std::string teste;
	
	PlaySound (TEXT (ALARM), NULL, SND_ALIAS|SND_LOOP|SND_ASYNC);
	timer.Restart();
	

	//std::cin>>teste;
	//getline(std::cin, teste);
	//std::cout<<"teste foi "<<teste<<std::endl;
	while(TRUE){
		timer.Update();
		if(timer.GetTime()>=5000){
			std::thread input(&Pomodoro::GetInput,this);
			std::cout<<"Foram 5 segs"<<std::endl;
			PlaySound (TEXT (ALARM), NULL, SND_ALIAS|SND_LOOP|SND_ASYNC|SND_NOSTOP);
			timer.Restart();
		}
	}
}


char Pomodoro::GetInput(){
	char in;
	std::cin>>in;
	std::cout<<"Peguei um valor na thread"<<std::endl;
	return in;
}