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
	char cadena[MIDA]=" Bon    Dia   Nenes  ";
	printf("--%s--",cadena);
//	eliminaEspaiDarrera(cadena,MIDA);
//	eliminarEspaisDavant(cadena,MIDA);
	adeuEspai(cadena,MIDA);
	printf("\n\n--%s--",cadena);



	acabament();
	return 0;
}
