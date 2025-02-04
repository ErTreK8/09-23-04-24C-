#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include <stdbool.h> 
#include "rlutil.h"
#include "llibreriaPropia.h"
#include "llibreriaExercici.h"

void llegirFitxer(char fitxer[])
{
    FILE *z=obrirFitxer(UBICACIOFITXERORIGENCOPIA,"r");
    ALUMNE un;
    ESCOLA escola;
    bool existeix=false;
    saltaLinea(z);
    if(z!=NULL)
    {
        while(feof(z)==0)
        {
            un=agafaAlumne2(z);
            existeix=existeixEscola(un.escola);
            if (existeix==false)
            {
                FILE *f;
                f=obrirFitxer(fitxer,"r");
                strcpy(escola.escola,un.escola);
                escola.qttNo=0;
                escola.qttSi=0;
                saltaLinea(f);
                while(feof(f)==0)
                {
                    un=agafaAlumne2(f);
                    if(strcmp(un.escola,escola.escola)==0)
                    {
                        if (un.adscrita==1) escola.qttSi++;
                        else escola.qttNo++;
                    }
                }
                escriu(escola);
                fclose(f);
            }            
        }
        
    }
}

void copiaArixu(char fitxerOriginal[],char fitxerCopia[])
{
    FILE *f=obrirFitxer(fitxerOriginal,"r");
    FILE *a=obrirFitxer(fitxerCopia,"w");
    
    char cadena[255];
    while (feof(f)==0)
    {
        fgets(cadena,sizeof(cadena),f);
        cadena[sizeof(cadena)]='\0';
        fprintf(a,"%s",cadena);
    }
    fclose(f);
    fclose(a);
}

void saltaLinea(FILE *f)
{
    char caracter='a';
    while(caracter!='\n')
    {
        caracter=fgetc(f);
    }
}

ALUMNE agafaAlumne2(FILE *f)
{
    ALUMNE un;
    char caracter;

    for (int i = 0; i < 10; i++)
    {
        if(feof(f)==0) un.IDpreins[i]=fgetc(f);
    }
    un.IDpreins[10]='\0';
    fseek(f,1,SEEK_CUR);
    fflush(f);
    int i=0;
    do
    {
        caracter=fgetc(f);
        if (caracter!=';')
        {
            un.inicials[i]=caracter;
            i++;
        }  
    } while (caracter!=';');
    un.inicials[i]='\0';
    i=0;
    fflush(f);
    for (int i = 0; i < 7; i++)
    {
        un.escola[i]=fgetc(f);
    }
    un.escola[7]='\0';
    fflush(f);
    fseek(f,1,SEEK_CUR);
    // agafa ADscrita
    fflush(f);
    fscanf(f,"%d",&un.adscrita);
    fseek(f,1,SEEK_CUR);
    fflush(f);
    // Agafa puntuacio
    fscanf(f,"%d",&un.puntuacio);
    caracter=fgetc(f);
    fflush(f);
    return un;
}


bool existeixEscola(char escola[])
{
    FILE *a=obrirFitxer(UBICACIOFITXRESUM,"r");
    bool existeix=false;
    char escolaBusca[8];
    if(a!=NULL)
    {
        while(feof(a)==0 && existeix==false)
        {
            cojeEscuelaResum(a,escolaBusca);
            if (strcmp(escola,escolaBusca)==0)
            {
                existeix=true;
            }
        }
    }
    fclose(a);
    return existeix;
}


void cojeEscuelaResum(FILE *f,char escola[])
{
    char caracter;
    for (int i = 0; i < 7; i++)
    {
        escola[i]=fgetc(f);
    }
    escola[7]='\0';
    do
    {
        caracter=fgetc(f);
    }
    while(caracter!='\n' && feof(f)==0);
}

void escriu(ESCOLA escola)
{
    bool existeixFichero;
    FILE *a;
    existeixFichero=existeixFitxer(UBICACIOFITXRESUM);
    if(existeixFichero==false) a=obrirFitxer(UBICACIOFITXRESUM,"w");
    else a=obrirFitxer(UBICACIOFITXRESUM,"a");
    fseek(a,0,SEEK_END);
    if(existeixFichero==true) fprintf(a,"\n%s %d %d",escola.escola,escola.qttSi,escola.qttNo);
    else fprintf(a,"%s %d %d",escola.escola,escola.qttSi,escola.qttNo); 
    fclose(a);
}