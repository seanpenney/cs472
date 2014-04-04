// Sean Penney and Paul Atkinson, Lab1

#include <math.h>
#include <float.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	double x, r;
	int exp;

	x = strtod(argv[1], NULL);
	r = frexp(x, &exp);

	printf("frexp(%g, &e) = %g: %g * %d^%d = %g\n",
			x, r, r, FLT_RADIX, exp, x);
	exit(EXIT_SUCCESS);
}

double frexp(double x, int *exp) {
	int exponent = 2; // check the largest value needed for the exponent
	int counter = 1; // keep track of how many times exponent is multiplied by 2
	double fraction;
	
	if (x == NAN) {
		return NAN;
	}
	if (x == INFINITY) {
		return INFINITY;
	}
	if (x == -INFINITY) {
		return -INFINITY;
	}
	if (x == 0) {
		*exp = 0;
		return 0;
	}
	
	while (exponent < x) {
		exponent = 2*exponent; // increase by another power of 2
		counter++;
	}
	*exp = counter; // store exponent 
	
	fraction = x / exponent;
	return fraction;
}