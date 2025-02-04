#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include <stdbool.h> 
#include "rlutil.h"
#include "llibreriaPropia.h"
#include "llibreriaExercici.h"

int Partido(int *local,int *visitante,int *i,int *puntsjornada)
{
    int puntstotal=0;
    *puntsjornada=0;
    
        if (*i%2!=0)
        {
            if (*local>*visitante)
            {
                *puntsjornada=3;
            }
            else if (*local==*visitante)
            {
                *puntsjornada=1;
            }
        }
        if (*i%2==0)
        {
            if (*visitante>*local)
            {
                *puntsjornada=3;
            }
            else if (*local==*visitante)
            {
                *puntsjornada=1;
            }
        }
    puntstotal=*puntsjornada;
    return puntstotal;
}
