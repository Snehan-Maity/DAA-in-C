// Randomized Quick Sort
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}
void display(int arr[], int low, int high) {
	int i;
	for (i = low; i <= high; i++) {
		printf("%3d", arr[i]);
	}
}
int partition(int arr[], int low, int high) {
	int pivot = arr[high];
	int i = low - 1;
	printf("\nSubarray : ");
	display(arr, low, high);
	int j;
	for (j = low; j < high; j++) {
		if (arr[j] < pivot) {
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return i + 1;
}

// Randomized partition
int randomizedPartition(int arr[], int low, int high) {
	int pivotIndex = low + rand() % (high - low + 1);
	swap(&arr[pivotIndex], &arr[high]);  // To Move pivot to the end
	return partition(arr, low, high);
}

void quickSort(int arr[], int low, int high) {
	if (low < high) {
		int pi = randomizedPartition(arr, low, high);
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}

int main() {
	int n;
	printf("Enter the number of elements: ");
	scanf("%d", &n);

	int *arr = (int *)malloc(n * sizeof(int));
	printf("Enter the elements: ");
	int i;
	for (i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	srand(time(0));  // To Seed the random number generator
	quickSort(arr, 0, n - 1);
	printf("\nThe Sorted Array is : ");
	display(arr, 0, n - 1);
	printf("\n");
	free(arr);
	return 0;
}

