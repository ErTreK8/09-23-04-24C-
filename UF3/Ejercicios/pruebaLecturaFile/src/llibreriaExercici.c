#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include <stdbool.h> 
#include "rlutil.h"
#include "llibreriaPropia.h"
#include "llibreriaExercici.h"



void crear(const char fitxer[])
{
    FILE *f=obrirFitxer(fitxer,"w");
    if (f!=NULL)
    {
        // si pones         fprintf(f,"pep antoni\nguardiola\n52\nmario\nruiz\n18");
        // se bugea y pilla antoni como apellido porque los espacios los detecta como \n

        // los \n los lee como 1 caracter (al escribirlo te lo escribe como 2)
        fprintf(f,"abce\ndefg hijk\nlmnopq");
        fclose(f);
    }
}

void llegir(const char fitxer[])
{

    FILE *f=obrirFitxer(fitxer,"r");
    //ALUMNE un;
    char cadena[40];
    // al ser una cadena de 4 espacios lee 3 porque siempre deja 1 espacio para el \0 entonces pone la e bajo 1 seria: 1)abc\n 2)e\n 3)def...
    
    // si la haces grande la cadena para en el \n y luego vuelve a correr y pilla solo el \n y asi hasta q acaba seria: 1)abce\n 2)defg hijk\n  3)lmopq
    if (f!=NULL)
    {
        // el feof si esta en el fichero hace pone un 0 si no pone un 1 o un -1
        // while (feof(f)==0)
        // {
        //     un=llegirAlumneFitxer(f);
        //     pintaALumne(un);
        // }
        
        
        // lee el salto de linea 
        while (feof(f)==0)
        {
            fgets(cadena,sizeof(cadena),f);
            eliminaSaltLinia(cadena);
            printf("\n%s",cadena);
            printf("Feof: %d\n", feof(f)); // en el final no habra \n porque en el fichero no hay entonces no lo coje
            // si se queda sin nada el fichero porque se ha leido entero printara lo ultimo que ha leido y no te modificara la cadena
        }
        fclose(f);
    }

}
// el feof si esta en el fichero hace pone un 0 si no pone un 1 o un -1

void eliminaSaltLinia(char cadena[])
{
    if (strlen(cadena)>0 && cadena[strlen(cadena)-1]=='\n')
    {
        cadena[strlen(cadena)-1]='\0';
    }
    
}

void cojeCadenaFichero(FILE *f, char cadena[])
{
    int i=0;
    while (feof(f)==0)
    {
        cadena[i]=fgetc(f);
        i++;
    }
    cadena[i]='\0';
}

void cojeCadenaSimboloFichero(FILE *f, char cadena[], char simbolo)
{
    char caracter=1;
    int i=0;
    while (feof(f)==0 && caracter!=simbolo)
    {
        cadena[i]=fgetc(f);
        caracter=cadena[i];
        i++;
    }
    cadena[i]='\0';
}

ALUMNE llegirAlumneFitxer(FILE *f)
{
    ALUMNE un;
    // el fscanf pilla toda la linea tmb se para si encuentra un espacio
    printf("%d \n",fscanf(f,"%s %s %d",un.nom, un.cognom, &un.edat)); // se pone el & por que es como un scanf("%d";&edad);
    // lee cantidad de variables



    // char cadena[3]
    //fscanf(f,"%s %s %d",un.nom, un.cognom, cadena))
    // un.edad=atoi(cadena);
    // si haces esto siempre es una cadena
    return un;
}

void pintaALumne(ALUMNE un)
{
    printf("Nom: %s  Cognom: %s  Edad: %d\n",un.nom,un.cognom,un.edat);
}



