#include <stdio.h>
#include <stdlib.h>
#include <time.h>  
#include <windows.h>
#include <string.h>
#include <stdbool.h>
#include "rlutil.h"
#include "llibreriaPropia.h"
#include "llibreriaExercici.h"

printCadena(char cadena[],int longitud)
{
    int i = 0;

    while (i < longitud && cadena[i] != '\0')
    {
        printf("%c",cadena[i]);
        i++;
    }
    
}

bool compararCadenes(char cadena1[],char cadena2[],int longitud )
{
    int i = 0;
    int vegades = 0;
    bool te = false;
    while (i < longitud && cadena2[i] != '\0')
    {
        if (cadena2[i] == cadena1[i])
        {
            vegades++;   
        }
        i++;
    }

    if (vegades == strlen(cadena1) && strlen(cadena2) == strlen(cadena1))
    {
        te = true;
    }
    else 
    {
        te = false;
    }
    
    return te;

}