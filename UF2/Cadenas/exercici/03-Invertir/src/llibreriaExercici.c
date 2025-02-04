#include <stdio.h>
#include <stdlib.h>
#include <time.h>  
#include <windows.h>
#include <string.h>
#include <stdbool.h>
#include "rlutil.h"
#include "llibreriaPropia.h"
#include "llibreriaExercici.h"

void pintaFrase(char cadena[],int longitud)
{
    int i = 0;
    while (i<longitud && cadena[i]!='\0')
    {
        printf("%c",cadena[i]);
        i++;
    }
    
}

void invertirCadena(char frase[],char fraseInvertida[], int longitud)
{
    int j = 0;
    for (int i = longitud-1; i >= 0; i--)
    {
        fraseInvertida[j] = frase[i];
        j++;
    }
    fraseInvertida[j]='\0';

    copiar(frase,fraseInvertida,longitud);
}

void copiar(int frase[],int fraseInvertida[],int longitud)
{
    //strcpy(frase,fraseInvertida);
    
    for (int i = longitud-1; i >= 0; i--)
    {
        frase[i] = fraseInvertida[i];
    }
}
