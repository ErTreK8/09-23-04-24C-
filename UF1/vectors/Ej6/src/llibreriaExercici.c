#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include <stdbool.h> 
#include "rlutil.h"
#include "llibreriaPropia.h"
#include "llibreriaExercici.h"


int llenarVector(int v[],int max){
    int qtt=0;
    for (int i = 0; i < max; i++)
	{
        printf("\nIntrodueix un Numero: ");
		v[i]=demanarNumeroMinMax(-499,499);
        qtt++;
        printaVectorOrdenatNumero(v,qtt);
	}
    return qtt;
}
void printaVectorOrdenatNumero(int v[],int qtt){
    int pos=-1,i=-500,j=0;
//    for (int i = -500; i < 500; i++)
    while (i<500 && j<qtt)
    {
        pos=posicio(v,qtt,i);
        if (pos!=-1)
        {
            printf("%d     ",i);
            j++;
        }
        i++;
    }
}
