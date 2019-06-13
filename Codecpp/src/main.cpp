#include <windows.h>
#include <mmsystem.h>
#include <iostream>

#include "Pomodoro.h" 

int main(int argc, char **argv)
{
    //PlaySound (TEXT ("assets/boom.wav"), NULL, SND_ALIAS);
    Pomodoro pomo = Pomodoro();
    pomo.Run();
    return 0;
}
