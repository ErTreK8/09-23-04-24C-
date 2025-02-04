#ifndef D8E5564E_A998_46E6_9A70_0B73488F1AF3
#define D8E5564E_A998_46E6_9A70_0B73488F1AF3
//incloure les llibreries que es necessiten
#include <stdbool.h>

#define FICADENA '\0'
#define SALTLINIA '\n'
#define ESPAI ' '

#define UBICACIOFITXERORIGEN "./fitxers/origen.txt"
#define UBICACIOFITXRESUM "./fitxers/resum.txt"
#define UBICACIOFITXRESUMCOPIA "./fitxers/resumCopia.txt"
#define UBICACIOFITXRESUMBONIC "./fitxers/resumBonic.txt"
typedef struct
{
    char esport[50];
    char nacionalitat[50];
}ESPORTNACIONALITAT;

typedef struct
{
    char esport[50];
    char nacionalitat[50];
    int cont;
}ESPORTNACIONALITATRESUM;


ESPORTNACIONALITAT llegirUnEsportNacionalitat(FILE *);
void llegirFitxerOrigen();
bool cercaEsportNacionalitat(ESPORTNACIONALITAT );
ESPORTNACIONALITATRESUM llegirFitxerResum(FILE *);
void tractament(ESPORTNACIONALITAT );
void incrementarEn1(ESPORTNACIONALITAT );
void actualitzar(ESPORTNACIONALITATRESUM ,FILE *);
int calculaPosicio(ESPORTNACIONALITAT  );
void afegirEnLaPosicio(ESPORTNACIONALITAT , int );
int calculaLinies();
void generarFitxerBonic();
void imprimirCapacelera(ESPORTNACIONALITATRESUM );
void imprimirPaisContador(ESPORTNACIONALITATRESUM );

#endif /* D8E5564E_A998_46E6_9A70_0B73488F1AF3 */
