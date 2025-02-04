#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include <stdbool.h> 
#include "rlutil.h"
#include "llibreriaPropia.h"
#include "llibreriaExercici.h"

int main(){
	//1252 coje codigos distintos no como el UTF_8 i akgi asu¡i
	SetConsoleOutputCP(1252);
	SetConsoleCP(1252);
	srand(time(NULL));
	
	char nom[20];
	printf("Introdueix el teu nom: ");
	//scanf("%s",nom); // si tiene espacios no furula

	fgets(nom,20,stdin);// Pilla los espacios y el enter de aceptar si tiene espacio es un scanf de una cadena
	
	printf("\n%d",strlen(nom)-1); // -1 porque coje el \n

	// Esto te quita el \n si te lo ha leeido god
	
	if (strlen(nom)>0 && nom[strlen(nom)-1]=='\n')
	{
		nom[strlen(nom)-1]='\0';
	}
	

	//comparar cadenas Tienes q tenero lo de arriba para que quite el \n porque si no no te lo pilla Para que fulule le tendrias de poner Pedro\n
	if (strcmp(nom,"Pedro")==0)
	{
		printf("Bon dia Pedro");
	}
	else
	{
		printf("No eres pedro");
	}

	// Lo mismo pero no es key sensitive
	if (strcmpi(nom,"Pedro")==0)
	{
		printf("\nBon dia Pedro");
	}
	else
	{
		printf("No eres pedro");
	}	


	// 0== encontrado diferente a 0 (1,-1)==No encontrado
	//<0 == La primera antes en codigo asci ordenar en ascendente
	//>0 == la primera despues en codigo asci ordenar en descendente
	// Mira la primera letra y la q vaya antes en el abc y si es lo mismo mira la siguinte (las minusculas son mejores q las mayus)
	printf("\n%d",strcmp("Pedro","pedro"));
	printf("\n%d",strcmp("pedro","Pedro"));

	//printf("Bon dia %sesto sale abajo por el enter q pilla",nom);


	
	cls();
	char matriu[4][20]={"pedro","avui","fa","bibloteca"};
	for (int i = 0; i < 4; i++)
	{
		printf("%s\n",matriu[i]);
	}
	printf("\n\n");
	ordenarCadenes(matriu, 4);


	for (int i = 0; i < 4; i++)
	{
		printf("%s\n",matriu[i]);
	}
	
	//strcat(nom,matriu[1])// concatenaCadenas
	cls();
	printf("%s",strcat(nom," Garcia"));


//Per a saber la quantitat de files d'una matriu: int files=sizeof(matriu)/sizeof(matriu[0])
//Per a saber la quantitat de columnes d'una matriu:   in col=sizeof(matriu[0])/sizeof(matriu[0][0])

int num=atoi("67");
// pasar un num asci a integrer

	entraCadena(nom,20);

	acabament();
	return 0;
}
