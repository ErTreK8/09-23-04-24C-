#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <string.h>
#include <stdbool.h>
#include "rlutil.h"
#include "llibreriaPropia.h"
#include "llibreriaExercici.h"

int preguntaOpcio()
{
    char opcionsMenu[SORTIR][40] = {"Afegir alumne",
                                    "Modificar alumne",
                                    "Eliminar alumne",
                                    "Inserir notes",
                                    "Calcular Nota",
                                    "Mostrar alumnes",
                                    "Sortir"};

    int op;
    printf("MENU:\n");
    for (int i = 0; i < SORTIR; i++)
    {
        printf("%d.- %s\n", i + 1, opcionsMenu[i]);
    }

    printf("\nIntrodueix quina opcio vols fer? [%d-%d]: ", 1, SORTIR);
    op = demanaNumEntreRangInt(AFEGIR, SORTIR);
    return op;
}
void omplirAlumne(ALUMNE classe[], int *qttAlumnes)
{
    if (*qttAlumnes == MAXALUMNES)
    {
        comentaris(1);
    }
    else
    {
        classe[*qttAlumnes] = altaUnAlumne();
        if (existeixAlumne(classe, *qttAlumnes) == false)
            (*qttAlumnes)++;
        else
            comentaris(3);
    }
}
void comentaris(int num)
{
    printf("\n");
    switch (num)
    {
    case 1:
        printf("Classe plena");
        break;
    case 2:
        printf("Classe buida");
        break;
    case 3:
        printf("Alumne ja donat d'alta en el sistema");
        break;
    case 4:
        printf("No se le puede introducir la Nota");
        break;
    case 5:
        printf("Notes Ja introduides en aquesta UF");
        break;
    }
    printf("\n");
}

ALUMNE altaUnAlumne()
{
    ALUMNE nou;
    printf("Introdueix el nom de l'alumne: ");
    entrarCadena(nou.nom, sizeof(nou.nom));

    nou.qttNotesALumne = 0;
    return nou;
}
bool existeixAlumne(ALUMNE classe[], int qttA)
{
    bool existeix = false;
    int i = 0;
    while (existeix == false && i < qttA)
    {
        if (strcmpi(classe[i].nom, classe[qttA].nom) == 0)
        {
            existeix = true;
        }
        else
        {
            i++;
        }
    }
    return existeix;
}

void ordenar2(NOTES v[],int qttNotesALumne)
{
    bool canvi=false;

    for (int i=0;i<qttNotesALumne-1 && !canvi;i++)
    {
        for (int j=0;j<qttNotesALumne-i-1;j++)
        {
            if (v[j].unitatFor>v[j+1].unitatFor)
            {
                canvi=true;
                intercanvi(&v[j].unitatFor,&v[j+1].unitatFor);
                intercanvi(&v[j].nota,&v[j+1].nota);
            }
        }
        canvi=!canvi;
    }
}

void pinta(ALUMNE classe[], int qttAlumnes)
{
    char ufDisponible [TOTALUF][10]={"M1UF1","M1UF2","M1UF3","M2UF1","M2UF2","M2UF3","M2UF4","M3UF1","M3UF2","M3UF3","M4UF1","M4UF2","M4UF3","M6UF1","M10UF1","M10UF2","M11UF1","M11UF2","M12UF1"};
    if (qttAlumnes == 0)
    {
        comentaris(2);
        getch();
    }
    else
    {
        for (int i = 0; i < qttAlumnes; i++)
        {
            pintaUnAlumne(classe[i]);
            for (int j = 0; j < classe[i].qttNotesALumne; j++)
            {

                printf("La nota de %s es de %d\n",ufDisponible[classe[i].qualificacions[j].unitatFor-1],classe[i].qualificacions[j].nota);
            }
            getch();
        }
    }
    
}
void pintaUnAlumne(ALUMNE un)
{
    printf("\nAlumne: %s \n", un.nom);
}

void inserirNotes(ALUMNE classe[], int qttAlumnes, int NotesUFjaInserides[])
{
    int unitatFormativa;
    printf("\nIntrodueix a quina UF vols inserir les notes: ");
    unitatFormativa = demanaNumEntreRangInt(M1UF1, M12UF1);
    if (NotesUFjaInserides[unitatFormativa] == 1)
    {
        comentaris(5);
    }
    else
    {
        afegirNotesUF(classe, qttAlumnes, unitatFormativa);
        NotesUFjaInserides[unitatFormativa]++;
    }
}

void afegirNotesUF(ALUMNE classe[], int qttAlumnes, int unitatFormativa)
{
    for (int i = 0; i < qttAlumnes; i++)
    {
        printf("Alumne %s fa la materia? ", classe[i].nom);

        if (demanaNumEntreRangInt(NO, SI) == SI /* Asi se usa el enum*/)
        {
            printf("Nota: ");
            classe[i].qualificacions[classe[i].qttNotesALumne].nota = demanaNumEntreRangInt(0, 10);
            classe[i].qualificacions[classe[i].qttNotesALumne].unitatFor = unitatFormativa;
            classe[i].qttNotesALumne++;
        }
        else
        {
            comentaris(4);
        }
    }
}