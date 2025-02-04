#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <string.h>
#include <stdbool.h>
#include "rlutil.h"
#include "llibreriaPropia.h"
#include "llibreriaExercici.h"

void omplirTirades(int jug[][MAXTIRADES])
{
    for (int jugador=0;jugador<MAXJUGADOR;jugador++)
    {
        omplirUnJugador(jug[jugador],MAXTIRADES);
    }
}

void omplirUnJugador(int v[],int qtt)
{
    //cada jugador tirar�8 numeros aleatoris entre 1 i 88 (sense repeticions)
    for (int i=0;i<qtt;i++)
    {
        do
        {
            v[i]=generarNumEntreRang(MINNUM,MAXNUM);
        } while (cerca(v,i,v[i]));
    }
}
void pintaTirades(int jug[][MAXTIRADES])
{
    for (int jugador=0;jugador<MAXJUGADOR;jugador++)
    {
        printf("\n\nTirada Jugador %d: \n",jugador+1);
        pintavector(jug[jugador],MAXTIRADES);
    }
}

void omplirDistanciaMinima(int jug[][MAXTIRADES],int qttJug,int dist[],int num){
    for (int i=0; i<qttJug;i++)
    {
        dist[i]=calculaDistanciaMinimaJugador(jug[i],MAXTIRADES,num);
    }
    
}
int calculaDistanciaMinimaJugador(int v[],int qttTirades,int num){
    int minim=abs(v[0]-num);
    int minimActiu;
    for (int i = 0; i < qttTirades; i++)
    {
        minimActiu=abs(v[i]-num);
        if (minimActiu<minim)
        {
            minim=minimActiu;
        }
    }
    return minim;
}

int calculaMinim(int v[],int qtt){
    int minim=v[0];
    for (int i = 0; i < qtt; i++)
    {
        if (minim>v[i])
        {
            minim=v[i];
        }
    }
}

void mostraGuanyador(int v[],int qtt,int minim){
    
}