#include <windows.h>
#include <mmsystem.h>
#include <iostream>

#include "Pomodoro.h" 
#include "InputManager.h"
#include <thread>
#include "SerialPort.h"
#include "SerialManager.h"

using namespace std;

#define PORT "COM15"

int main(int argc, char **argv)
{
	SerialManager sm(PORT);
	int result;

	while(TRUE){
		Sleep(300);
		result = sm.UpdateReadings();
		if(result == 0) cout<<"No data passed"<<endl;
		else if(result == -1) cout<<"Data in wrong format"<<endl;
		else{
			cout<<"GSR: "<<sm.GetGSR()<<"; BPM: "<<sm.GetBPM()<<"; Strength: "<<sm.GetHStr()<<endl;
		}
	}

}
