#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//排序法：先升序排序，再顺序扫描，统计每段相同数的个数
//时间 O(n^2)（冒泡排序），空间 O(n)
int main(void)
{
	int arr[1000];//题目未给 n 的上限，这里按 1000 预留
	int n = 0;
	int maxCnt = 0;//出现次数的最大值
	int maxVal = 0;//出现次数最多的数

	if (scanf("%d", &n) != 1 || n <= 0)
	{
		return 0;
	}

	for (int i = 0;i < n;i++)
	{
		if (scanf("%d", &arr[i]) != 1)
		{
			return 1;
		}
	}

	//冒泡排序，升序
	for (int i = 0;i < n - 1;i++)
	{
		int swapped = 0;
		for (int j = 0;j < n - 1 - i;j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
				swapped = 1;
			}
		}
		if (!swapped)
		{
			break;
		}
	}

	//顺序扫描，每段相同数只统计、输出一次
	for (int i = 0;i < n;)
	{
		int v = arr[i];//当前这一段的数
		int c = 0;//该数出现的次数
		//i 一直往后走，直到离开这一段
		while (i < n && arr[i] == v)
		{
			c++;
			i++;
		}
		printf("%d %d\n", v, c);
		//严格大于才更新；数组已升序，并列时自然保留较小的数
		if (c > maxCnt)
		{
			maxCnt = c;
			maxVal = v;
		}
	}

	//最后一行：出现次数最多的数及其次数
	printf("%d %d\n", maxVal, maxCnt);

	return 0;
}
