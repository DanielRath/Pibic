
#include "SerialManager.h"


SerialManager::SerialManager(char *portName){
	//Add the '\\\\.\\' prefix to the port name
	char *prefix = "\\\\.\\";
	char newPortName[20];
	strcpy(newPortName,prefix);
	strcat(newPortName,portName);

	port = new SerialPort(newPortName);
	while(!port->isConnected()){
		port = new SerialPort(newPortName);
		cout<<"Trying to connect"<<endl;
	}

}

SerialManager::~SerialManager(){
	port->~SerialPort();
}



//Method to read buffer and extract useful information from it (sensor readings)
int SerialManager::UpdateReadings(){
	//Read all bytes from serial to buffer
	char buffer[MAX_DATA_LENGTH];
	int bytesRead = port->readSerialPort(buffer, MAX_DATA_LENGTH);
	//cout<<"Aqui eu li "<<buffer;
	//If nothing was read, return 0
	if(bytesRead == 0) return 0;
	//Check if read bytes follow the protocol
	else{
		//Mark begining and ending index of messages, given by '(' and ')', respectively
		int flagInit = -1, flagEnd = -1;
		for(int i=0;(( i<bytesRead) || (buffer[i] == '\n')); i++){
			if(buffer[i] == '('){
				if(flagInit == -1){
					flagInit = i;
				}
			}

			else if(buffer[i] == ')'){
				if(flagEnd == -1){
					flagEnd = i;
				}
			}
		}

		//Check if markers were found
		if((flagInit == -1) || (flagEnd == -1)) return -1;

		//Goes through message getting the information needed
		int indMarker=flagInit+1;
		int readingCounter=0;
		for(int i=flagInit; i<=flagEnd; i++){
			//If index is at a value separator (',' or ')', the last one actually ending message), value to the left of the separator
			if((buffer[i] == ',') || (i == flagEnd)){
				//Passing value to auxiliar buffer
				char auxBuffer[i - indMarker];
				for(int j=0; j<(i - indMarker); j++){
					auxBuffer[j] = buffer[indMarker + j];
				}

				//Convert value in auxiliar buffer to float, and store it in the right atribute from this object
				if(readingCounter==0) bpm = atof(auxBuffer);
				else if(readingCounter==1) gsrReading = atof(auxBuffer);
				//else if(readingCounter==2) heartStr = atof(auxBuffer);

				//Update counter and marker
				readingCounter++;
				indMarker = i+1;
			}
		}

		if(readingCounter != 2) return -1;

		//If all the values were in the correct form, return 1
		else return 1;
	}

}

float SerialManager::GetGSR(){
	return gsrReading;
}

float SerialManager::GetBPM(){
	return bpm;
}
/*
float SerialManager::GetHStr(){
	return heartStr;
}
*/