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

void limpiaFitxer()
{
    CONTRASENYA una,guardada;
    int qttUsers;
    int cops=0;
    int qttGuardats=0;
    int posicionLogin=0;
    int pos[calculaTotal(UBICACIOCONTRASENYA,sizeof(CONTRASENYA))];
    inicializaPos(pos,calculaTotal(UBICACIOCONTRASENYA,sizeof(CONTRASENYA)));

    // Inicializamos variable y un vector que guardara la posicion del fichero original de los logins que guarde
    // Con el archivoCopia y el original miramos con un doble bucle todos los registros y cojemos los ultimos de cada login y los guardamos en el auxiliar para luego poder guardalo

    FILE *f=fopen(UBICACIOCONTRASENYA,"rb");
    FILE *a;
    FILE *c;
    if (f!=NULL)
    {
        fread(&una, sizeof(CONTRASENYA),1,f);
        while (feof(f)==0)
        {
            c=fopen(UBICACIOCONTRASENYACOPIA,"rb");
            qttUsers=buscaUsers(una.login);
            cops=0;
            posicionLogin=0;
            fread(&guardada, sizeof(CONTRASENYA),1,c);
            while (feof(c)==0)
            {
                if (cops==qttUsers-1 && strcmpi(guardada.login,una.login)==0 && existeixLoginAuxiliar(guardada.login)==false)
                {
                    a=fopen(UBICACIOAUXILIAR,"ab");
                    fwrite(&guardada, sizeof(CONTRASENYA),1,a);
                    fclose(a);
                    pos[qttGuardats]=posicionLogin;
                    qttGuardats++;
                }
                else if(strcmpi(guardada.login,una.login)==0) 
                {
                    cops++;
                    posicionLogin++;
                }
                else posicionLogin++;

                fread(&guardada, sizeof(CONTRASENYA),1,c);
            }
            fclose(c);
            fread(&una, sizeof(CONTRASENYA),1,f);
        }
        fclose(f);        
        // Aqui ya tenemos el auxiliar creado y borramos el original y cambiamos el nombre del auxiliar al original
        remove(UBICACIOCONTRASENYA);
        rename(UBICACIOAUXILIAR,UBICACIOCONTRASENYA);
        
        
        // Esto era para debugar 
        // printf("\n\n");
        // llegirFitxer();


        ordena(qttGuardats,pos);

    }

}

void ordena(int qttGuardats, int posV[])
{
    int qttV=qttGuardats;
    int pos;
    CONTRASENYA guardada;
    FILE *f=fopen(UBICACIOCONTRASENYA,"rb");
    FILE *a;
    // Realmente el qttV podriamos quitarlo porque era de otra idea pero tendriamos de remplazar todos y como funciona no lo quiero tocar porque me quedan 5 minutos perdon
    for (int i = 0; i < qttGuardats; i++)
    {
        // Buscamos la posicion del vector en el cual el numero de dentro sea el mas bajo (el 0 del vector es la pos 0 del fichero porque se han ido guardando a la vez)
        pos=buscaPosVector(posV,qttV);
        fseek(f,pos*sizeof(CONTRASENYA),SEEK_SET);
        fread(&guardada, sizeof(CONTRASENYA),1,f);
        // Saltamos hasta la linea que toca y leemos para seguidamente en otro auxiliar guardar el registro
        a=fopen(UBICACIOAUXILIAR,"ab");
        fwrite(&guardada, sizeof(CONTRASENYA),1,a);
        fclose(a);
        // La posicion del vector en la cual estaba este numero cambia a 255 para que no sea el numero mas pequeño otra vez
        posV[pos]=255;

        // esto era para debugar tambien 
        //pintavector(posV,qttV);
    }
    fclose(f);

    // Lo mismo que arriba borramos el archivo original que es sin ordenar y le cambiamos el nombre al ordenado para q sea el original
    remove(UBICACIOCONTRASENYA);
    rename(UBICACIOAUXILIAR,UBICACIOCONTRASENYA);
}



int buscaPosVector(int posV[],int qttV)
{
    int pos=-1;
    int i=0;
    int petit=buscaNumMesPetit(posV,qttV);

    while(pos==-1)
    {
        if (posV[i]==petit) pos=i;
        i++;
    }
    return pos;
}

int buscaNumMesPetit(int posV[],int qttV)
{
    int petit=1000;
    for (int i = 0; i < qttV; i++)
    {
        if (posV[i]<petit)
        {
            petit=posV[i];
        }    
    }
    return petit;
}

void inicializaPos(int pos[], int maxV)
{
    for (int i = 0; i < maxV; i++)
    {
        pos[i]=-1;
    }
}

bool existeixLoginAuxiliar(char login[])
{
    bool trobat=false;
    CONTRASENYA guardada;
    FILE *f=fopen(UBICACIOAUXILIAR,"rb");
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


int buscaUsers(char login[])
{
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

void copiaFitxer(char fileOriginal[],char fileCopia[])
{
    FILE *f=fopen(fileOriginal,"rb");
    FILE *c=fopen(fileCopia,"wb");
    CONTRASENYA guardada;
    fread(&guardada, sizeof(CONTRASENYA),1,f);
    while (feof(f)==0)
    {
        fwrite(&guardada, sizeof(CONTRASENYA),1,c);
        fread(&guardada, sizeof(CONTRASENYA),1,f);
    }
    fclose(f);
    fclose(c);
}

