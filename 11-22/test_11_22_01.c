
#define _CRT_SECURE_NO_WARNINGS
#define MOD 1000000
#include <stdio.h>
int main()
{
	int n = 0;//0 < n < 25
	int b = 1;
	int S = 0;
	scanf("%d", &n);
	if (n > 25) 
	{
		n = 25;
	}
	for (int i = 1;i <= n;i++)
	{
		b = (b * i) % MOD;
		S = (S + b) % MOD;
	}
	printf("%d\n", S);
	return 0;
}