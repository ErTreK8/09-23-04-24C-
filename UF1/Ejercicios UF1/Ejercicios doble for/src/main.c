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

//Ejercicio7
/*
	int min=0, ver=0, i=0, min1=0;

	printf("Cuantos minutos quieres en el contador?:");
	scanf("%d", &min);
	min1=min;
	while (min1!=ver)
	{
		if (min!=0)
		{
			printf("%d:%02d", ver, i);
			Sleep(1000);
			cls();
			i++;

			if (i==60)
			{
				min=min-1;
				i=0;
				ver++;
			}
		}
	}

	printf("%d:00\nSe ha acabado el contador", ver);
*/

//Ejercicio 8
/*
	int min=0, sec=0, i=0;
	do
	{
		if (min<0 || min>3)
		{
			printf("Numero Incorrecto introduce uno entre 0-3\n");
		}
		printf("Cuantos minutos quieres en el contador?:");
		scanf("%d", &min);
	} while (min<0 || min>3);

	do
	{
		if (sec<0 || sec>59)
		{
			printf("Numero Incorrecto introduce uno entre 0-59\n");
		}
		
		printf("Cuantos segundos quieres en el contador?:");
		scanf("%d", &sec);
		
	} while (sec<0 || sec>59);

	

	for (min; min >=0 ; min--)
	{
		for (sec; sec >=0; sec--)
		{
			printf("%d:%02d", min, sec);
			Sleep(1000);
			cls();
		}
		sec=59;
	}
*/
	

//Ejercicio 5 1.9
/*

	int num,num2=0,intentos;

    printf("Cuantos intentos quieres hacer: ");
    scanf("%d",&intentos);

    while ((num/1000)<1 || (num/1000)>9)
    {
        num=rand();
    }
    printf("numero: %d\n",num);
    for (int i = 0; i<intentos && num2!=num; i++)
    {
        printf("Introduce un numero: ");
        scanf("%d",&num2);
        if (num2<num)
        {
            printf("El numero es más alto\n");
        }
        else if (num2>num)
        {
            printf("El numero es más bajo\n");
        }
    }
    printf("Felicidades saliste del videojuego");

*/

//Ejercicio 1 1.10
/*
	for (int numero = 1; numero <=10; numero++)
	{
		for (int i = 1; i <=10 ; i++)
		{
			printf(" Taula del %d\n%d x %d = %d\n", numero, numero, i, numero*i);
		}
		Sleep(1000);
		printf("\n");
	}

	printf("Aquestes son totes les tables de multiplicar");
*/
/*
	// Variables

    int xo, yo, col;

    // Fem un rang per a limitar la distancia que es pot fer el rectangle

    do
    {
        printf("Introdueix la posició xo del rectangle (0 - 80): ");
        scanf("%d", &xo);

    } while (xo <= 0 || xo > 80);

    do
    {
        printf("Introdueix la posició yo del rectangle (0 - 30): ");
        scanf("%d", &yo);

    } while (yo <= 0 || yo > 30);

    // Defineix la posició depenent del numero escrit

    gotoxy(xo, yo);

    for (int columna = 0; columna < 10; columna++)
    {
        // Vas a donde ha dicho el usuario + el numero de columna para ir moviendote a la derecha

        gotoxy(xo + columna, yo);

        // Canviamos color del texto para hacerlo aleatorio (Quitamos el negro con el (15) + 1)

        setColor(rand() % (15) + 1);

        // Escrive el texto para formar la figura

        printf("X");
        Sleep(200);
    }

    // Atura programa fins a premer teccla

    getch();

    for (int alçada = 1; alçada < 5; alçada++)
    {
        gotoxy(xo + 9, yo + alçada);

        setColor(rand() % (15) + 1);

        printf("X");
        Sleep(200);
    }

    getch();

    for (int columna = 8; columna >= 0; columna--)
    {
        gotoxy(xo + columna, yo + 4);

        setColor(rand() % (15) + 1);

        printf("X");
        Sleep(200);
    }

    getch();

    for (int alçada = 3; alçada > 0; alçada--)
    {
        gotoxy(xo, yo + alçada);

        setColor(rand() % (15) + 1);

        printf("X");
        Sleep(200);
    }

    // Cambiamos color a blanco para que imprima el final blanco
*/
	int x=10, y=4;
	for (int col = 0; col < 2; col++)
	{
		gotoxy(x,y);
		printf("X");
		x=x+1;
	}
	for (int fila = 0; fila < 2; fila++)
	{
		gotoxy(x,y);
		printf("X");
		y=y+1;
	}
	y--;
	x--;
	printf("%d",x);
	
    setColor(WHITE);

	acabament();
	return 0;
}
