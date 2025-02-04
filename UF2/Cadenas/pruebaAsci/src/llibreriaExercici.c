#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "rlutil.h"
#include "llibreriaPropia.h"
#include "llibreriaExercici.h"

void separa(char cadena[], int longitud)
{
    int i = 0;
    while (i < longitud && cadena[i] != '\0')
    {
        // es el caracter una consonant, una vocal o un digit?
        printf("&c: ", cadena[i]);
        if (esVocal(cadena[i]))
        {
            printf("vocal");
        }
        else if (esConsonant(cadena[i]))
        {
            printf("consonant");
        }
        else if (esDigit(cadena[i]))
        {
            printf("es digit");
        }
        else
        {
            printf("no es res");
        }
    }
}

bool esVocal(char car)
{
    char vocals[] = "AEIOUÀÁÈÉÍÏÒÓÚÜaeiouàáèéíïòóúü";
    int i = 0;
    bool trobat = false;
    while (i < strlen(vocals) && !trobat)
    {
        if (vocals[i] == car)
        {
            trobat = true;
        }
        else
        {
            i++;
        }
    }
    return trobat;
}

bool esConsonant(char car)
{
    char lletres[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZÀÁÈÉÍÏÒÓÚÜÑÇabcdefghijklmnopqrstuvwxyzàáèéíïòóúüñç";
    int i = 0;
    bool trobat = false;
    if (!esVocal(car))
    {
        trobat = false;
        while (i < strlen(lletres) && !trobat)
    {
        if (lletres[i] == car)
        {
            trobat = true;
        }
        else
        {
            i++;
        }
    }
    }
    return trobat;
}


bool esDIgit(char car)
{
    
    return(car>='0' && car<='9');
}