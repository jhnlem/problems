#include <stdlib.h>
#include <stdio.h>

/*
 * Recursive quicksort.
 */
void rqsort(size_t first, size_t last, double V[])
{
	if (first < last) {
		double pivot = V[last];
		size_t f = first;
		size_t l = last;
		while (f < l) {	
			if (V[l] < V[f]) {
				V[l] = V[f];
				V[f] = V[l - 1];
				V[l - 1] = pivot;
				l--;
			} else {
				f++;
			}
		}
		rqsort(first, l - 1, V);
		rqsort(l + 1, last, V);
	}
}

/*
 * Call recursive quicksort.
 */
 void quicksort(size_t size, double V[])
 {
	rqsort(0, size - 1, V);
 }

/*
 * Check if is sorted.
 */
size_t issorted(size_t size, double V[])
{
        for (size_t t = 0; t < size - 1; ++t) {
                if (V[t] > V[t + 1]) {
                        return 0;
                }
        }
        return 1;
}

int main(void) {
	double V[] = {
		4.0,
		52.0,
		23.5,
		12.1,
		34.2,
		67.8,
		90.1,
		11.3,
		45.6,
		78.9,
		22.2,
		33.3,
		-44.4,
		55.5,
		-66.6,
		77.7,
		-88.8,
		99.9,
		10.0,
		20.1,
		31.2,
		41.3,
		-51.4,
		-61.5,
		71.6,
		81.7,
		91.8,
		2.9,
		13.0,
		24.1,
                 };
	size_t size = sizeof(V) / sizeof(V[0]);

        quicksort(size, V);

        size_t sorted = issorted(size, V);
        if (sorted) {
                for (size_t i = 0; i < size; ++i) {
                        printf("%f\n", V[i]);
                }
        }
        else {
                printf("The array is not sorted.\n");
        }
        return EXIT_SUCCESS;
}
