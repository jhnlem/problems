#include <stdio.h>

/*
 * Split the array V in half and merge the sub arrays.
 */
void merge(int first, int last, double V[])
{
	// Position of the first element of the left sub array.
	int i = first;
	// Position of the first element of the right sub array.
	int j = (first + last) / 2 + 1;
	// Size of array V.
	int size = last - first + 1;
	int c = 0;
	double U[size];

	// Merge the sub arrays until one of them ends.
	while (i <= (first + last) / 2 || j <= last) {
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
	while (i <= (first + last) / 2) {
		U[c] = V[i];
		i++;
		c++;
	}
	while (j <= last) {
		U[c] = V[j];
		j++;
		c++;
	}

	for (int t = first; t <= last; ++t)
		V[t] = U[t - first];
}

/*
 * Recursive mergesort.
 */
void rmsort(int first, int last, double V[])
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
void mergesort(int size, double V[])
{
	rmsort(0, size - 1, V);
}

/*
 * Check if the array is sorted.
 */
int issorted(int size, double V[])
{
	for (int t = 0; t < size - 1; ++t) {
		if(V[t] > V[t + 1])
			return 0;
	}
	return 1;
}

int main(void)
{
	double V[] = {4.0, 52.0, 23.5, 12.1, 34.2, 67.8, 90.1, 11.3, 45.6, 78.9,
        22.2, 33.3, -44.4, 55.5, -66.6, 77.7, -88.8, 99.9, 10.0, 20.1, 31.2, 41.3,
       	-51.4, -61.5, 71.6, 81.7, 91.8, 2.9, 13.0, 24.1};

	int size = sizeof(V) / sizeof(V[0]);

	mergesort(size, V);

	int sorted = issorted(size, V);

	if (sorted) {
		for (int i = 0; i < size; ++i)
			printf("%f\n", V[i]);
	} else {
		printf("error: the array is not sorted\n");
	}
	return 0;
}
