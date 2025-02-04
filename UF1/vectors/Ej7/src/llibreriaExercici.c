#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include <stdbool.h> 
#include "rlutil.h"
#include "llibreriaPropia.h"
#include "llibreriaExercici.h"


void omplirVector(int v[],int qtt){
    for (int i = 0; i < qtt; i++)
    {
        v[i]=RandomizadorNumeros(1,10);
    }
}

bool totsDintre(int v1[],int qttV1,int v2[],int qttV2){
    bool esta=true;
    int i=0;
    while (i<qttV1 && esta)
    {
        esta=cerca(v2, qttV2, v1[i]);
        if (esta)
        {
            i++;
        }
    }
    return esta;
}