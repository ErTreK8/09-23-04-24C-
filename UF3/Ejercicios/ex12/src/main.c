#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include <stdbool.h> 
#include "rlutil.h"
#include "llibreriaPropia.h"
#include "llibreriaExercici.h"

int main(){
	//1252 coje codigos distintos no como el UTF_8 i akgi asuÂ¡i
	SetConsoleOutputCP(1252);
	SetConsoleCP(1252);
	srand(time(NULL));
	const char fitxer1[]="./fitxers/respostes_alumne.txt";
	const char fitxer2[]="./fitxers/respostes_ok.txt";

	int contador[3]={0}; // 0 es Cert, 1 es False, 2 es blanc
	int qttPreguntas;
	int opcio;
	float puntuacioTotal;
	printf("Cuantas preguntas tiene el examen? ");
	qttPreguntas=demanarNumeroMinMax(1,20);

	
	creaArxiuCorrecte(qttPreguntas);
	do
		{
			cls();
			opcio = preguntaOpcio();
			switch (opcio)
				{
				case AFEGIR:
					responAlumne(qttPreguntas,fitxer1);
					break;
				case MOSTRAR:
					mostrar(fitxer1);
					// lee el fichero del alumno y enseña todas las respuestas (cada printf son 2 lineas q cojer[fgets de la linea])
					break;
				case SORTIR:
					if (existeixFitxer(fitxer1)==true)
					{
						contadores(contador,fitxer1,fitxer2,qttPreguntas);
						// busca falladas y no contestadas y ciertas
						puntuacioTotal=calcula(contador,qttPreguntas);
						// calcula Nota sobre numPreguntes
						cls();
						printf("Has Contestat correctament %d Preguntes\nHas constestat Malament %d Preguntes\nNo has contestad %d Preguntes\n",contador[0],contador[1],contador[3]);
						printf("La Nota ha sigut de %.2f",puntuacioTotal);
					}
					break;
				}		
		} while (opcio != SORTIR);
	

	acabament();
	return 0;
}
