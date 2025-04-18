#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include <stdbool.h> 
#include "rlutil.h"
#include "llibreriaPropia.h"
#include "llibreriaExercici.h"

void acabament (void)
{
	printf("\nPrem una tecla per finalitzar");
	getch();
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
    } while (n<minim);
    return n;
}
//Pide un numero entre una variable min y una max
int demanarNumeroMinMax(int min, int max){
    int numero;
    do{
        scanf("%d", &numero);
		if (numero < min || numero > max)
		{
			printf("Introduce un numero entre %d y %d: ", min, max);
		}
	}
    while (numero < min || numero > max);
    return numero;
}

//Pide un numero
int demanarNumero(void){
    int numero;
    scanf("%d", &numero);
    return numero;
}
//Pide un Caracter
char demanarCaracter(void){
    char caracter;
    scanf("%c", &caracter);
    return caracter;
}
//Calcula los digitos de un numero
int calculaQuantitatDigits(int n){
    
    int digits=0;
    
    while( n > 0){
        n /= 10;
        digits++;
    }
    return digits;
}
// Randomiza un numero entre una variable min y una max
int RandomizadorNumeros(int min, int max){
    int numero;
    numero=rand()%(max-min+1)+min;
    return numero;
}

void pintaQuadrat(int xMax, int yMax){
    int x=1, y=1;
    for (y = 1; y <= yMax; y++)
    {
        if (y==1 || y==yMax)
        {
            for (x = 1; x <= yMax; x++)
            {
                gotoxy(x,y);
                printf("x");
            }
        }
        x=1;
        gotoxy(x,y);
        printf("x");
        x=xMax;
        gotoxy(x,y);
        printf("x");
    }
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

void moureVector(int v[],int qtt,int pos)
{
    for (int i=qtt;i>pos;i--)
    {
        v[i]=v[i-1];
    }
}

void ordenarVector(int v[],int qtt)
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
    }
}

void entrarCadena(char cad[], int longitud)
{
    do
    {
        fgets(cad, longitud, stdin);    
    } while (strlen(cad)==1);
    
    
    if (strlen(cad) > 0 && cad[strlen(cad) - 1] == '\n')
    {
        cad[strlen(cad) - 1] = '\0';
    }
}
bool esLletra(char car)
{
    char lletres[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstu��������������������";
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