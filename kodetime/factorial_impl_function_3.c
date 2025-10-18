/*
 * Compute the factorial of a given number.
 */

#include <stdio.h>  /* scanf, printf */
#include <assert.h> /* assert */

int f; /* factorial */

/* Compute the factorial of a given number. */
void fact(int n)
{
    int g; /* previous factorial */
    int i; /* counter variable for factorial */
    int j; /* counter variable for multiplication */
    /* precondition */
    assert(n >= 0);

    /* postcondition */
    g = 1;
    f = 1;
    for (i = 0; i < n; i = i + 1)
    { /* invariant: f equals factorial of i
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
}

int main(void)
{
    int n; /* number for which to compute the factorial */
    /* read input */
    scanf("%d", &n);

    /* call the function */
    fact(n);

    /* print output */
    printf("%d\n", f);

    /* return from the body and exit program */
    return 0;
}