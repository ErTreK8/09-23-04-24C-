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

void pintaColor(int x,int y, int color){
    gotoxy(x,y);
    setBackgroundColor(color);
    printf(" ");
}

void preguntaMover(char *letra, int *numero){
    setBackgroundColor(BLACK);
    do
    {
        gotoxy(1,22);
        printf("Introdueix quina opcio vols: L-R-U-D-W-S : ");
        scanf("%c",&(*letra));
        printf("                                                                                           ");
    } while ((*letra)!='L' && (*letra)!='R' && (*letra)!='U' && (*letra)!='D' && (*letra)!='W' && (*letra)!='S');
    if ((*letra)!='S')
    {
        do
        {
            gotoxy(1,22);
            printf("Introdueix cuants cops vols repetir l'accio: ");
            scanf("%d",&(*numero));
            printf("                                                                                           ");
        } while ((*numero)<1);
    }
    
    
}

void modificarXY(char letra, int numero, int *x, int *y, int *color, int *compro){
   int xant,yant;
   xant=(*x);
   yant=(*y);
   int comprobacion=0, comprobacion2=0;
   switch (letra)
   {
   case 'L':
   for (int i = (*x); i != (xant-numero); i--)
   {
        if (comprobacion2==0)
        {
            (*x)=i-1;
            comprobacion2=1;
        }
        else
        {
        (*x)=i;
        }
        if ((*x)<2 || comprobacion==1)
        {
            (*x)=(*x)+78;
            if (comprobacion==0)
            {
                (*color)=RandomizadorNumeros(1, 15);
            } 
            comprobacion=1;
        }
        if ((*x)==40 && (*y)==10)
        {
            (*compro)=1;
            break;
        }
        
        pintaColor((*x),(*y),(*color));
        Sleep(100);
   }   
    break;
   case 'R':
    for (int i = (*x); i != (xant+numero); i++)
   {
        if (comprobacion2==0)
        {
            (*x)=i+1;
            comprobacion2=1;
        }
        else
        {
        (*x)=i;
        }
        if ((*x)>79 || comprobacion==1)
        {
            (*x)=(*x)-78;
            if (comprobacion==0)
            {
                (*color)=RandomizadorNumeros(1, 15);
            } 
            comprobacion=1;
        }
        if ((*x)==40 && (*y)==10)
        {
            (*compro)=1;
            break;
        }
        pintaColor((*x),(*y),(*color));
        Sleep(100);
   }
    
    break;
   case 'U':
    for (int i = (*y); i != (yant-numero); i--)
   {
        if (comprobacion2==0)
        {
            (*y)=i-1;
            comprobacion2=1;
        }
        else
        {
        (*y)=i;
        }
        if ((*y)<2 || comprobacion==1)
        {
            (*y)=(*y)+18;
            if (comprobacion==0)
            {
                (*color)=RandomizadorNumeros(1, 15);
            } 
            comprobacion=1;
        }
        if ((*x)==40 && (*y)==10)
        {
            (*compro)=1;
            break;
        }
        pintaColor((*x),(*y),(*color));
        Sleep(100);
   }
    break;
   case 'D':
    for (int i = (*y); i != (yant+numero); i++)
   {
        if (comprobacion2==0)
        {
            (*y)=i+1;
            comprobacion2=1;
        }
        else
        {
        (*y)=i;
        }
        if ((*y)>19 || comprobacion==1)
        {
            (*y)=(*y)-18;
            if (comprobacion==0)
            {
                (*color)=RandomizadorNumeros(1, 15);
            } 
            comprobacion=1;
        }
        if ((*x)==40 && (*y)==10)
        {
            (*compro)=1;
            break;
        }
        pintaColor((*x),(*y),(*color));
        Sleep(100);
   }
    break;

   case 'W':
    for (int i = (*x); i != (xant+numero); i++)
    {
        (*x)=i+1;
       
        if ((*x)>79)
        {
            (*x)=(*x)-78;
            (*color)=RandomizadorNumeros(1, 15);
        }

        (*y)--;

        if ((*y)<2)
        {
            (*y)=(*y)+18;
            (*color)=RandomizadorNumeros(1, 15);
        }
        
        pintaColor((*x),(*y),(*color));
        Sleep(100);
        if ((*x)==40 && (*y)==10)
        {
            (*compro)=1;
            break;
        }
    }
    break;

   default:
    break;
   }
}

void salirBucle(bool *bucle, int x, int y, char letra, int compro){
    if (x==40 && y==10)
    {
        (*bucle)=true;
    }
    else if (letra=='S')
    {
        (*bucle)=true;
    }
    else if (compro==1)
    {
        (*bucle)=true;
    }

}

void fuera(){
    setBackgroundColor(BLACK);
    gotoxy(82,1);   
}



