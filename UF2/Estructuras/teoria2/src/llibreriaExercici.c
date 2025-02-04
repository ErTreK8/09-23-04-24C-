#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "rlutil.h"
#include "llibreriaPropia.h"
#include "llibreriaExercici.h"

bool buscaSiExisteix(ALUMNE classe[], int qttAlumnes)
{
    bool existe = false;
    int i=0;
    while (i < qttAlumnes && existe==false)
    {
        int igual=strcmp(classe[i].nom,classe[qttAlumnes].nom);
        if (strcmp(classe[i].nom,classe[qttAlumnes].nom)==0)
        {
            existe = true;
        }
        i++;
    }
    return existe;
}

void omplirAlumnes(ALUMNE classe[], int *qttAlumnes)
{
    if (*qttAlumnes == MAXALUMNES)
    {
        comentaris(1);
    }
    else
    {
        // Poner en el .h que es de tipo ALUMNE porque si no da error
        if (*qttAlumnes != 0)
        {
            do
            {
                classe[*qttAlumnes] = demanaUnAlumne();
                if (buscaSiExisteix(classe, *qttAlumnes) == true)
                {
                    printf("El Alumne ja Existeix");
                }
            } while (buscaSiExisteix(classe, (*qttAlumnes)) == true);
        }
        else
        {
            classe[*qttAlumnes] = demanaUnAlumne();
        }
        (*qttAlumnes)++;
    }
}

void comentaris(int num)
{
    switch (num)
    {
    case 1:
        printf("Classe Plena");
        break;
    case 2:
        printf("1. Añadir alumno\n2. modificar alumne\n3. Eliminar Alumne\n4. Calcular Nota\n5. Calcular nota promig de la classe (es demana el modul)\n6. Mostrar alumnes / notas (ordenat por UF)\n7. sortir\n");
        break;
    case 3:
        printf("Classe Plena");
        break;
    default:
        break;
    }
}

ALUMNE demanaUnAlumne()
{
    ALUMNE alum;
    cls();
    printf("Introdueix el nom del alumne: ");
    entrarCadena(alum.nom,sizeof(alum.nom));
    return alum;
}