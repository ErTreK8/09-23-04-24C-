#ifndef D8E5564E_A998_46E6_9A70_0B73488F1AF3
#define D8E5564E_A998_46E6_9A70_0B73488F1AF3
//incloure les llibreries que es necessiten
#include <stdbool.h>

#define FICADENA '\0'
#define SALTLINIA '\n'
#define ESPAI ' '
#define UBICACIOARTICLE "./fitxers/article.dat"
#define UBICACIOARTICLEAUXILIAR "./fitxers/auxiliar.dat"

typedef struct
{
    char nom[30];
    float preu;
}ARTICLE; 
void generar();
void llegir();
int calculaTotal(char [],int );
void incrementar();
void eliminar();
void copiar(ARTICLE un);

#endif /* D8E5564E_A998_46E6_9A70_0B73488F1AF3 */
