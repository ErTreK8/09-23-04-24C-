#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include <stdbool.h> 
#include "rlutil.h"
#include "llibreriaPropia.h"
#include "llibreriaExercici.h"

void CombinacioGuanyadora(int *numero1, int *numero2, int *numero3){
    *numero1 = RandomizadorNumeros();
    *numero2 = RandomizadorNumeros();
    *numero3 = RandomizadorNumeros();

    *numero1 = RandomizadorNumeros();
    do
    {
        *numero2 = RandomizadorNumeros();
    } while (*numero2 == *numero1);
    
    do
    {
        *numero3 = RandomizadorNumeros();
    } while (*numero3==*numero1 || *numero3==*numero2 );
}

int RandomizadorNumeros(){
    int numero;
    numero=rand()%(9-0+1)+0;
    return numero;
}

void CombinacioUsuario(int *numero1, int *numero2, int *numero3){
    
    printf("Introdueix El primer Valor: ");
    *numero1=demanarNumeroMinMax(MIN,MAX);
    do
    {
        printf("Introdueix El Segon Valor: ");
        *numero2=demanarNumeroMinMax(MIN,MAX);
    } while (*numero2 == *numero1);
    
    do
    {
        printf("Introdueix El Tercer Valor: ");
        *numero3=demanarNumeroMinMax(MIN,MAX);
    } while (*numero3==*numero1 || *numero3==*numero2 );

}

int CalculaEncerets(int numeroBien1, int numeroBien2, int numeroBien3, int NumeroUsuario1, int NumeroUsuario2, int NumeroUsuario3){
    int encerts=0;

    if (numeroBien1 == NumeroUsuario1 || numeroBien2 == NumeroUsuario1 || numeroBien3 == NumeroUsuario1)
    {
       encerts++;
    }
    if (numeroBien1 == NumeroUsuario2 || numeroBien2 == NumeroUsuario2 || numeroBien3 == NumeroUsuario2)
    {
        encerts++;
    }
    if (numeroBien1 == NumeroUsuario3 || numeroBien2 == NumeroUsuario3 || numeroBien3 == NumeroUsuario3)
    {
        encerts++;
    }


   /* if ((numeroBien1 == NumeroUsuario1 && NumeroUsuario2 != numeroBien2 && NumeroUsuario3 != numeroBien3) || (numeroBien2 == NumeroUsuario2 && NumeroUsuario3 != numeroBien3 && NumeroUsuario1 != numeroBien1) ||(NumeroUsuario3 == numeroBien3 && NumeroUsuario2 != numeroBien2 && NumeroUsuario1 != numeroBien1))
    {
        encerts=1;
    }   
    else if(numeroBien1 != NumeroUsuario1 && NumeroUsuario2 != numeroBien2 && numeroBien3 != NumeroUsuario3){
        encerts=0;
    }
    else if ((numeroBien1 == NumeroUsuario1 && NumeroUsuario2 == numeroBien2 && NumeroUsuario3 != numeroBien3) || (numeroBien2 == NumeroUsuario2 && NumeroUsuario3 == numeroBien3 && NumeroUsuario1 != numeroBien1) ||(NumeroUsuario3 == numeroBien3 && NumeroUsuario2 != numeroBien2 && NumeroUsuario1 == numeroBien1))
    {
        encerts=2;
    }
    else
    {
        encerts=3;
    }  */
    return encerts;;
}