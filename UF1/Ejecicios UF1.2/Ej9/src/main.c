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
	int mes, dia;
	printf("Introduce un Mes entre %d y %d: ", Minimo, MaximoMes);
	mes=demanarNumeroMinMax(Minimo, MaximoMes);
	printf("Introduce un Dia entre %d y %d: ", Minimo, MaximoDia);
	dia=demanarNumeroMinMax(Minimo, MaximoDia);
	printa(mes, dia);
	acabament();
	return 0;
}
