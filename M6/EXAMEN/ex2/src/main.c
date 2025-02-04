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
	

	if(existeixFitxer(UBICACIOCONTRASENYACOPIA)) remove(UBICACIOCONTRASENYACOPIA);	
	copiaFitxer(UBICACIOCONTRASENYA,UBICACIOCONTRASENYACOPIA);


	llegirFitxer();
	limpiaFitxer();
	printf("\n\n Fitxer Net");
	llegirFitxer();
	

	acabament();
	return 0;
}
