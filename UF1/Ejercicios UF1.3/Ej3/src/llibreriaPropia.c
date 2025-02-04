#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include <stdbool.h> 
#include "rlutil.h"
#include "llibreriaPropia.h"
#include "llibreriaExercici.h"

void acabament (void)
{
	printf("\nPrem una tecla per finalitzar");
	getch();
}

//rep un minim que aceptamos i retorna un numeros superior o igual a aquest minim
//0  -->    >=0
int demanaNumUnLimitInt(int minim)
{
    int n;
    do
    {
       scanf("%d",&n);
       if (n<minim)
       {
            printf("Introdueix un numero superior o igual a %d: ",minim);
       }
    } while (n<minim);
    return n;
}

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


int demanarNumero(void){
    int numero;
    scanf("%d", &numero);
    return numero;
}

char demanarCaracter(void){
    char caracter;
    scanf("%c", &caracter);
    return caracter;
}

int calculaQuantitatDigits(int n){
    
    int digits=0;
    
    while( n > 0){
        n /= 10;
        digits++;
    }
    return digits;
}
