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

	//Ejercicio 1 Algoritmos Equivocado xd
/*
int numero, suma = 0;

    do {
        printf("Introduce un número natural positivo: ");
        scanf("%d", &numero);

        if (numero <= 0) {
            printf("El número debe ser positivo. Intenta de nuevo.\n");
        }
    } while (numero <= 0);
	suma = 1+numero;
    // Calcular la suma de los números entre 1 y el número introducido
    for (int i = 1; i <= numero; i++) {
		if (i==1)
		{
			printf("i = %d   acum = %d + %d = %d\n", i, numero, i, suma);
		}
		else
		{
			printf("i = %d   acum = %d + %d = ", i, suma, i);
			suma = i+suma;
			printf("%d \n", suma);
		}
	}

    // Mostrar la suma
    printf("La suma de todos los números entre 1 y %d es: %d\n", numero, suma);
*/

//Ejercicio 1 algoritmos bien hecho xd
/*

	int numero, suma = 0;

    // Solicitar al usuario un número natural
    do {
        printf("Introduce un número natural positivo: ");
        scanf("%d", &numero);

        if (numero <= 0) {
            printf("El número debe ser positivo. Intenta de nuevo.\n");
        }
    } while (numero <= 0);

    // Calcular la suma de los números entre 1 y el número introducido
    for (int i = 1; i <= numero; i++) {
		printf("i = %d   acum = %d + %d = ", i, suma, i);
			suma = i+suma;
			printf("%d \n", suma);
	}

    // Mostrar la suma
    printf("La suma de todos los números entre 1 y %d es: %d\n", numero, suma);
*/
//Exercici 2 algoritmes
/*
    int numero, pares = 0, impares = 0;
    int sumaPares = 0, sumaImpares = 0;
    float promedioPares, promedioImpares;

    printf("Introduce 10 números enteros:\n");

    for (int i = 0; i < 10; i++) {
        printf("Número %d: ", i + 1);
        scanf("%d", &numero);

        if (numero % 2 == 0) {
            pares++;
            sumaPares += numero;
        } else {
            impares++;
            sumaImpares += numero;
        }
    }
	if (pares==0)
	{
		printf("\nNo se han introduido numeros pares\n");
	}
	else
	{
		promedioPares = (float)sumaPares / pares;
		printf("\nCantidad de números pares: %d\n", pares);
  		printf("Suma de los números pares: %d\n", sumaPares);
    	printf("Promedio de los números pares: %.2f\n", promedioPares);
    }
	if (impares==0)
	{
		printf("\nNo se han introduido numeros impares\n");
	}
	else
	{
    	promedioImpares = (float)sumaImpares / impares;

	    printf("\nCantidad de números impares: %d\n", impares);
	    printf("Suma de los números impares: %d\n", sumaImpares);
    	printf("Promedio de los números impares: %.2f\n", promedioImpares);
	}
*/ 



//Exercici 3 algoritme
/*
	int suma = 0;

    for (int i = 2; i <= 100; i += 2) {
        suma += i;
    }

    printf("La suma de los números pares entre 2 y 100 es: %d\n", suma);
*/
//Exercici 4
/*
	int valor, suma = 0;
    int cantidad_valores = 0;

    printf("Introduce valores (finaliza con -1):\n");

    while (1) {
        printf("Valor: ");
        scanf("%d", &valor);

        if (valor == -1) {
            break;
        }

        suma += valor;
        cantidad_valores++;
    }

    if (cantidad_valores == 0) {
        printf("No se introdujeron valores válidos.\n");
    } else {
        float media = (float)suma / cantidad_valores;
        printf("La media de los valores introducidos es: %.2f\n", media);
    }
*/
//Ejercicio 5
/*
	int cantidadDigitos = 0, numero;

    printf("Introduce un número positivo: ");
    scanf("%d", &numero);

    if (numero == 0) 
	{
        cantidadDigitos = 1;
    } 
	else
	{
        while (numero > 0) 
		{
    	    numero /= 10;
    	    cantidadDigitos++;
    	}
    }

    printf("La cantidad de dígitos en el número es: %d\n", cantidadDigitos);


*/
//Ejercicio 6
/*
	int numero = 1, numeroMaximo = 0, numeroMinimo = 0, primerNumero = 1;

	printf("Introduce números (finaliza con 0):\n");

	while (numero!=0) 
	{
		printf("Número: ");
		scanf("%d", &numero);

		if (primerNumero == 1 && numero != 0) 
		{
			numeroMaximo = numero;
			numeroMinimo = numero;
			primerNumero = 0;
		} 
		else 
		{
			if (numero > numeroMaximo) 
			{
				numeroMaximo = numero;
			}
			if (numero < numeroMinimo && numero != 0) 
			{
				numeroMinimo = numero;
			}
		}
	}

		if (primerNumero == 1)
		{
			printf("No se ingresaron números válidos (excluyendo 0).\n");
		} 
		else 
		{
			printf("El número más grande es: %d\n", numeroMaximo);
			printf("El número más pequeño es: %d\n", numeroMinimo);
		}
*/

//Ejercicio 7
/*
	int numero, factorial = 1;

    printf("Introduce un número natural para calcular su factorial: ");
    scanf("%d", &numero);

    if (numero < 0) 
	{
        printf("El factorial no está definido para números negativos.\n");
    } 
	else 
	{
        for (int i = 1; i <= numero; i++) 
		{
            factorial *= i;
        }

        printf("El factorial de %d es: %d\n", numero, factorial);
    }
*/


	acabament();
	return 0;
}
