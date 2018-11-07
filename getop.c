#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "calc.h"

int getop(char s[])
{
    int i,c;

// if the operation if space or \t
    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';

// if the operation is a negative number
    if (c == '-')
    {
        if (isdigit(c = getch()))
        {
            s[0] = '-';
            ungetch(c);
        }else{
            ungetch(c);
            return '-';
        }
    }

// if the operation is in alphebat
    i = 0;
    if (isalpha(c))
    {
        while (isalpha(s[++i] = c = getch()))
            ;
        s[i] = '\0';
        if (c != EOF)
            ungetch(c);
        if (strlen(s) > 1)
            return FUNC;
        else
            return VAR;
    }


// if the operation is arithmetic symbol
    if (!isdigit(c) && c != '.')
        return c;

// if the operation is digits
    i = 0;
    if (isdigit(c))
        while (isdigit(s[++i] = c = getch()))
            ;
    if (c == '.')
        while (isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';
    if (c != EOF)
        ungetch(c);
    return NUMBER;
}
