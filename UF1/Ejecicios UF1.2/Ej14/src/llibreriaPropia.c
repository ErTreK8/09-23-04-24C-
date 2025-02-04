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

int demanaNumMinMax(int min, int max){
    int n=1;
    do 
    {
        if (n<min || n>max)
        {
            printf("Numero incorrecto, introduce un numero entre %d y %d\n", min, max);
        }
        scanf("%d", &n);
    }
    while (n<min || n>max);
    return n;
}