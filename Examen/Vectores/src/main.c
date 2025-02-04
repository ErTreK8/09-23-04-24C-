#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include <stdbool.h> 
#include "rlutil.h"
#include "llibreriaPropia.h"
#include "llibreriaExercici.h"

int main(){
	SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(CP_UTF8);
	srand(time(NULL));

	/*
	Funciones: Busca Posicion Al Reves para el 5,
	CaseSpecial si es 5 que lo aparte un momento del vector y vuelva a buscar etc;
	MueveDelVectorAPareja,
	*/


	// Vector de los numeros (Se inicializa el vector abajo cuando maxVNumeros tiene un valor asignado)
	int maxVNumeros;
	int qttVNumeros=0;

	// Vector contador para contar numero repetidos y que no se repitan 
	int vRepetidos[MAXVECTOREPETIDO]={0};
	int qttVRepetidos=MAXVECTOREPETIDO;

	// Vector para guardar las parejas y asi poder luego imprimirlas y contarlas etc
	int vParejas[MAXVECTORPAREJAS];
	int qttVParejas=0;

	// Variables jugador
	int numero1, numero2;

	// Variable bucle
	int final=0;
	bool esta=false, hay10=false;
	int contRonda=0;


// ------- Inici Programa ---------------------
	printf("Presiona Enter Per Començar");
	getch();
	cls();
	// Pedimos un numero para el vector controlado entre 2 y 20 y que parejo
	maxVNumeros=numeroDeNumeros();
	// Inicializamos el Vector
	int vNumeros[maxVNumeros];
	setColor(WHITE);
	ompleVectorNumeros(vNumeros, &qttVNumeros, maxVNumeros, vRepetidos,qttVRepetidos);
	while (final==0)
	{
		hay10=comprovarHiHa10(vNumeros,qttVNumeros);
		if (hay10==true)
		{
			printaInci(vNumeros,qttVNumeros);
			
			printf("Introdueix el Primer Numero [0..10]: ");
			numero1=demanarNumeroMinMax(0,10);
			printf("Introdueix el Segon Numero [0..10]: ");
			numero2=demanarNumeroMinMax(0,10);


			comprovarNumeros(numero1,numero2,&esta,vNumeros,qttVNumeros,&final);
			
			if (final==0)
			{
				rellenaParejas(numero1,numero2,vParejas,qttVParejas);
				
				eliminaVector(vNumeros,&qttVNumeros,numero1,numero2);
				qttVNumeros=qttVNumeros-2;
			}			
		}
		else if (hay10==false && contRonda!=0)
		{
			final=5;
		}
		else
		{
			final=4;
		}
		if (hay10==true)
		{
			printf("\n\n Se ha eliminado la siguiente pareja [ %d - %d ]\n\n", numero1,numero2);
			printf("Prem una Tecla per anar a la Seguent Ronda");
			getch();
			cls();
		}
		contRonda++;
	}

	// Final=1 es que los numeros puestos por el usuario no dan 10
	// Final=2 es que el numero 1 no esta en el vector
	// Final=3 es que el Numero 2 no esta en el Vector
	// Final=4 es que no quedan sumas que den 10
	// Final=5 Has ganado el Juego
	
	printf("Joc Finalitzat\n");
	switch (final)
	{
	case 1:
		setColor(RED);
		printf("Cal que Continuis Practicant ja que t'has equivocat\n\n");
		pintaFinal(vNumeros,qttVNumeros,vParejas,qttVParejas);
		break;
	case 2:
		setColor(RED);
		printf("El Primer Numero no esta dins del Vector\n\n");
		pintaFinal(vNumeros,qttVNumeros,vParejas,qttVParejas);
		break;
	case 3:
		setColor(RED);
		printf("El Segon Numero no esta dins del Vector\n\n");
		pintaFinal(vNumeros,qttVNumeros,vParejas,qttVParejas);
		break;
	case 4:
		setColor(RED);
		printf("El Vector S'ha Generat Sense Numeros que Sumin 10 :O\n\n");
		pintaFinal(vNumeros,qttVNumeros,vParejas,qttVParejas);
		break;
	case 5:
		setColor(GREEN);
		printf("ETS UN CRAC HAS TORBAT TOTS ELS GRUPS QUE SUMEN 10\n\n");
		pintaFinal(vNumeros,qttVNumeros,vParejas,qttVParejas);
		break;
	default:
		break;
	}

	

	acabament();
	return 0;
}
