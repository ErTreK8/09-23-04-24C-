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
