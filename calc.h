#ifndef _CALC_H_
#define _CALC_H_

#define NUMBER '0'
#define FUNC '@'

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
