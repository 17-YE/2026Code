#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX_VAL 100 //数值范围 0 ~ MAX_VAL
#define COUNT_SIZE (MAX_VAL + 1)

//桶计数：时间 O(n + MAX_VAL)，空间 O(MAX_VAL)
int main(void)
{
	int cnt[COUNT_SIZE] = { 0 };//cnt[x] 表示数值 x 出现的次数
	int n = 0;
	int x = 0;
	int maxCnt = 0;//出现次数的最大值
	int maxVal = 0;//出现次数最多的数

	if (scanf("%d", &n) != 1)
	{
		return 1;
	}

	for (int i = 0;i < n;i++)
	{
		if (scanf("%d", &x) != 1)
		{
			return 1;
		}
		//题面保证 0 ~ MAX_VAL，这里做防御性判断，避免越界
		if (x < 0 || x > MAX_VAL)
		{
			continue;
		}
		cnt[x]++;
	}

	//按数值从小到大输出出现过的数
	for (int v = 0;v <= MAX_VAL;v++)
	{
		if (cnt[v] > 0)
		{
			printf("%d %d\n", v, cnt[v]);
			//严格大于才更新，v 从小到大，并列时自然保留较小的数
			if (cnt[v] > maxCnt)
			{
				maxCnt = cnt[v];
				maxVal = v;
			}
		}
	}

	//最后一行：出现次数最多的数及其次数
	if (maxCnt > 0)
	{
		printf("%d %d\n", maxVal, maxCnt);
	}

	return 0;
}
