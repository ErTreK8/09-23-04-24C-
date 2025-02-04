#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include <stdbool.h> 
#include "rlutil.h"
#include "llibreriaPropia.h"
#include "llibreriaExercici.h"

void llegir(char file[])
{
    FILE *f=obrirFitxer(file,"rt");
    CURSQUANTITAT un;
    if(f!=NULL);
    {
        while (feof(f)==0)
        {
            un=llegirUnCurs(f);
            printf("\n%s %c",un.curs,un.letra);
        }
    }
    fclose(f);
}

CURSQUANTITAT llegirUnCurs(FILE *f)
{
    CURSQUANTITAT un;

    fgets(un.curs,sizeof(un.curs),f);
    eliminaSaltLinia(un.curs);
    fflush(f);

    // ASI SE COJE UN NUMEROç
    //fscanf(f,"%d",&numero);

    un.letra=fgetc(f);
    fgetc(f);
    return un;
}

void actualitzar(char file[])
{
    //volem incremenetar en 1 cada una de les lletres
    char cursIncrementar[30];
    printf("\nQuin curs vols incrementar: ");
    
    entrarCadena(cursIncrementar,sizeof(cursIncrementar));

    CURSQUANTITAT unFile;
    FILE *f=obrirFitxer(file,"rt+");
    bool trobat=false;
    if(f!=NULL)
    {
        while (feof(f)==0 && trobat!=true)
        {
            unFile=llegirUnCurs(f);
            if (strcmp(unFile.curs,cursIncrementar)==0)
            {
                trobat=true;
                if(feof(f)==0) fseek(f,-3,SEEK_CUR);
                else fseek(f,-1,SEEK_CUR);
                fputc(unFile.letra+1,f);
                fflush(f);
            }   
        }
    }
    fclose(f);
}