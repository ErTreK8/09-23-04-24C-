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

		//EJERCICIO 1:
	/*
	int dia;

	printf("Escribe un dia: ");
	scanf("%d", &dia);
	if(dia>=1 && dia<=5)
	{
		printf("el dia %d es laborable",dia);
	}
	else if(dia>=6 && dia<=7){
		printf("el dia %d no es laborable", dia);
	}
	else{
		printf("el dia %d no es valido",dia);
	}
	*/
	//EJERCICIO 2:
	/*
	int dia;

	printf("Dime un dia: ");
	scanf("%d",&dia);

	if(dia>=1 && dia<=5){
		printf("el dia %d no es fin de semana",dia);
	}
	else if(dia>=6 && dia<=7){
		printf("el dia %d es fin de semana", dia);
	}
	else{
		printf("el dia %d no es valido",dia);
	}
	*/
	//EJERCICIO 3:
	/*
	int dia=0;
	
	while (dia<1||dia>7)
	{
		printf("que dia es?\n");
		scanf("%d",&dia);
		if(dia<1||dia>7){
			printf("el dia %d no existe\n",dia);
		}
	}
	
	switch (dia)
	{
	case 1:
		printf("el dia %d es  lunes",dia);
		break;
	case 2:
		printf("el dia %d es  martes",dia);
		break;
	case 3:
		printf("el dia %d es  miercoles",dia);
		break;
	case 4:
		printf("el dia %d es jueves",dia);
		break;
	case 5:
		printf("el dia %d es viernes",dia);
		break;
	case 6:
		printf("el dia %d es sabado",dia);
		break;
	case 7:
		printf("el dia %d es domingo",dia);
		break;
	default:
		printf("el dia %d no es valido");
		break;
	}
	*/
	//EJERCICIO 4:
	/*
	bool lluvia;
	int dia;		

	printf("Dia: ");
	scanf("%d",&dia);
	printf("llueve: 1(si),0(no)");
	scanf("%d",&lluvia);

	while (dia<1||dia>7)
	{
		printf("que dia es?\n");
		scanf("%d",&dia);
		if(dia<1||dia>7){
			printf("el dia %d no existe\n",dia);
		}
	}
	while (lluvia<0||lluvia>1)
	{
		printf("llueve??\n");
		scanf("%d",&lluvia);
		if(lluvia<0||lluvia>1){
			printf("el numero %d no es valido\n",lluvia);
		}
	}
	
	switch (dia)
	{
	case 1:
		printf("el dia %d que es lunes y ",dia);
		break;
	case 2:
		printf("el dia %d que es martes y ",dia);
		break;
	case 3:
		printf("el dia %d que es miercoles y ",dia);
		break;
	case 4:
		printf("el dia %d que es jueves y ",dia);
		break;
	case 5:
		printf("el dia %d que es viernes y ",dia);
		break;
	case 6:
		printf("el dia %d que es sabado y ",dia);
		break;
	case 7:
		printf("el dia %d que es domingo y ",dia);
		break;
	default:
		printf("el dia %d no es valido");
		break;
	}
	switch (lluvia)
	{
	case 0:
		printf("no llueve: ");
		break;
	case 1:
		printf("llueve: ");
		break;
	default:
		break;
	}
	
	if ((dia==1||dia==3||dia==5)&&lluvia==false)
	{
		printf("entrenamiento fuera del pavellón");
	}
	else if((dia==1||dia==3||dia==5)&&lluvia==true)
	{
		printf("entrenamiento dentro del pavellón");
	}
	else{
		printf("no hay entrenamiento");
	}
	*/
	//EJERCICIO 5:
	/*
	int A=-1,B=-1;

	while (A<0 || B<0)
	{
		if(A<0){
			printf("goles A: ");
			scanf("%d",&A);
		}
		else if(B<0){
			printf("goles B: ");
			scanf("%d", &B);
		}
	}
	
	if(A>B){
		printf("Ha ganado el equipo A");
	}
	else if(A<B){
		printf("Ha ganado el equipo B");
	}
	else{
		printf("Los dos equipos han empatado");
	}	
	*/
	//EJERCICIO 6:
	/*
	char car;
	printf("caracter: ");
	scanf("%c",&car);
	if(car>=48 && car<=57)
	{
		printf("El caracter %c es un numero",car);
	}
	else if(car>=65 && car<=90)
	{
		printf("El caracter %c es una letra mayuscula",car);
	}
	else if(car>=97 && car<=122)
	{
		printf("El caracter %c es una letra minuscula", car);
	}
	else{
		printf("El caracter %c no es ni mayuscula, ni minuscula, ni un numero",car);
	}
	*/
	//EJERCICIO 7:
	/*
	int num1,num2;

	printf("num1: ");
	scanf("%d",&num1);
	
	printf("num2: ");
	scanf("%d",&num2);
	
	printf("El numero máximo de los dos es: ");
	if(num1>num2){
		printf("%d",num1);
	}
	else if(num2>num1){
		printf("%d",num2);
	}
	else{
		printf("ninguno, son iguales");
	}
	*/
	//EJERCICIO 8:
	/*
	int num,num2;

	printf("num=");
	scanf("%d",&num);

	num2=num;

	if(num<0)
	{
		num=num*-1;
	}

	printf("El valor absoluto del numero %d es %d",num2,num);
	*/
	//EJERCICIO 9:
	/*
	int num=-1;

	while(num<0){
	printf("num=");
	scanf("%d",&num);
	if(num<0)
	{
		printf("Datos iniciales incorrectos\n");
	}
	}
	if(num%2==1){
		printf("el numero %d es senar",num);
	}
	else{
		printf("el numero %d no es senar",num);
	}	
	*/
	//EJERCICIO 10:
	/*
	int mes,dias;

	while(mes<=0 || mes>12)
	{
		printf("mes=");
		scanf("%d",&mes);
		if(mes<=0 || mes>12)
		{
			printf("el mes %d no existe\n",mes);
		}
	}

	switch (mes)
	{
	case 1:
		dias=31;
		break;
	case 2:
		dias=28;
		break;
	case 3:
		dias=31;
		break;
	case 4:
		dias=30;
		break;
	case 5:
		dias=31;
		break;
	case 6:
		dias=30;
		break;
	case 7:
		dias=31;
		break;
	case 8:
		dias=31;
		break;
	case 9:
		dias=30;
		break;
	case 10:
		dias=31;
		break;
	case 11:
		dias=30;
		break;
	case 12:
		dias=31;
		break;
	default:
		break;
	}

	printf("Resultado: %d dias",dias);
	*/
	//EJERCICIO 11
	/*
	int hora=-1;
	int dia;

	while (hora<0 || hora>24)
	{
		printf("Hora=");
		scanf("%d",&hora);
	}
	while (dia<1||dia>7)
	{
		printf("dia=");
		scanf("%d",&dia);
	}
	
	if (dia>=6&&dia<=7){
		printf("Todo el fin de semana es Valle");
	}
	else{
		switch (dia)
		{
		case 1:
			printf("Lunes a las ");
			break;
		case 2:
			printf("Martes a las ");
			break;
		case 3:
			printf("Miercoles a las ");
			break;
		case 4:
			printf("Jueves a las ");
			break;
		case 5:
			printf("Viernes a las ");
			break;
		case 6:
			printf("Sabado a las ");
			break;
		case 7:
			printf("Domingo a las ");
			break;
		default:
			break;
		}
		if (hora>=0&&hora<=8)
		{
			printf("%d es Valle",hora);
		}
		else if((hora>=9 && hora<=10) ||(hora>=15&&hora<=18)||(hora>=23&&hora<=24)){
			printf("%d es Llano",hora);
		}
		else{
			printf("%d es Punta",hora);
		}
	*/
	//EJERCICIO 12:
	/*
	int dia,mes;

	printf("mes: ");
	scanf("%d",&mes);
	printf("dia: ");
	scanf("%d",&dia);

	if (mes>=1&&mes<=2||mes==3&&dia<=20||mes==12&&dia>=21)
	{
		printf("Invierno");
	}
	else if(mes==3&&dia>20||mes>=4&&mes<=5||mes==6&&dia<=20){
		printf("Primavera");
	}
	else if(mes==6&&dia>20||mes>=7&&mes<=8||mes==9&&dia<=20){
		printf("Verano");
	}
	else{
		printf("Otoño");
	}
	*/
	//EJERCICIO 13:
	/*
	int precio,cuenta=-1,dia;

	while (dia<=0 || dia>7 )
	{
		printf("dia: ");
		scanf("%d",&dia);
	}
	while(cuenta<0)
	{
		printf("cantidad pagada: ");
		scanf("%d",&cuenta);
	}

	if(dia>=1&&dia<=5)
	{
		precio=10;
	}
	else{
		precio=14;
	}

	if(precio>cuenta){
		printf("Sr cliente, faltan %d€",precio-cuenta);
	}
	else if(cuenta>precio){
		printf("Sr cliente, su cambio: %d€",cuenta-precio);
	}
	else{
		printf("Sr cliente, tenga un buen dia");
	}
	*/
	//EJERCICIO 14:
	/*
	int a,b,c;

	printf("a=");
	scanf("%d",&a);
	printf("b=");
	scanf("%d",&b);
	printf("c=");
	scanf("%d",&c);

	if(b>=a && c>=b)
	{
		printf("La secuencia es creciente");
	}
	else if(a>=b && b>=c)
	{
		printf("La secuencia es decreciente");
	}
	else
	{
		printf("La secuencia no es creciente ni decreciente");
	}
	*/
	//EJERCICIO 15:
	/*
	int a,b,c,max1,max2,max3;

	printf("a: ");
	scanf("%d",&a);
	printf("b: ");
	scanf("%d",&b);
	printf("c: ");
	scanf("%d",&c);

	if (a>b&&a>c)
	{
		max1=a;
	}
	else if (b>a&&b>c)
	{
		max1=b;
	}
	else if (c>b&&c>a)
	{
		max1=c;
	}
	if (a<b&&a<c)
	{
		max3=a;
	}
	else if (b<a&&b<c)
	{
		max3=b;
	}
	else if (c<b&&c<a)
	{
		max3=c;
	}
	if (a>max3&&a<max1)
	{
		max2=a;
	}
	else if (b>max3&&b<max1)
	{
		max2=b;
	}
	else if (c>max3&&c<max1)
	{
		max2=c;
	}
	
	printf("%d, %d, %d",max3,max2,max1);
	*/
	//EJERCICIO 16:
	/*
	a=2  b=1 aux=1 
	c=1 - b=3 - aux=1
	a=3   b=2   aux=2 
	a=3,b=2,c=1
	printf 3,2,1 
	Los ordena de manera decreciente.
	*/
	//EJERCICIO 17:
	/*
	int traspas=0,any,duesPrimeresXifres;

    printf("Introdueix l'any: ");
    scanf("%d",&any);

    // es div entre 4 i no es final de segle
    // es div entre 4 , es final de segle i les dos primers numeros son div entre 4

    if (any%4==0 && any%100!=0)
    {
        //2004, 2008
        traspas=1;
    }
    else if (any%4==0 && any%100==0)
    {
        //2000, 3000
        duesPrimeresXifres=any/100;
        if (duesPrimeresXifres%4==0)
        {
            //2000
            traspas=1;
        }
    }

    printf("L'any %d es any de traspas %d",any, traspas);
	*/
	//EJERCICIO 18:
	/*
	int horas;
	float preciohora,deduccion,sueldo;

	printf("horas: ");
	scanf("%d",&horas);
	printf("preciohora: ",&preciohora);
	scanf("%f",&preciohora);

	if (horas<35)
	{
		sueldo=horas*preciohora;
	}
	else{
		sueldo=34*preciohora+((horas-34)*preciohora*1.5);
	}
	
	if (sueldo<=120){
		sueldo==sueldo;
	}
	else if(sueldo<=900){
		sueldo=sueldo*0.8;
	}
	else{
		sueldo=900*0.8+sueldo-900;
	}

	printf("El sueldo final es %.2f",sueldo);
	*/
	//EJERCICIO 19
	/*
	char tipus;
	float precio,litros;
	bool client;
	printf("tipo de gasolina(95=a,98=b,gasoil=c): ");
	scanf("%c",&tipus);
	printf("cantidad de litros: ");
	scanf("%f",&litros);
	printf("dispones de tarjeta cliente? 1:si 2:no");
	scanf("%d",&tipus);

	if (tipus=="a"||tipus=="A")
	{
		precio=litros*2.083;
	}
	else if(tipus=="b"||tipus=="B"){
		precio=litros*2.238;
	}
	else{
		precio=litros*2.003;
	}

	if (client==true)
	{
		precio=precio*0.9;
	}
	
	printf("%.2f€",precio);
	*/
	//EJERCICIO 20: 
	/*
	int dia=0;
	float precio;
	bool socio;
	
	printf("eres socio(1:si 0:no): ");
	scanf("%d",&socio);

	printf("que dia es: ");
	scanf("%d",&dia);

	if (dia>=1&&dia<=5)
	{
		precio=80;
	}
	else{
		precio=100;
	}

	if (socio==true)
	{
		precio=precio*0.95;
	}
	
	printf("%.2f€",precio);
	*/
	//EJERCICIO 21:
	/*
	float precio;
	int dia,edad;

	printf("que edad tienes: ");
	scanf("%d",&edad);

	printf("que dia es?");
	scanf("%d",&dia);

	if(dia>=1&&dia<=5){
		precio=8;
	}
	else{
		precio=12;
	}

	if(edad>=0&&edad<=15){
		precio=precio*0.7;
	}
	else if(edad>=16 && edad<=59){
		precio=precio*0.3;
	}
	else{
		precio=precio*0.15;
	}

	printf("%.2f",precio);
	*/
	//EJERCICIO 22:
	/*
	int adultos,menores,dia;
	float precio;

	printf("que dia es: ");
	scanf("%d",&dia);

	printf("cuantos menores hay: ");
	scanf("%d",&menores);

	printf("cuantos mayores hay: ");
	scanf("%d",&adultos);

	precio=menores*8.50+adultos*10.50;

	if (menores>=2&&adultos>=2)
	{
		precio=precio*0.8;
	}
	
	if (dia==2)
	{
		precio=precio*0.7;
	}
	
	printf("precio: %.2f",precio);
	*/

	acabament();
	return 0;
}
