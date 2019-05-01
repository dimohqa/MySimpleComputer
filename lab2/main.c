#include "memory.h"
#include "mt.h"
#include <stdio.h>

int main() {
    printf("Memory:\n");
    if (sc_memoryInit() == 0) {
        printf("sc_memoryInit() - Successful !");
    }
    int i = 15;
    if (sc_memorySet(i, 51) == 0) {
        printf("\nsc_memoryInit() - Successful !");
        printf("\n\tArr[%d] = %d", i, arr[i]);
    } else {
        printf("\nsc_memoryInit() - Not successful !");
    }
    int value;
    if (sc_memoryGet(i, &value) == 0) {
        printf("\nsc_memoryInit() - Successful !");
        printf("\n\tvalue = %d", value);
    } else {
        printf("\nsc_memoryInit() - Not successful !");
    }
    char file[8] = "kek.txt";
    sc_memorySet(10, 25);
    if (sc_memorySave(file) == 0) {
        printf("\nsc_memorySave - Successful !");
    }
    if (sc_memoryLoad(file) == 0) {
        printf("\nsc_memoryLoad - Successful !\n");
        for (int j = 0; j < SIZE; ++j) {
            printf("%d ",arr[j]);
        }
    }
    printf("\nRegistr: \n");
    sc_regInit();
    if (sc_regSet(T, 1) == 0) {
        printf("sc_regSet - Successful !");
        sc_regFlagPrint();
    } else {
        printf("sc_regSet - Not successful !");
    }
    if (sc_regGet(T, &value) == 0) {
        printf("sc_regGet - Successful !");
        printf("\n\tvalue = %d\n", value);
    } else {
        printf("\nsc_regGet - Not successful !");
    }
    printf("Command:");
    if (sc_commandEncode(0x11, 0x59, &value) == 0) {
        printf("\nsc_commandEncode - Successful !\n\t");
        for (int j = 14; j >= 0 ; j--) {
            printf("%d", value&(1<<j)?1:0);
        }
    } else {
        printf("\nsc_commandEncode - Not successful !");

    }
    int command, operand;
    if (sc_commandDecode(value, &command, &operand) == 0) {
        printf("\nsc_commandEncode - Successful !\n\t");
        printf("command = %x\n\t", command);
        printf("operand = %x\n", operand);
    }
    mt_clrscr();
    mt_gotoXY(10, 20);
    return 0;
}
