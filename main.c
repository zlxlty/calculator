#include <stdio.h>
#include <stdlib.h>
#include "calc.h"

#define MAXOP 100
#define NUMBER '0'
#define FUNC '@'

extern int getop(char []);
extern void push(double);
extern double pop(void);
extern double ans;

int main(int argc, char const *argv[]) {

  int type;
  double op2;
  char s[MAXOP];

  while ((type = getop(s)) != EOF)
  {
      switch (type) {
      case FUNC:
          apply_func(s);
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
