/*
we will use the Leibniz formula for pi:
pi/4 = sum_k=0( (-1)^k / (2k + 1) ) 
(it's inefficient)
*/

#include <stdio.h>
#include <math.h>

int main(void) {
	double s = 0, ps = 0, k = 0;
	double n = 5;

	do {
		ps = s;
		s += (4 * pow(-1,k)) / (2 * k + 1);
		k++;
	} while(fabs(ps - s) > pow(10,-n-1));

	printf("%.5f\n", s);
	return 0;
}
