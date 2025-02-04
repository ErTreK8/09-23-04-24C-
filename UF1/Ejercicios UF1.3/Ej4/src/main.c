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
	int numeroGanador1, numeroGanador2, numeroGanador3, numeroUsuario1, numeroUsuario2, numeroUsuario3, NumeroEncerts;
	
	CombinacioGuanyadora(&numeroGanador1, &numeroGanador2, &numeroGanador3);
	printf("%d %d %d \n\n", numeroGanador1, numeroGanador2, numeroGanador3);
	CombinacioUsuario(&numeroUsuario1, &numeroUsuario2, &numeroUsuario3);
	printf("\nConvinacio Usuario: %d %d %d\n\n", numeroUsuario1,numeroUsuario2, numeroUsuario3);
	NumeroEncerts=CalculaEncerets(numeroGanador1, numeroGanador2, numeroGanador3, numeroUsuario1, numeroUsuario2, numeroUsuario3);
	printf("Has encertat %d Numeros", NumeroEncerts);
	acabament();
	return 0;
}
