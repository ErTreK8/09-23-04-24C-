#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include <stdbool.h> 
#include "rlutil.h"
#include "llibreriaPropia.h"
#include "llibreriaExercici.h"


void DemanaCarta(int *numero, char *simbol){
    printf("Introduce un numero de carta: ");
    *numero = demanarNumeroMinMax(MINCARTA, MAXCARTA);
	printf("Introduce el palo de la carta: ");
    *simbol=DemanaSibol();
}

char DemanaSibol(void){
    char simbol='c';
    do
    {
        if (simbol!='O' && simbol!='o' && simbol != 'C' && simbol != 'c' && simbol != 'B' && simbol != 'b' && simbol != 'E' && simbol !='e')
        {
            printf("Dame un palo valido para la carta(O,C,B,E): ");
        }
        while(getchar()!='\n');
        scanf("%c",&simbol);
    } while (simbol!='O' && simbol!='o' && simbol != 'C' && simbol != 'c' && simbol != 'B' && simbol != 'b' && simbol != 'E' && simbol !='e');
    return simbol;
}

