#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include <stdbool.h> 
#include "rlutil.h"
#include "llibreriaPropia.h"
#include "llibreriaExercici.h"

int lineasFitxer(char fitxer[])
{
    int lineas=0;
    FILE *f;
    char c;
    if (!fitxerBuid(fitxer))
    {
        f=obrirFitxer(fitxer,"r");
        c=fgetc(f);
        while (feof(f)==0)
        {
            if (c=='\n') lineas++;
            c=fgetc(f);
        }
        lineas++;
        fclose(f);
    }
    return lineas;
}