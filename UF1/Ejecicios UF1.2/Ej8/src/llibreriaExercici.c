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
    int digitinv=0, digito=0;
    while(numero>0)
    {      
        digito=numero%10;
        digitinv= digitinv * 10 + numero%10;
        numero=numero/10;
    }
    while (digitinv>0)
    {
        digito=digitinv%10;
        printf("%d-", digito);
        digitinv=digitinv/10;
    }
}