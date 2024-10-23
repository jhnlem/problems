#include <stdlib.h>
#include <stdio.h>

/*
 * Split the array V in half and merge the sub arrays.
 */
void merge(size_t first, size_t last, double V[])
{
	size_t llast = (first + last) / 2;
	size_t rfirst = llast + 1;
	
	size_t sizeV = last - first + 1;
	double U[sizeV];

	size_t i = first;
	size_t j = rfirst;
	size_t c = 0;

	// Merge the sub arrays until one of them ends.
	while (i <= llast && j <= last) {
		if (V[i] <= V[j]) {
			U[c] = V[i];	
			i++;
		} else {
			U[c] = V[j];
			j++;
		}
		c++;
	}

	// Append the remaining.
	while (i <= llast) {
		U[c] = V[i];
		i++;
		c++;
	}
	while (j <= last) {
		U[c] = V[j];
		j++;
		c++;
	}

	for (size_t t = first; t <= last; ++t)
		V[t] = U[t - first];
}

/*
 * Recursive mergesort.
 */
void rmsort(size_t first, size_t last, double V[])
{
	if (first < last) {
		rmsort(first, (last + first) / 2, V);
		rmsort( (last + first) / 2 + 1, last, V);
		merge(first, last, V);
	}
}

/*
 * Call recursive mergesort.
 */
void merge_sort(size_t size, double V[])
{
	rmsort(0, size - 1, V);
}

/*
 * Check if the array is sorted.
 */
size_t issorted(size_t size, double V[])
{
	for (size_t t = 0; t < size - 1; ++t) {
		if (V[t] > V[t + 1])
			return 0;
	}
	return 1;
}

int main(void)
{
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

	merge_sort(size, V);

	size_t sorted = issorted(size, V);
	if (sorted) {
		for (size_t i = 0; i < size; ++i)
			printf("%f\n", V[i]);
	} else {
		printf("The array is not sorted.\n");
	}
	return EXIT_SUCCESS;
}
