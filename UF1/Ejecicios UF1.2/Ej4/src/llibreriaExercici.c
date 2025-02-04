#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include <stdbool.h> 
#include "rlutil.h"
#include "llibreriaPropia.h"
#include "llibreriaExercici.h"

void printaTaula(){
    for (int b = 1; b!=11; b++)
    {
        for(int i = 1; i!=11; i++)
        {
        printf("%d x %d = %d\n", b, i, b*i);
        }
        printf("\n");
    } 
}