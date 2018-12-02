#ifndef _CALC_H_
#define _CALC_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define NUMBER '0'
#define FUNC '@'
#define VAR 'n'

void push(double);
double pop(void);
void print_top(void);
double copy_top(void);
void switch_top2(void);
int getop(char []);
void apply_func(char type[]);
int getch(void);
void ungetch(int);

double ans;

#endif
