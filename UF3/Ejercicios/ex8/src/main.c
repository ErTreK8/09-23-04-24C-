#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include <stdbool.h> 
#include "rlutil.h"
#include "llibreriaPropia.h"
#include "llibreriaExercici.h"

int main(){
	//1252 coje codigos distintos no como el UTF_8 i akgi asuÂ¡i
	SetConsoleOutputCP(1252);
	SetConsoleCP(1252);
	srand(time(NULL));
	const char fitxer1[]="./fitxers/info.txt";

	FILE *f;
	f=obrirFitxer(fitxer1,"w");
	fprintf(f,"Claudina\nRiaza\n50\nDAM\nDavid\nPorti\n40\nDAM\nMaria\nPérez\n23\nAIF");
	fclose(f);

	crearFitxers(fitxer1);

	acabament();
	return 0;
}
