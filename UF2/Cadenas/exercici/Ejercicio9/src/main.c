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
	
	char cadena[]="Free    Paco     Sans   No se que no se quantos";

	int puntos = 0;

	int palabra = 0;

	printCadena(cadena,strlen(cadena));

	contaParaules(cadena,strlen(cadena),&palabra);

	printf("\nNumero de paraules %d",palabra);


	acabament();
	return 0;
}
