#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define BATCHSIZE 128


int SetHandler(char port[], HANDLE *hSerial);

int GetReadings(HANDLE hSerial, char buffer[]);

void PrintSerial();