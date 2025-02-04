#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include <stdbool.h> 
#include "rlutil.h"
#include "llibreriaPropia.h"
#include "llibreriaExercici.h"

void printaNumeroLoteria(int numero){
    cls();
    printf("%d\n", numero);
    Sleep(500);
    cls();
}

void printaMarcadorInicial(int caixa, int import){
    printf("MARCADORS INICIALS:\n\n");
    setColor(BLUE);
    printf("IMPORT CAIXA: %d i Import Jugador: %d\n", caixa, import);
    setColor(WHITE);
    printf("Amb quin numero vols apostar? [0..%d]: ", MAX_LOTERIA);
}

void resumInicial(int jugador, int aposta){
    int digitos=calculaQuantitatDigits(jugador);
    printf("\n-----------------------------------------\n");
    printf("RESUM INICIAL APOSTA JUGADOR:\nTOTAL NUMEROS   GUANY   NUMERO \n");
    if (digitos==1)
    {
        printf("1               x2          %d\n", jugador);
        printf("2               x5         0%d\n", jugador);
        printf("3               x20       00%d\n", jugador);
        printf("4               x50      000%d\n", jugador);
    }
    else if (digitos==2)
    {
        printf("1               x2          %d\n", jugador%10);
        printf("2               x5         %d\n", jugador);
        printf("3               x20       0%d\n", jugador);
        printf("4               x50      00%d\n", jugador);
    }
    else if (digitos==3)
    {
        printf("1               x2          %d\n", jugador%10);
        printf("2               x5         %d\n", jugador%100);
        printf("3               x20       %d\n", jugador);
        printf("4               x50      0%d\n", jugador);
    }
    else
    {
        printf("1               x2          %d\n", jugador%10);
        printf("2               x5         %d\n", jugador%100);
        printf("3               x20       %d\n", jugador%1000);
        printf("4               x50      %d\n", jugador);

    }
    printf("-----------------------------------------\n");
    printaContador();
}

void printaContador(){
    printf("RECALCULANT PREMI\n");
    for (int p = 2; p >=0; p--)
    {
        for (int i = 10; i >=0; i--)
        {
            printf(".");
            Sleep(100);
        }
        if (p==2)
        {
            printf(" %d segons\n", p);
        }
        else if (p==1)
        {
            printf(" %d segon\n", p);
        }
        else
        {
            printf(" Clacul Finalitzat\n");
        }
    }
    printf("Prem una tecla per coneixer el teu premi");
    getch();
}

int pruebaDigitos(int numLoteria, int numJugador){
    int numLoteria1=numLoteria;
    int numJugador1=numJugador;
    int digitos=0;
    for (int i = 1; i <= 4; i++)
    {   
        switch (i)
        {
        case 1:
            numJugador1=numJugador%10;
            numLoteria1=numLoteria%10;
            break;
        case 2:
            numJugador1=numJugador%100;
            numLoteria1=numLoteria%100;
            break;
        case 3:
            numJugador1=numJugador%1000;
            numLoteria1=numLoteria%1000;
            break;
        case 4:
            numJugador1=numJugador;
            numLoteria1=numLoteria;
            break;
        default:
            break;
        }
        
        if (numLoteria1==numJugador1)
        {
            digitos++;
        }
    }
    return digitos;
}

int calcularPremi(int aposta,int digitos,int importJugador){
    int numero=importJugador;
    numero=numero-aposta;
    switch (digitos)
    {
    case 1:
        aposta= aposta*2;
        break;
    case 2:
        aposta= aposta*7;
        break;
    case 3:
        aposta= aposta*27;
        break;
    case 4:
        aposta= aposta*50;
        break;
    default:
        break;
    }
    numero=numero+aposta;
    return numero;
}

void pirntfaResumFinal(int digitosCorrectos,int importJugador,int caixa, int jugador, int numLoteria){
    cls();
    int digitos=calculaQuantitatDigits(jugador);
    printf("\n-----------------------------------------\n");
    printf("RESUM INICIAL APOSTA JUGADOR:\nTOTAL NUMEROS   GUANY   NUMERO \n");
    if (digitos==1 && digitosCorrectos==0)
    {
        printf("1      %d          x2          %d\n", numLoteria%10,jugador);
        printf("2      %d         x5         0%d\n", numLoteria%100,jugador);
        printf("3      %d        x20       00%d\n", numLoteria%1000,jugador);
        printf("4      %d       x50      000%d\n", numLoteria,jugador);
    }
    else if (digitos==1 && digitosCorrectos==1)
    {
        setColor(GREEN);
        printf("1      %d          x2          %d\n", numLoteria%10,jugador);
        setColor(WHITE);
        printf("2      %d         x5         0%d\n", numLoteria%100,jugador);
        printf("3      %d        x20       00%d\n", numLoteria%1000,jugador);
        printf("4      %d       x50      000%d\n", numLoteria,jugador);
    }
    else if (digitos==1 && digitosCorrectos==2)
    {
        setColor(GREEN);
        printf("1      %d          x2          %d\n", numLoteria%10,jugador);
        printf("2      %d         x5         0%d\n", numLoteria%100,jugador);
        setColor(WHITE);
        printf("3      %d        x20       00%d\n", numLoteria%1000,jugador);
        printf("4      %d       x50      000%d\n", numLoteria,jugador);
    }
    else if (digitos==1 && digitosCorrectos==3)
    {
        setColor(GREEN);
        printf("1      %d          x2          %d\n", numLoteria%10,jugador);
        printf("2      %d         x5         0%d\n", numLoteria%100,jugador);
        printf("3      %d        x20       00%d\n", numLoteria%1000,jugador);
        setColor(WHITE);
        printf("4      %d       x50      000%d\n", numLoteria,jugador);
    }
    else if (digitos==1 && digitosCorrectos==4)
    {
        
        printf("1      %d          x2          %d\n", numLoteria%10,jugador);
        printf("2      %d         x5         0%d\n", numLoteria%100,jugador);
        printf("3      %d        x20       00%d\n", numLoteria%1000,jugador);
        setColor(GREEN);
        printf("4      %d       x50      000%d\n", numLoteria,jugador);
        setColor(WHITE);
    }


    else if (digitos==2 && digitosCorrectos==0)
    {
        printf("1      %d          x2          %d\n", numLoteria%10,jugador%10);
        printf("2      %d         x5         %d\n", numLoteria%100,jugador);
        printf("3      %d        x20       0%d\n", numLoteria%1000,jugador);
        printf("4      %d       x50      00%d\n", numLoteria,jugador);
    }
    else if (digitos==2 && digitosCorrectos==1)
    {
        setColor(GREEN);
        printf("1      %d          x2          %d\n", numLoteria%10,jugador%10);
        setColor(WHITE);
        printf("2      %d         x5         %d\n", numLoteria%100,jugador);
        printf("3      %d        x20       0%d\n", numLoteria%1000,jugador);
        printf("4      %d       x50      00%d\n", numLoteria,jugador);
    }
    else if (digitos==2 && digitosCorrectos==2)
    {
        setColor(GREEN);
        printf("1      %d          x2          %d\n", numLoteria%10,jugador%10);
        printf("2      %d         x5         %d\n", numLoteria%100,jugador);
        setColor(WHITE);
        printf("3      %d        x20       0%d\n", numLoteria%1000,jugador);
        printf("4      %d       x50      00%d\n", numLoteria,jugador);
    }
    else if (digitos==2 && digitosCorrectos==3)
    {
        setColor(GREEN);
        printf("1      %d          x2          %d\n", numLoteria%10,jugador%10);
        printf("2      %d         x5         %d\n", numLoteria%100,jugador);
        printf("3      %d        x20       0%d\n", numLoteria%1000,jugador);
        setColor(WHITE);
        printf("4      %d       x50      00%d\n", numLoteria,jugador);
    }
    else if (digitos==2 && digitosCorrectos==4)
    {
        
        printf("1      %d          x2          %d\n", numLoteria%10,jugador%10);
        printf("2      %d         x5         %d\n", numLoteria%100,jugador);
        printf("3      %d        x20       0%d\n", numLoteria%1000,jugador);
        setColor(GREEN);
        printf("4      %d       x50      00%d\n", numLoteria,jugador);
        setColor(WHITE);
    }


    else if (digitos==3 && digitosCorrectos==0)
    {
        printf("1      %d          x2          %d\n", numLoteria%10,jugador%10);
        printf("2      %d         x5         %d\n", numLoteria%100,jugador%100);
        printf("3      %d        x20       %d\n", numLoteria%1000,jugador);
        printf("4      %d       x50      0%d\n", numLoteria,jugador);
    }
    else if (digitos==3 && digitosCorrectos==1)
    {
        setColor(GREEN);
        printf("1      %d          x2          %d\n", numLoteria%10,jugador%10);
        setColor(WHITE);
        printf("2      %d         x5         %d\n", numLoteria%100,jugador%100);
        printf("3      %d        x20       %d\n", numLoteria%1000,jugador);
        printf("4      %d       x50      0%d\n", numLoteria,jugador);
    }
    else if (digitos==3 && digitosCorrectos==2)
    {
        setColor(GREEN);
        printf("1      %d          x2          %d\n", numLoteria%10,jugador%10);
        printf("2      %d         x5         %d\n", numLoteria%100,jugador%100);
        setColor(WHITE);
        printf("3      %d        x20       %d\n", numLoteria%1000,jugador);
        printf("4      %d       x50      0%d\n", numLoteria,jugador);
    }
    else if (digitos==3 && digitosCorrectos==3)
    {
        setColor(GREEN);
        printf("1      %d          x2          %d\n", numLoteria%10,jugador%10);
        printf("2      %d         x5         %d\n", numLoteria%100,jugador%100);
        printf("3      %d        x20       %d\n", numLoteria%1000,jugador);
        setColor(WHITE);
        printf("4      %d       x50      0%d\n", numLoteria,jugador);
    }
    else if (digitos==3 && digitosCorrectos==4)
    {
        
        printf("1      %d          x2          %d\n", numLoteria%10,jugador%10);
        printf("2      %d         x5         %d\n", numLoteria%100,jugador%100);
        printf("3      %d        x20       %d\n", numLoteria%1000,jugador);
        setColor(GREEN);
        printf("4      %d       x50      0%d\n", numLoteria,jugador);
        setColor(WHITE);
    }


    else if (digitos==4 && digitosCorrectos==0)
    {
        printf("1      %d          x2          %d\n", numLoteria%10,jugador%10);
        printf("2      %d         x5         %d\n", numLoteria%100,jugador%100);
        printf("3      %d        x20       %d\n", numLoteria%1000,jugador%1000);
        printf("4      %d       x50      %d\n", numLoteria,jugador);
    }
    else if (digitos==4 && digitosCorrectos==1)
    {
        setColor(GREEN);
        printf("1      %d          x2          %d\n", numLoteria%10,jugador%10);
        setColor(WHITE);
        printf("2      %d         x5         %d\n", numLoteria%100,jugador%100);
        printf("3      %d        x20       %d\n", numLoteria%1000,jugador%1000);
        printf("4      %d       x50      %d\n", numLoteria,jugador);
    }
    else if (digitos==4 && digitosCorrectos==2)
    {
        setColor(GREEN);
        printf("1      %d          x2          %d\n", numLoteria%10,jugador%10);
        printf("2      %d         x5         %d\n", numLoteria%100,jugador%100);
        setColor(WHITE);
        printf("3      %d        x20       %d\n", numLoteria%1000,jugador%1000);
        printf("4      %d       x50      %d\n", numLoteria,jugador);
    }
    else if (digitos==4 && digitosCorrectos==3)
    {
        setColor(GREEN);
        printf("1      %d          x2          %d\n", numLoteria%10,jugador%10);
        printf("2      %d         x5         %d\n", numLoteria%100,jugador%100);
        printf("3      %d        x20       %d\n", numLoteria%1000,jugador%1000);
        setColor(WHITE);
        printf("4      %d       x50      %d\n", numLoteria,jugador);
    }
    else if (digitos==4 && digitosCorrectos==4)
    {
        
        printf("1      %d          x2          %d\n", numLoteria%10,jugador%10);
        printf("2      %d         x5         %d\n", numLoteria%100,jugador%100);
        printf("3      %d        x20       %d\n", numLoteria%1000,jugador%1000);
        setColor(GREEN);
        printf("4      %d       x50      %d\n", numLoteria,jugador);
        setColor(WHITE);
    }
    printf("-----------------------------------------\n\n\n");
    printf("MARCADORS FINALS:\n");
    if (digitosCorrectos==1)
    {
        printf("Has Multiplicat la aposta per 2\n\n");
    }
    else if (digitosCorrectos==2)
    {
        printf("Has Multiplicat la aposta per 7\n\n");
    }
    else if (digitosCorrectos==3)
    {
        printf("Has Multiplicat la aposta per 27\n\n");
    }
    else if (digitosCorrectos==4)
    {
        printf("Has Multiplicat la aposta per 50\n\n");
    }
    else
    {
        printf("Has Perdut La aposta Pringat!\n\n");
    }
    setColor(BLUE);
    printf("IMPORT A CAIXA: %d i IMPORT JUGADOR: %d ", caixa, jugador);
}

char SioNo(){
    char letra;
    do
    {   
        setColor(WHITE);
        printf("\nQuieres seguir en el programa [S-N]?: ");
        while(getchar()!='\n');
        scanf("%c", &letra);
    } while (letra!='s' && letra!='n' && letra!='S' && letra!='N');
    return letra;
}

bool salirBucle(seguir,importJugador, caixa){
    bool bucle=false;
    if (importJugador < 1 || caixa<50 || seguir=='n' || seguir=='N')
    {
        bucle=true;
    }
    return bucle;
}
