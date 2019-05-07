#include <stdio.h>
#include <stdlib.h>
int bpm=0;

int main ()
{
	printf("Digite o valor de seu batimento cardíaco\n");
	scanf("%d", &bpm);
	if (bpm > 70)
        system("mpg123 Canon.mp3");
        return 0;
}





