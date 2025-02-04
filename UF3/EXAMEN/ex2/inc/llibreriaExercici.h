#ifndef D8E5564E_A998_46E6_9A70_0B73488F1AF3
#define D8E5564E_A998_46E6_9A70_0B73488F1AF3
//incloure les llibreries que es necessiten
#include <stdbool.h>

#define MIDA 255
#define MARCA '\0'
#define UBICACIOFITXERORIGEN "./fitxers/vendes.txt"
#define UBICACIOFITXERORIGENCOPIA "./fitxers/vendesCopia.txt"
#define UBICACIOFITXRESUM "./fitxers/resum.txt"

typedef struct {
    char IDventa[8];
    char nomProducte[35];
    int qttVenut;
    float preu;
    char fehca[13];
}VENTA;

typedef struct {
    char nomProducte[35];
    float gananciaTotal;
}PRODUCTE;



void copiaArixu(char [],char []);
void llegirFitxer(char []);
void saltaLinea(FILE *);
VENTA agafaVenta(FILE *);
bool existeixProducte(char []);
void cojeProducteResum(FILE *,char []);
void escriu(PRODUCTE );
void llegirFinal(char []);

#endif /* D8E5564E_A998_46E6_9A70_0B73488F1AF3 */
