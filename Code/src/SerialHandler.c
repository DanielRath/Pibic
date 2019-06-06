#include "SerialHandler.h"


int SetHandler(char port[], HANDLE *hSerial){
    //Variables to set comunication   
    DCB dcbSerialParams = {0};
    COMMTIMEOUTS timeouts = {0};


    //Create comunication channel
    *hSerial = CreateFile(port, GENERIC_READ|GENERIC_WRITE, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL );
    //Check if operation was succesful
    if (*hSerial == INVALID_HANDLE_VALUE)
    {
        printf("Unable to create handle\n");
        return -1;
    }


    // Set device parameters
    dcbSerialParams.DCBlength = sizeof(dcbSerialParams);
    if (GetCommState(*hSerial, &dcbSerialParams) == 0)
    {
        printf("Failed getting comm state\n");
        CloseHandle(*hSerial);
        return -1;
    }

    dcbSerialParams.BaudRate = CBR_9600;
    dcbSerialParams.ByteSize = 8;
    dcbSerialParams.StopBits = ONESTOPBIT;
    dcbSerialParams.Parity = NOPARITY;


    if(SetCommState(*hSerial, &dcbSerialParams) == 0)
    {
        printf("Failed setting comm parameters\n");
        CloseHandle(*hSerial);
        return -1;
    }


     // Set COM port timeout settings
    timeouts.ReadIntervalTimeout = 100;
    timeouts.ReadTotalTimeoutConstant = 100;
    timeouts.ReadTotalTimeoutMultiplier = 10;
    timeouts.WriteTotalTimeoutConstant = 50;
    timeouts.WriteTotalTimeoutMultiplier = 10;



    if(SetCommTimeouts(*hSerial, &timeouts) == 0)
    {
        printf("Failed setting comm timeouts\n");
        CloseHandle(*hSerial);
        return -1;
    }

}



int GetReadings(HANDLE hSerial, char buffer[]){
	DWORD bufferSize;
}



void PrintSerial(){
	
}

