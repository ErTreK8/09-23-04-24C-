#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <string.h>
#include <stdbool.h>
#include "rlutil.h"
#include "llibreriaPropia.h"
#include "llibreriaExercici.h"

int calculaPosicio(int v[],int qtt,int num)
{
    int i=0;

    while (i<qtt && num>v[i])
    {
        i++;
    }

    return i;
}

void moure(int v[],int qtt,int pos)
{
    for (int i=qtt;i>pos;i--)
    {
        v[i]=v[i-1];
    }
}

