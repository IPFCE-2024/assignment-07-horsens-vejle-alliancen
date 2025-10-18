/*
 * Stack data structure implemented using integer array
 */

#ifndef _STACK_H_
#define _STACK_H_

#include <stdio.h>   /* printf */
#include <assert.h>  /* assert */
#include <stdbool.h> /* bool, true, false */

#define STACKSIZE 10

typedef struct
{
  int  data[STACKSIZE + 1];
  int  top;
} stack;


/* Create an empty stack */
void Initialize(stack *s);

/* Insert item x at the top of stack s */
void Push(int x, stack *s);

/* Return (and remove) the top item of stack s */
int Pop(stack *s);

/* Test whether a stack can accept more pushes */
bool Full(stack *s);

/* Test whether a stack can accept more pops */
bool Empty(stack *s);

/* Print the contents of the stack */
void Print(stack *s);

#endif