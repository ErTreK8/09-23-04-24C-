#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include <stdbool.h> 
#include "rlutil.h"
#include "llibreriaPropia.h"
#include "llibreriaExercici.h"

void ordenarCadenes(char matriu[][20],int totalFiles)
{
    bool canvi=false;
    char auxiliar[20];

    for (int i=0;i<totalFiles-1 && !canvi;i++)
    {
        for (int j=0;j<totalFiles-i-1;j++)
        {
            if (strcmp(matriu[j],matriu[j+1])>0)
            {
                canvi=true;
                strcpy(auxiliar,matriu[j]);
                strcpy(matriu[j],matriu[j+1]);
                strcpy(matriu[j+1],auxiliar);
            }
        }
        canvi=!canvi;
    }
}

void entraCadena(char cad[],int longuitud)
{
    fgets(cad,longuitud,stdin);
    if (strlen(cad)>0 && cad[strlen(cad)-1]=='\n')
	{
		cad[strlen(cad)-1]='\0';
	}
}