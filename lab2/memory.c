#include "memory.h"
#include <stdio.h>

int sc_memoryInit() {
    for (int i = 0; i < SIZE; ++i) {
        arr[i] = 0;
    }
    return 0;
}

int sc_memorySet(int address, int value) {
    if (address >= SIZE || address < 0) {
        return 1;
    }
    arr[address] = value;
    return 0;
}

int sc_memoryGet(int address, int *value) {
    if (address >= SIZE || address < 0) {
        return 1;
    }
    *value = arr[address];
    return 0;
}

int sc_memorySave(char *filename) {
    FILE *file = fopen(filename, "wb");

    fwrite(arr, sizeof(int), SIZE, file);
    fclose(file);

    return 0;
}

int sc_memoryLoad(char *filename) {
    FILE *file = fopen(filename, "rb");
    fread(arr, sizeof(int), SIZE, file);
    fclose(file);

    return 0;
}

int sc_regInit() {
    flag = 0;
    return 0;
}

int sc_regSet(int reg, int value) {
    if (reg == P || reg == O || reg == M || reg == T || reg == E) {
        if (value == 0) {
            flag = flag & ~reg;
            return 0;
        } else if (value == 1) {
            flag = flag | reg;
            return 0;
        } else {
            return 1;
        }
    }
    return 1;
}

int sc_regGet(int reg, int *value) {
    if (reg == P || reg == O || reg == M || reg == T || reg == E) {
         if ((flag & reg) != 0) {
             *value = 1;
             return 0;
         } else {
             *value = 0;
             return 0;
         }
    }
    return 1;
}

int sc_commandEncode(int command, int operand, int *value) {
    if (command < 0x10
        || (command > 0x11 && command < 0x20)
        || (command > 0x21 && command < 0x30)
        || (command > 0x33 && command < 0x40)
        || (command > 0x43 && command < 0x51)
        || command > 0x76) {
        return 1;
    }
    if (operand > 0x127 || operand < 0) {
        return 1;
    }
    *value = (command << 7) | operand;

    return 0;
}

int sc_commandDecode(int value, int *command, int *operand) {
    if ((value >> 14) != 0) {
        return 1;
    }
    *command = value >> 7;
    *operand = value & 0x7F; // 7F =  1 111 111
    return 0;
}

int sc_regFlagPrint()
{
    printf("\n\tflag = %d\n", flag);
    return 0;
}