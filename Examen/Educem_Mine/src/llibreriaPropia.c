#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include <stdbool.h> 
#include "rlutil.h"
#include "llibreriaPropia.h"
#include "llibreriaExercici.h"

void acabament (void)
{
  	printf("\nFelices Fiestas Porti y Claudina :)\n");
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
//Pide un numero entre una variable min y una max
int demanarNumeroMinMax(int min, int max){
    int numero;
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

//Pide un numero
int demanarNumero(void){
    int numero;
    scanf("%d", &numero);
    return numero;
}
//Pide un Caracter
char demanarCaracter(void){
    char caracter;
    scanf("%c", &caracter);
    return caracter;
}
//Calcula los digitos de un numero
int calculaQuantitatDigits(int n){
    
    int digits=0;
    
    while( n > 0){
        n /= 10;
        digits++;
    }
    return digits;
}
// Randomiza un numero entre una variable min y una max
int RandomizadorNumeros(int min, int max){
    int numero;
    numero=rand()%(max-min+1)+min;
    return numero;
}

void pintaQuadrat(int xMax, int yMax){
    int x=1, y=1;
    for (y = 1; y <= yMax; y++)
    {
        if (y==1 || y==yMax)
        {
            for (x = 1; x <= yMax; x++)
            {
                gotoxy(x,y);
                printf("x");
            }
        }
        x=1;
        gotoxy(x,y);
        printf("x");
        x=xMax;
        gotoxy(x,y);
        printf("x");
    }
}