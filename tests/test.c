#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "../include/taylor_sine.h"

int main() {
  int n = 4;
  double pi = 3;
  printf("sin(pi) = %f\n", sin(pi));

  double result = taylor_sine(pi, n);
  printf("sin(pi) = %f\n", result);

  return 0;
}


/* Test Resutater
x = pi 
ANSI = 0.001593 
Vores = 0.002643

x = 0.1 
ANSI = 0.099833 
Vores = 0.099833

x = 100 
ANSI = -0.506366 
Vores = 51510615882984200

x = 10
ANSI = -0.544021 
Vores = 4118.900866

Vores funktioner giver samme resultat når sin er lavt, når det er højt fucker den helt op
Hvis vi sætter n op bliver funktionen mere præcis, men n kan ikke blive for høj med Jens' funktion:(

*/