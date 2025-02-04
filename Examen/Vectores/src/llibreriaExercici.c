#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include <stdbool.h> 
#include "rlutil.h"
#include "llibreriaPropia.h"
#include "llibreriaExercici.h"

int numeroDeNumeros()
{
    int num;
    do
    {
        printf("Amb Quants Numeros Vols Jugar (2..20): (Recorda que ha de ser un numero parell): ");
        num=demanarNumeroMinMax(2,20);
    } while (num%2!=0);
    return num;
}

void ompleVectorNumeros(int vNumeros[],int *qttVNumeros,int maxVNumeros,int vRepetidos[],int qttVRepetidos)
{
    int posicion=0;
    while (posicion>-1)
    {
        (*qttVNumeros)=0;
        // Poner El Vector de Contador a 0
        for (int i = 0; i < qttVRepetidos; i++)
        {
            vRepetidos[i]=0;
        }
        // Cambiar el vector de vNumeros y poner en funcionamiento el vector de vRepetidos
        for (int i = 0; i < maxVNumeros; i++)
        {
            vNumeros[i]=RandomizadorNumeros(0,10);
            int numero=vNumeros[i];
            (*qttVNumeros)=(*qttVNumeros)+1;
            vRepetidos[vNumeros[i]]++;
        }
        posicion=posicio(vRepetidos,qttVRepetidos,3);
    }   
}

void printaInci(int vNumeros[],int qttVNumeros)
{
    printf("-------------------------------------------------\n ----- TROBA 2 NOMBRES QUE SUMATS FACIN 10 ----- \n-------------------------------------------------\n\n");
    pintaVectorHorizontal(vNumeros,qttVNumeros);
    printf("\n\n");
}

void pintaVectorHorizontal(int v[], int qtt)
{
    if (qtt == 0)
    {
        printf("\nVector buit");
    }

    else
    {
        printf("| ");
        for (int i = 0; i < qtt; i++)
        {
            printf("%d | ", v[i]);
        }
    }
}

void pintaParelles(int v[],int qtt)
{
    if (qtt == 0)
    {
        printf("No has fet Parelles\n\n");
    }

    else
    {
        for (int i = 0; i < qtt; i=i+2)
        {
            printf("[ %d - %d]  ", v[i],v[i+1]);
        }
    }
}

bool estaVector(int num1, int num2, int v[], int qtt)
{

}

bool comprovarHiHa10(int v[],int qtt)
{
    bool hay10=false;
    int i=0;
    int numero1, numero2;
    while (hay10==false && i<qtt)    
    {
        for (int j = i+1; j < qtt; j++)
        {
            numero1=v[i];
            numero2=v[j];
            if (v[i]+v[j]==10)
            {    
                hay10=true;
            }
        }
        i++;
    }
    return hay10;
}

void comprovarNumeros(int numero1,int numero2,bool *esta,int vNumeros[],int qttVNumeros,int *final)
{
    if ((numero1+numero2)==10)
	{
		if (numero1==5)
		{
			final=estaVector5(numero1,numero2,vNumeros,qttVNumeros);
		}
		else
		{
			*esta=cerca(vNumeros,qttVNumeros, numero1);
			if (*esta==true)
			{
				*esta=cerca(vNumeros,qttVNumeros, numero2);
                if (*esta==false)
                {
                    *final=3;
                }
			}
			else
			{
				*final=2;
			}
		}
	}
	else
	{
		*final=1;
	}
}
int estaVector5(int numero1,int numero2,int v[],int qtt)
{
    int final=0;
    int posicion=-1;
    int posicionAnt;
    int ant=0;
    posicion=posicio(v,qtt,numero1);
    if (posicion!=-1)
    {
        posicionAnt=posicion;
        ant=v[posicion];
        v[posicion]=-1;
        posicion=posicio(v,qtt,numero1);
        if (posicion==posicionAnt)
        {
            v[posicionAnt]=5;
            final=3;
        }
        else
        {
            final=0;
        }
        
    }
    else
    {
        final=2;
    }
    return final;
}
void rellenaParejas(int numero1,int numero2,int vParejas[],int qttVParejas)
{
    qttVParejas++;
	vParejas[qttVParejas]=numero1;
	qttVParejas++;
	vParejas[qttVParejas]=numero2;
}

int posicioReves(int v[],int qtt,int numCerca)
{
    int i=qtt-1, pos=-1;
    while(i>-1 && pos==-1)
    {
        if(v[i]==numCerca)
        {
            pos=i;
        }
        else
        {
            i--;
        }
    }
    return pos;
}

void eliminaVector(int v[],int *qtt,int numero1,int numero2)
{
    int posicion=-1;
    posicion=posicioReves(v,*qtt,numero1);
    for (int i = posicion; i < *qtt; i++)
    {
        if (i+1!=*qtt)
        {
            v[i]=v[i+1];
        }
    }
    posicion=posicioReves(v,*qtt,numero2);
    for (int i = posicion; i < *qtt; i++)
    {
        if (i+1!=*qtt)
        {
            numero1=v[i];
            numero2=v[i+1];
            v[i]=v[i+1];
        }
    }
}

void pintaFinal(int vNumeros[],int qttVNumeros,int vParejas[],int qttVParejas)
{
    setColor(BLUE);
	printf("HAN QUEDAT SENSE AGRUPAR EL SEGUENTS NUMEROS:\n");
	setColor(WHITE);
	pintaVectorHorizontal(vNumeros,qttVNumeros);
	setColor(BLUE);
	printf("\n\nPARELLAS TROBADES (MANTENIR L'ORDRE):\n");
	setColor(WHITE);
	pintaParelles(vParejas,qttVParejas);
	setColor(BLUE);
	printf("ESBRINA QUANTS COPS HA SORTIT CADA UNA DE LES PARELLES\n");
    setColor(WHITE);
	printaParelles(vParejas,qttVParejas);
}

void printaParelles(int v[],int qtt)
{
    int qtt10=0,qtt9=0,qtt8=0,qtt7=0,qtt6=0,qtt5=0;
    for (int i = 0; i < qtt; i=i+2)
    {
        if (v[i]==10 && v[i+1]==0 || v[i]==0 && v[i+1]==10)
        {
            qtt10++;
        }
        else if (v[i]==9 && v[i+1]==1 || v[i]==1 && v[i+1]==9)
        {
            qtt9++;
        }
        else if (v[i]==8 && v[i+1]==2 || v[i]==2 && v[i+1]==8)
        {
            qtt8++;
        }
        else if (v[i]==7 && v[i+1]==3 || v[i]==3 && v[i+1]==7)
        {
            qtt7++;
        }
        else if (v[i]==6 && v[i+1]==4 || v[i]==4 && v[i+1]==6)
        {
            qtt6++;
        }
        else if (v[i]==5 && v[i+1]==5)
        {
            qtt5++;
        }
    }    
    printf("[ 0-10]: ");
    printa(qtt10);
    printf("\n[ 9-1]: ");
    printa(qtt9);
    printf("\n[ 2-8]: ");
    printa(qtt8);
    printf("\n[ 3-7]: ");
    printa(qtt7);
    printf("\n[ 4-6]: ");
    printa(qtt6);
    printf("\n[ 5-5]: ");
    printa(qtt5);
}

void printa(int numero)
{   
    if (numero==0)
    {
        printf("Cap");
    }
    else
    {
        printf("%d",numero);
    }
}


