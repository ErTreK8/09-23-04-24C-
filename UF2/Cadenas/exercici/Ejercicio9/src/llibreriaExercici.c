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
    for (int i = 0; i < longitud; i++)
    {
        printf("%c",cadena[i]);
    }
    
}

contaParaules(char cadena[],int longitud,int *palabra)
{
    int contar=0;
    char lletres[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZÀÁÈÉÍÏÒÓÚÜÑÇabcdefghijklmnopqrstuvwxyzàáèéíïòóúüñç";

    for (int i = 0; i < longitud; i++)
    {
        if (cadena[i] != ' ')// eslletra ==true 
        {
            contar++;
        }
        else if((cadena[i] == ' ' && contar > 0))
        {
            (*palabra)++;
            contar= 0;
        }
        
    }

    if (contar > 0)
    {
        (*palabra)++;
    }
    

}