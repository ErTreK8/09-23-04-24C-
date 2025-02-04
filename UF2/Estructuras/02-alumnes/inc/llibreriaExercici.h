#ifndef D8E5564E_A998_46E6_9A70_0B73488F1AF3
#define D8E5564E_A998_46E6_9A70_0B73488F1AF3
//incloure les llibreries que es necessiten
#include <stdbool.h>

#define FICADENA '\0'
#define SALTLINIA '\n'
#define ESPAI ' '
#define MIDA 30
#define TOTALUF 19
#define MAXALUMNES 30
// se podria decir q es un define es como lo del setcolor(GREEN) el GREEN es un ENUM que mira un numero por eso podemos poner setColor(3) por ejemplo y funciona
enum OPCIONSMENU
{
    AFEGIR=1,
    MODIFICAR,
    ELIMINAR,
    INSERIR,
    CALCULARNOTA,
    MOSTRAR,
    SORTIR
};

enum UF
{
    M1UF1=1,
    M1UF2,
    M1UF3,
    M2UF1,
    M2UF2,
    M2UF3,
    M2UF4,
    M3UF1,
    M3UF2,
    M3UF3,
    M4UF1,
    M4UF2,
    M4UF3,
    M6UF1,
    M10UF1,
    M10UF2,
    M11UF1,
    M11UF2,
    M12UF1,
};

enum OPCIONS
{
    NO,
    SI
};

typedef struct
{
    int unitatFor;
    int nota;
}NOTES;

typedef struct
{
    char nom[MIDA];
    NOTES qualificacions[TOTALUF];
    int qttNotesALumne;
}ALUMNE;


int preguntaOpcio();
ALUMNE altaUnAlumne();
void omplirAlumne(ALUMNE [],int *);
void comentaris(int );
bool existeixAlumne(ALUMNE [], int );
void pinta(ALUMNE [],int );
void pintaUnAlumne(ALUMNE );
void ordenar2(NOTES [],int);
void afegirNotesUF(ALUMNE [], int , int );



#endif /* D8E5564E_A998_46E6_9A70_0B73488F1AF3 */
