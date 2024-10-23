#include <stdlib.h>
#include <stdio.h>
#include <tgmath.h>

/*
 * Calculate sin(x).
 */
double complex F(double complex x)
{
	return csin(x);
}

/*
 * Calculate the derivative of sin(x).
 */
double complex f(double complex x)
{
	double h = 0.0001;
	return (F(x + h) - F(x)) / h;
}

int main(void)
{
	double complex z = f(3.14 + 0.5*I);

	printf("%f + (%f)i\n", crealf(z), cimagf(z));
	return EXIT_SUCCESS;
}
