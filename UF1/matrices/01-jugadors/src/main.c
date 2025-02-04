#include <stdio.h>
#include <stdlib.h>
#include <time.h>  
#include <windows.h>
#include <string.h>
#include <stdbool.h>
#include "rlutil.h"
#include "llibreriaPropia.h"
#include "llibreriaExercici.h"
/*1.	(NotaNumericaaLLetres) Fer un programa que demani una nota compresa entre 1 i 10 i
 posteriorment transformi la nota en la seva qualificaci� en lletres. */


int main(){
	SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(CP_UTF8);
	srand(time(NULL));

	/* Jugaran 4 jugadors
	cada jugador tirar�8 numeros aleatoris entre 1 i 88 (sense repeticions)
	genera un numero entre 1 i el 88
	qui �s el jugador que m�s s'apropa a aquest numero*/

	int jug[MAXJUGADOR][MAXTIRADES];
	int num, minim;
	int dist[MAXJUGADOR];

	omplirTirades(jug);
	pintaTirades(jug);
	num=generarNumEntreRang(MINNUM,MAXNUM);
	omplirDistanciaMinima(jug,MAXJUGADOR,dist,num);

	printf("\n\n\nEl Numero es %d \n\n",num);

	pintavector(dist,MAXJUGADOR);
	printf("\n");

	minim=calculaMinim(dist,MAXJUGADOR);
	mostraGuanyador(dist,MAXJUGADOR,minim);

	acabament();
	return 0;
}
