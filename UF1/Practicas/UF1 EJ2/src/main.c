#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include <stdbool.h> 
#include "rlutil.h"
#include "llibreriaPropia.h"
#include "llibreriaExercici.h"
#include <windows.h>
HANDLE wHnd;
int main(){
	SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(CP_UTF8);
	srand(time(NULL));
	wHnd = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTitle("PROGRAMA COTIZACION");
    SMALL_RECT windowSize = {0, 0, 50, 15};
    SetConsoleWindowInfo(wHnd, 1, &windowSize);

	//DEFINIMOS VARIABLES
	int CotizacionMinima=0, CotizacionMinimaInicial=0, CotizacionMaxima=0, CotizacionMaximaInicial=0, CotizacionInicial=0, Cotizacion=0, dia=1, RandomizadorCotizacion=0, ContadorBolsa, X=1, Y=1, CotizacionMedia=0, DiaMaxima=1, DiaMinima=1, FinalCasos=0, numant1=0, numant2=0;
	bool bucle=false, comprobar=false;

	//Inicio Del Programa
	printf("Benvingut al SISTEMA GESTOR DE COTIZACIONS A BROSA\n\n----------------------------------\nREALITZAT PER: Eric Garcia Gispert\n----------------------------------\n\n");
	do
	{
		printf("Introdueix Cotizacion Minima:(0-10): ");
		scanf("%d",&CotizacionMinimaInicial);
	} while (CotizacionMinimaInicial<0 || CotizacionMinimaInicial>10);
	do
	{
		printf("Introdueix Cotizacion Maxima:(30-40): ");
		scanf("%d",&CotizacionMaximaInicial);
	} while (CotizacionMaximaInicial<30 || CotizacionMaximaInicial>40);
	do
	{
		printf("Introdueix Cotizacion Inicial:(%d-%d): ", CotizacionMinimaInicial, CotizacionMaximaInicial);
		scanf("%d",&CotizacionInicial);
	} while (CotizacionInicial<CotizacionMinimaInicial || CotizacionInicial>CotizacionMaximaInicial);
	//DEFINIMOS VALORES DE COTIZACION
	Cotizacion=CotizacionInicial;
	CotizacionMedia=CotizacionInicial;
	CotizacionMaxima=CotizacionInicial;
	CotizacionMinima=CotizacionInicial;


	cls();
	//IMPRIMIMOS LA BARRA DE LA IZQUIERDA QUE CUANDO LA I= CotiMaxIni escriba una barra roja de guines
	for (int i = 40; i >=0; i--)
	{
		if (i==CotizacionMaximaInicial)
		{	
			X=3;
			for (int i = 0; i < 60; i++)
			{
				X++;
				setColor(1);
				gotoxy(X,Y);
				printf("-");
				
			}
		}
		else if (i==CotizacionMinimaInicial)
		{
			X=3;
			for (int i = 0; i < 60; i++)
			{
				X++;
				setColor(7);
				gotoxy(X,Y);
				printf("-");
			}
		}
		setColor(WHITE);	
		X=1;
		gotoxy(X,Y);
		Y++;
		printf("%2d|",i);
	}
	Y=Y-1;
	X=2;
	//Imprimimos la barra horizontal de abajo de chill
	for (int i = 0; i <= 69; i++)
	{
		X++;
		gotoxy(X,Y);
		
		if (i%5==0 && i<61)
		{
			printf("|");
			gotoxy(X,Y+1);
			printf("%d",i);
		}
		else if (i==69)
		{
			printf(">");
			gotoxy(X,Y+1);
			printf("dia");
		}
		else{
			printf("-");
		}
	}
	while (bucle==false)
	{
		Y=40-Cotizacion+1;
		X=dia+3;
		gotoxy(X,Y);
		//Si cotizacion es mas grande de 40 que imprima el simbolo de la flecha arriba, si es mas pequeño de 40 pero mas grande de cotizacion maxima escribir * azul, mas pequeña...
		if (Cotizacion>40)
		{
			setColor(2);
			printf("^");
			ContadorBolsa=0;
		}
		else if (Cotizacion>CotizacionMaximaInicial && Cotizacion<=40)
		{
			setColor(1);
			printf("*");
			ContadorBolsa=0;
		}
		else if (Cotizacion<CotizacionMinimaInicial)
		{
			setColor(4);
			printf("*");
			ContadorBolsa++;
		}
		else
		{
			setColor(7);
			printf("*");
			ContadorBolsa=0;
		}
		//IF PARA ROMPER EL BUCLE y para decir en el final como ha acabado el programa
		if (dia==60)
		{
			bucle=true;
			FinalCasos=1;
		}
		else if(Cotizacion<0 && ContadorBolsa==3){
			bucle=true;
			FinalCasos=2;
		}
		else if(ContadorBolsa==3){
			bucle=true;
			FinalCasos=3;
		}
		else if(Cotizacion<0){
			bucle=true;
			FinalCasos=4;
		}
		RandomizadorCotizacion=rand()%(2-(-2)+1)-2;
		dia++;
		X++;
		Cotizacion=Cotizacion+RandomizadorCotizacion;
		Y=Cotizacion;
		Sleep(100);
	}
	X=1;
	Y=45;
	gotoxy(X,Y);

	acabament();
	return 0;
}