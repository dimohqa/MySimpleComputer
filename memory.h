#ifndef MYSIMPLECOMPUTER_MEMORY_H
#define MYSIMPLECOMPUTER_MEMORY_H
#define P 00000001
#define O 00000010
#define M 00000100
#define T 00001000
#define E 00010000
#define Y 00100000


#define SIZE 100
int arr[SIZE];

int flag;

int sc_memoryInit();
int sc_memorySet(int address, int value);
int sc_memoryGet(int address, int *value);
int sc_memorySave(char *filename);
int sc_memoryLoad(char *filename);
int sc_regInit();
int sc_regSet(int reg, int value);
int sc_regGet(int reg, int *value);
int sc_commandEncode(int command, int operand, int *value);
int sc_commandDecode(int value, int *command, int *operand);
int sc_regFlagPrint();

#endif //MYSIMPLECOMPUTER_MEMORY_H
