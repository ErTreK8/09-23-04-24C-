#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include <stdbool.h> 
#include "rlutil.h"
#include "llibreriaPropia.h"
#include "llibreriaExercici.h"

int demanaNum()
{
    int n;
    printf("Introduce un numero: ");
    scanf("%d", &n);
    return n;
}

int calculNumMax(int a,int b)
{
    int c;
    if (a>b)
    {
        c=a;
    }
    else
    {
        c=b;
    }
    return c;
}

void mostraResultat(num1,num2,maxim)
{
    printf("\nEl Primer numero es: %d\n",num1);
    printf("El Segundo numero es: %d\n",num2);
    printf("\nEl Numero maximo es: %d\n",maxim);
}