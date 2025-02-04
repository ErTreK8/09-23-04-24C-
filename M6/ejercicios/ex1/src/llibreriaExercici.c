#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include <stdbool.h> 
#include "rlutil.h"
#include "llibreriaPropia.h"
#include "llibreriaExercici.h"

void inserirNovaCompanyia()
{
    COMPANYIA una;
    printf("Introdueix el nom de la nova companyia: ");
    entrarCadena(una.nomComp,sizeof(una.nomComp));
    if(existeixCompamyia(una.nomComp)==true)
    {
        printf("\nAquesta companyia ja existeix");
    }
    else
    {
        printf("Introdueix el Pais de la Companyia: ");
        entrarCadena(una.paisComp,sizeof(una.paisComp));
        inserirUnaCompanyia(una,UBICACIOCOMPANYIA);
    }

}

bool existeixCompamyia(char companyiaCerca[])
{
    bool trobat=false;
    COMPANYIA guardada;
    FILE *f=fopen(UBICACIOCOMPANYIA,"rb");
    if(f!=NULL)
    {
        fread(&guardada, sizeof(COMPANYIA),1,f);
        while(feof(f)==0 && !trobat)
        {
            if(strcmpi(guardada.nomComp,companyiaCerca)==0)
            {
                trobat=true;
            }
            fread(&guardada, sizeof(COMPANYIA),1,f);
        }
        fclose(f);
    }
    return trobat;
}

void inserirUnaCompanyia(COMPANYIA una, char file[])
{
    FILE *f= fopen(file,"ab");
    if(f!=NULL)
    {
        fwrite(&una,sizeof(COMPANYIA),1,f);
        printf("\nCompanyia inserida");
    }
    fclose(f);
}

void mostrarCompanyies()
{
    COMPANYIA guardada;
    int cont=1;
    FILE *f=fopen(UBICACIOCOMPANYIA,"rb");
    if(f!=NULL)
    {
        fread(&guardada,sizeof(COMPANYIA),1,f);
        while (feof(f)==0)
        {
            printf("\n[%d]%s  %s",cont,guardada.nomComp,guardada.paisComp);
            cont++;
            fread(&guardada,sizeof(COMPANYIA),1,f);
        }
    }
}

void mostrarCompanyies2()
{
    FILE *f = fopen(UBICACIOCOMPANYIA, "rb");
    COMPANYIA una;
    int qttElements = calculaTotal(UBICACIOCOMPANYIA, sizeof(COMPANYIA));
    if(f!=NULL)
    {

        printf("···· COMPANYIES GUARDADES ····\n");
        printf("------------------------------\n");
        for (int i = 0; i < qttElements; i++)
        {
            fread(&una, sizeof(COMPANYIA), 1, f);
            printf("\tCompanyia [%d]\n\tNom: %s\n\tPais: %s\n------------------------------\n", i+1, una.nomComp, una.paisComp);
        }
        fclose(f);
    }
    else
    {
        printf("\nEncara no s'ha guardat cap companyia.");
    }
    getch();
}

int calculaTotal(char nFile[], int longElement)
{
    int total = 0;
    FILE *f = fopen(nFile, "rb");
    if(f!=NULL)
    {
        fseek(f, 0, SEEK_END);
        total = ftell(f)/longElement;
        fclose(f);
    }
    return total;
}



void modificarNom()
{

    COMPANYIA una;
    int posCompanyia;
    printf("Introdueix el nom de la companyia: ");
    entrarCadena(una.nomComp,sizeof(una.nomComp));
    posCompanyia=cercaPosicio(una.nomComp);

    if (posCompanyia==-1)
    {
        printf("La companyia no existe");
    }
    else
    {
        printf("Introdueix el pais: ");
        entrarCadena(una.paisComp,sizeof(una.paisComp));
        modificaPos(una,posCompanyia);
    }
}


int cercaPosicio(char nomCompCerca[])
{   
    int posCompanyia=-1;
    int cont=0;
    COMPANYIA guardada;
    FILE *f=fopen(UBICACIOCOMPANYIA,"rb");
    if(f!=NULL)
    {
        fread(&guardada, sizeof(COMPANYIA),1,f);
        while(feof(f)==0 && posCompanyia==-1)
        {
            if(strcmpi(guardada.nomComp,nomCompCerca)==0)
            {
                posCompanyia=true;
            }
            else
            {
            fread(&guardada, sizeof(COMPANYIA),1,f);
            cont++;
            }
        }
        fclose(f);
    }

}

void modificaPos(COMPANYIA una, int posCompanyia)
{
    FILE *f=fopen(UBICACIOCOMPANYIA,"rb+");
    if(f!=NULL)
    {
        fseek(f,posCompanyia*sizeof(COMPANYIA),f);
        fwrite(&una,sizeof(COMPANYIA),1,f);
        fclose(f);
    }
}




