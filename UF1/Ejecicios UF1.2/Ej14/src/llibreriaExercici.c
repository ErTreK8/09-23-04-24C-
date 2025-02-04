#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include <stdbool.h> 
#include "rlutil.h"
#include "llibreriaPropia.h"
#include "llibreriaExercici.h"

int GeneraValorEntreRang(int min,int max){
    int valor;
    valor = rand() % (max - min + 1) + min;
    return valor;
}

void pintaTemp(){
    int temp,hora,dia;

    for (dia = 1; dia <= MAXDIAS; dia++)
    {
        setColor(WHITE);
        printf("dia %d:\n",dia);
        for(hora = 0; hora <= MAXHORA; hora++)
        {
        temp=GeneraValorEntreRang(MINTEMP,MAXTEMP);
        if (temp>50 &&(dia==12 && hora>=10 || dia>12 && dia <20 || dia==20 && hora<=15))
        {
            setColor(RED);
        }
        else{
            setColor(WHITE);
        }
        printf("[%2d]:%2d\n",hora,temp);
        }
        getch();
        cls();
    }
}
