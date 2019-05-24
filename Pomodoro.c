
#define TIMER1 10*1000
#define TIMER2 5*1000

#define STUDY 1
#define REST 2

#include <stdio.h>
#include <time.h>
#include <dos.h>
#include <windows.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>



struct thread
{
	pthread_t id;
	bool started;
};

char stop = ' ';



void *GetInput(void *a){
	while(stop != 'e'){
		scanf("%c", &stop);
		getchar();
	}
}



void main(){
	clock_t tend, tstart = clock();
	int ctrl=STUDY, startFlag=1;

	thread tInput, tAlarm, tStudyMusic, tRestMusic;
	tAlarm.started=FALSE;
	tStudyMusic.started=FALSE;
	tRestMusic.started=FALSE;


	pthread_create(&tInput.id, NULL, &GetInput, NULL);
	tInput.started=TRUE;

	while(stop != 'e'){


		switch(ctrl){

			//Start studies routine
			case(STUDY):
				//Keep alarm to start studies untill user presses 'p'
				if(startFlag==0){

					//Create alarm thread, if it doesn't exists yet
					if(stop != 'p'){
						if (!tAlarm.started){
							//Create one alarm thread

							tAlarm.started = TRUE;
						}

						
					}
					else{
						//junta o alarme
						tAlarm.started = FALSE;

						startFlag=1;
						tend = clock();
						tstart = clock();
					}
				}
				//Start studies timer
				else{
					if(tend-tstart < TIMER1){
						tend = clock();
					}
					else{
						ctrl = REST;
						startFlag=0;
						stop = ' ';
						printf("Time to rest\nPress 'p' to stop the alarm and start rest timer\n");
					}
				}
				break;



			//Start resting routine
			case(REST):
				//Keep alarm to start resting untill user presses 'p'
				if(startFlag==0){
					if(stop == 'p'){
						startFlag=1;
						tend = clock();
						tstart = clock();
					}
				}
				//Start resting timer
				else{
					if(tend-tstart < TIMER2){
						tend = clock();
					}
					else{
						ctrl = STUDY;
						startFlag=0;
						stop = ' ';
						printf("Time to study\nPress 'p' to stop the alarm and start study timer\n");
					}
				}
				break;
		}


		


















		
	}
	printf("acabei\n");
	pthread_join(tInput.id, NULL);
	//printf("final\n");
}
