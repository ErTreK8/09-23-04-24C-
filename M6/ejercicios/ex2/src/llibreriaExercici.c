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
    }
    fclose(f);
    return total;
}


void ordenar()
{
    int qttE=calculaTotal(UBICACIOCOMPANYIA,sizeof(COMPANYIA));
    COMPANYIA guarJ;
    COMPANYIA guarJ1;
    FILE *f=fopen(UBICACIOCOMPANYIA,"rb+");
    for (int i = 0; i < qttE-1; i++)
    {
        for (int j = 0; j <= (qttE-2-i); j++)
        {
            fseek(f,j*sizeof(COMPANYIA),SEEK_SET);
            fread(&guarJ,sizeof(COMPANYIA),1,f);
            fread(&guarJ1,sizeof(COMPANYIA),1,f);
            if(strcmpi(guarJ.nomComp,guarJ1.nomComp)>0)
            {
                fseek(f,j*sizeof(COMPANYIA),SEEK_SET);
                fwrite(&guarJ1,sizeof(COMPANYIA),1,f);
                fwrite(&guarJ,sizeof(COMPANYIA),1,f);
                fflush(f);
            }
        }   
    }
    fclose(f);
}


