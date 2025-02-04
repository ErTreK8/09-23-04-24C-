#ifndef __LLIBRERIA_PROPIA_H__
#define __LLIBRERIA_PROPIA_H__
//incloure les llibreries que es necessiten
#include <stdbool.h>
    
    void acabament (void);
    int demanaNumUnLimitInt(int);
    int demanarNumeroMinMax(int, int);
    int demanarNumero (void);
    int calculaQuantitatDigits(int);
    char demanarCaracter(void);
    int RandomizadorNumeros(int, int);
    void pintaQuadrat(int,int);
    void pintaVector(int[],int);
    int posicio(int[],int,int);
    bool cerca(int [], int, int );
    void moureVector(int[],int,int);
    void intercanvi(int *,int *);
    void ordenarVector(int[],int);
    void entrarCadena(char[], int);
    bool esLletra(char);
    FILE *obrirFitxer(const char [], char []);
#endif