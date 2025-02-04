#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include <stdbool.h> 
#include "rlutil.h"
#include "llibreriaPropia.h"
#include "llibreriaExercici.h"

int main(){
	SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(CP_UTF8);
	srand(time(NULL));

	int x,y;
	printf("Dame una cordenada X entre %d y %d: ",Minim,MaximX);
	x=demanarNumeroMinMax(Minim,MaximX);
	printf("Dame una cordenada Y entre %d y %d: ",Minim,MaximY);
	y=demanarNumeroMinMax(Minim,MaximY);
	printa(x,y);
	acabament();
	return 0;
}
