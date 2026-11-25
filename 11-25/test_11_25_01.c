//矩阵转置
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int arr[105][105] = {0};
	int m = 0;
	int n = 0;
	scanf("%d %d", &m, &n);
	int i = 0;
	int j = 0;
	for (i = 0;i < m;i++)
	{
		for (j = 0;j < n;j++)
		{
			scanf("%d", &arr[i][j]);
		}
	}
	for (i = 0;i < n;i++)
	{
		for (j = 0;j < m;j++)
		{
			printf("%d", arr[j][i]);
			if (j < m - 1)
			{
				printf(" ");
			}
		}
		printf("\n");
	}
	return 0;
}