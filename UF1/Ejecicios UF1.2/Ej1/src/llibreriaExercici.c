#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include <stdbool.h> 
#include "rlutil.h"
#include "llibreriaPropia.h"
#include "llibreriaExercici.h"

int demanarNumero(){
    int numero;
    do
    {
    printf("Introduce un numero entre el 1 y el 10: ");
    scanf("%d", &numero);
    }
    while(numero < 1 || numero > 10);
    return numero;
}

void transformarNota(int numero){
    switch (numero)
    {
    case 1:
    case 2:
    case 3:
    case 4:
        printf("Insuficient");
        break;
    case 5:
    case 6:
        printf("Suficient");
        break;
    case 7:
    case 8:
        printf("Notable");
        break;
    case 9:
    case 10:
        printf("Excellent");
        break;
    default:
        break;
    }    
}