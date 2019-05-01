#ifndef MYBIGCHARS_H
#define MYBIGCHARS_H

#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <../lab3/mt.h>

#define BC_ANGLE_LEFT_UP "l"
#define	BC_ANGLE_LEFT_DOWN "m"
#define	BC_ANGLE_RIGHT_UP "k"
#define	BC_ANGLE_RIGHT_DOWN "j"
#define	BC_LINE_VERTICAL "x"
#define	BC_LINE_HORIZONTAL "q"
#define	BC_CAGED_CELL "a"

int bc_printA(char* str);
int bc_box(int x1, int y1, int x2, int y2);

#endif