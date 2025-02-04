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

int calculaQuantitatDigits(int numero){
    int quantitat = 0;
    while(numero > 0){
        numero = numero/10;
        quantitat++;
    }
    return quantitat;
}

void pinta(int numero, int quantitat){
    printf("El numero %d tiene %d dígits\n", numero, quantitat);
}