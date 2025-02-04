#include <stdio.h>
#include <stdlib.h>
#include <time.h>  
#include <windows.h>
#include <string.h>
#include <stdbool.h>
#include "rlutil.h"
#include "llibreriaPropia.h"
#include "llibreriaExercici.h"

void agrupaCadenes(char cadena[], char cadenaFinal[], int pos)
{
    int i = 0;
    while (i<strlen(cadena))
    {
        cadenaFinal[i + pos] = cadena[i];
        i++;
    }
}

void pintaCadena(char cadena[], int num)
{
    for (int i = 0; i < num; i++)
    {
        printf("%c", cadena[i]);
    }
    printf("\n");
}
