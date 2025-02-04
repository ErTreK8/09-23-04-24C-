#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <string.h>
#include <stdbool.h>
#include "rlutil.h"
#include "llibreriaPropia.h"
#include "llibreriaExercici.h"

void llegirFitxerOrigen()
{
    ESPORTNACIONALITAT un;
    FILE *f = obrirFitxer(UBICACIOFITXERORIGEN, "rt");
    if (f != NULL)
    {
        while (feof(f) == 0)
        {
            un = llegirUnEsportNacionalitat(f);
            printf("%s %s\n", un.esport, un.nacionalitat);
            tractament(un);
        }
        fclose(f);
    }
}
ESPORTNACIONALITAT llegirUnEsportNacionalitat(FILE *f)
{
    ESPORTNACIONALITAT un;
    /*
    Leo Messi
    Argentina
    Futbol
    --------------------------------------------*/
    char brossa[50];
    fgets(brossa, sizeof(brossa), f);                   // Leo Messi\n\0
    fgets(un.nacionalitat, sizeof(un.nacionalitat), f); // Argentina\n\o
    eliminaSaltLinia(un.nacionalitat, sizeof(un.nacionalitat));
    fgets(un.esport, sizeof(un.esport), f); // Argentina\n\o
    eliminaSaltLinia(un.esport, sizeof(un.esport));
    fgets(brossa, sizeof(brossa), f); //--------------------\n\0
    return un;
}
void tractament(ESPORTNACIONALITAT un)
{
    if (cercaEsportNacionalitat(un))
    {
        // he d'incrementar en 1 el comptador
        // Futbol  Argentina  2
        // Tenis   Portugal   1

        // Futbol Argentina

        // en un fitxer auxiliar
        // Futbol  Argentina  3
        // Tenis   Portugal   1

        incrementarEn1(un);
    }
    else
    {
        // Futbol  Argentina  2
        // Tenis   Portugal   1

        // Futbol  Brasil

        int pos = calculaPosicio(un);
        printf("\nPosicio: %d", pos);
        afegirEnLaPosicio(un, pos);
    }
}

bool cercaEsportNacionalitat(ESPORTNACIONALITAT un) // UN: Futbol Argentina
{
    bool trobat = false;
    ESPORTNACIONALITATRESUM enFile;
    FILE *f = obrirFitxer(UBICACIOFITXRESUM, "rt");
    if (f != NULL)
    {
        while (feof(f) == 0 && !trobat)
        {
            enFile = llegirFitxerResum(f);
            if (strcmp(enFile.esport, un.esport) == 0 && strcmp(enFile.nacionalitat, un.nacionalitat) == 0)
            {
                trobat = true;
            }
        }
        fclose(f);
    }
    return trobat;
}
ESPORTNACIONALITATRESUM llegirFitxerResum(FILE *f)
{
    // futbol
    // suiza
    // 1
    char cadAuxiliar[30];
    ESPORTNACIONALITATRESUM una;
    fgets(una.esport, sizeof(una.esport), f);
    eliminaSaltLinia(una.esport, sizeof(una.esport));
    fgets(una.nacionalitat, sizeof(una.nacionalitat), f);
    eliminaSaltLinia(una.nacionalitat, sizeof(una.nacionalitat));

    fgets(cadAuxiliar, sizeof(cadAuxiliar), f);
    eliminaSaltLinia(cadAuxiliar, sizeof(cadAuxiliar));
    una.cont = atoi(cadAuxiliar);
    return una;
}

void incrementarEn1(ESPORTNACIONALITAT un)
{
    // Futbol  Argentina  2
    // Tenis   Portugal   1

    // Futbol Argentina

    FILE *fResum = obrirFitxer(UBICACIOFITXRESUM, "rt");
    FILE *fAuxiliar = obrirFitxer(UBICACIOFITXRESUMCOPIA, "wt");

    if (fResum != NULL && fAuxiliar != NULL)
    {
        ESPORTNACIONALITATRESUM enFile;
        while (feof(fResum) == 0)
        {
            enFile = llegirFitxerResum(fResum);
            if (strcmp(enFile.esport, un.esport) == 0 && strcmp(enFile.nacionalitat, un.nacionalitat) == 0)
            {
                enFile.cont++;
            }
            actualitzar(enFile, fAuxiliar);
        }
        fclose(fResum);
        fclose(fAuxiliar);
        remove(UBICACIOFITXRESUM);
        rename(UBICACIOFITXRESUMCOPIA, UBICACIOFITXRESUM);
    }
    else
    {
        printf("\nNo s'ha pogut actualitzar el fitxer");
        fclose(fResum);
        fclose(fAuxiliar);
    }
}
void actualitzar(ESPORTNACIONALITATRESUM enFile, FILE *fAuxiliar)
{
    fseek(fAuxiliar, 0, SEEK_END);
    if (ftell(fAuxiliar) > 0)
        fputc('\n', fAuxiliar);
    fprintf(fAuxiliar, "%s\n%s\n%d", enFile.esport, enFile.nacionalitat, enFile.cont);
}

int calculaPosicio(ESPORTNACIONALITAT un)
{
    int pos = -1;
    int cont = 0;
    FILE *f = obrirFitxer(UBICACIOFITXRESUM, "r");
    if (f != NULL)
    {
        while (feof(f) == 0 && pos == -1)
        {
            ESPORTNACIONALITATRESUM guardat = llegirFitxerResum(f);
            if (strcmpi(guardat.esport, un.esport) > 0)
            {
                pos = cont;
            }
            else if (strcmpi(guardat.esport, un.esport) == 0 && strcmpi(guardat.nacionalitat, un.nacionalitat) > 0)
            {
                pos = cont;
            }
            cont++;
        }

        fclose(f);
    }
    // es necessari si el nou esport > que el darrer que tenim en el fitxer.
    if (pos == -1)
        pos = cont;
    return pos;
}

void afegirEnLaPosicio(ESPORTNACIONALITAT un, int pos)
{
    int qttElement = calculaLinies() / 3;
    ESPORTNACIONALITATRESUM guardat;
    FILE *f = obrirFitxer(UBICACIOFITXRESUM, "r");
    if (f != NULL)
    {
        for (int i = 0; i < qttElement; i++)
        {
            guardat=llegirFitxerResum(f);
            if (i == pos) 
            {
                //posem 1 pq és un esport o esport - nacionalitat nou
                afegir(un.esport,un.nacionalitat,1);
            }
            afegir(guardat.esport,guardat.nacionalitat,guardat.cont);
        }
        if (pos==qttElement) afegir(un.esport,un.nacionalitat,1);
        fclose(f);
        remove(UBICACIOFITXRESUM);
        rename(UBICACIOFITXRESUMCOPIA,UBICACIOFITXRESUM);
    }
    else
    {
        //s'encarrega de generar el primer cop el fitxer;
        FILE *f=obrirFitxer(UBICACIOFITXRESUM,"w");
        fprintf(f,"%s\n%s\n%d",un.esport,un.nacionalitat,1);
        fclose(f);
    }
}
void afegir(char esport[],char nacionalitat[],int cont)
{
    FILE *f=obrirFitxer(UBICACIOFITXRESUMCOPIA,"a");
    fseek(f,0,SEEK_END); 
    if (ftell(f)>0) fputc('\n',f);
    fprintf(f,"%s\n%s\n%d",esport,nacionalitat,cont);
    fclose(f);
}

int calculaLinies()
{
    int linies=0;
    FILE *f;
    char cadena[200];
    if (fitxerBuit(UBICACIOFITXRESUM)==false)
    {
        f=obrirFitxer(UBICACIOFITXRESUM,"r");
        while (feof(f)==0)
        {
            fgets(cadena,sizeof(cadena),f);
            linies++;
        }
        fclose(f);
    }
    return linies;
}

void generarFitxerBonic()
{
    FILE *f=fopen(UBICACIOFITXRESUM,"r");
    if (f!=NULL)
    {
        ESPORTNACIONALITATRESUM actual,anterior;

        strcpy(anterior.esport,"BUIT");
       
        while (feof(f)==0)
        {
            actual=llegirFitxerResum(f);
            if (strcmpi(actual.esport,anterior.esport)!=0)
            {
                imprimirCapacelera(actual);
            }
            else
            {
                imprimirPaisContador(actual);
            }
            anterior=actual;
        }

        fclose(f);
    }

}
void imprimirCapacelera(ESPORTNACIONALITATRESUM actual)
{
    FILE *f=obrirFitxer(UBICACIOFITXRESUMBONIC,"a");
    fseek(f,0,SEEK_END); 
    if (ftell(f)>0) fputc('\n',f);
    fprintf(f,"------------------------\n%s\n------------------\n\t%s %d",actual.esport,actual.nacionalitat,actual.cont);
    fclose(f);
}
void imprimirPaisContador(ESPORTNACIONALITATRESUM actual)
{
    FILE *f=obrirFitxer(UBICACIOFITXRESUMBONIC,"a");
    fprintf(f,"\n\t%s %d",actual.nacionalitat,actual.cont);
    fclose(f);
}