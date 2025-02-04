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
            printf("Dame un palo valido para la carta (O,C,B,E): ");
        }
        while(getchar()!='\n');
        scanf("%c",&simbol);
    } while (simbol!='O' && simbol!='o' && simbol != 'C' && simbol != 'c' && simbol != 'B' && simbol != 'b' && simbol != 'E' && simbol !='e');
    return simbol;
}
void ComprovarCartes(int n1,int n2,int n3,char p1,char p2,char p3)
{   
    if(n1==n2 && n2==n3 && p1==p2 && p2==p3){
        printf("\n\nLas 3 cartas son iguales\n");
    }
    else if((n1==n2 && n2!=n3 && p1==p2 && p2!=p3) ||(n1==n3 && n2!=n3 && p1==p3 && p2!=p3) || (n3==n2 && n1!=n3 && p3==p2 && p1!=p3))
    {
        printf("\n\nHay 2 cartas que son iguales\n");
    }
    else{
        printf("\n\nLa 3 cartas no son iguales\n");
    }
}

