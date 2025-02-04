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

	// borra fitxer Resum
	if(existeixFitxer(UBICACIOFITXRESUM)==true) remove(UBICACIOFITXRESUM);
	
	// copia el arxiu de Vendes per poder fer un doble bucle
	copiaArixu(UBICACIOFITXERORIGEN,UBICACIOFITXERORIGENCOPIA);
	// lee el fichero y creo el fichero resumen	
	llegirFitxer(UBICACIOFITXERORIGEN);
	// si existe el resumen hace el print final
	if(existeixFitxer(UBICACIOFITXRESUM)==true) llegirFinal(UBICACIOFITXRESUM);
	// borra la copia antes hecha
	remove(UBICACIOFITXERORIGENCOPIA);

	acabament();
	return 0;
}
