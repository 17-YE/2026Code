//数组最值与统计
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    int n = 0;
    scanf("%d", &n);
    int arr[1000];

    // 1. 读取数组
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    // 2. 初始化
    int max = arr[0];
    int min = arr[0];
    int a = 0;          // 最大值第一次出现的下标
    long long he = 0;   // 总和

    // 3. 遍历计算
    for (int j = 0; j < n; j++)
    {
        he += arr[j]; // 累加总和

        // 如果当前元素大于 max，更新 max 和 下标 a
        // 注意使用 > 而不是 >=，可以确保记录的是“第一次”出现的位置
        if (arr[j] > max)
        {
            max = arr[j];
            a = j;
        }

        // 如果当前元素小于 min，更新 min
        if (arr[j] < min)
        {
            min = arr[j];
        }
    }

    // 4. 计算平均值
    float p = (float)he / n;

    // 5. 输出结果（严格按照题目要求的 5 个值，用空格隔开）
    printf("%d %d %lld %.2f %d\n", max, min, he, p, a);

    return 0;
}