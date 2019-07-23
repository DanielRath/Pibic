/*
Class created to manage message read from the arduino using the message protocol:
	"(gsrReading,heartbeatFrequency,heartbeatStrength)"
*/
#ifndef SERIALMANAGER_H
#define SERIALMANAGER_H

#include <iostream>

#include "SerialPort.h"



using namespace std;

class SerialManager{
public:
	SerialManager(char *portName);
	~SerialManager();

	int UpdateReadings();

	float GetGSR();
	float GetBPM();
	//float GetHStr();


private:
	float gsrReading;
	float bpm;
	//float heartStr;

	SerialPort *port;
};




#endif