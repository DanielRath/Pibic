#include <windows.h>
#include <mmsystem.h>
#include <iostream>

#include "Pomodoro.h" 
#include "InputManager.h"
#include <thread>
#include "SerialPort.h"

using namespace std;


using std::cout;
using std::endl;

/*Portname must contain these backslashes, and remember to
replace the following com port*/
char *port_name = "\\\\.\\COM15";

//String for incoming data
char incomingData[MAX_DATA_LENGTH];


int main(int argc, char **argv)
{
	SerialPort arduino(port_name);
	if (arduino.isConnected()) cout << "Connection Established" << endl;
	else cout << "ERROR, check port name";
	  
	while (arduino.isConnected()){
		//Check if data has been read or not
		int read_result = arduino.readSerialPort(incomingData, MAX_DATA_LENGTH);
		//prints out data
		puts(incomingData);
		//wait a bit
		Sleep(10);
  	}
	
	InputManager input;
	input.Start();
	string cinp = input.GetCurrentInput();
	while(cinp != QUIT_REQUESTED){
		if(cinp == ""){
			//cout<<"tem nada aqui nao"<<endl;
		}
		else{
			cout<<"Lendo na main: "<<cinp<<endl;
		}
		cinp = input.GetCurrentInput();
	}
    return 0;
}
