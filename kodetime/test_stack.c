/*
 * Tests for the stack library
 */

#include "stack.h"

#include <stdio.h>

bool test_stack()
{
  {
    stack s;
    Initialize(&s);
    if(!Empty(&s))
      return false;
  }

  {
    stack s;
    Initialize(&s);
    Push(3, &s);
    if(Empty(&s))
      return false;
  }

  {
    stack s;
    int v;

    Initialize(&s);
    Push(3, &s);
    v = Pop(&s);
    if(v != 3)
      return false;
  }

  {
    stack s;
    int v;

    Initialize(&s);
    Push(3, &s);
    Push(5, &s);
    Push(10, &s);
    v = Pop(&s);
    if(v != 10)
      return false;

    v = Pop(&s);
    if(v != 5)
      return false;

    v = Pop(&s);
    if(v != 3)
      return false;

    if(!Empty(&s))
      return false;
  }

  return true;
}

int main(void)
{
  /* test stack library */
  {
    bool success;
    success = test_stack();
    if(success)
      printf("test succeeded\n");
    else
      printf("test failed\n");
  }

  /* return from body and exit program */
  return 0;
}