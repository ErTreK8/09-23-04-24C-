#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include <stdbool.h> 
#include "rlutil.h"
#include "llibreriaPropia.h"
#include "llibreriaExercici.h"

int demanarNumero(){
    int numero;
    scanf("%d", &numero);
    return numero;
}

void resultat(int numero){ 

    for (int numeroant=numero; numeroant>=1; numeroant=numeroant/10)
    {        
        printf("%d-", numero%10);
        numero=numero/10;
    }
}

