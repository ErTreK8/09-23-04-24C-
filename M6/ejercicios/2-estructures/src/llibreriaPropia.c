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
    } while (n<minim || n>maxim);
    while(getchar()!='\n');
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
    } while (n<minim);
    while(getchar()!='\n');
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
    while(getchar()!='\n'); 
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
    char lletres[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZÀÁÈÉÍÏÒÓÚÜÑÇabcdefghijklmnopqrstuvwxyzàáèéíïòóúüñç";
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
FILE * obrirFitxer(const char nomFitxer[], char mode[])
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
    bool existeix=true;
    f=obrirFitxer(fitxer,"r");
    if (f==NULL)
    {
        existeix=false;
    }
    else
    {
        fclose(f);
    }
    return existeix;
}

bool fitxerBuit(char fitxer[])
{
    FILE *f;
    bool buit=true; 
    //un fitxer buit ???  s un fitxer que existeix pero que no te contignut
    
    if (existeixFitxer(fitxer))
    {
        f=obrirFitxer(fitxer,"r");
        fseek(f,0,SEEK_END);
        if (ftell(f)>0) buit=false;
        fclose(f);
    }

    return buit;
}
void  eliminaSaltLinia(char cadena[],int longitud)
{
    if (cadena[strlen(cadena)-1]=='\n') cadena[strlen(cadena)-1]='\0';
}

