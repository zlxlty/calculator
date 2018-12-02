#include "calc.h"

extern void push(double);
extern double pop(void);
extern double ans;

void apply_func(char type[])
{
    double op2;

    if (strcmp(type, "sin") == 0)
        push(sin(pop()/180*3.1415926));
    else if (strcmp(type, "exp") == 0)
        push(exp(pop()));
    else if (strcmp(type, "ans") == 0)
        push(ans);
    else if (strcmp(type, "pow") == 0)
    {
        op2 = pop();
        push(pow(pop(), op2));
    }
    else
        printf("\terror: invalid function\n");
}
