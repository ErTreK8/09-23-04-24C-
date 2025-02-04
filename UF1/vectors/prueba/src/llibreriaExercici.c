#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include <stdbool.h> 
#include "rlutil.h"
#include "llibreriaPropia.h"
#include "llibreriaExercici.h"

void omplirVectorUsuari(int v[],int qtt)
{
    for (int i=0;i<qtt;i++)
    {
        printf("Introdueix valor de la casella [%d]: (entre 0 i 10) ",i);
        v[i]=demanarNumeroMinMax(0,10);
    }
}

void pintaVector(int v[],int qtt)
{
    if (qtt==0) printf ("\nVector buit");
    else
    {
        for (int i=0;i<qtt;i++)
        {
            printf("\n[%02d]:%d",i,v[i]);
        }
    }
}

void calculaParellsSenarsY0(int v[],int qtt,int *parells,int *senars,int *zero){
    
    for (int i = 0; i < qtt; i++)
    {
        if (v[i]==0)
        {
            (*zero)++;
        }
        
        else if ((v[i]%2)==0)
        {
            (*parells)++;
        }

        else if ((v[i]%2)!=0)
        {
            (*senars)++;
        }
    }
}

void calculaParellsSenarsY02(int v[],int qtt,int cont[]){
   
    for (int i = 0; i < qtt; i++)
    {
        if (v[i]==0)
        {
            cont[0]++;
        }
        
        else if ((v[i]%2)==0)
        {
            cont[1]++;
        }

        else if ((v[i]%2)!=0)
        {
            cont[2]++;
        }
    }
}

int calculaDiesMes(int numeroMes){
    int numero=0;
	int mes[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    numero=mes[numeroMes-1];
    return numero;
}

int calculaMax(int v[],int qtt){
    int max=v[0];

    for (int i = 1; i < qtt; i++)
    {
        if (v[i]>=max)
        {
            max=v[i];
        }
    }
    return max;
}

void copiarVector(int v[],int qtt,int v2[]){
    for (int i = 0; i < qtt; i++)
    {
        v2[i]=v[i];
    }
}

void calculaSumes(int v[],int qtt){
    
    for (int i = 1; i < qtt; i++)
    {
        v[i]+=v[i-1];
    }   
}
void separarVector(int v[],int qtt,int vParell[],int vSenar[]){
    int j=0, h=0;
    for (int i = 0; i < qtt; i++)
    {        
        if ((v[i]%2)==0)
        {
            vParell[j]=v[i];
            j++;
        }

        else if ((v[i]%2)!=0 && v[i]!=0)
        {
            vSenar[h]=v[i];
            h++;
        }
    }
}

bool cercaNumeroVector(int numero,int v[],int qtt){
    bool trobat=false;
    int i=0;
    while (i<qtt && trobat==false)
    {
        if (numero==v[i])
        {
            trobat=true;
        }
        else
        {
            i++;
        }
    }
    return trobat;
}


int testPosition(int numero,int v[], int qtt){
    int i=0, posicio=-1;
    while (i<qtt && posicio==-1)
    {
        if (numero==v[i])
        {
            posicio=i;
        }
        else
        {
            i++;
        }
    }
    return posicio;
}

void invertirVector(int v[],int qtt){
    int i=0, j=qtt-1, aux;
    while (i<j)
    {   
        aux=v[i];
        v[i]=v[j];
        v[j]=aux;
        i++;
        j--;
    }
}   

void eliminar(int numero, int v[], int *qtt, int *posicio){
    int i=0, comprueba=0;
    while (i!=(*qtt) && (*posicio)!=-1)
    {
        if (numero==v[i] || comprueba!=0)
        {
            if (numero==v[i])
            {
                (*posicio)=v[i];
            }
            v[i]=v[i+1];
            comprueba=1;
            i++;
        }
        else
        {
            i++;
        }
    }
    if ((*posicio)!=-1)
    {
        (*qtt)--;
    }
    
}
