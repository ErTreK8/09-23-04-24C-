#ifndef D8E5564E_A998_46E6_9A70_0B73488F1AF3
#define D8E5564E_A998_46E6_9A70_0B73488F1AF3
//incloure les llibreries que es necessiten
#include <stdbool.h>

#define MIDA 255
#define MARCA '\0'

typedef struct
{
    char nom[MIDA];
    char cognom[MIDA];
    int edat;
}ALUMNE; // nomes es pot fer un unic element NO VECTOR D'ESTRUCTURES

void crear(const char []);
void llegir(const char[]);
ALUMNE llegirAlumneFitxer(FILE *);
void pintaALumne(ALUMNE);



#endif /* D8E5564E_A998_46E6_9A70_0B73488F1AF3 */
