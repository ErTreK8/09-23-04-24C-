#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <string.h>
#include <stdbool.h>
#include "rlutil.h"
#include "llibreriaPropia.h"
#include "llibreriaExercici.h"

int main()
{
	SetConsoleOutputCP(1252);
	SetConsoleCP(1252);
	srand(time(NULL));
	int qttAlumnes = 0;
	int NotesUFjaInserides[TOTALUF+1]={0};

    char ufDisponible [TOTALUF][10]={"M1UF1","M1UF2","M1UF3","M2UF1","M2UF2","M2UF3","M2UF4","M3UF1","M3UF2","M3UF3","M4UF1","M4UF2","M4UF3","M6UF1","M10UF1","M10UF2","M11UF1","M11UF2","M12UF1"};


	ALUMNE classe[MAXALUMNES];

	int opcio;

	do
	{
		cls();
		opcio = preguntaOpcio();
		switch (opcio)
			{
			case AFEGIR:
				omplirAlumne(classe, &qttAlumnes);
				break;
			case MODIFICAR:
				break;
			case ELIMINAR:
				break;
			case INSERIR:
				inserirNotes(classe,qttAlumnes,NotesUFjaInserides);
				break;
			case CALCULARNOTA:
				break;
			case MOSTRAR: pinta(classe,qttAlumnes);
				break;
			case SORTIR: printf("\nAdeu");
				break;
			}
		for (int i = 0; i < qttAlumnes; i++)
		{
			ordenar2(classe[i].qualificacions,classe[i].qttNotesALumne);
		}
	
	} while (opcio != SORTIR);

	acabament();
	return 0;
}