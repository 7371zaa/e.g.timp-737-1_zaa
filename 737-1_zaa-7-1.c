#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

int	sorting_function(int* arr, size_t low, size_t high)
{
	size_t i, j;
	int tmp, pivot;
	i = low;
	j = high;
	pivot = arr[(low + (high - low) / 2)];
	do {
		while (arr[i] < pivot) {
			i++;
		}
		while (arr[j] > pivot) {
			j--;
		}
		if (i <= j) {
			if (arr[i] > arr[j]) {
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
			i++;
			if (j > 0) {
				j--;
			}
		}
	} while (i <= j);

	if (i < high) {
		sorting_function(arr, i, high);
	}
	if (j > low) {
		sorting_function(arr, low, j);
	}
	return 0;
}

int main()
{
	int i, n, x;
	int *arr;
	arr = (int*)malloc(n * sizeof(int));
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	sorting_function(arr,0, n-1);
	for (i = 0; i < n; i++)
	{
		if (i == n - 1)
		{
			printf("%d\n", arr[i]);
			break;
		}
		printf("%d ", arr[i]);
	}
	free(arr);
	return 0;
}
