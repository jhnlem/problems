#include <stdio.h>

void merge(int first, int last, double V[]) {
	/* splits the array V in half and merges the sub arrays */

	int size = last - first + 1;
	double U[size];
	int i = first, j = (first + last)/2 + 1, c = 0;

	while(i <= (first +last )/2 && j <= last) {
		if(V[i] <= V[j]) {
		       U[c] = V[i];	
		       c++;
		       i++;
		}
		else {
			U[c] = V[j];
			c++;
			j++;
		}
	}

	while(i <= (first + last)/2) {
		U[c] = V[i];
		i++;
		c++;
	}

	while(j <= last) {
		U[c] = V[j];
		j++;
		c++;
	}

	for(int t = first; t <= last; ++t) {
		V[t] = U[t - first];
	}
}

void mergesort(int first, int last, double V[]) {
	if(first < last) {
		mergesort(first, (last + first)/2, V);
		mergesort( (last + first)/2 + 1, last, V);
		merge(first , last, V);
	}
}

int issorted(int size, double V[]) {
	for(int t = 0; t < size-1; ++t) {
		if(V[t] > V[t+1]) {
			return 0;
		}
	}
	return 1;
}

int main(void) {
	double V[] = {4.0, 52.0, 23.5, 12.1, 34.2, 67.8, 90.1, 11.3, 45.6, 78.9,
        22.2, 33.3, -44.4, 55.5, -66.6, 77.7, -88.8, 99.9, 10.0, 20.1, 31.2, 41.3,
       	-51.4, -61.5, 71.6, 81.7, 91.8, 2.9, 13.0, 24.1};

	int size = sizeof(V)/sizeof(V[0]);

	mergesort(0, size - 1, V);

	int sorted = issorted(size, V);

	if(sorted) {
		for(int i = 0; i < size; ++i) {
			printf("%f\n", V[i]);
		}
	}
	else {
		printf("error: the array is not sorted\n");
	}

	return 0;
}
