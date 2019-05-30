#include "FileFuncs.h"

#define DATAFILE "../DataBase/teste.csv"

void main(int argc, char const *argv[])
{
	int data[3], data1[3];
	data[0] = 1;
	data[1] = 3;
	data[2] = 2;

	WriteSensorsData(DATAFILE, data);
	GetDataLine(DATAFILE, data1, 1);
	printf("%d %d %d\n", data1[0], data1[1], data1[2]);
}