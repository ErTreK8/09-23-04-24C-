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

void cojerTecla(int *tecla){
    (*tecla)=getkey();
}

prueba(long score, int *x, int *y, int *tecla, int *xant1,int *xant2,int *xant3,int *xant4,int *xant5,int *xant6,int *xant7,int *xant8,int *xant9,int *xant10,int *yant1,int *yant2,int *yant3,int *yant4,int *yant5,int *yant6,int *yant7,int *yant8,int *yant9,int *yant10){
    int digitos=calculaQuantitatDigits(score);
    int color=RandomizadorNumeros(1, 15);
    setBackgroundColor(color);
    setColor(BLACK);
    switch (digitos)
    {
    case 1:
        modificarXY((*tecla), &(*x), &(*y));
        gotoxy((*x),(*y));
        printf("1");
        break;
    case 2:
    /*
    case <1:
        int i=0;
        while (i!=digitos-1)
        {
            x[i]=(*x);
            y[i]=(*y);
            gotoxy(x[i], y[i]);
            printf("0");
            i++;
        }
    */    


        (*xant1)=(*x);
        (*yant1)=(*y);
        gotoxy(*xant1,*yant1);
        printf("0");
        modificarXY((*tecla), &(*x), &(*y));
        gotoxy((*x),(*y));
        printf("1");
        break;
    case 3:
        (*xant2)=(*xant1);
        (*yant2)=(*yant1);
        gotoxy(*xant2,*yant2);
        printf("0");
        (*xant1)=(*x);
        (*yant1)=(*y);
        gotoxy(*xant1,*yant1);
        printf("0");
        modificarXY((*tecla), &(*x), &(*y));
        gotoxy((*x),(*y));
        printf("1");
        break;
    case 4:
        (*xant3)=(*xant2);
        (*yant3)=(*yant2);
        gotoxy(*xant3,*yant2);
        printf("0");
        (*xant2)=(*xant1);
        (*yant2)=(*yant1);
        gotoxy(*xant2,*yant2);
        printf("0");
        (*xant1)=(*x);
        (*yant1)=(*y);
        gotoxy(*xant1,*yant1);
        printf("0");
        modificarXY((*tecla), &(*x), &(*y));
        gotoxy((*x),(*y));
        printf("1");
        break;
    case 5:
        (*xant4)=(*xant3);
        (*yant4)=(*yant3);
        gotoxy(*xant4,*yant4);
        printf("0");
        (*xant3)=(*xant2);
        (*yant3)=(*yant2);
        gotoxy(*xant3,*yant3);
        printf("0");
        (*xant2)=(*xant1);
        (*yant2)=(*yant1);
        gotoxy(*xant2,*yant2);
        printf("0");
        (*xant1)=(*x);
        (*yant1)=(*y);
        gotoxy(*xant1,*yant1);
        printf("0");
        modificarXY((*tecla), &(*x), &(*y));
        gotoxy((*x),(*y));
        printf("1");
        break;
    case 6:
        (*xant5)=(*xant4);
        (*yant5)=(*yant4);
        gotoxy(*xant5,*yant5);
        printf("0");
        (*xant4)=(*xant3);
        (*yant4)=(*yant3);
        gotoxy(*xant4,*yant4);
        printf("0");
        (*xant3)=(*xant2);
        (*yant3)=(*yant2);
        gotoxy(*xant3,*yant3);
        printf("0");
        (*xant2)=(*xant1);
        (*yant2)=(*yant1);
        gotoxy(*xant2,*yant2);
        printf("0");
        (*xant1)=(*x);
        (*yant1)=(*y);
        gotoxy(*xant1,*yant1);
        printf("0");
        modificarXY((*tecla), &(*x), &(*y));
        gotoxy((*x),(*y));
        printf("1");
        break;
    case 7:
        (*xant6)=(*xant5);
        (*yant6)=(*yant5);
        gotoxy(*xant6,*yant6);
        printf("0");
        (*xant5)=(*xant4);
        (*yant5)=(*yant4);
        gotoxy(*xant5,*yant5);
        printf("0");
        (*xant4)=(*xant3);
        (*yant4)=(*yant3);
        gotoxy(*xant4,*yant4);
        printf("0");
        (*xant3)=(*xant2);
        (*yant3)=(*yant2);
        gotoxy(*xant3,*yant3);
        printf("0");
        (*xant2)=(*xant1);
        (*yant2)=(*yant1);
        gotoxy(*xant2,*yant2);
        printf("0");
        (*xant1)=(*x);
        (*yant1)=(*y);
        gotoxy(*xant1,*yant1);
        printf("0");
        modificarXY((*tecla), &(*x), &(*y));
        gotoxy((*x),(*y));
        printf("1");
        break;
    case 8:
        (*xant7)=(*xant6);
        (*yant7)=(*yant6);
        gotoxy(*xant7,*yant7);
        printf("0");
        (*xant6)=(*xant5);
        (*yant6)=(*yant5);
        gotoxy(*xant6,*yant6);
        printf("0");
        (*xant5)=(*xant4);
        (*yant5)=(*yant4);
        gotoxy(*xant5,*yant5);
        printf("0");
        (*xant4)=(*xant3);
        (*yant4)=(*yant3);
        gotoxy(*xant4,*yant4);
        printf("0");
        (*xant3)=(*xant2);
        (*yant3)=(*yant2);
        gotoxy(*xant3,*yant3);
        printf("0");
        (*xant2)=(*xant1);
        (*yant2)=(*yant1);
        gotoxy(*xant2,*yant2);
        printf("0");
        (*xant1)=(*x);
        (*yant1)=(*y);
        gotoxy(*xant1,*yant1);
        printf("0");
        modificarXY((*tecla), &(*x), &(*y));
        gotoxy((*x),(*y));
        printf("1");
        break;
    case 9:
        (*xant8)=(*xant7);
        (*yant8)=(*yant6);
        gotoxy(*xant8,*yant8);
        printf("0");
        (*xant7)=(*xant6);
        (*yant7)=(*yant6);
        gotoxy(*xant7,*yant7);
        printf("0");
        (*xant6)=(*xant5);
        (*yant6)=(*yant5);
        gotoxy(*xant6,*yant6);
        printf("0");
        (*xant5)=(*xant4);
        (*yant5)=(*yant4);
        gotoxy(*xant5,*yant5);
        printf("0");
       (*xant4)=(*xant3);
       (*yant4)=(*yant3);
        gotoxy(*xant4,*yant4);
        printf("0");
        (*xant3)=(*xant2);
        (*yant3)=(*yant2);
        gotoxy(*xant3,*yant3);
        printf("0");
        (*xant2)=(*xant1);
        (*yant2)=(*yant1);
        gotoxy(*xant2,*yant2);
        printf("0");
        (*xant1)=(*x);
        (*yant1)=(*y);
        gotoxy(*xant1,*yant1);
        printf("0");
        modificarXY((*tecla), &(*x), &(*y));
        gotoxy((*x),(*y));
        printf("1");
        break;
    case 10:
        (*xant9)=(*xant8);
        (*yant9)=(*yant8);
        gotoxy(*xant9,*yant9);
        printf("0");
        (*xant8)=(*xant7);
        (*yant8)=(*yant7);
        gotoxy(*xant8,*yant8);
        printf("0");
        (*xant7)=(*xant6);
        (*yant7)=(*yant6);
        gotoxy(*xant7,*yant7);
        printf("0");
        (*xant6)=(*xant5);
        (*yant6)=(*yant5);
        gotoxy(*xant6,*yant6);
        printf("0");
        (*xant5)=(*xant4);
        (*yant5)=(*yant4);
        gotoxy(*xant5,*yant5);
        printf("0");
        (*xant4)=(*xant3);
        (*yant4)=(*yant3);
        gotoxy(*xant4,*yant4);
        printf("0");
        (*xant3)=(*xant2);
        (*yant3)=(*yant2);
        gotoxy(*xant3,*yant3);
        printf("0");
        (*xant2)=(*xant1);
        (*yant2)=(*yant1);
        gotoxy(*xant2,*yant2);
        printf("0");
        (*xant1)=(*x);
        (*yant1)=(*y);
        gotoxy(*xant1,*yant1);
        printf("0");
        modificarXY((*tecla), &(*x), &(*y));
        gotoxy((*x),(*y));
        printf("1");
        break;
    case 11:
        (*xant10)=(*xant9);
        (*yant10)=(*yant9);
        gotoxy(*xant10,*yant10);
        printf("0");
        (*xant9)=(*xant8);
        (*yant9)=(*yant8);
        gotoxy(*xant9,*yant9);
        printf("0");
        (*xant8)=(*xant7);
        (*yant8)=(*yant7);
        gotoxy(*xant8,*yant8);
        printf("0");
        (*xant7)=(*xant6);
        (*yant7)=(*yant6);
        gotoxy(*xant7,*yant7);
        printf("0");
        (*xant6)=(*xant5);
        (*yant6)=(*yant5);
        gotoxy(*xant6,*yant6);
        printf("0");
        (*xant5)=(*xant4);
        (*yant5)=(*yant4);
        gotoxy(*xant5,*yant5);
        printf("0");
        (*xant4)=(*xant3);
        (*yant4)=(*yant3);
        gotoxy(*xant4,*yant4);
        printf("0");
        (*xant3)=(*xant2);
        (*yant3)=(*yant2);
        gotoxy(*xant3,*yant3);
        printf("0");
        (*xant2)=(*xant1);
        (*yant2)=(*yant1);
        gotoxy(*xant2,*yant2);
        printf("0");
        (*xant1)=(*x);
        (*yant1)=(*y);
        gotoxy(*xant1,*yant1);
        printf("0");
        modificarXY((*tecla), &(*x), &(*y));
        gotoxy((*x),(*y));
        printf("1");
        break;
    default:
        break;
    }  
    cojerTecla(&(*tecla));
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

void salirBucle(bool *bucle, int x, int y, long score, int xant1,int xant2,int xant3,int xant4,int xant5,int xant6,int xant7,int xant8,int xant9,int xant10,int yant1,int yant2,int yant3,int yant4,int yant5,int yant6,int yant7,int yant8,int yant9,int yant10){
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
    else if ((x==xant1 && y==yant1)  || (x==xant2 && y==yant2) || (x==xant3 && y==yant3) || (x==xant4 && y==yant4) || (x==xant5 && y==yant5) || (x==xant6 && y==yant6) || (x==xant7 && y==yant7) || (x==xant8 && y==yant8) || (x==xant9 && y==yant9) || (x==xant10 && y==yant10))
    {
        (*bucle)=true;
    }   
}

void fuera(){
    setBackgroundColor(BLACK);
    gotoxy(82,1);   
}


void manzana(int *x, int *y){
    (*x)=RandomizadorNumeros(2, 79);
    (*y)=RandomizadorNumeros(2, 19);
}
void pintaManzana(int x, int y){
    gotoxy(x,y);
    setColor(RED);
    printf("");
}