#include "FileFuncs.h"
#include "SerialHandler.h"

#define DATAFILE "DataBase/teste.csv"

void main(int argc, char const *argv[])
{
	/*
	char bytes_to_receive[2];

	HANDLE hSerial;
    DCB dcbSerialParams = {0};
    COMMTIMEOUTS timeouts = {0};

    hSerial = CreateFile("\\\\.\\COM15", GENERIC_READ|GENERIC_WRITE, 0, NULL,
    OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL );

    if (hSerial == INVALID_HANDLE_VALUE)
    {
        printf("Deu nao\n");
        return;
    }
    else printf("DEEEEUUU\n");


    // Set device parameters (38400 baud, 1 start bit,
    // 1 stop bit, no parity)
    dcbSerialParams.DCBlength = sizeof(dcbSerialParams);
    if (GetCommState(hSerial, &dcbSerialParams) == 0)
    {
        printf("De segunda nao foi :(\n");
        CloseHandle(hSerial);
        return;
    }
    else{
    	printf("Foi de novooooo\n");
    } 


    dcbSerialParams.BaudRate = CBR_9600;
    dcbSerialParams.ByteSize = 8;
    dcbSerialParams.StopBits = ONESTOPBIT;
    dcbSerialParams.Parity = NOPARITY;


    if(SetCommState(hSerial, &dcbSerialParams) == 0)
    {
        printf("De terceira nao foi :(\n");
        CloseHandle(hSerial);
        return;
    }
    else{
    	printf("TERCEIRAAAA FOI BOA\n");
    }


    // Set COM port timeout settings
    timeouts.ReadIntervalTimeout = 100;
    timeouts.ReadTotalTimeoutConstant = 100;
    timeouts.ReadTotalTimeoutMultiplier = 10;
    timeouts.WriteTotalTimeoutConstant = 50;
    timeouts.WriteTotalTimeoutMultiplier = 10;



    if(SetCommTimeouts(hSerial, &timeouts) == 0)
    {
        printf("Quarta nao foi :(\n");
        CloseHandle(hSerial);
        return;
    }
    else{
    	printf("EH TETRAAAAA\n");
    }
*/
 	DWORD buffer_size_r;
    char buffer_r[128] = {0};
	
	HANDLE hSerial;
	SetHandler("\\\\.\\COM15", &hSerial);
    if(!ReadFile (hSerial, buffer_r, 128, &buffer_size_r, 0))
    {
        printf("Nao consegui ler\n");
        CloseHandle(hSerial);
        return;
    }
    else{
    	//bytes_to_receive[0]='c';
    	printf("AEEEEE EU LI ESSA BAGACA\nO QUE EU LI FOI: %d\n", buffer_size_r);
    }

    while(TRUE){
    	ReadFile (hSerial, buffer_r, 128, &buffer_size_r, 0);
    	//printf("li x %d bicho\n", buffer_size_r);
    	printf("%s\n", buffer_r);
    }
	//while(1){
	//	PrintSerial();
	//}
	CloseHandle(hSerial);
    
}