#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "rlutil.h"
#include "llibreriaPropia.h"
#include "llibreriaExercici.h"



void separarVocalsConsonants(char frase[],char VocalsFrase[],char ConsonantsFrase[],int longitud)
{
    char lletres[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZÀÁÈÉÍÏÒÓÚÜÑÇabcdefghijklmnopqrstuvwxyzàáèéíïòóúüñç";
    char vocals[] = "AEIOUÀÁÈÉÍÏÒÓÚÜaeiouàáèéíïòóúü";


    int i = 0;

    while (i < longitud && frase[i] != '\0')
    {
      
        
            if(cercaLletra(vocals,strlen(vocals),frase[i]) == true && frase[i] != ' ')
            {
                int j = 0;
                while (VocalsFrase[j] != 0)
                {
                    j++;
                }
                VocalsFrase[j] = frase[i];
            }
            else if( frase[i] != ' ')
            {
                int y = 0;
                while (ConsonantsFrase[y] != 0)
                {
                    y++;
                }
                ConsonantsFrase[y] = frase[i];
            }
        
        i++;
        
    }
    


}

 bool cercaLletra(char vocals[],int longitud,char lletra)
 {
    bool trobat=false;
    int i=0;

    while (i<longitud && trobat==false)
    {
        if (vocals[i]==lletra) trobat=true;
        else i++;
    }

    return trobat;
 }