#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include <stdbool.h> 
#include "rlutil.h"
#include "llibreriaPropia.h"
#include "llibreriaExercici.h"

void pintaVector2(int v[],int qtt)
{
    if (qtt==0) printf ("\nVector buit");
    else
    {
        for (int i=0;i<qtt;i++)
        {
            if (v[i]>0)
            {
                printf("\n[%02d]:%d",i,v[i]);
            }
        }
    }
}

int posicio(int v[],int qtt,int numCerca)
{
    int i=0, pos=-1;
    while(i<qtt && pos==-1)
    {
        if(v[i]==numCerca)
        {
            pos=i;
        }
        else
        {
            i++;
        }
    }
    return pos;
}