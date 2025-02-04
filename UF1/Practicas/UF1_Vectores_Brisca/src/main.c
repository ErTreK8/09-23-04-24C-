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

	//Vector Baraja
	int vectorCartes[MAXVECTORCARTES];
	int qttCartesTotals=1;
	//Vector Cartas Que tiene el Jugador 1
	int vectorCartesJugador1[MAXVECTORJUGADORS];
	int qttCartesJugador1=0;

	//Vector Cartas Que tiene el Jugador 2
	int vectorCartesJugador2[MAXVECTORJUGADORS];
	int qttCartesJugador2=0;
	
	//Cartas que ha ganado el jugador 1
	int vectorCartesGuanyadesJugador1[MAXVECTORCARTESGUANYADES];
	int qttCartesGuanyadesJugador1=0;
	
	//Cartas que ha ganado el jugador 2
	int vectorCartesGuanyadesJugador2[MAXVECTORCARTESGUANYADES];
	int qttCartesGuanyadesJugador2=0;
	
	//Palo Ganador y tabla de puntuaciones
	int cartaPalGuanyador=0, numeroCartaPalGuanyador=0;
	char palGuanyador;
	int puntsJugador1=0, puntsJugador2=0, puntosCarta=0;

	//BOOL de saber quien tira
	bool jugador1Primer=true;
	
	//Variables de carta jugada por el jugador 1
	int numeroCartaJugador1, numero1;
	char paloCartajugador1;
	
	//Variables de carta jugada por el jugador 2
	int numeroCartaJugador2, numero2;
	char paloCartajugador2;

	bool acabar=false;




	//Rellena la Baraja y pinta el vector de la baraja (Falta hacer el print vonito) (tmb pinta el qtt para ver si esta bien)
	rellenarBaraja(vectorCartes,&qttCartesTotals);
	getch();
	//Pinta la barralla inicial
	printf("BARALLA:\n");
	pintaVectorHorizontal(vectorCartes,qttCartesTotals);
	//Reparte las Cartas Al Jugador 1
	repartirCartasJugadrors(vectorCartesJugador1,MAXVECTORJUGADORS,&qttCartesJugador1,vectorCartes,&qttCartesTotals);
	//Reparte las Cartas Al Jugador 2
	repartirCartasJugadrors(vectorCartesJugador2,MAXVECTORJUGADORS,&qttCartesJugador2,vectorCartes,&qttCartesTotals);
	printf("\nS'HAN REPARTIT 6 CARTES DE LA BARRALLA, 3 A CADA UN DELS JUGADORS\n\n");
	//Consigue carta del palo Ganador Codificada y sin codificar
	cartaPalGuanyador = sacarCartaAletoriaBaraja(vectorCartes,&qttCartesTotals);
	decodificarCarta(&numeroCartaPalGuanyador,&palGuanyador,cartaPalGuanyador);
	printf("S'HA TRET LA CARTA DEL PAL GUANYADOR\n");
	
	while (acabar==false)
	{
		//Printa inicial de ronda
		printf("PAL GUANYADOR %c i la carta: %d%c\n\n",palGuanyador,numeroCartaPalGuanyador,palGuanyador);
		printf("BARALLA:\n");
		pintaVectorHorizontal(vectorCartes,qttCartesTotals);
		printf("\n\n\n");

		//Elejir quien va primero por un bool y asi  poder printar su vector y escojer carta el jugador indicado
		if (jugador1Primer==true)
		{
			printf("Escull carta JUGADOR 1:\n          Les teves cartes son: ");
			//Funcion q pinta el vector del jugador
			pintaJugadorCartes(vectorCartesJugador1,qttCartesJugador1);
			printf("\n          ");
			//Funcion para que el jugador tire la carta con sus do whiles para q no se repita y que la tenga cojida etc
			tirarCartaJugador(&numero1,&paloCartajugador1,&numeroCartaJugador1, vectorCartesJugador1, qttCartesJugador1);

			//Lo mismo que arriba pero del jugador 2
			printf("\n\nEscull carta JUGADOR 2:\n          Les teves cartes son: ");
			pintaJugadorCartes(vectorCartesJugador2,qttCartesJugador2);
			printf("\n          ");
			tirarCartaJugador(&numero2,&paloCartajugador2,&numeroCartaJugador2, vectorCartesJugador2, qttCartesJugador2);
		}
		else
		{
			//Lo mismo que arriba pero si sale primero el jugador 2
			printf("Escull carta JUGADOR 2:\n          Les teves cartes son: ");
			pintaJugadorCartes(vectorCartesJugador2,qttCartesJugador2);
			printf("\n          ");
			tirarCartaJugador(&numero2,&paloCartajugador2,&numeroCartaJugador2, vectorCartesJugador2, qttCartesJugador2);

			printf("\n\nEscull carta JUGADOR 1:\n          Les teves cartes son: ");
			pintaJugadorCartes(vectorCartesJugador1,qttCartesJugador1);
			printf("\n          ");
			tirarCartaJugador(&numero1,&paloCartajugador1,&numeroCartaJugador1, vectorCartesJugador1, qttCartesJugador1);
		}
		//Reglas de la ronda de saber quien gana (Esta funcion principalmente cambia el bool de quien sale primero)
		guanyadorRonda(&jugador1Primer,numero1,paloCartajugador1,numeroCartaJugador1,numero2,paloCartajugador2,numeroCartaJugador2,palGuanyador);
		//Mover las cartas que se han tirado a los vectores de cartas ganadas y darle los puntos a los jugadores 
		cartasRondaEnGanadoras(jugador1Primer,&puntsJugador1,&puntsJugador2,vectorCartesGuanyadesJugador1,&qttCartesGuanyadesJugador1,vectorCartesGuanyadesJugador2,&qttCartesGuanyadesJugador2,&numeroCartaJugador1,&numeroCartaJugador2,numero1,numero2);
		quitarCartaJugadores(vectorCartesJugador1,vectorCartesJugador2,&qttCartesJugador1,&qttCartesJugador2,&numero1,&numero2);
		//Restar cantidad de cartas
		qttCartesJugador1--;
		qttCartesJugador2--;
		//si solo queda 1 carta que robe la del mazo y la del palo ganador
		if (qttCartesTotals==1)
		{
			if (jugador1Primer==true)
			{
				vectorCartesJugador1[qttCartesJugador1]=sacarCartaAletoriaBaraja(vectorCartes, &qttCartesTotals);
				qttCartesJugador1++;
				vectorCartesJugador2[qttCartesJugador2]=cartaPalGuanyador;
				qttCartesJugador2++;	
			}
			else if (jugador1Primer==false)
			{
				vectorCartesJugador2[qttCartesJugador2]=sacarCartaAletoriaBaraja(vectorCartes, &qttCartesTotals);
				qttCartesJugador2++;
				vectorCartesJugador1[qttCartesJugador1]=cartaPalGuanyador;
				qttCartesJugador1++;
			}	
		}
		//si hay mas de 1 carta que robe de normal
		else if (qttCartesTotals>1)
		{
			if (jugador1Primer==true)
			{
				vectorCartesJugador1[qttCartesJugador1]=sacarCartaAletoriaBaraja(vectorCartes, &qttCartesTotals);
				qttCartesJugador1++;
				vectorCartesJugador2[qttCartesJugador2]=sacarCartaAletoriaBaraja(vectorCartes, &qttCartesTotals);
				qttCartesJugador2++;	
			}
			else if (jugador1Primer==false)
			{
				vectorCartesJugador2[qttCartesJugador2]=sacarCartaAletoriaBaraja(vectorCartes, &qttCartesTotals);
				qttCartesJugador2++;
				vectorCartesJugador1[qttCartesJugador1]=sacarCartaAletoriaBaraja(vectorCartes, &qttCartesTotals);
				qttCartesJugador1++;
			}		
		}
		//Si no hay cartas pues no puede robar xd

		printf("\n\nResum Ronda\n\n");
		if (jugador1Primer==true)
		{
			printf("Ha guanyat el Jugador 1");
		}
		else
		{
			printf("Ha guanyat el Jugador 2");
		}

		printf("Punts Jugador 1: %d          Punts Jugador 2: %d\n\n", puntsJugador1,puntsJugador2);

		//Acabar Bucle		
		if (qttCartesJugador1==0 && qttCartesJugador2==0)
		{
			acabar=true;
		}
		cls();
	}

	printf("PAL GUANYADOR %c i la carta: %d%c\n\n",palGuanyador,numeroCartaPalGuanyador,palGuanyador);
	if (puntsJugador1>puntsJugador2)
	{
		printf("Felicitats Jugador 1 Has Guanyat :)\n");
	}
	else
	{
		printf("Felicitats Jugador 2 Has Guanyat :)\n");
	}
	printf("Punts Jugador 1: %d          Punts Jugador 2: %d\n\n", puntsJugador1,puntsJugador2);
	


	acabament();
	return 0;
}
