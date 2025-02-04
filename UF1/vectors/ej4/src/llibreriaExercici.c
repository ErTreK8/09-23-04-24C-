#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include <stdbool.h> 
#include "rlutil.h"
#include "llibreriaPropia.h"
#include "llibreriaExercici.h"


void omplevector(int v[],int qtt)
{
    
    for (int  i = 0; i < qtt; i++)
    {
        do
        { 
            printf("Introdueix el numero %d: ",i);
            v[i] = demanaNumero();

        } while (cerca(v,i,v[i]) == true);
    }
    
}

bool cerca(int v[], int qtt, int numUsuari)
{
    bool trobat = false;
    int i = 0;
    while (i < qtt && !trobat)
    {
        if (v[i] == numUsuari)
        {
            trobat = true;
        }
        else
        {
            i++;
        }
    }
    return trobat;
}