#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <string.h>
#include <stdbool.h>
#include "rlutil.h"
#include "llibreriaPropia.h"
#include "llibreriaExercici.h"


void separa(char frase[],int longFrase,char matriu[][MIDA])
{
    int fila=0,col=0;
    int i=0;

    while (i<longFrase && frase[i]!='\0')
    {
        if (frase[i]!='-')
        {
            matriu[fila][col]=frase[i];
            col++;
        }
        else
        {
            matriu[fila][col]=MARCA;
            fila++;
            col=0;
        }
        i++;
    }
    matriu[fila][col]=MARCA;
}

void pinta(char matriu[][MIDA])
{
    char opcions[4][20]={"NOM: ","COGMOM1: ","COGNOM2: ","CURS: "};
    for (int i=0;i<MAXPARAULES;i++)
    {
        printf("\n%-10s:%s",opcions[i],matriu[i]);
    }
}

void separa2(char frase[],int longFrase,char matriu[][MIDA])
{
    int i=0;
    char auxParaula[MIDA];
    int fila=0;

    while (i<longFrase && frase[i]!='\0')
    {
        separaParaulaSeparador(frase,longFrase,'-',auxParaula,&i);
        strcpy(matriu[fila],auxParaula);
        fila++;
        i++; // incrementem un per a saltar el separador
    }

    
    
}

void separaParaulaSeparador(char frase[],int longFrase,char separador,char auxParaula[],int *i)
{
    int j=0;
    while (*i<longFrase && frase[*i]!=separador && frase[*i]!=MARCA)
    {
        auxParaula[j]=frase[*i];
        (*i)++;
        j++;
    }
    auxParaula[j]=MARCA;

}
