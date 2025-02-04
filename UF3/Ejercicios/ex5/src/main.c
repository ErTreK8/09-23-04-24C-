#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include <stdbool.h> 
#include "rlutil.h"
#include "llibreriaPropia.h"
#include "llibreriaExercici.h"

int main(){
	//1252 coje codigos distintos no como el UTF_8 i akgi asu¡i
	SetConsoleOutputCP(1252);
	SetConsoleCP(1252);
	srand(time(NULL));
	const char fitxer[]="./fitxers/dades1.txt";
	const char fitxer2[]="./fitxers/dades2.txt";

	FILE *f;
	f=obrirFitxer(fitxer,"w");

	fprintf(f,"Hola QUE tal ESTAS\n");
	fprintf(f,"SE ME SALE");
	fclose(f);
	
	creaFitxer(fitxer,fitxer2);
	
	acabament();
	return 0;
}
