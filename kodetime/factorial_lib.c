/*
 * Library source code for mathematics functions
 */

#include "factorial_lib.h"
#include <assert.h>  /* assert */

/* Compute the factorial of a given number. */
int fact(int n)
{
    int f; /* factorial */
    int g; /* previous factorial */
    int i; /* counter variable for factorial */
    int j; /* counter variable for multiplication */
    /* precondition */
    assert(n >= 0);
    
    /* postcondition */
    g = 1;
    f = 1;
    for (i = 0; i < n; i = i + 1)
    {   /* invariant: f equals factorial of i
         *            0 <= i <= n
         */
        for (j = 0; j < i; j = j + 1)
        { /* invariant: g = (j + 1) * f
           *            0 <= j <= i 
           */
            g = g + f;
        }
        f = g;
    }   
    return f;
}
