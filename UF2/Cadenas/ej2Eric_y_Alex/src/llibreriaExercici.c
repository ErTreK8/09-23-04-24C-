#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include <stdbool.h> 
#include "rlutil.h"
#include "llibreriaPropia.h"
#include "llibreriaExercici.h"

void ompleVector(int v[],int mida)
{
    for (int i = 0; i < mida; i++)
    {
        v[i]=RandomizadorNumeros(0,4);
    }
}

void pintavector2(int v[], int qtt)
{
    if (qtt == 0)
    {
        printf("\nVector buit");
    }

    else
    {
        for (int i = 0; i < qtt; i++)
        {
            printf("%d  ", v[i]);
        }
    }
}

void cambiaVector(int v[], int mida,int v2[],int *qtt)
{
    for (int i = 0; i < mida; i++)
    {
        if (i==0)
        {
            v2[(*qtt)]=v[i];
            (*qtt)++;
        }
        else if (v[i]!=v[i-1])
        {
            v2[(*qtt)]=v[i];
            (*qtt)++;
        }
    }
}

void compteNum(int v[],int qtt,int comptador[],int numero)
{
    for (int i = 0; i < qtt; i++)
    {
        switch (v[i])
        {
        case 0:
            comptador[0]++;
            break;
        case 1:
            comptador[1]++;
            break;
        case 2:
            comptador[2]++;
            break;
        case 3:
            comptador[3]++;
            break;
        case 4:
            comptador[4]++;
            break;        
        default:
            break;
        }
    }
}
