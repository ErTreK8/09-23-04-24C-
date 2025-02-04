#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include <stdbool.h> 
#include "rlutil.h"
#include "llibreriaPropia.h"
#include "llibreriaExercici.h"


void contaNum(char fitxer1[], char fitxer2[]){

    FILE *f;
    FILE *a;    

    a=obrirFitxer(fitxer2,"w");
    f=obrirFitxer(fitxer1,"r");

    int contador=0;
    int numero;
    int numAnt=11;
    
    numero=fgetc(f)-48;
    while (feof(f)==0)
    {
        // restar -48 porque te lo pilla de la tabla asci

        if (numAnt==numero)
        { 
            contador++;
        }
        else contador=1;
        
        numAnt=numero;
        
        numero=fgetc(f)-48;
        if(numAnt!=numero && feof(f)==0) fprintf(a,"%d%d-",numAnt,contador);
        else if(numAnt!=numero) fprintf(a,"%d%d",numAnt,contador);
    }


    fclose(a);
    fclose(f);
}



