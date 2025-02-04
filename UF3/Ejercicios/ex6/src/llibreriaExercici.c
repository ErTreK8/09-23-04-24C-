#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include <stdbool.h> 
#include "rlutil.h"
#include "llibreriaPropia.h"
#include "llibreriaExercici.h"


void comprobarFitxersIguals(char fitxer1[], char fitxer2[])
{
    FILE *f;
    FILE *a;

    char cadena1[255];
    char cadena2[255];
    int igual=0;
    bool iguales=true;

    f=obrirFitxer(fitxer1,"r");
    a=obrirFitxer(fitxer2,"r");

    fgets(cadena1,sizeof(cadena1),f);
    fgets(cadena2,sizeof(cadena2),a);
    int pene;
    pene=feof(f);

    pene=feof(a);
    while (feof(f)==0 && feof(a)==0 && igual==0)
    {
        igual=strcmp(cadena1,cadena2);
        fgets(cadena1,sizeof(cadena1),f);
        fgets(cadena2,sizeof(cadena2),a);
    }
    igual=strcmp(cadena1,cadena2);

    
    if (feof(f)==1 && feof(a)==0) iguales=false;
    else if (feof(f)==0 && feof(a)==1) iguales=false;
    else if (igual!=0) iguales=false;
    fclose(f);
    fclose(a);
    if (iguales==true) printf("Los archivos son iguales");
    else printf("Los ficheros no son iguales");

}