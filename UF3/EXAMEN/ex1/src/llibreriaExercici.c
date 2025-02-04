#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include <stdbool.h> 
#include "rlutil.h"
#include "llibreriaPropia.h"
#include "llibreriaExercici.h"


void llegirFitxer(char fitxer[])
{
    // declarem Variables y abrimos fichero
    FILE *f=obrirFitxer(UBICACIOFITXERORIGEN,"r");
    MALALTIA un;
    SIMPTOMA simptoma;
    if(f!=NULL)
    {
        // Bucle Principal
        while(feof(f)==0)
        {
            // Cojemos malaltia
            un=agafaMalaltia(f);
            // copiamos el nombre de la malaltia a la struc de simptoma
            strcpy(simptoma.malaltia,un.malaltia);
            // bucle de cojer simptomas que dura lo q tenga de numero
            for (int i = 0; i < un.qttSimpto; i++)
            {
                // cojer simptoma
                agafaSimptoma(f,simptoma.simptoma);
                // escribir en el fichero
                escriu(simptoma);
                escriuBarres();
            }
            // saltarse la linea de las barras
            saltaLinea(f);
        }
    }
    // cerrar ficheros
    fclose(f);
}

void saltaLinea(FILE *f)
{
    // esto se salta una linea y si se sale del fichero para tmb
    char caracter='a';
    while(caracter!='\n' && feof(f)==0)
    {
        caracter=fgetc(f);
    }
}


MALALTIA agafaMalaltia(FILE *f)
{
    // lee malaltia
    MALALTIA un;
    fgets(un.malaltia,sizeof(un.malaltia),f);
    eliminaSaltLinia(un.malaltia);
 
    // lee qtt Simptomas
    fscanf(f,"%d",&un.qttSimpto);
    // se salta el \n
    fseek(f,2,SEEK_CUR);
    fflush(f);
    return un;
}

void agafaSimptoma(FILE *f,char simptoma[])
{
    // coje un simptoma y lo del 30 es eso q no has explicao
    fgets(simptoma,30,f);
    eliminaSaltLinia(simptoma);
}

void escriu(SIMPTOMA simptoma)
{

    bool existeixFichero;
    FILE *f;
    
    // Comprueba si existe el fichero y si es asi lo abre en modo actualizar, si no, lo crea. Tmb se dirije al final del fichero
    existeixFichero=existeixFitxer(UBICACIOFITXRESUM);
    if(existeixFichero==false) f=obrirFitxer(UBICACIOFITXRESUM,"w");
    else f=obrirFitxer(UBICACIOFITXRESUM,"a");
    fseek(f,0,SEEK_END);

    // si el fichero existe pone un \n y escribe, si no, simplemente escribe
    if(existeixFichero==true) fprintf(f,"\n%s",simptoma.malaltia);
    else fprintf(f,"%s",simptoma.malaltia);
    fprintf(f,"\n%s",simptoma.simptoma);
    fclose(f);
}

void escriuBarres()
{
    // ya lo dice el nombre de la funcion no? xdd
    FILE *f=obrirFitxer(UBICACIOFITXRESUM,"a");
    fseek(f,0,SEEK_END);
    fprintf(f,"\n----------"); 
    fclose(f);
}