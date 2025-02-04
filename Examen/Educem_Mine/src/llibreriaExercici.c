#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include <stdbool.h> 
#include "rlutil.h"
#include "llibreriaPropia.h"
#include "llibreriaExercici.h"

void aconseguiMines(int *casellaMina1, int *casellaMina2, int *casellaMina3, int *casellaMina4, int *casellaMina5){
do
{
    (*casellaMina1)=calcularCasellaMina();
    (*casellaMina2)=calcularCasellaMina();
    (*casellaMina3)=calcularCasellaMina();
    (*casellaMina4)=calcularCasellaMina();
    (*casellaMina5)=calcularCasellaMina();
} while ( ( (*casellaMina1) == (*casellaMina2) ) || ( (*casellaMina1) == (*casellaMina3) ) || ((*casellaMina1) == (*casellaMina4) ) || ( (*casellaMina1) == (*casellaMina5) ) || ( (*casellaMina2) == (*casellaMina3) ) || ((*casellaMina2) == (*casellaMina4)) || ((*casellaMina2) == (*casellaMina5)) || ( (*casellaMina3) == (*casellaMina4) ) || ( (*casellaMina3) == (*casellaMina5) ) || ( (*casellaMina4) == (*casellaMina5) ) );

}

int calcularCasellaMina(){
    int x=0, y=0, casella=0;
    y=RandomizadorNumeros(MIN_FILA, MAX_FILA);
    x=RandomizadorNumeros(MIN_COLUMNA, MAX_COLUMNA);
    casella=(y*10)+x;
    return casella;
}

void pintaTaulell(int casellaMina1, int casellaMina2, int casellaMina3, int casellaMina4, int casellaMina5){
    int casella=0;
    printf("\n ");
    for (int i = 0; i < 3; i++)
    {
        for (int x = 0; x < 10; x++)
        {
            casella=(i*10)+x;
            if (casella==casellaMina1 || casella==casellaMina2 || casella==casellaMina3 || casella==casellaMina4 || casella==casellaMina5)
            {
                printf("M ");
            }
            else
            {
                printf("- ");
            } 
        }
        printf("\n ");
    }
    
}

char UoM(){
    char letra;
    do
    {   
        printf("\nIntroidueix un Caracter U (Usuari) M (Maquina): ");
        scanf("%c", &letra);
        while(getchar()!='\n');
    } while (letra!='u' && letra!='m' && letra!='U' && letra!='M');
    return letra;
}

void salirBucleM(int *final,int casella, int *punts, int casellaMina1, int casellaMina2, int casellaMina3, int casellaMina4, int casellaMina5){
    if (casella==casellaMina1 || casella==casellaMina2 || casella==casellaMina3 || casella==casellaMina4 || casella==casellaMina5)
    {
        printf("Ups, acabes de perdre el joc, ja que en la casella [%d-%d] hi ha una mina.\n",(casella/10),(casella%10));
        (*final)=2;
    }
    else if ((*punts)==BUCLE_M)
    {
        (*final)=1;
    }
    
    else
    {
		(*punts)++;
        printf("Portes %d punts i et queden %d caselles per guanyar el joc.\n",(*punts), (BUCLE_M-(*punts)));
        getch();
    }
}

int calcularCasella(int casellaJugadorFila,int casellaJugadorColumna){
    int casella=0;
    casella=(casellaJugadorFila*10)+casellaJugadorColumna;
    return casella;
}

void salirBucleU(int *final,int casella, int *punts, int casellaMina1, int casellaMina2, int casellaMina3, int casellaMina4, int casellaMina5){
    if (casella==casellaMina1 || casella==casellaMina2 || casella==casellaMina3 || casella==casellaMina4 || casella==casellaMina5)
    {
        printf("Ups, acabes de perdre el joc, ja que en la casella [%d-%d] hi ha una mina.\n",(casella/10),(casella%10));
        (*final)=3;
    }
    else if ((*punts)==BUCLE_U)
    {
        (*final)=1;
    }
    
    else
    {
		(*punts)++;
        printf("Portes %d punts i et queden %d caselles per guanyar el joc.\n",(*punts), (BUCLE_U-(*punts)));
        getch();
    }
}

void printaFinal2(int cordenadesMaquina, int casellaMina1, int casellaMina2, int casellaMina3, int casellaMina4, int casellaMina5)
{
    int casella=0;
    cls();
    printf("RESUM BOMBES\n");
    printf("\n ");
    for (int i = 0; i < 3; i++)
    {
        for (int x = 0; x < 10; x++)
        {
            casella=(i*10)+x;
            if (casella==casellaMina1 || casella==casellaMina2 || casella==casellaMina3 || casella==casellaMina4 || casella==casellaMina5)
            {   
                if (cordenadesMaquina==casella)
                {
                    setColor(RED);
                    printf("B ");
                    setColor(WHITE);
                }
                else
                {
                printf("M ");
                }
            }
            else
            {
                printf("- ");
            } 
        }
        printf("\n ");
    }
    printf("\nHas tocat la mina [%d-%d], Has Perdut :(\n",(cordenadesMaquina/10),(cordenadesMaquina%10));
}

void printaFinal3(int casellaJugador,int casellaMina1, int casellaMina2, int casellaMina3, int casellaMina4, int casellaMina5)
{
    int casella=0;
    cls();
    printf("RESUM BOMBES\n");
    printf("\n ");
    for (int i = 0; i < 3; i++)
    {
        for (int x = 0; x < 10; x++)
        {
            casella=(i*10)+x;
            if (casella==casellaMina1 || casella==casellaMina2 || casella==casellaMina3 || casella==casellaMina4 || casella==casellaMina5)
            {   
                if (casellaJugador==casella)
                {
                    setColor(RED);
                    printf("B ");
                    setColor(WHITE);
                }
                else
                {
                printf("M ");
                }
            }
            else
            {
                printf("- ");
            } 
        }
        printf("\n ");
    }
    printf("\nHas tocat la mina [%d-%d], Has Perdut :(\n",(casellaJugador/10),(casellaJugador%10));
}