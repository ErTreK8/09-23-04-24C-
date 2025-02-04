#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <string.h>
#include <stdbool.h>
#include "rlutil.h"
#include "llibreriaPropia.h"
#include "llibreriaExercici.h"

void generar()
{
    FILE *f=fopen(UBICACIONUMEROS,"wb"); //no es pot posar w --> creuria que es de texte
    if (f!=NULL)
    {
        int num1=10,num2=33,num3=333333;
        int v[3]={56,566,5666};
        fwrite(&num1,sizeof(int),1,f);
        fwrite(&num2,sizeof(int),1,f);
        fwrite(&num3,sizeof(int),1,f);
        for (int i=0;i<3;i++)
        {
            fwrite(&v[i],sizeof(int),1,f);
        }
        fwrite(v,sizeof(int),3,f);
        fclose(f);
    }
}
int calculaQuantitatElements(char file[],int tamanyUnElement)
{
    int totalElements=0;
    FILE *f=fopen(file,"rb"); //no es pot posar w --> creuria que es de texte
    if (f!=NULL)
    {
        fseek(f,0,SEEK_END);
        totalElements=ftell(f)/tamanyUnElement;
        fclose(f);
    }
    return totalElements;
}

void llegirWhile(char file[])
{
    FILE *f=fopen(file,"rb"); //no es pot posar w --> creuria que es de texte
    int num;
    if (f!=NULL)
    {
        fread(&num,sizeof(int),1,f);
        while (feof(f)==0)
        {
            printf("\n%d",num);
            fread(&num,sizeof(int),1,f);
        }
        fclose(f);
    }
}

void llegirFor(char file[],int qttElements)
{
    FILE *f=fopen(file,"rb"); //no es pot posar w --> creuria que es de texte
    int num;
    if (f!=NULL)
    {
        for (int i=0;i<qttElements;i++)
        {
            fread(&num,sizeof(int),1,f);
            printf("\n[%d]: %d",i+1,num);
        }
        fclose(f);
    }
}

void modificarElement(int qttElements)
{
    printf("Introdueix l'element que vols modificar [1...%d]: ",qttElements);
    int index=demanaNumEntreRangInt(1,qttElements);

    //modificarem el valor a 10
    FILE *f=fopen(UBICACIONUMEROS,"rb+");
    
    if (f!=NULL)
    {
        int num=14;
        fseek(f,sizeof(int)*(index-1),SEEK_SET);
        fwrite(&num,sizeof(int),1,f);
        fclose(f);
    }
}
