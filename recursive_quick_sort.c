#include <stdio.h>

void quicksort(int first, int last, double V[]) {
	if(first < last) {
		double pivot = V[last];
		int f = first, l = last;
		while(first < last) {	
			if(V[last] < V[first]) {
				V[last] = V[first];
				V[first] = V[last-1];
				V[last-1] = pivot;
				last--;
			}
			else {
				first++;
			}
		}
		quicksort(f, last-1, V);
		quicksort(last+1, l, V);
	}
}

int issorted(int size, double V[]) {
        for(int t = 0; t < size-1; ++t) {
                if(V[t]>V[t+1]) {
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
        quicksort(0,size-1,V);
        int sorted = issorted(size, V);
        if(sorted) {
                for(int i = 0; i < size; ++i) {
                        printf("%f\n",V[i]);
                }
        }
        else {
                printf("error: the array is not sorted\n");
        }
        return 0;
}
