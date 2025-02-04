#ifndef D8E5564E_A998_46E6_9A70_0B73488F1AF3
#define D8E5564E_A998_46E6_9A70_0B73488F1AF3
//incloure les llibreries que es necessiten
#include <stdbool.h>

#define MIDA 255
#define MARCA '\0'
#define TOTALUF 19
#define MAXALUMNES 30

typedef struct
{
    char nomUF[10];
    int nota;
}NOTES;

typedef struct
{
    char nom[MIDA];
    NOTES quali[TOTALUF];
}ALUMNE;


ALUMNE demanaUnAlumne();

#endif /* D8E5564E_A998_46E6_9A70_0B73488F1AF3 */
