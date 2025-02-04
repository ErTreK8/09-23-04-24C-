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
	SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(CP_UTF8);
	srand(time(NULL));

	char cadena1[] = "Hola ";
	char cadena2[] = "DAM 1";
	char cadenaFinal[strlen(cadena1) + strlen(cadena2)];
	int pos = 0;
	
	agrupaCadenes(cadena1, cadenaFinal, pos);
	pos = strlen(cadena1);
	agrupaCadenes(cadena2, cadenaFinal, pos);

	pintaCadena(cadenaFinal, strlen(cadenaFinal));

	acabament();
	return 0;
}
