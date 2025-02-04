#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include <stdbool.h> 
#include "rlutil.h"
#include "llibreriaPropia.h"
#include "llibreriaExercici.h"

void demanarDomino(int *cara1, int *cara2, int min, int max){
    int i=0;
    do{
		if (((*cara1) < min || (*cara1) > max) || ((*cara2) < min || (*cara2) > max) && i==1)
		{
			printf("Introduce la pieza de domino [0-6]: ");
		}
        scanf("%d%d", &(*cara1), &(*cara2));
        i=1;
	}
    while (((*cara1) < min || (*cara1) > max) || ((*cara2) < min || (*cara2) > max));
}
void final(int pieza1Domino1, int pieza1Domino2, int pieza2Domino1, int pieza2Domino2){
    if (pieza1Domino1==pieza2Domino1 || pieza1Domino1==pieza2Domino2)
    {
        setColor(GREEN);
        printf("\n\nLes fitxes es poden juntar\n");
        setColor(WHITE);
    }
    else if (pieza1Domino2==pieza2Domino1 || pieza1Domino2==pieza2Domino2)
    {
        setColor(GREEN);
        printf("\n\nLes fitxes es poden juntar\n");
        setColor(WHITE);
    }
    else{
        setColor(RED);
        printf("\n\nLes fitxes NO es poden juntar\n");
        setColor(WHITE);
    }
}
