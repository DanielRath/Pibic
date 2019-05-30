#include <stdio.h>
#include <stdlib.h>

//File used in tests. Uncomment it to use the main tests
//#define TEST_FILE "arquivo/teste.csv"

//Write the 3 values of the sensors in the .csv file
void WriteSensorsData(int data[], char file[]){
	FILE *fp;

	//Open file
	fp = fopen(file, "r+");
	//Write at file end
	fseek(fp, 0, SEEK_END);

	//Insert new line to the new values
	fprintf(fp, "\n");

	//Insert the three values in the file
	for(unsigned int i=0; i<3; i++){
		fprintf(fp, "%d", data[i]);
		if(i<2){
			fprintf(fp, ",");
		}
	}
	fclose(fp);
}

//Read a single value from the .csv file
int GetDataValue(int line, int column, char file[]){
	FILE *fp;
	int data;
	char discard;

	//Check if it is in the data lines (first line is data definition, string)
	if((line <= 0) || (column > 2) || (column < 0)){
		printf("No data to be found in here\n");
		return -1;
	}

	//Open file
	fp = fopen(file, "r");

	//Go to line in file
	int l=0;
	while(l<line){
		fscanf(fp, "%c", &discard);
		if(discard == '\n'){
			l++;
		}
	}

	//Go to column in line
	int c=0;
	while(c<column){
		fscanf(fp, "%c", &discard);
		if(discard == ','){
			c++;
		}
	}

	//Read correct value now
	fscanf(fp, "%d", &data);

	fclose(fp);

	return data;
}

void GetDataLine(int data[], int line, char file[]){
	FILE *fp;
	char discard;

	//Check if it is in the data lines (first line is data definition, string)
	if(line <= 0){
		printf("No data to be found in here\n");
		return;
	}

	//Open file
	fp = fopen(file, "r");

	//Go to line in file
	int l=0;
	while(l<line){
		fscanf(fp, "%c", &discard);
		if(discard == '\n'){
			l++;
		}
	}

	//Pass values in the line to the vector
	fscanf(fp, "%d", &data[0]);
	fscanf(fp, "%c", &discard);		//','
	fscanf(fp, "%d", &data[1]);
	fscanf(fp, "%c", &discard);		//','
	fscanf(fp, "%d", &data[2]);

	fclose(fp);
}


//int main()
//{
	
	//Writing in file test
	/*
	int data[3];
	data[0] = 309;
	data[1] = 400;
	data[2] = 378;
	WriteSensorsData(data, TEST_FILE);
	*/

	//Read value in file test
	/*
	printf("%d\n", GetDataValue(1, 0, TEST_FILE));
	*/

	//Read line in file test
	/*
	int data[3];
	GetDataLine(data, 2, TEST_FILE);
	printf("%d  %d  %d\n", data[0], data[1], data[2]);
	*/
//	return 1;
//}
