#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include <stdbool.h> 
#include "rlutil.h"
#include "llibreriaPropia.h"
#include "llibreriaExercici.h"

int demanarNumero(){
    int numero;
    do{
        printf("Introduce un numero del 1 al 10: ");
        scanf("%d", &numero);
        printf("\n");
    }
    while (numero < 1 || numero > 10);    
    return numero;
}
void printaTaula(numero){
    int i;
    for(i = 1; i!=11; i++){
        printf("%d x %d = %d\n", numero, i, numero*i);
        Sleep(30);
    }
}