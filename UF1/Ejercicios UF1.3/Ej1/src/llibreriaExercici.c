#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include <stdbool.h> 
#include "rlutil.h"
#include "llibreriaPropia.h"
#include "llibreriaExercici.h"

void intercanviVariables(int *num1, int *num2){
    int ant;
    ant=*num1;
    *num1=*num2;
    *num2=ant;
}
