#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "calc.h"

#define MAXOP 100

extern int getop(char []);
extern void push(double);
extern double pop(void);
extern double ans;

int main(int argc, char const *argv[]) {

  int i,type;
  double op2;
  char s[MAXOP];
  char upvar;
  double vars[26];

  for (i = 0; i < 26; i++)
      vars[i] = 0.0;

  while ((type = getop(s)) != EOF)
  {
      switch (type) {
      case FUNC:
          apply_func(s);
          break;

      case VAR:
          upvar = s[0];
          if (upvar >= 'A' && upvar <= 'Z')
              push(vars[upvar - 'A']);
          break;

      case '=':
          pop();
          // printf("%c\n", upvar);
          if (upvar >= 'A' && upvar <= 'Z')
          {
              vars[upvar - 'A'] = pop();
              push(vars[upvar - 'A']);
          }
          else
              printf("error: No such variable\n");
          break;

      case NUMBER:
          push(atof(s));
          break;

      case '+':
          push(pop() + pop());
          break;

      case '*':
          push(pop() * pop());
          break;

      case '-':
          op2 = pop();
          push(pop() - op2);
          break;

      case '/':
          op2 = pop();
          if (op2 != 0.0)
              push(pop() / op2);
          else
              printf("error: zero divisor\n");
          break;

      case '\n':
          ans = pop();
          printf("\t%.5g\n", ans);
          break;

      default:
          printf("error: unknown command %s\n", s);
          break;
      }
  }

  return 0;
}
