#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include <stdbool.h> 
#include "rlutil.h"
#include "llibreriaPropia.h"
#include "llibreriaExercici.h"

void quadrat(){
    int x=1, y=1;
    for (y = 1; y <= 20; y++)
    {
        if (y==1 || y==20)
        {
            for (x = 1; x <= 80; x++)
            {
                gotoxy(x,y);
                printf("x");
            }
        }
        x=1;
        gotoxy(x,y);
        printf("x");
        x=80;
        gotoxy(x,y);
        printf("x");
    }
}

void pintaColor(int x,int y){
    int color=0;
    gotoxy(x,y);
    color=RandomizadorNumeros(1, 15);
    setBackgroundColor(color);
    printf(" ");
}

void cojerTecla(int *tecla){
    (*tecla)=getkey();
}

void modificarXY(int tecla, int *x, int *y){
    switch (tecla)
    {
    case 14:
        (*y)--;
        break;
    case 15:
        (*y)++;
        break;
    case 16:
        (*x)--;
        break;
    case 17:
        (*x)++;
        break;
    default:
        break;
    }
}

void salirBucle(bool *bucle, int x, int y){
    if (y==20)
    {
        (*bucle)=true;
    }
    else if (y==1)
    {
        (*bucle)=true;
    }
    else if (x==80)
    {
        (*bucle)=true;
    }
    else if (x==1)
    {
        (*bucle)=true;
    }
    else if (x==40 && y==10)
    {
        (*bucle)=true;
    }
}

void fuera(){
    setBackgroundColor(BLACK);
    gotoxy(82,1);   
}