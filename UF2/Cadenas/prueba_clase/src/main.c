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

	char cadena[MIDA]="Hola";
	// char cadena2[]="Adeu";

	pintaCadena(cadena,MIDA);
	// printf("\n%lld\n", strlen(cadena2));
	// pintaCadena(cadena2,strlen(cadena2)); // strlen retrona la longitud de la cadena

	// Separar per consonants y vocals
	char consonants[MIDA];
	char vocals[MIDA];
	separaLletres(cadena,MIDA,consonants,vocals);
	pintaCadena(vocals,MIDA);
	pintaCadena(consonants,MIDA);

	acabament();
	return 0;
}
