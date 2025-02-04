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

	//Ejercicio 1:
    /*
    int resultado;

    for (int tabla=1; tabla<=10; tabla++)
    {
        if (tabla<=10)
        {
            if (tabla!=1)
            {
                printf("\n");
            }
            printf("TABLA %d\n",tabla);
        }
        for (int i = 1; i <=10; i++)
        {
            resultado=i*tabla;
            printf("%2d x %2d= %2d\n",tabla,i,resultado);
        }
    }
    */
    //Ejercicio 2:
    /*
    int tabla=1,resultado,limit=10;

    int x=1, y=0,y0=1;

    for (int i = 1; tabla<=10; i++)
    {
        for (int j = 1; j <= 10; j++)
        {
                if (y<limit) 
                {
                    y++;
                }
                else if(tabla>=6)
                {
                    y=y0+1;
                }
                else{y=y0;}
            
            gotoxy(x,y);
            resultado=j*tabla;
            printf("%2d x %2d= %2d\n",tabla,j,resultado);
        }
        tabla++;
        if (tabla<=5)
        {
            x+=20;
        }
        else if (tabla==6)
        {
            y0+=12;
            y=12;
            limit=limit+12;
            x=1;
        }
        else{
            x+=20;
            y0+=12;
            y=12;
        }
    }
    */

       //Ejercicio 3:
  /*  
    int franja=1,limit=120,limity=13;
    int x=1, y,y0=1,x0=1;
    for (int i = 1; franja<=3; i++)
    {
        for (y=y0; y < limity; y++)
        {
            while (x<=limit)
            {
                gotoxy(x,y);
                if (y<=12)
                {
                    setBackgroundColor(RED);
                    printf(" ");
                }
                else if (y>12 && y<=24)
                {
                    setBackgroundColor(YELLOW);
                    printf(" ");
                }
                else 
                {
                    setBackgroundColor(RED);
                    printf(" ");
                }
                x++;
            }    
            x=x0;            
        }
        franja++;
        switch (franja)
        {
        case 2:y0=13;limity=limity+12;break;
        case 3:y0=25;limity=36;break;
        default:break;
        }
    }
    setBackgroundColor(BLACK);
*/

    //Ejercicio 5 1.9
/*

	int num=0, num2=0, intentos;

    printf("Cuantos intentos quieres hacer: ");
    scanf("%d",&intentos);

    while ((num/1000)<1 || (num/1000)>9)
    {
        num=rand();
    }
    //printf("numero: %d\n",num);
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
    if (num2==num)
    {
        printf("\nFelicidades saliste del videojuego");
    }
    else
    {
        printf("\nPerdiste videojuego");
    }
    
*/


//Ejercicio 6 1.9 100 grados

    int dias = 0;
    float temperatura, suma_temperaturas = 0.0;
    float max_temp = -70.0, min_temp = 70.0;
    int dia_max_temp, dia_min_temp;
    bool seguir = true;

    printf("Introduce temperaturas diarias (-69.9°C a 69.9°C). Para finalizar, introduce 100.0°C.\n");

    for (int dia = 1; seguir; dia++) {
        printf("Día %d - Introduce temperatura (°C): ", dia);
        scanf("%f", &temperatura);

        if (temperatura == 100.0) {
            seguir = false;
        } else if (temperatura >= -69.9 && temperatura <= 69.9) {
            suma_temperaturas += temperatura;
            dias++;

            if (temperatura > max_temp) {
                max_temp = temperatura;
                dia_max_temp = dia;
            }

            if (temperatura < min_temp) {
                min_temp = temperatura;
                dia_min_temp = dia;
            }
        } else {
            printf("Temperatura fuera del rango permitido. Introduce una temperatura válida.\n");
        }
    }

    if (dias > 0) {
        float temperatura_media = suma_temperaturas / dias;
        float diferencia_maxima = max_temp - temperatura_media;
        float diferencia_minima = min_temp - temperatura_media;

        printf("Número de días registrados: %d\n", dias);
        printf("Temperatura media máxima: %.2f°C (Día %d)\n", max_temp, dia_max_temp);
        printf("Temperatura media mínima: %.2f°C (Día %d)\n", min_temp, dia_min_temp);
        printf("Diferencial en grados respecto a la temperatura media global:\n");
        printf("  Máximo: %.2f°C\n", diferencia_maxima);
        printf("  Mínimo: %.2f°C\n", diferencia_minima);
    } else {
        printf("No se introdujeron temperaturas válidas.\n");
    }




//Ejercicio cuadrado con colores EJ6 1.10 mejorado
/*
    int ample, alt;
    char simbol;
    int color;

    // Pedir al usuario el ancho y la altura del cuadrado
    do {
        printf("Introduce el ancho del cuadrado (entre 2 y 20): ");
        scanf("%d", &ample);
    } while (ample < 2 || ample > 20);

    do {
        printf("Introduce la altura del cuadrado (entre 2 y 20): ");
        scanf("%d", &alt);
    } while (alt < 2 || alt > 20);

    // Limpiar la pantalla
    cls();

    // Pedir al usuario el color y el símbolo
    printf("Elige un color para el cuadrado:\n");
    printf("1. Azul\n");
    printf("2. Verde\n");
    printf("3. Cyan\n");
    printf("4. Rojo\n");
    printf("5. Purpura\n");
    printf("6. Amarillo\n");
    printf("7. Blanco\n");
    printf("8. Gris\n");
    printf("Elige el número del color: ");
    scanf("%d", &color);

    printf("Introduce un símbolo para el cuadrado: ");
    scanf(" %c", &simbol); // Usamos un espacio antes de %c para ignorar espacios en blanco

    // Dibujar el cuadrado
    setColor(color);
    for (int i = 0; i < alt; i++) {
        for (int j = 0; j < ample; j++) {
            printf("%c", simbol);
        }
        printf("\n");
    }
    resetColor();
*/

//Bandera Irlanda
/*
    //Col es la Y y I es la X en el gotoxy chill
    for (int col=15;col!=27;col++)
    {
        for (int i=0;i < 20; i++)
        {
            gotoxy(i+1,col);
            setBackgroundColor(GREEN);
            printf(" ");
        }
    }

    for (int col=15;col!=27;col++)
    {
        for (int i=20;i < 40; i++)
        {
            gotoxy(i+1,col);
            setBackgroundColor(WHITE);
            printf(" ");
        }
    }

    for (int col=15;col!=27;col++)
    {
        for (int i=40;i < 60; i++)
        {
            gotoxy(i+1,col);
            setBackgroundColor(RED);
            printf(" ");
        }
    }
*/

//Ejercicio Classe Diagonal
/*
    int x=1, y=1, veces;
    printf("Cuantas Veces quieres que rebote: ");
    scanf("%d", &veces);
    for (int i = 1; i <= veces; i++)
    {
        for (int i = 0; i < 15; i++)
        {
            gotoxy(x,y);
            setBackgroundColor(RED);
            printf(" ");
            x++;
            y++;
            Sleep(100);
            setBackgroundColor(BLACK);
            cls();
        }
        for (int i = 0; i < 15; i++)
        {
            gotoxy(x,y);
            setBackgroundColor(RED);
            printf(" ");
            x--;
            y++;
            Sleep(100);
            setBackgroundColor(BLACK);
            cls();
        }
        cls();
        x=1;
        y=1;
    }
*/   
/*
//Ejercicio Alfabeto Classe
    //Definimos Variables god
    int xini=1, yini=1, color=1, colorAnt=0, yiniAnt=0;
    char letra='A';

    //Bucle para pedir un x mayor que 0 menor que 40 y una y mayor que 0 y menor de 20 asique god
    
    do
    {
        printf("Dime un valor para la x: ");
        scanf("%d", &xini);
    } while (xini<=0 || xini>= 40);
    do
    {
        printf("Dime un valor para la y: ");
        scanf("%d", &yini);
    } while (yini<=0 || yini>=20);
    
    //Limpiamos Pantalla god
    cls();

    //Definimos el valor de la variable yiniAnt al valor inicial de yini god
    
    yiniAnt=yini;
    
    //Randomizamos los colores del 1 al 15 (el 0 es el negro asique no sale god) COMO FUNCIONA EL RAND [color=rand()%(colormax-colormin+1)+colormin;]

    color=rand()%(15-1+1)+1;
    
    //Bucle de impresion del alfabeto god
    
    while (letra!='[')    
    {
        //Si imprimimos 10 letras pasar al lado y volver arriba god

        if (yini==(yiniAnt+10))
        {
            xini=xini+5;
            yini=yiniAnt;
        }

        //Bucle para que no se repitan los colores bien hecho
        
        do
        {
            color=rand()%(15-1+1)+1;
        } while (colorAnt==color);
        colorAnt=color;
        
        //Poner el color god
        
        setColor(color);

        //Cordenadas del printf y el printf con us sleep a 200 god

        gotoxy(xini,yini);
        printf("%c", letra);
        Sleep(200);

        //Aumentamos variables yini y letra  god
        
        yini++;
        letra++;
    }

    //Ponemos el finalizar programa abajo de todo y salga god
    yini=yiniAnt+12;
    gotoxy(xini,yini);  

// Todo god  ඞ ඞ ඞ ඞ
*/
	acabament();
	return 0;
}
