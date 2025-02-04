#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include <stdbool.h> 
#include "rlutil.h"
#include "llibreriaPropia.h"
#include "llibreriaExercici.h"

int main()
{
	SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(CP_UTF8);
	srand(time(NULL));

//Ejercicio 1
/*	
	int i, resultado; 

	for (i = 0; i <= 10; i++)
	{
		resultado=5*i;
		printf("5 x %d = %d\n", i, resultado );
	}
*/

//Ejercicio 2
/*
	int i, resultado, num; 

	printf("Dime un numero:");
	scanf("%d", &num);
	for (i = 0; i <= 10; i++)
	{
		resultado=num*i;
		printf("%d x %d = %d\n", num, i, resultado );
	}
*/

//Ejercicio3
/*
	int num;
	printf("Dime un numero:");
	scanf("%d", &num);

	for (int i = 0; i <= num ; i=i+2)
	{
		printf("%d   ", i);
	}
*/

//Ejercicio4
/*
	int num,num1,max1,min;
	char i;

	while (i!='<' && i!='>')
	{
		printf("\nDime un caracter < o >:");
		scanf("%c", &i);
	}
	
	printf("Dime un numero:");
	while(getchar()!='\n');
	scanf("%d", &num);

	printf("Dime otro numero:");
	while(getchar()!='\n');
	scanf("%d", &num1);

	if (num>=num1)
	{
		max1=num;
		min=num1;
	}
	
	else
	{
		max1=num1;
		min=num;
	}

	if (i=='<')
	{
		while (max1!=min)
		{
			printf("%d ",max1);
			max1=max1-1;
		}
		
		
	}

	else if (i=='>')
	{
		while (min!=max1)
		{
			printf("%d ",min);
			min=min+1;
		}
	}	
	printf("%d ",min);
*/

//Ejercicio5 For
/*
	for (int i = 0; i <= 10; i++)
	{
		if (i!=10)
		{
			printf("%d - ", i);
		}
		else
			printf("%d", i);

	}
*/
//Ejercicio5 While
/*
	int i;
	i=0;

	while (i <= 10)
	{
		if (i!=10)
		{
			printf("%d - ", i);
		}
		else
			printf("%d", i);
		i++;
	}
*/
//Ejercicio5 Do While
/*
	int i;
	i=0;
	do
	{
		if (i!=10)
		{
			printf("%d - ", i);
		}
		else
			printf("%d", i);
		i++;
	} while (i <= 10);
*/	

//Ejercicio6 For
/*
	for (int i = 10; i >= 0; i--)
	{
		printf("%d",i);
		Sleep(100);
		cls();
	}
*/
//Ejercicio6 Do While
/*
	int i;
	i=10;

	do
	{
		printf("%d",i);
		Sleep(100);
		cls();
		i--;
	} while (i>=0);
*/
//Ejercicio6 While
/*
	int i;
	i=10;

	while (i>=0)
	{
		printf("%d",i);
		Sleep(100);
		cls();
		i--;
	}
*/	

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

//Ejercicio 9 con while
/*
	int num=0, contador=1;

	printf("Dime un numero:");
	scanf("%d", &num);

	while (contador<=num)
	{
		if (contador==num || contador==(num-1))
		{
			printf("%d", contador);
			break;
		}
		else
		{	
			printf("%d, ", contador);
			contador=contador+2;
		}
	}
*/	

//Ejercicio 9 do while
/*
	int num=0, contador=1;

	printf("Dime un numero:");
	scanf("%d", &num);
	
	do
	{
		if (contador==num || contador==(num-1))
		{
			printf("%d", contador);
			break;
		}
		else
		{	
			printf("%d, ", contador);
			contador=contador+2;
		}
	} while (contador<=num);
*/

//Ejercicio 9 For
/*
	int num=0;

	printf("Dime un numero:");
	scanf("%d", &num);

	for (int i = 1; i <= num; i=i+2)
	{
		if (i==num || i==(num-1))
		{
			printf("%d", i);
			break;
		}
		else
		{	
			printf("%d, ", i);
		}
	}
*/

//Ejercicio 10
/*
    int contable = 100;

    for (int num = 0; num <= 99; num++)
    {
        printf("%2d", num);

        contable--;
        
        if (contable % 10 == 0)
        {
            printf("\n");
        }

        else
        {
            printf(", ");
        }
    }
*/


	acabament();
	return 0;
}
