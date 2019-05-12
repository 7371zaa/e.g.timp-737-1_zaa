#include <stdio.h>

int main()
{
	int n, sum,a;
	sum = 0;
	scanf("%d", &n);
	for (int i =1 ; i <= n; i++)
	{
		scanf("%d", &a);
		sum = sum +a-i;		
	}
	printf("%d\n", sum);
	return 0;
}
