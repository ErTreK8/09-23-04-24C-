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
    int numero=1;
    do{
		if (numero < min || numero > max)
		{
			printf("Introduce un numero entre %d y %d: ", min, max);
		}
        scanf("%d", &numero);
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
    char lletres[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstu‡¿·¡Ë»È…ÏÃÌÕÚ“Û”˘Ÿ˙⁄";
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

FILE *obrirFitxer(const char nomFitxer[], char mode[])
{
    FILE *f;
    f = fopen(nomFitxer, mode);
    if (f == NULL)
    {
        // MODE: R    W    A
        if (strcmpi(mode, "r") == 0 || strcmpi(mode, "rt") == 0 || strcmpi(mode, "r+") == 0 || strcmpi(mode, "rt+") == 0)
        {
            printf("\nNo s'ha pogut obrir el fitxer en mode lectura");
        }
        else if (strcmpi(mode, "w") == 0 || strcmpi(mode, "wt") == 0 || strcmpi(mode, "w+") == 0 || strcmpi(mode, "wt+") == 0)
        {
            printf("\nNo s'ha pogut crear el fitxer");
        }
        else if (strcmpi(mode, "a") == 0 || strcmpi(mode, "at") == 0 || strcmpi(mode, "a+") == 0 || strcmpi(mode, "at+") == 0)
        {
            printf("\nNo s'ha pogut crear/obrir el fitxer");
        }
        else
        {
            printf("\nMode incorrecta");
        }
    }
    return f;
}


bool existeixFitxer(char fitxer[])
{
    FILE *f;
    f=obrirFitxer(fitxer,"r");
    bool existeix=true;
    if (f==NULL)
    {   
        existeix=false;

    }
    else fclose(f);

    return existeix;
}

bool fitxerBuid(char fitxer[])
{
    FILE *f;
    bool esBuit=true;
    // un fitxer buit ???
    // Fitxer que existeix pero sense contingut

    if (existeixFitxer(fitxer)) // esto es que es true
    {
        f=obrirFitxer(fitxer,"r");
        fseek(f,0,SEEK_END); // esto es para ir al final o al principio
        if (ftell(f)!=0) esBuit=false; // el ftell te dice cuantos caracteres hay hasta el principio desde donde estes y como arriba estamos en el final si da 0 es q no hay nada
        fclose(f);
    }
    
    return esBuit;
}

void mouTot(char cadena[], int num)
{
    int i=num;
    while (i < (strlen(cadena)-1))
    {
        cadena[i]=cadena[i+1];
        i++;
    }
    cadena[i]='\0';
}

void eliminaSaltLinia(char cadena[])
{
    if (strlen(cadena) > 0 && cadena[strlen(cadena) - 1] == '\n')
    {
        cadena[strlen(cadena) - 1] = '\0';
    }
}


