#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include <stdbool.h> 
#include "rlutil.h"
#include "llibreriaPropia.h"
#include "llibreriaExercici.h"

int demanarNumero(){
    int numero;
    printf("Introduce un numero: ");
    scanf("%d", &numero);
    return numero;
}
int calculaSumaNumerosAnterior(int numero){
    int total = 0;
    for(int i = 1; i <= numero; i++){
        total = total+i;
    }
    return total;
}
void pinta(int numeros, int total){
    printf("Suma dels %d numeros es: %d\n", numeros, total);
}