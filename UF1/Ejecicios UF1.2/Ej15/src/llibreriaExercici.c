#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include <stdbool.h> 
#include "rlutil.h"
#include "llibreriaPropia.h"
#include "llibreriaExercici.h"

void printa(int x, int y){
    while (kbhit()!= true)
    {
        gotoxy(x,y);
        printf("-");
        Sleep(60);
        cls();
        gotoxy(x,y);
        printf("/");
        Sleep(60);
        cls();
        gotoxy(x,y);
        printf("|");
        Sleep(60);
        cls();
        gotoxy(x,y);
        printf("\\");
        Sleep(60);
        cls();
        kbhit();
    }
}