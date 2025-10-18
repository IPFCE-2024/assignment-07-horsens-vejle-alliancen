/*
 * Evaluation of an expression.
 */

#include <stdio.h>   /* scanf, printf */
#include <stdlib.h>  /* abort */
#include <stdbool.h> /* bool, true, false */

#include "stack.h"   /* Initialize, Push, Pop, Empty, Full */

#define SIZE 7 /* size of the expression array */

typedef enum { NUMBER, OPERATOR } command;

typedef struct
{
	command com; /* command of the term */
	int num; /* the number if com == NUMBER */
	char op; /* the operator if com == OPERATOR */
} symbol;


/* Postfix expression: (((4 6 *) 8 *) 98 -) without the brackets */
symbol expr[SIZE] = 
{
 { NUMBER,    4,  0 },
 { NUMBER,    6,  0 },
 { OPERATOR,  0, '*'},
 { NUMBER,    8,  0 },
 { OPERATOR,  0, '*'},
 { NUMBER,   98,  0 },
 { OPERATOR,  0, '-'},
};

/* utility function to print the symbol */
void print(symbol *s)
{
  if(s->com == NUMBER)
    printf("%d",s->num);
  else if(s->com == OPERATOR)
    printf("%c",s->op);
  else
   abort();
}

/* program body */
int main(void)
{
    stack s;   /* stack used to evaluate the expression */
    int curr;  /* current symbol variable */
    
    int v1;    /* first operand on which an arithmetic operator is applied */
    int v2;    /* second operand on which an arithmetic operator is applied */
    int res;   /* result of applying the operator to the operands */

    /* precondition */
    /* true */
    
    /* postcondition */

    Initialize(&s);

    for (curr = 0; curr < SIZE; curr = curr + 1)
    {
      switch (expr[curr].com)
      {
        case NUMBER:
            /* numbers are pushed to the stack */
            Push(expr[curr].num, &s);
            break;
        case OPERATOR:
            /* carry out specified operation on last two */
            /* numbers (operands) on the stack, and push result */
            /* to the stack */

            v2 = Pop(&s);
            v1 = Pop(&s);

            switch (expr[curr].op)
            {
                case '+':
                    res = v1 + v2;
                    break;
                case '-':
                    res = v1 - v2;
                    break;
                case '*':
                    res = v1 * v2;
                    break;
                case '/':
                    res = v1 / v2;
                    break;
                default:
                    abort();
            }

            Push(res, &s);

            break;
        default:
            abort();

      }

      /* print intermediate evaluation results to console */
      printf("------\nNext symbol:");
      print(&(expr[curr]));
      Print(&s);

    }

    /* The final value on the stack is the final evaluation of the expression */

    res = Pop(&s);
    printf("%d\n", res);
    
    /* return from body and exit program */
    return 0;
}