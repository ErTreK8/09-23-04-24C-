#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include <stdbool.h> 
#include "rlutil.h"
#include "llibreriaPropia.h"
#include "llibreriaExercici.h"

void pintaCadena(char cadena[],int longitud)
{
    int i=0;
    while (i<longitud && cadena[i]!=MARCA)
    {
        printf("%c",cadena[i]);
        i++;
    }
    printf("\n");
}

void separaLletres(char cadena[],int longitud,char consonants[],char vocals[])
{
    int i=0;
    int contV=0,contC=0;
    while (i<longitud && cadena[i]!=MARCA)
    {
       if (esVocal(cadena[i]))
       {
        vocals[contV]=cadena[i];
        contV++;
       }        
       else
       {
        consonants[contC]=cadena[i];
        contC++;
       }
       i++;
    }
    vocals[contV+1]='\0';
    consonants[contC+1]='\0';
}

bool esVocal(char car)
{
    bool vocal=false;
    if (car=='a' || car=='e' || car=='i' || car=='o' || car=='u')
    {
        vocal=true;
    }
    return vocal;
}