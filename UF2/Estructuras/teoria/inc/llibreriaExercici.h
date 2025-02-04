#ifndef D8E5564E_A998_46E6_9A70_0B73488F1AF3
#define D8E5564E_A998_46E6_9A70_0B73488F1AF3
//incloure les llibreries que es necessiten
#include <stdbool.h>

#define MIDA 255
#define FICADENA '\0'
#define SALTLINIA '\n'
#define MIDA 40
// Subestructura
typedef struct
{
    char color[MIDA];
    float pes;
}CARACTERISTICA;


typedef struct 
{
    char nom[MIDA];
    char familia[MIDA];
    float preu;
    CARACTERISTICA car;
}ARTICLE;

void pintaArticle(ARTICLE);
float demanarFloat();
ARTICLE demanarArticle2();



#endif /* D8E5564E_A998_46E6_9A70_0B73488F1AF3 */
