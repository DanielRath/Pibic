#include <windows.h>
#include <mmsystem.h>
#include <iostream>

int main()
{
    PlaySound (TEXT ("Canon.wav"), NULL, SND_ALIAS);
    return 0;
}
