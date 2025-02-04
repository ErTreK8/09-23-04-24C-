#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <string.h>
#include <stdbool.h>
#include "rlutil.h"
#include "llibreriaPropia.h"
#include "llibreriaExercici.h"

void demanaGPS(int *x,int *y)
{
    do
    {
        printf("Introdueix la posicio inicial del GPS [x y] - [80 20]: ");
        scanf("%d %d", *&x, *&y);
    } while ((*x < MINX || *x > MAXX) || (*y < MINY || *y > MAXY));
}

void pinta(int x,int y,char car,int color)
{
    gotoxy(x,y);
    setColor(color);
    printf("%c", car);
}

void generaPunt(int *x,int *y,int gpsx,int gpsy)
{
    do
    {
        (*x) = generarNumEntreRang(MINX, MAXX);
        (*y) = generarNumEntreRang(MINY, MAXY);
    } while (controlaPunts(*x,*y,gpsx,gpsy));
}
bool controlaPunts(int x,int y,int gpsx,int gpsy)
{
    return (x==gpsx && y==gpsy);
}



float calculaDistancia(int p1x, int p1y, int p2x, int p2y)
{
    return (sqrt(pow((p2x - p1x), 2) + pow((p2y - p1y), 2)));
}