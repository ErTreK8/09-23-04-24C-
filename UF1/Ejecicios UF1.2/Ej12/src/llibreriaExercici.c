#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include <stdbool.h> 
#include "rlutil.h"
#include "llibreriaPropia.h"
#include "llibreriaExercici.h"

int demanarDiaMes(int mes, int ano){
    int dia, diamin=1, diamax;
    diamax=demanarDiaMax(mes, ano);
    printf("Introduce un Mes entre %d y %d: ", diamin, diamax);
    dia=3;
    do{
		if (dia < diamin || dia > diamax)
		{
			printf("Introduce un Mes entre %d y %d: ", diamin, diamax);
		}
        scanf("%d", &dia);
	}
    while (dia < diamin || dia > diamax);
    return dia;
}

int demanarDiaMax(int mes, int ano){
    int diamax;
    switch (mes)
    {
    case 1:
        diamax = 31;
        break;
    case 2:
        if (ano % 4 == 0 && ano % 100!= 0)
        {
            diamax = 29;
        }
        else
        {
            diamax = 28;
        }
        break;        
    case 3:
        diamax = 31;
        break;
    case 4:
        diamax = 30;
        break;
    case 5:
        diamax = 31;
        break;
    case 6:
        diamax = 30;
        break;
    case 7:
        diamax = 31;
        break;
    case 8:
        diamax = 31;
        break;
    case 9:
        diamax = 30;
        break;
    case 10:
        diamax = 31;
        break;
    case 11:
        diamax = 30;
        break;
    case 12:
        diamax = 31;
        break;
    default:
        break; 
    }
    return diamax;  
}

int demanarNumero(){
    int n;
    scanf("%d", &n);
    return n;
}


void printa(int dia, int mes, int ano, int numero){
    int diamax;
    diamax=demanarDiaMax(mes,ano);
    for (int i = 1; i <= numero; i++)
    {
        if (dia == diamax+1)
        {
            dia=1;
            mes++;
        }
        if (mes == 13)
        {
            mes=1;
            ano++;
        }
        printf("%02d: %02d/%02d/%d\n", i, dia, mes, ano);
        dia++;
    }   
}
