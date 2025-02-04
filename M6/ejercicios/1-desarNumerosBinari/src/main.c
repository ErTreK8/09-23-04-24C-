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
	
	printf("\nM6UF1:\n");
	generar();
	int qttElements=calculaQuantitatElements(UBICACIONUMEROS,sizeof(int));
	printf("\nLectura amb el while:\n");
	llegirWhile(UBICACIONUMEROS);
	printf("\nLectura amb FOR:\n");
	llegirFor(UBICACIONUMEROS,qttElements);

	modificarElement(qttElements);
	printf("\nLectura amb el canvi a 14\n");
	llegirFor(UBICACIONUMEROS,qttElements);

	mostrarFitxerDesDeSota(UBICACIONUMEROS,qttElements);

	acabament();
	return 0;
}
