#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include <stdbool.h> 
#include "rlutil.h"
#include "llibreriaPropia.h"
#include "llibreriaExercici.h"

void llenarMatriz(char cad[],int longuitud,char matriu[][20])
{
    int fila=0,col=0;
    int i=0;
    while (i<longuitud && cad[i]!='\0')
    {
        if (cad[i]!='-')
        {
            matriu[fila][col]=cad[i];
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

void pinta(char matriu[][20])
{
    char opcions[4][20]={"NOM ","COGNOM 1","COGNOM 2 ","CURS "};
    for (int i = 0; i < 4; i++)
	{
        // dejas 10 caracteres de lado para q todo se vea bien  
		printf("\n%-10s:%s",opcions[i],matriu[i]);
	}
}