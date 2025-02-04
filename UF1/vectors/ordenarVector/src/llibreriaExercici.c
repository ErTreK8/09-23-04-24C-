#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include <stdbool.h> 
#include "rlutil.h"
#include "llibreriaPropia.h"
#include "llibreriaExercici.h"

void ordenar(int v[],int qtt){
    for (int i = 0; i < qtt; i++)
    {
        for (int j = 0; j < qtt-i-1; j++)
        {
            if (v[j]>v[j+1])
            {
                intercanvi(&v[j],&v[j+1]);
            }   
        }    
    } 
}


void ordenar2(int v[],int qtt){
    bool canvi=false;
    int h=0;
    for (int i = 0; i < qtt && !canvi; i++)
    {
        for (int j = 0; j < qtt-i-1; j++)
        {
            if (v[j]>v[j+1])
            {
                intercanvi(&v[j],&v[j+1]);
                h=1;
            }   
            else if (h==0)
            {
                canvi=true;
            }
        }
        h=0;
    } 
}