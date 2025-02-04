#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include <stdbool.h> 
#include "rlutil.h"
#include "llibreriaPropia.h"
#include "llibreriaExercici.h"

void passarMajuscula(char cadena[],int longitud)
{
    int i=0;
    while (i<longitud && cadena[i]!='\0')
    {

        if (cadena[i]>='a' && cadena[i]<='z')
        {
            cadena[i]=cadena[i]-('a'-'A');
        }
        i++;
    }
}

void pintaCadena(char cadena[], int longitud)
{
    int i=0;
    while (i<longitud && cadena[i]!='\0')
    {
        printf("%c",cadena[i]);
        i++;
    }
}

int calculaPosicioMinuscula(char car)
{
    char lletresm[] = "abcdefghijklmnopqrstuvwxyzàáèéíïíòóúüñç";
    int i=0, pos=-1;
    while (i<strlen(lletresm) && pos==-1)
    {
        if (car==lletresm[i])
        {
            pos=i;
        }
        else
        {
            pos=-1;
        }
        i++;
    }
    return pos;
}

char passaCarMajus(char car)
{
    char lletresM[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZÀÁÈÉÍÏÍÒÓÚÜÑÇ";

    int pos=calculaPosicioMinuscula(car);
    if (pos>-1)
    {
        car=lletresM[pos];
    }
    return car;
}

void passarMajuscula2(char cadena[],int longitud)
{
    int i=0;
    while (i<longitud && cadena[i]!='\0')
    {
        cadena[i]=passaCarMajus(cadena[i]);
        i++;
    }
}

