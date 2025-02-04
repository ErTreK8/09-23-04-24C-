#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include <stdbool.h> 
#include "rlutil.h"
#include "llibreriaPropia.h"
#include "llibreriaExercici.h"

int demanarNumeroMinMax(int min, int max){
    int numero=3;
    do{
		if (numero < min || numero > max)
		{
			printf("Introduce un numero entre %d y %d: ", min, max);
		}
        scanf("%d", &numero);
	}
    while (numero < min || numero > max);
    return numero;
}

void printa(int mes, int dia){
    if ( (mes>=1&&mes<=2) || (mes==3&&dia<=20) || (mes==12&&dia>=21))
	{
		printf("Invierno");
	}
	else if((mes==3&&dia>20) || (mes>=4&&mes<=5) || (mes==6&&dia<=20)){
		printf("Primavera");
	}
	else if((mes==6&&dia>20) || (mes>=7&&mes<=8) || (mes==9&&dia<=20)){
		printf("Verano");
	}
	else{
		printf("Otoño");
	}
}