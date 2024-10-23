/*
 * Can compute 16 digits of pi.
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <tgmath.h>

/*
 * Calculate sin(x).
 */
double F(double x)
{
	return sin(x);
}

/*
 * Calculate the derivative of sin(x).
 */
double f(double x)
{
	double h = 0.0001;
	return (F(x + h) - F(x)) / h;
}


int main(int argc, char *argv[])
{
	double s = 2.0;
	double ps = 0.0;
	long n = strtol(argv[1], 0, 10);

	while (fabs(s - ps) > pow(10,-n - 1)) {
		ps = s;
		s -= F(s) / f(s); // Newton's method.
	}

	size_t dgt = (size_t){(s - 3) * pow(10,n - 1)} ;
	printf("3.%zu\n", dgt);
	return EXIT_SUCCESS;
}
