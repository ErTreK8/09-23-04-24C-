#ifndef D8E5564E_A998_46E6_9A70_0B73488F1AF3
#define D8E5564E_A998_46E6_9A70_0B73488F1AF3
//incloure les llibreries que es necessiten
#include <stdbool.h>

#define MIDA 255
#define MARCA '\0'
#define MAX_NOM 25
#define MAX_PAIS 20

#define UBICACIOCOMPANYIA "./fitxers/companyies.dat"
#define UBICACIOARTICLEAUXILIAR "./fitxers/auxiliar.dat"

typedef struct {  
		char nomComp[MAX_NOM];		// MAX_NOM=25; 
char paisComp[MAX_PAIS];    	// MAX_PAIS=20;  
}COMPANYIA; 


void inserirNovaCompanyia();
bool existeixCompamyia(char []);
void inserirUnaCompanyia(COMPANYIA , char []);
int calculaTotal(char [], int );
void mostrarCompanyies2();
void ordenar();

#endif /* D8E5564E_A998_46E6_9A70_0B73488F1AF3 */
