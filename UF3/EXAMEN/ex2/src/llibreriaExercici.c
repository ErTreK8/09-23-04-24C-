#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include <stdbool.h> 
#include "rlutil.h"
#include "llibreriaPropia.h"
#include "llibreriaExercici.h"


void copiaArixu(char fitxerOriginal[],char fitxerCopia[])
{   
    // hace una copia del fichero original
    FILE *f=obrirFitxer(fitxerOriginal,"r");
    FILE *a=obrirFitxer(fitxerCopia,"w");
    
    char cadena[255];
    while (feof(f)==0)
    {
        fgets(cadena,sizeof(cadena),f);
        cadena[sizeof(cadena)]='\0';
        fprintf(a,"%s",cadena);
    }
    fclose(f);
    fclose(a);
}

void llegirFitxer(char fitxer[])
{
    // declaramos variables y abrimos fichero copia
    FILE *z=obrirFitxer(UBICACIOFITXERORIGENCOPIA,"r");
    VENTA un;
    PRODUCTE prod;
    bool existeix=false;
    saltaLinea(z);
    if(z!=NULL)
    {
        // bucle principal (el del fichero de copia)
        while(feof(z)==0)
        {
            // cojemos una venta
            un=agafaVenta(z);
            // mira si existe el producto en el fichero de resum
            existeix=existeixProducte(un.nomProducte);
            if (existeix==false)
            {
                // si no existe este producte entramos en el bucle y abrimos el fichero original
                FILE *f;
                f=obrirFitxer(fitxer,"r");
                // copiamos el nombre del producta y inicializamos la variable de ganancia total a 0
                strcpy(prod.nomProducte,un.nomProducte);
                prod.gananciaTotal=0;
                // nos saltamos la linea de arriba que es la leyenda
                saltaLinea(f);
                //segundo bucle (el del fichero original)
                while(feof(f)==0)
                {
                    // cojemos una venta
                    un=agafaVenta(f);
                    // si el nombre del producto y el de la venta es el mismo coje la qtt vendida y su precio lo multiplica y lo suma a la ganancia total
                    if(strcmp(un.nomProducte,prod.nomProducte)==0)
                    {
                        prod.gananciaTotal=prod.gananciaTotal+(un.preu*un.qttVenut);
                    }
                }
                // escribe en el fichero de resumen
                escriu(prod);
                // cerra el fichero
                fclose(f);
            }
        }
    }
    fclose(z);

}


void saltaLinea(FILE *f)
{
    char caracter='a';
    while(caracter!='\n' && feof(f)==0)
    {
        caracter=fgetc(f);
    }
}

VENTA agafaVenta(FILE *f)
{
    // inicializamos variables
    VENTA un;
    char caracter;
    int i=0;
    // cojemos idVenta
    do
    {
        caracter=fgetc(f);
        if (caracter!=',')
        {
            un.IDventa[i]=caracter;
            i++;
        }
    } while (caracter!=',');
    un.IDventa[i]='\0';
    i=0;
    fflush(f);
    // el fflush esta por si acaso no me acuerdo ni lo que hace pero como funcia no me quejo

    // cojemos el nombre del producto
    do
    {
        caracter=fgetc(f);
        if (caracter!=',')
        {
            un.nomProducte[i]=caracter;
            i++;
        }
    } while (caracter!=',');
    un.nomProducte[i]='\0';

    // cojemos la qttVenut y saltamos 1 caracter para saltarnos la coma
    fscanf(f,"%d",&un.qttVenut);
    fflush(f);
    fseek(f,1,SEEK_CUR);

    // aqui lo mismo pero con el precio
    fscanf(f,"%f",&un.preu);
    fseek(f,1,SEEK_CUR);
    for (int i = 0; i < 10; i++)
    {
        if(feof(f)==0) un.fehca[i]=fgetc(f);
    }
    fgetc(f);

    return un;
}


bool existeixProducte(char producte[])
{
    // abrimos archivo y inicializamos variables
    FILE *a=obrirFitxer(UBICACIOFITXRESUM,"r");
    bool existeix=false;
    char producteBusca[35];
    // miramos si el fichero esta lleno o vacio y si existe o no con lo mismo
    if(a!=NULL)
    {
        // saltamos la liena de resum vendes:
        saltaLinea(a);
        while(feof(a)==0 && existeix==false)
        {
            // cojemos el producto del resumen y saltamos hasta la siguiente linea pasando del precio
            cojeProducteResum(a,producteBusca);
            // si esta en el fichero exiteix es true
            if (strcmp(producte,producteBusca)==0)
            {
                existeix=true;
            }
        }
    }
    fclose(a);
    return existeix;
}

void cojeProducteResum(FILE *f,char producte[])
{
    // inicializamos variables
    char caracter;
    int i=0;
    // cojemos el nombre del producto
    do
    {
        caracter=fgetc(f);
        if (caracter!=':')
        {
            producte[i]=caracter;
            i++;
        }
    }
    while(caracter!=':' && feof(f)==0);
    producte[i]='\0';
    // tenia una cosa fea aqui y lo he arreglado para q no te de toc denada caludina xd 
    saltaLinea(f);
}



void escriu(PRODUCTE prod)
{
    // esto es casi que igual que el del ejercicio anterior 
    bool existeixFichero;
    FILE *a;
    existeixFichero=existeixFitxer(UBICACIOFITXRESUM);
    if(existeixFichero==false) a=obrirFitxer(UBICACIOFITXRESUM,"w");
    else a=obrirFitxer(UBICACIOFITXRESUM,"a");
    fseek(a,0,SEEK_END);


    if(existeixFichero==false) fprintf(a,"RESUM VENDES:");
    fprintf(a,"\n%s: %.2f",prod.nomProducte,prod.gananciaTotal);  
    fclose(a);
}

void llegirFinal(char fitxer[])
{
    //lee el fichero de resumen y lo escribe por pantalla.
    FILE *f=obrirFitxer(fitxer,"r");
    char cadena[255];
    if (f!=NULL)
    {
        printf("\n\n");
        setColor(GREEN);
        while (feof(f)==0)
        {
            fgets(cadena,sizeof(cadena),f);
            printf("%s",cadena);
        }
        setColor(WHITE);
    }
    else
    {
        printf("El fitxer No existeix o es buit");
    }
    fclose(f);
// }