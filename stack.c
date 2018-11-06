#include <stdio.h>
#include "calc.h"
#define MAXVAL 100

static int sp = 0;
static double val[MAXVAL];

void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stackoverflow, can't push %g\n", f);
}

double pop(void)
{
    if (sp > 0)
        return val[--sp];
    else
    {
        printf("error: stack empty\n");
        return 0.0;
    }
}

void print_top(void)
{
    printf("%.2f\n", val[sp-1]);
}

double copy_top(void)
{
    return val[sp-1];
}

void swap_top2(void)
{
    double temp;
    temp = val[sp-1];
    val[sp-1] = val[sp-2];
    val[sp-2] = temp;
}
