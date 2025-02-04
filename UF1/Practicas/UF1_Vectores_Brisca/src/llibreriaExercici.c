#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "rlutil.h"
#include "llibreriaPropia.h"
#include "llibreriaExercici.h"

void rellenarBaraja(int vectorCartes[], int *qttCartesTotals)
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 1; j < 13; j++)
        {
            if (i == 0)
            {
                vectorCartes[j - 1] = j + (100 * i);
                (*qttCartesTotals)++;
            }
            else if (i == 1)
            {
                vectorCartes[j + 11] = j + (100 * i);
                (*qttCartesTotals)++;
            }
            else if (i == 2)
            {
                vectorCartes[j + 23] = j + (100 * i);
                (*qttCartesTotals)++;
            }
            else if (i == 3)
            {
                vectorCartes[j + 35] = j + (100 * i);
                (*qttCartesTotals)++;
            }
        }
    }
    (*qttCartesTotals)--;
}

void repartirCartasJugadrors(int v[], int qtt, int *qttCartesJugador, int vcartes[], int *qttCartes)
{
    for (int i = 0; i < qtt; i++)
    {
        v[i] = sacarCartaAletoriaBaraja(vcartes, &(*qttCartes));
        (*qttCartesJugador)++;
    }
}

int sacarCartaAletoriaBaraja(int v[], int *qtt)
{
    int numeroCarta = RandomizadorNumeros(0, (*qtt) - 1);
    int carta = v[numeroCarta];
    v[numeroCarta] = v[(*qtt) - 1];
    (*qtt)--;
    return carta;
}

void pedirCarta(int *numero1, char *paloCarta, int *numeroCartaJugada)
{
    do
    {
        printf("Introduce la carta que quieras jugar: ");
        scanf("%d %c", &(*numero1), &(*paloCarta));
        (*paloCarta) = toupper((*paloCarta));

    } while (((*paloCarta) != 'C' && (*paloCarta) != 'B' && (*paloCarta)!= 'E' && (*paloCarta) != 'O') && ((*numero1)<1 || (*numero1)>12));
    (*numeroCartaJugada)=codificarCarta(*paloCarta,*numero1);
}

void tirarCartaJugador(int *numeroCodificado,char *paloCarta,int *numeroCarta,int v[], int qtt){
    int posicion=-1;
    int numEscollit;
    do
    {
        pedirCarta(&(*numeroCarta), &(*paloCarta),&(*numeroCodificado));
        posicion=posicio(v,qtt,(*numeroCodificado));
    } while (posicion==-1);
    
}

int codificarCarta(char pal, int numero)
{
    int carta = 0;
    pal = toupper(pal);
    switch (pal)
    {
    case 'B':
        carta = numero;
        break;
    case 'E':
        carta = numero + 100;
        break;
    case 'C':
        carta = numero + 200;
        break;
    case 'O':
        carta = numero + 300;
        break;
    default:
        break;
    }
    return carta;
}

void decodificarCarta(int *numero1, char *paloCarta, int numCarta){
    
    if (numCarta>0 && numCarta<13)
    {
        *paloCarta = 'B';
        *numero1 = numCarta;
    }

    else if (numCarta>100 && numCarta<113)
    {
        *paloCarta = 'E';
        *numero1 = numCarta-100;
    }

    else if (numCarta>200 && numCarta<213)
    {
        *paloCarta = 'C';
        *numero1 = numCarta-200;
    }

    else if (numCarta>300 && numCarta<313)
    {
        *paloCarta = 'O';
        *numero1 = numCarta-300;
    }
}

void pintaJugadorCartes(int v[], int qtt)
{
    char palo;
    int numeroCarta;

    for (int i = 0; i < qtt; i++)
    {
        decodificarCarta(&numeroCarta,&palo,v[i]);
        printf("%d%c   ",numeroCarta,palo);
    }
    
}


int puntsCarta(int carta){
    carta = sacarNumeroCarta(carta);
    int puntoCarta;
    switch (carta)
    {
    case 1:
        puntoCarta=11;
        break;
    case 3:
        puntoCarta=10;
        break;
    case 12:
        puntoCarta=4;
        break;
    case 11:
        puntoCarta=3;
        break;
    case 9:
        puntoCarta=2;
        break;

    default:
        puntoCarta=0;
        break;
    }
    return puntoCarta;
}

int sacarNumeroCarta(int carta){
    if (carta>100 && carta<113)
    {
        carta=carta-100;
    }

    else if (carta>200 && carta<213)
    {
        carta=carta-200;
    }

    else if (carta>300 && carta<313)
    {
        carta=carta-300;
    }
    return carta;
}


void pintaVectorHorizontal(int v[], int qtt)
{
    if (qtt == 0)
    {
        printf("\nBaralla buida");
    }

    else
    {
        for (int i = 0; i < qtt; i++)
        {
            printf("[%02d]: %03d    ", i, v[i]);
            switch (i)
            {
            case 11:
            case 23:
            case 35:
            case 47:
                printf("\n");
                break;          
            default:
                break;
            }
        }
        printf("\n");
    }
}


void guanyadorRonda(bool *jugador1Primer,int numero1,char paloCartajugador1,int numeroCartaJugador1,int numero2,char paloCartajugador2,int numeroCartaJugador2, char palGuanyador)
{
    int puntosCartaJugador1=0, puntosCartaJugador2=0;
    puntosCartaJugador1=puntsCarta(numero1);
    puntosCartaJugador2=puntsCarta(numero2);
    if (paloCartajugador1 == paloCartajugador2)
    {
        if (puntosCartaJugador1>puntosCartaJugador2)
        {
            *jugador1Primer=true;
        }
        else if (puntosCartaJugador1<puntosCartaJugador2)
        {
            *jugador1Primer=false;
        }      
        else if (numero1>numero2)
        {
            *jugador1Primer=true;
        }
        else if (numero1<numero2)
        {
            *jugador1Primer=false;
        }
    }   

    else if (paloCartajugador1==palGuanyador)
    {
        *jugador1Primer=true;
    }
    else if (paloCartajugador2==palGuanyador)
    {
        *jugador1Primer=false;
    }
    else
    {
        if (*jugador1Primer==true)
        {
            *jugador1Primer=true;
        }
        else if (*jugador1Primer==false)
        {
            *jugador1Primer=false;
        }
        
    }
}


void cartasRondaEnGanadoras(bool jugador1Primer,int *puntsJugador1,int *puntsJugador2,int vGuanyades1[],int *qttGuanyades1,int vGuanyades2[],int *qttGuanyades2,int *numeroCartaJugador1,int *numeroCartaJugador2,int numero1,int numero2)
{
    int puntosTotalCartas=puntsCarta(numero1)+puntsCarta(numero2);
    if (jugador1Primer==true)
    {
        *puntsJugador1+=puntosTotalCartas;
        vGuanyades1[*qttGuanyades1]=*numeroCartaJugador1;
        *qttGuanyades1++;
        vGuanyades1[*qttGuanyades1]=*numeroCartaJugador2;
        *qttGuanyades1++;
    }
    else if (jugador1Primer==false)
    {
        *puntsJugador2+=puntosTotalCartas;
        vGuanyades2[*qttGuanyades2]=*numeroCartaJugador1;
        *qttGuanyades2++;
        vGuanyades2[*qttGuanyades2]=*numeroCartaJugador2;
        *qttGuanyades2++;
    }
}

void quitarCartaJugadores(int vJugador1[],int vJugador2[],int *qttJugador1,int *qttJugador2,int *numeroCartaJugador1,int *numeroCartaJugador2)
{
    int posicion=-1;
    posicion=posicio(vJugador1,*qttJugador1,(*numeroCartaJugador1));
    vJugador1[posicion]=vJugador1[*qttJugador1-1];
    vJugador1[*qttJugador1-1]=0;

    posicion=posicio(vJugador2,*qttJugador2,(*numeroCartaJugador2));
    vJugador2[posicion]=vJugador2[*qttJugador2-1];
    vJugador2[*qttJugador2-1]=0;
}