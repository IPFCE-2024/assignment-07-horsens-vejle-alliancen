/*
 * Compute the factorial of a given number using a library.
 */

#include <stdio.h>         /* scanf, printf */
#include "factorial_lib.h" /* fact */

/* program body */
int main(void)
{
    int n; /* number for which to compute the factorial */
    int f; /* factorial */
        
    /* read input */
    scanf("%d", &n);
    
    /* call the function */
    f = fact(n);
    
    /* print output */
    printf("%d\n", f);
    
    /* return from body and exit program */
    return 0;
}