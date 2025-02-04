#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "rlutil.h"
#include "llibreriaPropia.h"
#include "llibreriaExercici.h"

void passarMajuscula(char cadena[], int longitud)
{
    int i = 0;
    while (i < longitud && cadena[i] != '\0')
    {

        if (cadena[i] >= 'a' && cadena[i] <= 'z')
        {
            cadena[i] = cadena[i] - ('a' - 'A');
        }
        i++;
    }
}

void pintaCadena(char cadena[], int longitud)
{
    int i = 0;
    while (i < longitud && cadena[i] != '\0')
    {
        printf("%c", cadena[i]);
        i++;
    }
}

int calculaPosicioMinuscula(char car)
{
    char lletresm[] = "abcdefghijklmnopqrstuvwxyzàáèéíïíòóúüñç";
    int i = 0, pos = -1;
    while (i < strlen(lletresm) && pos == -1)
    {
        if (car == lletresm[i])
        {
            pos = i;
        }
        else
        {
            pos = -1;
        }
        i++;
    }
    return pos;
}

char passaCarMajus(char car)
{
    char lletresM[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZÀÁÈÉÍÏÍÒÓÚÜÑÇ";

    int pos = calculaPosicioMinuscula(car);
    if (pos > -1)
    {
        car = lletresM[pos];
    }
    return car;
}

void passarMajuscula2(char cadena[], int longitud)
{
    int i = 0;
    while (i < longitud && cadena[i] != '\0')
    {
        cadena[i] = passaCarMajus(cadena[i]);
        i++;
    }
}

void eliminaEspaiDarrera(char cadena[], int longitud)
{
    int cont = 0;
    while (cont < longitud && cadena[cont] == ' ')
    {
        cont++;
    }
    for (int i = 0; i <= longitud - cont; i++)
    {
        cadena[i] = cadena[i + cont];
    }
}

int eliminarEspaisDavant(char cadena[], int longitud)
{
    int cont = 0;

    while (cont < longitud && cadena[cont] == ' ')
    {
        cont++;
    }
    for (int i = cont; i <= longitud; i++)
    {
        cadena[i - cont] = cadena[i];
    }
    longitud -= cont;
    return longitud;
}

void adeuEspai(char cadena[], int longitud)
{
    int i = 0;
    int j = i;
    int cont;
    while (i < longitud && cadena[i] != '\0')
    {
        if (i == 0)
        {
            if (cadena[i] == ' ')
            {
                j = i;
                while (j < longitud && cadena[j] == ' ')
                {
                    j++;
                }
                cont = j - i;
                int h = i;
                while (cadena[h] != '\0')
                {
                    cadena[h] = cadena[h + cont];
                    h++;
                }
            }
            i++;
        }
        else
        {
            if (cadena[i] == ' ')
            {
                j = i;
                while (j < longitud && cadena[j] == ' ')
                {
                    j++;
                }
                cont = j - i - 1;
                int h = i;
                while (cadena[h] != '\0')
                {
                    cadena[h] = cadena[h + cont];
                    h++;
                }
            }
            i++;
        }
    }
    int contador2=strlen(cadena)-1;
    char a=cadena[contador2];
    while (cadena[contador2]==' ')
    {
        cadena[contador2]=cadena[contador2+1];
        contador2--;
    }
}