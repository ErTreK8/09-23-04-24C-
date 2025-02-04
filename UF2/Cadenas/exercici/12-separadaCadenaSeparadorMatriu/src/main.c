#include <stdio.h>
#include <stdlib.h>
#include <time.h>  
#include <windows.h>
#include <string.h>
#include <stdbool.h>
#include "rlutil.h"
#include "llibreriaPropia.h"
#include "llibreriaExercici.h"


int main(){
	SetConsoleOutputCP(1252);
	SetConsoleCP(1252);
	srand(time(NULL));
	
	char frase[MIDA]="Adria-Betwin-Gonzalez-DAM";

	char matriu[MAXPARAULES][MIDA];

	printf("\n%d",strlen(frase));
	// separa(frase,MIDA,matriu);
	// pinta(matriu);

	//printf("%d   %d",strlen(matriu[0]),strlen(matriu));


	separa2(frase,MIDA,matriu);
	pinta(matriu);
	

	acabament();
	return 0;
}
