#ifndef D8E5564E_A998_46E6_9A70_0B73488F1AF3
#define D8E5564E_A998_46E6_9A70_0B73488F1AF3
//incloure les llibreries que es necessiten
#include <stdbool.h>

#define MIDA 255
#define MARCA '\0'

#define ALUMNES "./fitxers/alumnes.txt"
#define ACTUALITZAR "./fitxers/actualitzacio.txt"

typedef struct
{
    char curs[30];
    char letra;
}CURSQUANTITAT;

void llegir(char []);
CURSQUANTITAT llegirUnCurs(FILE *);


#endif /* D8E5564E_A998_46E6_9A70_0B73488F1AF3 */
