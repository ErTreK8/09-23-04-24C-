#include <stdio.h>
#include <stdlib.h>
#include <time.h>  
#include <windows.h>
#include <string.h>
#include <stdbool.h>
#include "rlutil.h"
#include "llibreriaPropia.h"
#include "llibreriaExercici.h"

void acabament (void)
{
	printf("\nPrem una tecla per finalitzar");
	getch();
}

int demanaNumEntreRangInt(int minim,int maxim)
{
    int n;
    do
    {
        scanf("%d",&n);
        if (n<minim || n>maxim)
        {
            printf("Introdueix un numero entre [%d-%d]: ",minim,maxim);
        }
        while (getchar()!='\n');
    } while (n<minim || n>maxim);
    return n;
}


int generarNumEntreRang(int minim,int maxim)
{
	return (rand()%(maxim-minim+1)+minim);
}

//rep un minim que aceptamos i retorna un numeros superior o igual a aquest minim
//0  -->    >=0
int demanaNumUnLimitInt(int minim)
{
    int n;
    do
    {
       scanf("%d",&n);
       if (n<minim)
       {
            printf("Introdueix un numero superior o igual a %d: ",minim);
       }
       while (getchar()!='\n');
    } while (n<minim);
    return n;
}
char demanaCaracter(void)
{
    char car;
    scanf("%c",&car);
    while(getchar()!='\n');
    return car;
}
int demanaNumInt()
{
    int n;
    scanf("%d",&n);
    while (getchar()!='\n');
    return n;
}
void intercanvi(int *num1,int *num2)
{
    int aux;
    aux=*num1;
    *num1=*num2;
    *num2=aux;
}
void pintavector(int v[], int qtt)
{
    if (qtt == 0)
    {
        printf("\nVector buit");
    }

    else
    {
        for (int i = 0; i < qtt; i++)
        {
            printf("\n[%02d]: %d", i, v[i]);
        }
    }
}
int posicio(int v[],int qtt,int numCerca)
{
    int i=0, pos=-1;
    while(i<qtt && pos==-1)
    {
        if(v[i]==numCerca)
        {
            pos=i;
        }
        else
        {
            i++;
        }
    }
    return pos;
}
bool cerca(int v[], int qtt, int numUsuari)
{
    bool trobat = false;
    int i = 0;
    while (i < qtt && !trobat)
    {
        if (v[i] == numUsuari)
        {
            trobat = true;
        }
        else
        {
            i++;
        }
    }
    return trobat;
} 
void ordenar(int v[],int qtt)
{
    bool canvi=false;

    for (int i=0;i<qtt-1 && !canvi;i++)
    {
        for (int j=0;j<qtt-i-1;j++)
        {
            if (v[j]>v[j+1])
            {
                canvi=true;
                intercanvi(&v[j],&v[j+1]);
            }
        }
        canvi=!canvi;
    }
}

void ordenarCadenes(char matriu[][20],int totalFiles)
{
    bool canvi=false;
    char auxiliar[20];

    for (int i=0;i<totalFiles-1 && !canvi;i++)
    {
        for (int j=0;j<totalFiles-i-1;j++)
        {
            if (strcmp(matriu[j],matriu[j+1])>0)
            {
                canvi=true;
                strcpy(auxiliar,matriu[j]);
                strcpy(matriu[j],matriu[j+1]);
                strcpy(matriu[j+1],auxiliar);
            }
        }
        canvi=!canvi;
    }
}
void entrarCadena(char cad[], int longitud)
{
    // while (getchar()!='\n');
    fgets(cad, longitud, stdin);
    if (strlen(cad) > 0 && cad[strlen(cad) - 1] == '\n')
    {
        cad[strlen(cad) - 1] = '\0';
    }
}
bool esLletra(char car)
{
    char lletres[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZÀÝÈÉÝÝÒÓÚÜÑÇabcdefghijklmnopqrstuvwxyzàáèéíïòóúüñç";
    bool trobada=false;
    int i=0;
    int longitud=sizeof(lletres);
    while (i<longitud && !trobada)
    {
        if (lletres[i]==car) trobada=true;
        else i++;
    }

    return trobada;
}


