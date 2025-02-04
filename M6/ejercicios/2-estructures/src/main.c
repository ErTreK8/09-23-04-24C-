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
	
	
	generar();
	printf("\ABANS DE L'INCREMENT:\n");
	llegir();
	incrementar();
	printf("\nDESPRES DE L'INCREMENT:\n");
	llegir();
	
	eliminar();
	printf("\nDESPRES D'ELIMINAR L'ARTICLE:\n");
	llegir();
	
	girarFitxerAuxiliar();



	//girarFitxerSenseAuxiliar();
	acabament();
	return 0;
}
