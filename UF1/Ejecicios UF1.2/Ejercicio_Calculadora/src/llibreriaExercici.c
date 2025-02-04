#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include <stdbool.h> 
#include "rlutil.h"
#include "llibreriaPropia.h" 
#include "llibreriaExercici.h"

float demanaNum()
{
    int n;
    printf("\nIntroduce un numero: ");
    scanf("%d", &n);
    return n;
}

char demanaSimbol()
{
    char c;
    while (c != '+' && c != '-' && c != '*' && c != '/')
    {
        while(getchar()!='\n');
        printf("\nIntroduce un simbol: ");
        scanf("%c", &c);
    }
    return c;
}

float suma(float a, float b)
{
    float c = a + b;
    return c;
}
float resta(float a, float b)
{
    float c = a - b;
    return c;
}
float multiplicacion(float a, float b)
{
    float c = a * b;
    return c;
}
float division(float a, float b)
{
    float c = a / b;
    return c;
}

void mostrarResultat(float num1, float num2, char operacion, float resultat)
{
    printf("\n%.2f %c %.2f = %.2f\n", num1, operacion, num2, resultat);
}
