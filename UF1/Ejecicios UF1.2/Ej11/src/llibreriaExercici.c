#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include <stdbool.h> 
#include "rlutil.h"
#include "llibreriaPropia.h"
#include "llibreriaExercici.h"

char demanaCaracter(){
    char c;
    scanf("%c", &c);
    return c;
}

int demanaNumero(){
    int n;
    scanf("%d", &n);
    return n;
}

void printa(char caracter, int numero){
    int numeroant=numero;
    for (int i = 1; i <= numero; i++)
    {
        for (int n = numeroant-1; n > 0; n--)
        {
            printf(" ");
        }
        for (int n = i; n > 0; n--)
        {
            printf("%c", caracter);
        }
        printf("\n");
        numeroant--;
    }
    
}