#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include <stdbool.h> 
#include "rlutil.h"
#include "llibreriaPropia.h"
#include "llibreriaExercici.h"

crearFitxers(char fitxer1[]){
    FILE *f;
    f=obrirFitxer(fitxer1,"r");

    char nom[20];
    char cognoms[40];
    int edad;

    
    while (feof(f)==0)
    {
        char cadena[40]="./fitxers/";
        char nombreFichero[40];

        fgets(nom,sizeof(nom),f);
        eliminaSaltLinia(nom);
        fgets(cognoms,sizeof(cognoms),f);
        eliminaSaltLinia(cognoms);
        fscanf(f,"%d",&edad);
        fgetc(f);

        
        fgets(nombreFichero,sizeof(nombreFichero),f);
        eliminaSaltLinia(nombreFichero);
        strcat(cadena,nombreFichero);
        strcat(cadena,".txt");

        FILE *a;
        // la mierda de funcion esta solo funciona con minuscualas
        a=obrirFitxer(cadena,"a");
        fseek(a,0,SEEK_END);
        if(ftell(a)!=0) fprintf(a,"\n%s;%s;%d",nom,cognoms,edad);
        else fprintf(a,"%s;%s;%d",nom,cognoms,edad);
        fclose(a);

    }
    fclose(f);

}

