#include <stdio.h>
#include <stdlib.h>
#include "myBigChars.h"

int main() {
    int bcintA [2] = {2118269952, 4342338};
    int bcintB [2] = {1044528640, 4080194};
    int bcintC [2] = {37895168, 3949058};
    mt_clrscr();
    bc_box(1, 1, 10, 26);
    bc_printbigchar(bcintA, 2, 2, purple, cyan);
    bc_printbigchar(bcintB, 2, 10, red, cyan);
    bc_printbigchar(bcintC, 2, 18, green, cyan);
    return 0;
}