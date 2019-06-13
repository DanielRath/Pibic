#include "Pomodoro.h"

Pomodoro::Pomodoro(){
	studyMusicF = STUDY_MUSIC;
	restMusicF = REST_MUSIC;
	alarmF = ALARM;
	timer = Timer();
	//input = thread(GetInput());
}

Pomodoro::Pomodoro(LPCSTR studyMusicF, LPCSTR restMusicF, LPCSTR alarmF){
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
	//Char to receive stop command
	char stop = ' ';

	while(TRUE){
		//Study time
		cout<<"Hora de estudar"<<endl;
		PlaySound (TEXT(studyMusicF), NULL, SND_ALIAS|SND_LOOP|SND_ASYNC);
		timer.Restart();
		while(timer.GetTime() < STUDY_TIME){
			timer.Update();
		}
		cout<<"Fim do tempo de estudo"<<endl;


		//Alarm to stop study time
		PlaySound (TEXT (alarmF), NULL, SND_ALIAS|SND_LOOP|SND_ASYNC);
		cout<<"Escreva 'p' para parar o alarme e comecar o tempo de descanco"<<endl;
		cin>>stop;
		while(stop =! 'p'){
			cin>>stop;
		}
		stop = ' ';


		//Rest time
		cout<<"Hora de descancar"<<endl;
		PlaySound (TEXT(restMusicF), NULL, SND_ALIAS|SND_LOOP|SND_ASYNC);
		timer.Restart();
		while(timer.GetTime() < REST_TIME){
			timer.Update();
		}
		cout<<"Fim do tempo de descanco"<<endl;


		//Alarm to stop resting time
		PlaySound (TEXT (alarmF), NULL, SND_ALIAS|SND_LOOP|SND_ASYNC);
		cout<<"Escreva 'p' para parar o alarme e comecar o tempo de estudo"<<endl;
		cin>>stop;
		while(stop =! 'p'){
			cin>>stop;
		}
		stop = ' ';


	}
}


char Pomodoro::GetInput(){
	char in;
	std::cin>>in;
	std::cout<<"Peguei um valor na thread"<<std::endl;
	return in;
}