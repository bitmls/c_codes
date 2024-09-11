#include <stdio.h>
#include <stdlib.h>

#define MAX  10

void PrintArray(int* array, int len) {
	for (int i = 0; i < len; i++)
		printf("%d ", array[i]);
	printf("\n");
}

void InsertSort(int* array, int len) {
	PrintArray(array, len);
	for (int i = 1; i < len; i++) {
		for (int j = 0; j < i; j++) {
			if (array[i] < array[j]) {
				int tmp = array[i];
				for (int k = i - 1; k >= j; k--)
					array[k + 1] = array[k];
				array[j] = tmp;
			}
		}
		PrintArray(array, len);
	}
}

int main() {
	int array[MAX] = { 10,8,6,4,2,1,3,5,7,9};
	InsertSort(array, MAX);

	return 0;
}