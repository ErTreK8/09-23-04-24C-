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
	int caixa=3000, importJugador=0, numLoteria=0, numJugador=0, apostaMax=0, digitos=0, aposta;
	bool bucle=false;
	char seguir;

	printf("INTRODUCCIO DE DADES:\nIntrodueix quin es l'import inicial del jugador [100-1000]: ");
	importJugador=demanarNumeroMinMax(MIN_IMPORT_JUGADOR, MAX_IMPORT_JUGADOR);
	while (bucle!=true)
	{
		numLoteria=RandomizadorNumeros(MIN_LOTERIA, MAX_LOTERIA);	
		printaNumeroLoteria(numLoteria);
		printaMarcadorInicial(caixa, importJugador);
		numJugador=demanarNumeroMinMax(0,MAX_LOTERIA);
		apostaMax=caixa/50;
		printf("Quin es l'import que et vols apostar: [1..%d]: ", apostaMax);
		aposta=demanarNumeroMinMax(1,apostaMax); 
		resumInicial(numJugador,aposta);
		digitos=pruebaDigitos(numLoteria,numJugador);
		importJugador=calcularPremi(aposta, digitos, importJugador);
		pirntfaResumFinal(digitos,importJugador, caixa, numJugador, numLoteria);
		seguir=SioNo();
		bucle=salirBucle(seguir,importJugador,caixa);
	}
	

	acabament();
	return 0;
}
