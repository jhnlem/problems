#include <stdlib.h>
#include <stdio.h>
#include <math.h>

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

int main(void)
{
	double a = f(3.14);

	printf("%f\n", a);
	return EXIT_SUCCESS;
}
