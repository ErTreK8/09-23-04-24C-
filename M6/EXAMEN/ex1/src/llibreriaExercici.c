#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include <stdbool.h> 
#include "rlutil.h"
#include "llibreriaPropia.h"
#include "llibreriaExercici.h"



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

void llegirFitxer()
{
    FILE *f = fopen(UBICACIOCONTRASENYA, "rb");
    CONTRASENYA una;
    int qttElements = calculaTotal(UBICACIOCONTRASENYA, sizeof(CONTRASENYA));
    if(f!=NULL)
    {
        
        printf("\n·· CONTRASENYES GUARDADADES ··\n");
        printf("------------------------------\n");
        for (int i = 0; i < qttElements; i++)
        {   
            fread(&una, sizeof(CONTRASENYA), 1, f);
            printf("\tLogin: [%s]   Contrasenya: %s   Bloquejat %d\n\n",una.login,una.contrasenya,una.bloquejat);
        }
        fclose(f);
    }
    else
    {
        printf("\nEncara no s'ha guardat cap Contrasenya.");
    }
    getch();

}

void modificaFitxer()
{
    CONTRASENYA una;
    bool existeix, bloquejat;
    // pide loign
    printf("\n\nIntrodueix el login de l'usuari: ");
    entrarCadena(una.login,sizeof(una.login));
    // mira si existe el login
    existeix=existeixLogin(una.login);
    if (existeix==true)
    {
        // Si existe mira si el user esta bloqueado
        bloquejat=estaBloquejat(una.login);
        if (bloquejat==false)
        {
            // Pedimos contraseña hasta que no se repita de las 3 ultimas
            do
            {
                printf("\n\nIntrodueix una contrasenya per l'usuari (No es pot repetir les darreres 3 contrasenyes): ");
                entrarCadena(una.contrasenya,sizeof(una.contrasenya));
            } while (existeixContrasenyaUser(una.login,una.contrasenya)==true);
            
            una.bloquejat=false;
            // Insertamos el user
            if(existeixContrasenyaUser(una.login,una.contrasenya)==false) insertarUser(una,UBICACIOCONTRASENYA);
            else printf("\nContrasenya Repetida");

            
        }
        else printf("\nUsuari Bloquejat");
        
    }
    else
    {
        printf("\n\nIntrodueix una contrasenya per l'usuari: ");
        entrarCadena(una.contrasenya,sizeof(una.contrasenya));
        una.bloquejat=false;
        insertarUser(una,UBICACIOCONTRASENYA);
    }

    getch();
}

bool existeixContrasenyaUser(char login[], char contrasenya[])
{
    bool existeix=false;

    CONTRASENYA guardada;
    int qttLogin=buscaUsers(login);
    int cops=0;
    FILE *f=fopen(UBICACIOCONTRASENYA,"rb");
    if(f!=NULL)
    {
        // Cuenta cuantos logins con ese login hay y busca hasta q sean los 3 ultimos y alli comprueba si tiene la misma contra
        fread(&guardada, sizeof(CONTRASENYA),1,f);
        while(feof(f)==0 && !existeix)
        {
            if (qttLogin>2)
            {
                if ((qttLogin-3<=cops) && strcmpi(guardada.login,login)==0 && strcmpi(guardada.contrasenya,contrasenya)==0)
                {
                    existeix=true;   
                }

                else if(strcmpi(guardada.login,login)==0)
                {
                    cops++;
                }
            }
            else
            {
                if(strcmpi(guardada.login,login)==0 && strcmpi(guardada.contrasenya,contrasenya)==0)
                {
                    existeix=true;
                }
            }
            fread(&guardada, sizeof(CONTRASENYA),1,f);
        }
        fclose(f);
    }
    return existeix;
}

bool estaBloquejat(char login[])
{
    bool bloquejat=false;
    CONTRASENYA guardada;
    int qttLogin=buscaUsers(login);
    int cops=0;
    FILE *f=fopen(UBICACIOCONTRASENYA,"rb");
    if(f!=NULL)
    {
        fread(&guardada, sizeof(CONTRASENYA),1,f);
        while(feof(f)==0 && !bloquejat)
        {
            if ((qttLogin-1==cops) && strcmpi(guardada.login,login)==0 && guardada.bloquejat==true)
            {
                bloquejat=true;
            }
            

            else if(strcmpi(guardada.login,login)==0)
            {
                cops++;
            }
            fread(&guardada, sizeof(CONTRASENYA),1,f);
        }
        fclose(f);
    }
    return bloquejat;
}

int buscaUsers(char login[])
{
    // cuenta cuantos usr con ese login existen
    int qtt=0;
    CONTRASENYA guardada;
    FILE *f=fopen(UBICACIOCONTRASENYA,"rb");
    if(f!=NULL)
    {
        fread(&guardada, sizeof(CONTRASENYA),1,f);
        while(feof(f)==0)
        {
            if(strcmpi(guardada.login,login)==0)
            {
                qtt++;
            }
            fread(&guardada, sizeof(CONTRASENYA),1,f);
        }
        fclose(f);
    }
    return qtt;
}

bool existeixLogin(char login[])
{
    bool trobat=false;
    CONTRASENYA guardada;
    FILE *f=fopen(UBICACIOCONTRASENYA,"rb");
    if(f!=NULL)
    {
        fread(&guardada, sizeof(CONTRASENYA),1,f);
        while(feof(f)==0 && !trobat)
        {
            if(strcmpi(guardada.login,login)==0)
            {
                trobat=true;
            }
            fread(&guardada, sizeof(CONTRASENYA),1,f);
        }
        fclose(f);
    }
    return trobat;
}

void insertarUser(CONTRASENYA una,char file[])
{
    FILE *f= fopen(file,"ab");
    if(f!=NULL)
    {
        fwrite(&una,sizeof(CONTRASENYA),1,f);
        printf("\nUsuari Nou Inserit");
    }
    fclose(f);
}






