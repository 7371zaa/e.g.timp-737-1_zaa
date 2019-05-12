#include <stdio.h>

int main()
{
	int n, sum,a;
	sum = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a);
		if (a > 0)
		{
			sum = sum + 1;
		}		
	}
	printf("%d\n", sum);
	return 0;
}









