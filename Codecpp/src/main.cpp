#include <windows.h>
#include <mmsystem.h>
#include <iostream>
#include <fstream>
#include <string>

#include "Pomodoro.h" 
#include "InputManager.h"
#include <thread>
#include "SerialPort.h"
#include "SerialManager.h"
//#include "koolplot.h"

using namespace std;

#define PORT "COM15"

void Play(string music, SerialManager *sm, bool play);




int main(int argc, char **argv)
{
	//Start serial manager
	SerialManager sm(PORT);

	char aux;


	Play("SemMusica",&sm,0);
	cout<<"Troque a musica"<<endl;
	//cin>>aux;
	Play("VivaLaVida",&sm,0);
	cout<<"Troque a musica"<<endl;
	//cin>>aux;
	Play("Weightless",&sm,0);
	return 0;
}

void Play(string music, SerialManager *sm, bool play){
	//Get music path
	string aux = "assets/"+music+".wav";
	LPCSTR musicFile = aux.c_str();

	//Get data saves path
	string csvFileName = "SavedDatas/"+music+".csv";

	//File saving variables
	ofstream outcsvFile;
	outcsvFile.open(csvFileName);

	//Start input manager
	InputManager im;
	im.Start();

	//Create timer, to read and save sensor data only in specific times
	Timer readTimer = Timer();
	long timeCount=0;

	//Checking if values "make sense", before start reccording
	string input;
	cout<<"Pressione s para comecar aquisicao de dados"<<endl;
	do{
		if(sm->UpdateReadings() == 1){
			cout<<"GSR: "<<sm->GetGSR()<<"; BPM: "<<sm->GetBPM()<<endl;
		}
		Sleep(2000);
		input = im.GetCurrentInput();
	}while(input != "s");

	//Start music and data acquisition
	cout<<"Aperte 'q' para finalizar aquisicao de dados"<<endl;
	if(play){
		PlaySound (TEXT(musicFile), NULL, SND_ALIAS|SND_LOOP|SND_ASYNC);
	}
	do{
		input = im.GetCurrentInput();
		readTimer.Update();
		if(readTimer.GetTime()>3000){
			timeCount += readTimer.GetTime();
			if(sm->UpdateReadings() == 1){
				//cout<<"GSR: "<<sm->GetGSR()<<"; BPM: "<<sm->GetBPM()<<endl;
				//Save next datas
				outcsvFile<<(float)timeCount/1000.0<<","<<sm->GetGSR()<<","<<sm->GetBPM()<<endl;

				readTimer.Restart();
			}
			
		}

	}while(input != "q");
	PlaySound(NULL, NULL, 0);	//Stop current music from playing
	outcsvFile.close();
}
