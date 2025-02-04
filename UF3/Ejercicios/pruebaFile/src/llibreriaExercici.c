#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include <stdbool.h> 
#include "rlutil.h"
#include "llibreriaPropia.h"
#include "llibreriaExercici.h"


FILE* obrirFItxer(const char nomFitxer[], char mode[])
{
    FILE *f;
    f=fopen(nomFitxer,mode);
    if (f==NULL)
    {
        // mode:R   W   A
        if (strcmpi(mode,"r")==0 ||strcmpi(mode,"rt")==0 ||strcmpi(mode,"r+")==0 ||strcmpi(mode,"rt+")==0)
        {
            printf("No s'ha pogut obrir el fitxer en modo lectrua");
        }
        else if (strcmpi(mode,"w")==0 ||strcmpi(mode,"wt")==0 ||strcmpi(mode,"w+")==0 ||strcmpi(mode,"wt+")==0)
        {
            printf("No s'ha pogut Crear el fitxer en modo lectrua");
        }
        else if (strcmpi(mode,"a")==0 ||strcmpi(mode,"at")==0 ||strcmpi(mode,"a+")==0 ||strcmpi(mode,"at+")==0)
        {
            printf("No s'ha pogut Actualitzar el fitxer en modo lectrua");
        }
        else
        {
            printf("\n Mode Incorrecta");
        }
    }
    return(f);
}

void omplir(FILE *f)
{
    int edat=25;
    printf("\n%d",fputs("A\nB",f));
	printf("\n%ld",ftell(f));
	printf("\n%d",fprintf(f,"Hola que tal \n %d",edat));
}

void exercici(FILE *a)
{
    for (int i = 1; i < 101; i++)
    {
        fprintf(a,"fitxer%d.txt",i);
        if (i!=100)
        {
            fputs("\n",a);
        }
    }
}
