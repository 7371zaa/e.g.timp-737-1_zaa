#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

void siftDown(int *arr, int root, int bottom)
{
	int max;
	int a = 0;
	while ((root * 2 <= bottom) && (!a))
	{
		if (root * 2 == bottom) 
			max = root * 2;  
		else if (arr[root * 2] > arr[root * 2 + 1])
			max = root * 2;
		else
			max = root * 2 + 1;
		if (arr[root] < arr[max])
		{
			int temp = arr[root];
			arr[root] = arr[max];
			arr[max] = temp;
			root = max;
		}
		else 
			a = 1; 
	}
}

int	sorting_function(int* arr, int arr_len)
{
	for (int i = (arr_len / 2) - 1; i >= 0; i--)
		siftDown(arr, i, arr_len - 1);
	for (int i = arr_len - 1; i >= 1; i--)
	{
		int temp = arr[0];
		arr[0] = arr[i];
		arr[i] = temp;
		siftDown(arr, 0, i - 1);
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
	sorting_function(arr,n);
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
