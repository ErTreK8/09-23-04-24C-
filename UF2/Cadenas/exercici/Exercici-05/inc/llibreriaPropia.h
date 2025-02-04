#ifndef __LLIBRERIA_PROPIA_H__
#define __LLIBRERIA_PROPIA_H__
//incloure les llibreries que es necessiten
#include <stdbool.h>
    void acabament (void);
        int demanaNumUnLimitInt(int );
    int demanaNumEntreRangInt(int ,int );
    int generarNumEntreRang(int ,int );
    char demanaCaracter(void);
    int demanaNumInt(void);
    void intercanvi(int *,int *);
    void pintavector(int [], int );
    int posicio(int [],int ,int );
    bool cerca(int [], int , int );
    void ordenar(int [],int );
#endif