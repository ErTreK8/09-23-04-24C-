#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "rlutil.h"
#include "llibreriaPropia.h"
#include "llibreriaExercici.h"

int main()
{
	// 1252 coje codigos distintos no como el UTF_8 i akgi asuÂ¡i
	SetConsoleOutputCP(1252);
	SetConsoleCP(1252);
	srand(time(NULL));

	int qttAlumnes = 0;
	ALUMNE classe[MAXALUMNES];
	int menu = 0;

	// hacer un menu que sea asi
	//	 1. Añadir alumno
	//	 2. modificar alumne
	//	 3. Eliminar Alumne
	//	 4. Calcular Nota
	//	 5. Calcular nota promig de la classe (es demana el modul)
	//	 6. Mostrar alumnes / notas (ordenat por UF)
	// 	 7. sortir

	while (menu != 7)
	{
		do
		{
			cls();
			comentaris(2);
			scanf("%d", &menu);
		} while (menu <= 0 || menu >= 8);

		switch (menu)
		{
		case 1:
			omplirAlumnes(classe, &qttAlumnes);
			break;
		case 2:
			omplirAlumnes(classe, &qttAlumnes);
			break;
		case 3:
			omplirAlumnes(classe, &qttAlumnes);
			break;
		case 4:
			omplirAlumnes(classe, &qttAlumnes);
			break;
		case 5:
			omplirAlumnes(classe, &qttAlumnes);
			break;
		case 6:
			omplirAlumnes(classe, &qttAlumnes);
			break;
		default:
			break;
		}
	}
	cls();

	acabament();
	return 0;
}
