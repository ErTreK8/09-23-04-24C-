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
    SMALL_RECT windowSize = {0, 0, 50, 30};
    SetConsoleWindowInfo(wHnd, 1, &windowSize);
//EJERICIO EXTRA MIO TO CHILL

	//DEFINIMOS VARIABLES
	int Tipo=0, CotizacionMinima=0, CotizacionMinimaInicial=0, CotizacionMaxima=0, CotizacionMaximaInicial=0, CotizacionInicial=0, Cotizacion=0, dia=1, RandomizadorCotizacion=0, ContadorBolsa, X=1, Y=6, CotizacionMedia=0, DiaMaxima=1, DiaMinima=1, FinalCasos=0, numant1=0, numant2=0;
	bool bucle=false;

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

	do
	{
		printf("\nComo quieres ver la Cotizacion?\n1=Numeros            2=Grafico:\n");
		scanf("%d",&Tipo);
	} while (Tipo<=0 || Tipo>2);

	//BUCLE QUE NO PARA HASTA QUE LA VARIABLE BUCLE SEA TRUE
	if (Tipo==1)
	{	
		cls();
		printf("Benvingut al SISTEMA GESTOR DE COTIZACIONS A BROSA\n\n----------------------------------\nREALITZAT PER: Eric Garcia Gispert\n----------------------------------\n\n");
		while (bucle==false)
		{
			//La variable Comprobar es para la otra manera q me gusta mas y es por flexeo puro y duro
			gotoxy(X,Y);
			if (dia==1)
			{
				printf("DIA %d: %02d", dia, Cotizacion);
			}
			else if (dia==2)
			{
				printf("DIA %d: %02d %02d", dia, Cotizacion, numant1);
			}
			else{
				printf("DIA %d: %02d %02d %02d", dia, Cotizacion, numant1, numant2);
			}
			
			//RANDOMIZADOR DE COTIZACION PARA QUE SUME un numero entre 2 y -2 CHILEANDO
			RandomizadorCotizacion=rand()%(2-(-2)+1)-2;
			
			//GOTOXY CORDENADAS EN EL DIA 30
			if (dia==30)
			{
				X=20;
				Y=5;
			}

			//COTIZACION MAXIMA Y MINIMA PARA QUE CAMBIE PARA LA MAS GRANDE ETC CON LOS DIAS Y TODO
			if (Cotizacion > CotizacionMaxima) {
					CotizacionMaxima = Cotizacion;
					DiaMaxima = dia;
			}

			if (Cotizacion < CotizacionMinima) {
					CotizacionMinima = Cotizacion;
					DiaMinima = dia;
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
			
			//QUE PASA CON EL RANDOMIZADOR DE LA COTIZACION, SI ES MENOR A la cotizacion minima COLOR ROJO, SI ES MAYOR A a la cotizacion maxima COLOR AZUL, SI ES entre medias COLOR BLANCO

			if (Cotizacion<CotizacionMinimaInicial)
				{
					setColor(4);
					ContadorBolsa++;
				}

			else if (Cotizacion>CotizacionMaximaInicial)
			{
				setColor(1);
					ContadorBolsa=0;
			}
			else
			{
				setColor(7);
				ContadorBolsa=0;
			}
			numant2=numant1;
			numant1=Cotizacion;
			Cotizacion=Cotizacion+RandomizadorCotizacion;
			dia++;
			Y++;
			CotizacionMedia=CotizacionMedia+Cotizacion;
			Sleep(100);
		}
		setColor(7);
		X=1;
		Y=35;
		gotoxy(X,Y);
		printf("\n");
		//RESUMEN MEDIO DE DATOS FINAL
		if (dia==61)
		{
			dia--;
		}
		CotizacionMedia=CotizacionMedia/dia;
		printf("\n-------------------------------------\n");
		printf("DADES INICIALS\n");
		printf("-------------------------------------\n");
		printf("La cotizacion Maxima que habias elejido era: %02d\n", CotizacionMinimaInicial);
		printf("La cotizacion Minima que habias elejido era: %02d\n", CotizacionMaximaInicial);
		printf("La cotizacion Inicial que habias elejido era: %02d\n", CotizacionInicial);


		printf("\n-------------------------------------\n");
		printf("RESUM DADES\n");
		printf("-------------------------------------\n");
		printf("El valor Promig de les Cotizacions ha sigut de: %d\n", CotizacionMedia);
		printf("El dia que s'ha obtingut la darrera maxima cotizacio ha sigut el dia %d amb un valor maxim de %d\n", DiaMaxima, CotizacionMaxima);
		printf("El dia que s'ha obtingut la darrera minima cotizacio ha sigut el dia %d amb un valor minim de %d\n\n", DiaMinima, CotizacionMinima);


	}
	else if (Tipo==2)
	{
		X=1;
		Y=1;
		cls();
		//Imprimir barra lateral con los guines
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
					setColor(4);
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
		//Imprimir barra horizontal guines
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
		//Bucle para q escriba cosas
		while (bucle==false)
		{
			Y=40-Cotizacion+1;
			X=dia+3;
			gotoxy(X,Y);
			//Escribir * o ^ dependiendo de cuanto valga la cotizacion 
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

			//IF para romper el bucle
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
	}
	setColor(7);
	if (Tipo==1)
	{
		//FINAL DE CASOS CHILL
		if (FinalCasos==1)
		{
			printf("-------------------------------------\n");
			printf("Tu Empresa A Superado el programa de simulaicon de bolsa pasando los 60 dias sin llegar a un valor inferior a 0 o ha estado por debajo de la minima 3 dias seguidos. Felicidades!!! :D");
			printf("\n-------------------------------------\n");
		}
		else if (FinalCasos==2)
		{
			printf("-------------------------------------\n");
			printf("Tu Empresa No A Superado el programa de simulaicon de bolsa, Ha Caido por debajo de cero en una racha de 3 dias seguidos por debajo de la cotizacion minima.\n");
			printf("-------------------------------------\n");
		}
		else if (FinalCasos==3)
		{
			printf("-------------------------------------\n");
			printf("Tu Empresa No A Superado el programa de simulaicon de bolsa, ha estado por debajo de la cotizacion minima 3 dias seguidos.\n");
			printf("-------------------------------------\n");
		}
		
		else if (FinalCasos==4)
		{
			printf("-------------------------------------\n");
			printf("Tu Empresa No A Superado el programa de simulaicon de bolsa, Ha Caido por debajo de 0.\n");
			printf("-------------------------------------\n");
		}
		printf("\nGracies Per Utilitzar el SISTEMA GESTOR DE COTIZACIONS A BROSA\n\n----------------------------------\nREALITZAT PER: Eric Garcia Gispert\n----------------------------------\n\n");
	}
	else
	{
		X=1;
		Y=45;
		gotoxy(X,Y);
		//FINAL DE CASOS CHILL
		if (FinalCasos==1)
		{
			printf("-------------------------------------\n");
			printf("Tu Empresa A Superado el programa de simulaicon de bolsa pasando los 60 dias sin llegar a un valor inferior a 0 o ha estado por debajo de la minima 3 dias seguidos. Felicidades!!! :D");
			printf("\n-------------------------------------\n");
		}
		else if (FinalCasos==2)
		{
			printf("-------------------------------------\n");
			printf("Tu Empresa No A Superado el programa de simulaicon de bolsa, Ha Caido por debajo de cero en una racha de 3 dias seguidos por debajo de la cotizacion minima.\n");
			printf("-------------------------------------\n");
		}
		else if (FinalCasos==3)
		{
			printf("-------------------------------------\n");
			printf("Tu Empresa No A Superado el programa de simulaicon de bolsa, ha estado por debajo de la cotizacion minima 3 dias seguidos.\n");
			printf("-------------------------------------\n");
		}
		
		else if (FinalCasos==4)
		{
			printf("-------------------------------------\n");
			printf("Tu Empresa No A Superado el programa de simulaicon de bolsa, Ha Caido por debajo de 0.\n");
			printf("-------------------------------------\n");
		}
		printf("\n\n\nGracies Per Utilitzar el SISTEMA GESTOR DE COTIZACIONS A BROSA\n\n----------------------------------\nREALITZAT PER: Eric Garcia Gispert\n----------------------------------\n\n");
	}
	
	acabament();
	return 0;
}
