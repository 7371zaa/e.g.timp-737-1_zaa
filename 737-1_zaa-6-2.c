#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

int	sorting_function(int* arr, int arr_len)
{
	int i, j, s;
	int p;
	for (s = arr_len / 2; s > 0; s /= 2)
	{
		for (i = s; i < arr_len; i++)
		{
			p = arr[i];
			for (j = i; j >= s; j -= s)
			{
				if (p < arr[j - s])
				{
					arr[j] = arr[j - s];
				}
				else
				{
					break;
				}
			}
			arr[j] = p;
		}
	}
	return 0;
}

int main()
{
	int i, n,x;
	int *arr;
	scanf("%d", &n);
	arr = (int*)malloc(n * sizeof(int));
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
