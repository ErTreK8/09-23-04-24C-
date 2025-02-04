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
	int numCarta1, numCarta2, numCarta3;
	char simbolCarta1,simbolCarta2,simbolCarta3;
	

	DemanaCarta(&numCarta1,&simbolCarta1);
	DemanaCarta(&numCarta2,&simbolCarta2);
	DemanaCarta(&numCarta3,&simbolCarta3);
	
	printf("\n\nLa Carta 1 %d%c",numCarta1,simbolCarta1);
	printf("\n\nLa Carta 2 %d%c",numCarta2,simbolCarta2);
	printf("\n\nLa Carta 3 %d%c",numCarta3,simbolCarta3);

	ComprovarCartes(numCarta1,numCarta2,numCarta3,simbolCarta1,simbolCarta2,simbolCarta3);
	acabament();
	return 0;
}

