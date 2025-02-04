#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include <stdbool.h> 
#include "rlutil.h"
#include "llibreriaPropia.h"
#include "llibreriaExercici.h"


void pintaArticle(ARTICLE art)
{
    printf("\nNom: %s  Familia: %s  Preu: %.2f",art.nom,art.familia,art.preu);
}

float demanarFloat()
{
    float num;
    scanf("%f",&num);
    return num;
}

void demanarArticle(ARTICLE *art)
{
    // importante el () en el *art porque si no por el . buscaria el ARTICLE *art cosa que no existe y el que existe es el art. entonces el parentesis para q busque bien
    // es lo mismo con el -> y te ahorras el *
    printf("\nIntrodueix el nom del article: ");
	entrarCadena((*art).nom,sizeof((*art).nom));
	printf("Introdueix la familia del article: ");
	entrarCadena(art->familia,sizeof(art->familia));
	printf("Introdueix el preu del article: "); 
	(*art).preu=demanarFloat();
}

ARTICLE demanarArticle2()
{
    ARTICLE nou;

    printf("\nIntrodueix el nom del article: ");
	entrarCadena(nou.nom,sizeof(nou.nom));
	printf("Introdueix la familia del article: ");
	entrarCadena(nou.familia,sizeof(nou.familia));
	printf("Introdueix el preu del article: "); 
	nou.preu=demanarFloat();
    return nou;
}