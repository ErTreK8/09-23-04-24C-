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

	int casellaMina1=0, casellaMina2=0, casellaMina3=0, casellaMina4=0, casellaMina5=0, final=0, punts=0, cordenadesMaquina=0, casellaJugador=0,casellaJugadorFila=0,casellaJugadorColumna=0;
	char lletra;
	setColor(WHITE);
	aconseguiMines(&casellaMina1, &casellaMina2, &casellaMina3, &casellaMina4, &casellaMina5);
    printf("BENVINGUT AL JOC DEL BUSCAMINES\n");
	pintaTaulell(casellaMina1, casellaMina2, casellaMina3, casellaMina4, casellaMina5);
	Sleep(2000);
	cls();
	printf("Amb quina modalitat vols jugar?\nU: hauras d'encertar %d caselles sense mines\nM: la maquina genera les caselles aleatoriament i s'hauran d'encertar %d caselles buides\n", BUCLE_U, BUCLE_M);
	lletra=UoM();
	printf("\n\n");
	if (lletra=='u' || lletra=='U')
	{
		while (final==0)
		{
			if (punts!=BUCLE_U)
			{
				printf("Digues la fila [0-2]: ");
				casellaJugadorFila=demanarNumeroMinMax(MIN_FILA, MAX_FILA);
				printf("Digues la fila [0-9]: ");
				casellaJugadorColumna=demanarNumeroMinMax(MIN_COLUMNA,MAX_COLUMNA);
				casellaJugador=calcularCasella(casellaJugadorFila,casellaJugadorColumna);
			}		
			salirBucleU(&final,casellaJugador, &punts, casellaMina1, casellaMina2, casellaMina3, casellaMina4, casellaMina5);
		}
	}
	else if (lletra=='m' || lletra=='M')
	{
		while (final==0)
		{
			if (punts!=BUCLE_M)
			{
				cordenadesMaquina=RandomizadorNumeros(MIN_NUM_CASELLA,MAX_NUM_CASELLA);
				printf("Les Cordenades Generades son [%d-%d]\n",(cordenadesMaquina/10),(cordenadesMaquina%10));
			}
			salirBucleM(&final,cordenadesMaquina, &punts, casellaMina1, casellaMina2, casellaMina3, casellaMina4, casellaMina5);
		}
		
	}
	switch (final)
	{
	case 1:
		cls();
	    printf("RESUM BOMBES\n");
		pintaTaulell(casellaMina1, casellaMina2, casellaMina3, casellaMina4, casellaMina5);
		printf("\nEts un crac... un altre cop et guanyo jo.\n");
		break;
	case 2:
		printaFinal2(cordenadesMaquina, casellaMina1, casellaMina2, casellaMina3, casellaMina4, casellaMina5);
		break;
	case 3:
		printaFinal3(casellaJugador, casellaMina1, casellaMina2, casellaMina3, casellaMina4, casellaMina5);
		break;
	default:
		break;
	}
	acabament();
	return 0;
}
