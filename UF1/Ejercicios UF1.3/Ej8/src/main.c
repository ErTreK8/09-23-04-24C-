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
	int pieza1Domino1, pieza1Domino2, pieza2Domino1, pieza2Domino2;
	printf("Introduce la primera pieza de domino: ");
	demanarDomino(&pieza1Domino1, &pieza1Domino2, MIN_PIEZA, MAX_PIEZA);
	while(getchar()!='\n');
	printf("Introduce la segunda pieza de domino: ");
	demanarDomino(&pieza2Domino1, &pieza2Domino2, MIN_PIEZA, MAX_PIEZA);
	printf("\nLa primera ficha es %d-%d \nLa segona ficha es %d-%d", pieza1Domino1, pieza1Domino2, pieza2Domino1, pieza2Domino2);
	final(pieza1Domino1, pieza1Domino2, pieza2Domino1, pieza2Domino2);
	acabament();
	return 0;
}
