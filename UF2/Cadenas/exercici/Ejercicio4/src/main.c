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
	
	char cadena1[MIDA] = "Hola";
	char cadena2[MIDA] = "Hola";

	printCadena(cadena1,MIDA);
	printf("\n");
	printCadena(cadena2,MIDA);

	bool igual = compararCadenes(cadena1,cadena2,MIDA);
	if (igual==false)
	{
		printf("\nLes dues cadenas No son Iguals");
	}
	else
	{
		printf("\nLes dues cadenas son Iguals");
	}
	


	acabament();
	return 0;
}
