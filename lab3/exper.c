#include <stdio.h>
#include "mt.h"

int main() {
    mt_clrscr();
    mt_gotoXY(5, 10);
    mt_setfgcolor(red);
    printf("Dima Shestov");
    mt_gotoXY(6, 8);
    mt_setbgcolor(white);
    mt_setfgcolor(green);
    printf("ИС-742");
    mt_gotoXY(10, 1);
    mt_stopcolor();
    int rows, cols;
    mt_getscreensize(&rows, &cols);
    printf("\n");
    return 0;
}
