#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include <stdbool.h> 
#include "rlutil.h"
#include "llibreriaPropia.h"
#include "llibreriaExercici.h"

int main(){
	SetConsoleTitle("Joc del Tresor");
	SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(CP_UTF8);
	srand(time(NULL));

	//Definimos Variables
	int RandomizadorX=0, RandomizadorY=0, X=1, Y=1, UsuariX=0, UsuariY=0, FinalCasos=0, Partida=1, ContadorSalir=0;
	float Import = 0.00;
	bool bucle=false;
	//Do While para preguntarle el importe inicial entre 10 y 200 Euros
	do
	{
		printf("Introdueix el Import amb el que Jugaras:(10-200): ");
		scanf("%f",&Import);
	} while (Import<10 || Import>200);
	getch();
	cls();
	//Randomizador Tesoro X
	RandomizadorX=rand()%(75-1+1)+1;
	//Randomizador Tesoro Y
	RandomizadorY=rand()%(15-1+1)+1;
	//Igualamos Las cordenadas del Gotoxy a las del Randomizador
	X=RandomizadorX;
	Y=RandomizadorY;
	//Hacer Cuadrado Verde Tesoro que cada 5 Prints de verde a la izquierda baje 1 liniea y se vuelva a igualar con la X inicial del Randomizador
	for (int i = 0; i != 5; i++)
	{
		for (int f = 0; f != 5; f++)
		{
			gotoxy(X,Y);
			setBackgroundColor(LIGHTGREEN);
			printf(" ");
			X++;
		}
		X=RandomizadorX;
		Y++;
	}
	//Temporizador de 500 milisegundos, cambiar Color del fondo a ninguno y limpiar pantalla
	Sleep(500);
	setBackgroundColor(0);
	cls();
	//For que vaya sumando +1 a la variable Partida y que se rompe cuando bucle == false
	while(bucle==false)
	{
		Partida = 1;
		//Poner COlor Cyan y escribir la primera linea y luego volver a poner el color en Blanco
		setColor(CYAN);
		printf("PARTIDA: %d Import Inicial Partida: %.2f", Partida, Import);
		setColor(7);
		//Do While que controla que las cordenadas introducidas por el usuario sean la X entre 1-80 y la Y entre 1-20
		do
		{
			printf("\nJugador Introdueix les coordenades del tresor (1..80 / 1..20): ");
			while(getchar()!='\n');
			scanf("%d %d", &UsuariX, &UsuariY);
		} while (UsuariX<=0 || UsuariX>80 || UsuariY<=0 || UsuariY>20);
		//Si La X es Mas pequeña que diga tal, Si es mas grande +5 Que diga tal, Si esta entremedias que diga tal y sume 1 al valor que si es 2 se sale del bucle
		if (UsuariX<RandomizadorX)
		{
			printf("La X del Tresor es mes Gran\n");
		}
		else if (UsuariX>RandomizadorX+5)
		{
			printf("La X del Tresor es mes Petita\n");
		}
		//Si la X esta en el punto de tesoro que mire si la Y tambien esta para saber si imprimir el texto o no
		else
		{
			if (UsuariY>RandomizadorY+5 || UsuariY<RandomizadorY)
			{
				printf("La X Esta en el Tresor\n");
			}			
			ContadorSalir++;
		}
		//Si La Y es Mas pequeña que diga tal, Si es mas grande +5 Que diga tal, Si esta entremedias que diga tal y sume 1 al valor que si es 2 se sale del bucle
		if (UsuariY<RandomizadorY)
		{
			printf("La Y del Tresor es mes Gran\n");
		}
		else if (UsuariY>RandomizadorY+5)
		{
			printf("La Y del Tresor es mes Petita\n");
		}
		// Si la Y esta en el punto de tesoro comprueba si la X tambien esta antes de escribir el texto, si esta haz un salto de linea
		else
		{
			if (ContadorSalir!=1)
			{
				printf("La Y Esta en el Tresor\n");
			}
			else
			{
				printf("\n");
			}
			ContadorSalir++;
		}
		//Si el Contador salir no es 2 Divide el importe entre 2
		if (ContadorSalir!=2)
		{
			Import=Import/2;
		}
		
		
		//Salir del Bucle
		//Si el Importe es mas pequeño que 5 sal y sera el final 1
		if (Import<5)
		{
			bucle=true;
			FinalCasos=1;
		}
		//Si el usuario le da al centro del tesoro Sal y sera el Final 2
		else if (UsuariX==RandomizadorX+2 && UsuariY==RandomizadorY+2)
		{
			bucle=true;
			FinalCasos=2;
		}
		// Si el Usuario esta en el tesoro pero no en el centro salir y el Final sera el 3
		else if (ContadorSalir==2)
		{
			bucle=true;
			FinalCasos=3;
			
		}	
		//Si el Importe es mas pequeño que 5 multiplicalo por 2 para que en el printf se vea bien como en el enunciado
		if (Import<5)
		{
			Import=Import*2;
		}
		//Printf de la linea de Resumen en Cyan y luego Barra de giones en blanco
		setColor(CYAN);
		printf("RESUM PARTIDA: %d Import Final Partida: %.2f\n", Partida, Import );
		setColor(7);
		printf("-------------------------------------------\n");
		//La variable Contador Salir se resetea a 0
		ContadorSalir=0;
		Partida++;
	}
	//Si el Usuario ha dado en el centro Multiplica el Importe por 100 (No esta arriba en el bucle porque si no se ve  bien en el printf)
	if (UsuariX==RandomizadorX+2 && UsuariY==RandomizadorY+2)
	{
		Import=Import*100;
	}
	// Linea de Reseum de donde estaba el tesoro
	printf("\nRESUM: Les Posicions del tresor son %d %d\n", RandomizadorX, RandomizadorY);
	//Switch de todos los finales que puede tener el programa El 1 es Perder la apuesta, El 2 es Darle al centro del Tesoro y El 3 es Darle al tesoro pero no al centro
	switch (FinalCasos)
	{
	case 1:
		Import=0;
		printf("QUIN DESASTRE HAS PERDUT LA TEVA APOSTA. UN ALTRE DIA SERA \n");
		break;
	case 2:
		printf("FELICITATS HAS OBTINGUT EL BONUNS EXTRA\n");
		break;
	case 3:
		printf("HAS ENCERTAT EL TRESOR PERO NO HAS ENCERTAT EL CENTRE\n");
		break;
	default:
		break;
	}
	//Printf de el importe final conseguido con un .2 para que solo se vean 2 decimales
	printf("Import obtingut: %.2f\n", Import);
	acabament();
	return 0;
}
