#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include <stdbool.h> 
#include "rlutil.h"
#include "llibreriaPropia.h"
#include "llibreriaExercici.h"


void exercici()
{
    const char fitxer[]="./fitxers/noms.txt";
    const char fitxer2[]="./fitxers/resum.txt";
    char fichero[255];
    char aux[255];
    
    FILE *f;
    FILE *a;
    FILE *c;

    f=obrirFitxer(fitxer,"r");
    a=obrirFitxer(fitxer2,"w");
    
    
    while (feof(f)==0)
    {
        iniciar(fichero);
        fscanf(f,"%s", aux);
        ponerBienFichero(fichero,aux);
        c=obrirFitxer(fichero,"r");
        fprintf(a,"Contingut Fitxer %s",aux);
        fgets(aux,sizeof(aux),c);
        if (fitxerBuid(fichero)==false)
        {
            while (feof(c)==0)
            {
                fprintf(a,"\n%s",aux);
                fgets(aux,sizeof(aux),c);
            }
            fprintf(a,"%s\n",aux);
        }
        fclose(c);
    }    
    fclose(f);
    fclose(a);
}

void iniciar(char fichero[])
{
    strcpy(fichero,"./fitxers/");
}


void ponerBienFichero(char fichero[],char aux[])
{
    int num=strlen(fichero);
    for (int i = 0; i < strlen(aux); i++)
    {
        fichero[num]=aux[i];
        num++;
    } 
    fichero[num]='\0';  
}




