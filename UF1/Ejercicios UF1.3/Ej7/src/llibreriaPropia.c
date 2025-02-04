#include <stdio.h>
#include <stdlib.h>
#include <time.h>  
#include <windows.h>
#include <string.h>
#include <stdbool.h>
#include "rlutil.h"
#include "llibreriaPropia.h"
#include "llibreriaExercici.h"

void acabament (void)
{
	printf("\nPrem una tecla per finalitzar");
	getch();
}

int demanaNumEntreRangInt(int minim,int maxim)
{
    int n;
    do
    {
        scanf("%d",&n);
        if (n<minim || n>maxim)
        {
            printf("Introdueix un numero entre [%d-%d]: ",minim,maxim);
        }
    } while (n<minim || n>maxim);
    return n;
}


int generarNumEntreRang(int minim,int maxim)
{
	return (rand()%(maxim-minim+1)+minim);
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
char demanaCaracter(void)
{
    char car;
    scanf("%c",&car);
    while(getchar()!='\n');
    return car;
}
int demanaNumInt()
{
    int n;
    scanf("%d",&n);
    return n;
}
void intercanvi(int *num1,int *num2)
{
    int aux;
    aux=*num1;
    *num1=*num2;
    *num2=aux;
}

