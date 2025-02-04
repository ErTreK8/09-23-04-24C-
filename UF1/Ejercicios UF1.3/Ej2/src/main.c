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
	int numCarta;
	char simbolCarta;
	
	DemanaCarta(&numCarta,&simbolCarta);
	printf("\n\nLa Carta Escojida es %d%c",numCarta,simbolCarta);
	acabament();
	return 0;
}
