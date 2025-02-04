#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include <stdbool.h> 
#include "rlutil.h"
#include "llibreriaPropia.h"
#include "llibreriaExercici.h"


int demanarNumero(){
    int numero;
    printf("Introduce el numero de alumnos: ");
    scanf("%d", &numero);
    return numero;
}
void demanarNotas(int alumnes){
    int notas;
    for(int i = 0; i < alumnes; i++){
        printf("Introduce las notas del alumno %d: ", i+1);
        scanf("%d", &notas);
        transformarNota(notas);
    }
    return;
}

void transformarNota(int numero){
    switch (numero)
    {
    case 1 ... 4:
        printf("Insuficient\n");
        break;
    case 5 ... 6:
        printf("Suficient\n");
        break;
    case 7 ... 8:
        printf("Notable\n");
        break;
    case 9 ... 10:
        printf("Excellent\n");
        break;
    default:
        break;
    }    
}