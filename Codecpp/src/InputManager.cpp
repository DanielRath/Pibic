#include "InputManager.h"

InputManager::InputManager():inputThread(){
	input = "";
}

InputManager::~InputManager(){
	if(inputThread.joinable()){
		inputThread.join();
	}
}

void InputManager::Start(){
	inputThread = thread(&InputManager::Read, this);
}

void InputManager::Read(){
	cin>>input;
	//If input is QUIT_REQUESTED, it is a request to end the program, so thread must end as well
	while(input != QUIT_REQUESTED){
		cin>>input;
	}
}

string InputManager::GetCurrentInput(){

	string aux = input;
	//Erase the input given, so it get read only once
	if(input != QUIT_REQUESTED){
		input = "";
	}
	return aux;
}
