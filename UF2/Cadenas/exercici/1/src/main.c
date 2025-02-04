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
	char cadena[MIDA]="Hola demà és divendres";
	// passarMajuscula(cadena,strlen(cadena));
	// pintaCadena(cadena, MIDA);
	// getch();
	// printf("\n");
	passarMajuscula2(cadena,strlen(cadena));
	pintaCadena(cadena, MIDA);

	acabament();
	return 0;
}
