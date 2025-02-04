#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include <stdbool.h> 
#include "rlutil.h"
#include "llibreriaPropia.h"
#include "llibreriaExercici.h"


int preguntaOpcio()
{
    char opcionsMenu[SORTIR][40] = {"Afegir Pilot",
                                    "Afegir Missio",
                                    "Retorna Missio",
                                    "Mostra Pilot",
                                    "Mostra Pilot Misio",
                                    "Sortir"};

    int op;
    printf("MENU:\n");
    for (int i = 0; i < SORTIR; i++)
    {
        printf("%d.- %s\n", i + 1, opcionsMenu[i]);
    }

    printf("\nIntrodueix quina opcio vols fer? [%d-%d]: ", 1, SORTIR);
    op = demanarNumeroMinMax(AFEGIR, SORTIR);
    return op;
}


void inserirPilot()
{
    PILOT una;
    int jedi;
    printf("Introdueix el nom del Pilot: ");
    entrarCadena(una.nom,sizeof(una.nom));
    if(existeixPilot(una.nom)==true)
    {
        printf("\nAquet Pilot ja existeix");
        Sleep(500);
    }
    else
    {
        printf("\nEs un Jedi? [0-1]: ");
        jedi=demanarNumeroMinMax(0,1);
        if(jedi==1)
        {
            una.jedi=true;
            printf("Introdueix la habilitat del pilot [10,20]: ");
            una.habilitat=demanarNumeroMinMax(10,20);
        }
        else 
        {
            una.jedi=false;
            printf("Introdueix la habilitat del pilot [1,9]: ");
            una.habilitat=demanarNumeroMinMax(1,9);
        }
        una.estaEnMissio=false;
        inserirUnPilot(una,UBICACIOPILOT);
    }
}

bool existeixPilot(char pilotCerca[])
{
    bool trobat=false;
    PILOT guardada;
    FILE *f=fopen(UBICACIOPILOT,"rb");
    if(f!=NULL)
    {
        fread(&guardada, sizeof(PILOT),1,f);
        while(feof(f)==0 && !trobat)
        {
            if(strcmpi(guardada.nom,pilotCerca)==0)
            {
                trobat=true;
            }
            fread(&guardada, sizeof(PILOT),1,f);
        }
        fclose(f);
    }
    return trobat;
}

void inserirUnPilot(PILOT una, char file[])
{
    FILE *f= fopen(file,"ab");
    if(f!=NULL)
    {
        fwrite(&una,sizeof(PILOT),1,f);
        printf("\nPilot Inserit");
    }
    fclose(f);
}

void mostrarPilot()
{
    FILE *f = fopen(UBICACIOPILOT, "rb");
    PILOT una;
    int qttElements = calculaTotal(UBICACIOPILOT, sizeof(PILOT));
    if(f!=NULL)
    {

        printf("······ PILOTS GUARDADTS ······\n");
        printf("------------------------------\n");
        for (int i = 0; i < qttElements; i++)
        {   
            fread(&una, sizeof(PILOT), 1, f);
            printf("\tPilot[%d]\n\tNom: %s\n\tJedi: %d\n\tHabilitat: %d\n\tEsta en Missio: %d\n------------------------------\n", i+1, una.nom,una.jedi, una.habilitat,una.estaEnMissio);
        }
        fclose(f);
    }
    else
    {
        printf("\nEncara no s'ha guardat cap Pilot.");
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

void inserirMissio()
{
    int habilitatJedi, habilitatPilot, totalTripulants;
    int numeroMissio;

    rellenaVariables(&habilitatJedi,&habilitatPilot,&totalTripulants);
    numeroMissio=buscaNumeroMissio();
    comprobacionsMissio(numeroMissio, habilitatJedi,habilitatPilot,totalTripulants);
}

void rellenaVariables(int *habilitatJedi,int *habilitatPilot,int *totalTripulants)
{
    printf("Introdueix la habilitat Minima del Jedi [10-20]: ");
    (*habilitatJedi)=demanarNumeroMinMax(10,20);
    printf("Introdueix la habilitat Minima dels Pilots [1-9]: ");
    (*habilitatPilot)=demanarNumeroMinMax(1,9);
    do
    {
        printf("Introdueix el numero de Tripulants [Min 1]: ");
        (*totalTripulants)=demanarNumero();
    } while ((*totalTripulants)<0);
}

int buscaNumeroMissio()
{
    FILE *f;
    char fichero[100];
    char aux[3];
    int cosa=-1;
    int i=1;
    bool trobat=false;
    while (i!=20 && trobat!=true )
    {

        strcat(fichero,MISIO);
        sprintf(aux,"%d",i);
        strcat(fichero,aux);
        strcat(fichero,DAT);
        f=fopen(fichero,"rb");
        if (f==NULL)
        {
            trobat=true;
            cosa=i;
        }
        fclose(f);
        i++;
        reseteaCadena(fichero,sizeof(fichero));
    }
    return cosa;
}

void reseteaCadena(char fichero[],int max)
{
    for (int i = 0; i <= max; i++)
    {
        fichero[i]='\0';
    }   
}

void comprobacionsMissio(int numeroMissio,int habilitatJedi,int habilitatPilot,int totalTripulants)
{
    char file[100];
    char aux[3];
    bool hayJedi;
    int numeroPilots;
    if(numeroMissio!=-1)
    {
        strcat(file,MISIO);
        sprintf(aux,"%d",numeroMissio);
        strcat(file,aux);
        strcat(file,DAT);
        hayJedi=buscaJedi(habilitatJedi);
        if (hayJedi==true)
        {
            numeroPilots=buscaPilots(habilitatPilot);
            if (numeroPilots>=totalTripulants)
            {
                creaFitxerMissio(file,habilitatJedi,habilitatPilot,totalTripulants);
            }
            else printf("\nNo hay suficientes pilotos con ese nivel de habilidad");
        }
        else printf("\nNo hay ningun jedi con ese nivel de hablididad");
    }
    else printf("\nNo hi ha mes espai per missions");
}

void creaFitxerMissio(char file[],int habilitatJedi,int habilitatPilot,int totalTripulants)
{

    int qttPilots=0;
    int qttJedi=0;
    PILOT guardada;
    FILE *f=fopen(UBICACIOPILOT,"rb");
    FILE *j=fopen(file,"wb");
    FILE *c=fopen(UBICACIOAUXILIAR,"wb");
    if(f!=NULL)
    {
        fread(&guardada, sizeof(PILOT),1,f);
        while(feof(f)==0 && (qttPilots+qttJedi!=totalTripulants))
        {
            if (guardada.jedi==true && qttJedi==0 && guardada.habilitat>=habilitatJedi && guardada.estaEnMissio==false)
            {
                guardada.estaEnMissio=true;
                fwrite(&guardada, sizeof(PILOT),1,j);
                fwrite(&guardada, sizeof(PILOT),1,c);
                qttJedi++;
            }
            else if((guardada.habilitat>=habilitatPilot) && (guardada.jedi==false) && (qttPilots+qttJedi!=totalTripulants) && guardada.estaEnMissio==false)
            {
                guardada.estaEnMissio=true;
                fwrite(&guardada, sizeof(PILOT),1,j);
                fwrite(&guardada, sizeof(PILOT),1,c);
                qttPilots++;
            }
            else
            {
                fwrite(&guardada, sizeof(PILOT),1,c);
            }
            fread(&guardada, sizeof(PILOT),1,f);
        }
        fclose(f);
        fclose(j);
        fclose(c);
        remove(UBICACIOPILOT);
        rename(UBICACIOAUXILIAR,UBICACIOPILOT);
    }
}

bool buscaJedi(int habilitatJedi)
{
    bool trobat=false;
    PILOT guardada;
    FILE *f=fopen(UBICACIOPILOT,"rb");
    if(f!=NULL)
    {
        fread(&guardada, sizeof(PILOT),1,f);
        while(feof(f)==0 && !trobat)
        {
            if(guardada.jedi==true && guardada.habilitat>=habilitatJedi && guardada.estaEnMissio==false)
            {
                trobat=true;
            }
            fread(&guardada, sizeof(PILOT),1,f);
        }
        fclose(f);
    }
    return trobat;
}

int buscaPilots(int habilitatPilot)
{
    int qtt=1;
    PILOT guardada;
    FILE *f=fopen(UBICACIOPILOT,"rb");
    if(f!=NULL)
    {
        fread(&guardada, sizeof(PILOT),1,f);
        while(feof(f)==0)
        {
            if(guardada.habilitat>=habilitatPilot && guardada.jedi==false && guardada.estaEnMissio==false)
            {
                qtt++;
            }
            fread(&guardada, sizeof(PILOT),1,f);
        }
        fclose(f);
    }
    return qtt;
}


void mostrarMissions()
{
    FILE *f;
    char fichero[100];
    char aux[3];
    bool trobat=false;
    reseteaCadena(fichero,sizeof(fichero));
    printf("\n····· Misions  Guardades ·····\n");
    printf("------------------------------\n");   
    for(int i=1;i<21;i++)
    {

        strcat(fichero,MISIO);
        sprintf(aux,"%d",i);
        strcat(fichero,aux);
        strcat(fichero,DAT);
        f=fopen(fichero,"rb");
        if (f!=NULL)
        {
            printf("\n• Missio Numero %d", i);
        }
        fclose(f);
        reseteaCadena(fichero,sizeof(fichero));
    }
    getch();
}

void retornaMissio()
{
    int numMissio,guanya;
    bool existeix;
    iniciRetorna(&numMissio,&guanya,&existeix);
    if (existeix==true)
    {
        tornaMisio(numMissio,guanya);
    } 


}

int iniciRetorna(int *numero,int *guanya, bool *existeix)
{
    mostrarMissions();
    printf("\n Quina Missio vols que retorni?: ");
    (*numero)=demanarNumeroMinMax(1,20);
    (*existeix)=existeixMissio((*numero));
    if((*existeix)==true)
    {
        printf("Han guanyat el combat [0-1]?: ");
        (*guanya)=demanarNumeroMinMax(0,1);
    }
    else printf("Aquesta Missio no existeix");
}

bool existeixMissio(int numero)
{
    char fichero[100];
    char aux[3];
    FILE *f;
    bool trobat=false;
    reseteaCadena(fichero,sizeof(fichero));

    strcat(fichero,MISIO);
    sprintf(aux,"%d",numero);
    strcat(fichero,aux);
    strcat(fichero,DAT);
    f=fopen(fichero,"rb");
    if (f!=NULL)
    {
        trobat=true;
    }   
    fclose(f);
    return trobat;
}

void tornaMisio(int numeroMissio,int guanya)
{
    PILOT guardada, un;
    
    char file[100];
    char aux[3];
    reseteaCadena(file,sizeof(file));
    strcat(file,MISIO);
    sprintf(aux,"%d",numeroMissio);
    strcat(file,aux);
    strcat(file,DAT);


    FILE *f;
    FILE *j=fopen(file,"rb");
    FILE *c=fopen(UBICACIOAUXILIAR,"wb");
    bool trobat=false;

    int punts;
    if (guanya==1) punts=1;
    else punts=-1;


    if(j!=NULL)
    {
        fread(&un, sizeof(PILOT),1,j);
        while (feof(j)==0)
        {
            f=fopen(UBICACIOPILOT,"rb");
            trobat=false;
            fread(&guardada, sizeof(PILOT),1,f);
            while(feof(f)==0 && trobat!=true)
            {
               if (strcmpi(un.nom,guardada.nom)==0)
                {
                    guardada.estaEnMissio=false;
                    guardada.habilitat=guardada.habilitat+punts;
                    if (guardada.habilitat>9)guardada.jedi=true;
                    else guardada.jedi=false;
                    fwrite(&guardada, sizeof(PILOT),1,c);
                    trobat=true;
                }
                fread(&guardada, sizeof(PILOT),1,f);
            }
            fread(&un, sizeof(PILOT),1,j);
            fclose(f);
        }
        fclose(j);
        fflush(c);

        f=fopen(UBICACIOPILOT,"rb");
        fread(&guardada, sizeof(PILOT),1,f);
        while(feof(f)==0)
        {
            if(existeixPilot2(guardada.nom)==false)
            {
                fwrite(&guardada, sizeof(PILOT),1,c);
            }
            fread(&guardada, sizeof(PILOT),1,f);
        }
        fclose(f);
        fclose(c);
        remove(UBICACIOPILOT);
        remove(file);
        rename(UBICACIOAUXILIAR,UBICACIOPILOT);
    }
}

bool existeixPilot2(char pilotCerca[])
{
    bool trobat=false;
    PILOT guardada;
    FILE *m=fopen(UBICACIOAUXILIAR,"rb");
    if(m!=NULL)
    {
        fread(&guardada, sizeof(PILOT),1,m);
        while(feof(m)==0 && !trobat)
        {
            if(strcmpi(guardada.nom,pilotCerca)==0)
            {
                trobat=true;
            }
            fread(&guardada, sizeof(PILOT),1,m);
        }
        fclose(m);
    }
    return trobat;
}

void mostraPilotsMissio()
{
    char file[100];
    char aux[3];
    int numero;
    bool existeix;
    mostrarMissions();
    printf("\n\n Quina Missio vols Printar?: ");
    numero=demanarNumeroMinMax(1,20);
    printf("\n\n");
    existeix=existeixMissio(numero);
    if (existeix==true)
    {
        reseteaCadena(file,sizeof(file));
        strcat(file,MISIO);
        sprintf(aux,"%d",numero);
        strcat(file,aux);
        strcat(file,DAT);
        mostrarPilot2(file);
    }
    else printf("La Missio no Existeix");

    
}

void mostrarPilot2(char file[])
{
    FILE *f = fopen(file, "rb");
    PILOT una;
    int qttElements = calculaTotal(file, sizeof(PILOT));
    if(f!=NULL)
    {

        printf("······ PILOTS GUARDADTS ······\n");
        printf("------------------------------\n");
        for (int i = 0; i < qttElements; i++)
        {   
            fread(&una, sizeof(PILOT), 1, f);
            printf("\tPilot[%d]\n\tNom: %s\n\tJedi: %d\n\tHabilitat: %d\n\tEsta en Missio: %d\n------------------------------\n", i+1, una.nom,una.jedi, una.habilitat,una.estaEnMissio);
        }
        fclose(f);
    }
    else
    {
        printf("\nEncara no s'ha guardat cap pilot.");
    }
    getch();
}
