
#define TIMER1 15*1000
#define TIMER2 15*1000

#define STUDY 1
#define REST 2

#include <stdio.h>
#include <time.h>
#include <dos.h>
#include <windows.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>



char stop = ' ';



void *GetInput(void *a){
	while(stop != 'e'){
		scanf("%c", &stop);
		getchar();
	}
}



void main(){
	clock_t tend, tstart = clock();
	int ctrl=STUDY;
	//Start flags
	boolean startFlag=TRUE, startOnceFlag=FALSE;

	pthread_t tInput;
	pthread_create(&tInput, NULL, &GetInput, NULL);

	while(stop != 'e'){


		switch(ctrl){

			//Start studies routine
			case(STUDY):

				//Keep alarm to start studies untill user presses 'p'
				if(!startFlag){
					//printf("ALARME DE ESTUDOS\n");

					//Start alarm sound only once
					if(!startOnceFlag){
							/***************COLOCAR SOM DE ALARME AQUI (SE TIVER)************/
						printf("Mandei tocar alarme 1x de estudos\n");

						startOnceFlag = TRUE;
					}

					//Stop the alarm, if requested by user
					if(stop == 'p'){
						tend = clock();
						tstart = clock();
						startFlag=TRUE;
						startOnceFlag = FALSE;
					}

				}

				//Start studies timer
				else{

					//Start study music only once
					if(!startOnceFlag){
							/***************COLOCAR A MUSICA DE ESTUDOS AQUI************/

						printf("Mandei tocar musica de estudos\n");
						startOnceFlag = TRUE;
					}

					//Check if time is over
					if(tend-tstart < TIMER1){
						tend = clock();
					}
					else{
						ctrl = REST;
						startFlag = FALSE;
						startOnceFlag = FALSE;
						stop = ' ';
						printf("Time to rest\nPress 'p' to stop the alarm and start rest timer\n");
					}
				}
				break;



			//Start resting routine
			case(REST):

				//Keep alarm to start resting untill user presses 'p'
				if(!startFlag){
					//printf("ALARME DE DESCANCO\n");

					//Start alarm sound only once
					if(!startOnceFlag){
							/***************COLOCAR SOM DE ALARME AQUI (SE TIVER)************/
						printf("Mandei tocar alarme 1x de descanco\n");
						startOnceFlag = TRUE;
					}

					//Stop the alarm, if requested by user
					if(stop == 'p'){
						tend = clock();
						tstart = clock();
						startFlag=TRUE;
						startOnceFlag = FALSE;
					}

				}

				//Start resting timer
				else{
					//printf("DESCANCO\n");

					//Start resting music only once
					if(!startOnceFlag){
							/***************COLOCAR A MUSICA DE DESCANCO AQUI************/
						
							printf("Mandei tocar a musica de descanco\n");

						startOnceFlag = TRUE;
					}

					//Check if time is over
					if(tend-tstart < TIMER1){
						tend = clock();
					}
					else{
						ctrl = STUDY;
						startFlag = FALSE;
						startOnceFlag = FALSE;
						stop = ' ';
						printf("Time to study\nPress 'p' to stop the alarm and start study timer\n");
					}
				}
				break;
		}


		
	}
	//End of pomodoro
	pthread_join(tInput, NULL);
}
