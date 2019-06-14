#include <windows.h>
#include <mmsystem.h>
#include <iostream>

#include "Pomodoro.h" 
#include "InputManager.h"
#include <thread>

using namespace std;


int main(int argc, char **argv)
{

	
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
