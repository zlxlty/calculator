#ifndef _CALC_H_
#define _CALC_H_

#define NUMBER '0'
void push(double);
double pop(void);
void print_top(void);
double copy_top(void);
void switch_top(void);
int getop(char []);
int getch(void);
void ungetch(int);

#endif
