#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include <stdbool.h> 
#include "rlutil.h"
#include "llibreriaPropia.h"
#include "llibreriaExercici.h"

void creaFitxer(char fitxer[] ,char fitxer2[])
{
    FILE *f;
    FILE *a;

    char cadena[255];

    f=obrirFitxer(fitxer,"r");

    a=obrirFitxer(fitxer2,"w");
    fgets(cadena,sizeof(cadena),f);
    
    while (feof(f)==0)
    {
        cambiaCadena(cadena);
        fprintf(a,"%s",cadena);
        fgets(cadena,sizeof(cadena),f);
    }
    cambiaCadena(cadena);
    fprintf(a,"%s",cadena);
    
}

void cambiaCadena(char cadena[])
{

    for (int i = 0; i < strlen(cadena); i++)
    {
        cadena[i]=cambiaSiEsMayus(cadena[i]);
    }
    
    for (int i = 0; i < strlen(cadena); i++)
    {
        if (cadena[i]==' ')
        {
            mouTot(cadena, i);
        }
    }
    eliminaSaltLinia(cadena);

}

char cambiaSiEsMayus(char cad)
{
    char lletresM[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZÀÁÈÉÍÏÍÒÓÚÜÑÇ";
	char lletresm[] = "abcdefghijklmnopqrstuvwxyzàáèéíïíòóúüñç";

    char lletra=cad;

    bool trobat=false;
    int i=0;

    while (i < strlen(lletresM) && trobat!=true)
    {
        if (lletra==lletresM[i])
        {
            lletra=lletresm[i];
            trobat=true;
        }
        i++;
    }
    return lletra;  
}

void mouTot(char cadena[], int num)
{
    int i=num;
    while (i < (strlen(cadena)-1))
    {
        cadena[i]=cadena[i+1];
        i++;
    }
    cadena[i]='\0';
}

void eliminaSaltLinia(char cadena[])
{
    if (strlen(cadena) > 0 && cadena[strlen(cadena) - 1] == '\n')
    {
        cadena[strlen(cadena) - 1] = '\0';
    }
}
