#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

#include <thread>
#include <iostream>

#define QUIT_REQUESTED "q"

using namespace std;

//Class used to take input from user in a thread, to get readings without blocking main program

class InputManager
{
public:
	InputManager();
	~InputManager();

	void Start();

	void Read();
	string GetCurrentInput();

private:
	string input;
	thread inputThread;
};




#endif