#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

int	sorting_function(int* arr, int arr_len)
{
	int p, k;
	int s = arr_len;
	long long cnt = 0;
	while (arr_len > 1) {
		s /= 1.247f;
		if (s < 1) s = 1;
		k = 0; 
		for (int i = 0; i + s < arr_len; ++i)
		{ 
			if (arr[i] > arr[i + s]) {
				p = arr[i];
				arr[i] = arr[i + s];
				arr[i + s] = p;
				k = i;
			}
			++cnt;
		}
		if (s == 1)
			arr_len = k + 1;
	}
	return 0;
}

int main()
{
	int i, n,x;
	int *arr;
	arr = (int*)malloc(n * sizeof(int));
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	sorting_function(arr, n);
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
