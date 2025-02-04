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
	int ano, mes, dia, numero;
	printf("Introdueix un Año entre %d i %d: ", MinAno, MaxAno);
	ano=demanarNumeroMinMax(MinAno,MaxAno);
	printf("Introdueix un Mes entre %d i %d: ", MinMes, MaxMes);
	mes=demanarNumeroMinMax(MinMes,MaxMes);
	dia=demanarDiaMes(mes,ano);
	printf("Cuants dias vols que pasin?: ");
	numero=demanarNumero();
	printa(dia,mes,ano,numero);

	acabament();
	return 0;
}
