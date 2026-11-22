//区间素数统计
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 自定义函数：判断一个数是否为素数
// 返回 1 表示是素数，返回 0 表示不是素数
int isPrime(int n) {
    if (n < 2) {
        return 0; // 小于2的数不是素数
    }
    // 只需要判断到 i * i <= n 即可，提高效率
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return 0; // 能被整除，说明有除了1和本身外的因数，不是素数
        }
    }
    return 1; // 是素数
}

int main() {
    int L, R;
    // 读取输入
    if (scanf("%d %d", &L, &R) != 2) {
        return 0;
    }

    // 确保 L 是较小值，R 是较大值（防止输入时 L > R）
    if (L > R) {
        int temp = L;
        L = R;
        R = temp;
    }

    int count = 0;        // 记录素数个数
    int max_prime = -1;   // 记录最大素数，初始化为 -1（符合题目要求）

    // 遍历区间 [L, R]
    for (int i = L; i <= R; i++) {
        if (isPrime(i)) {  // 如果 i 是素数
            count++;       // 个数加 1
            max_prime = i; // 因为从小到大遍历，直接覆盖，最后留下的就是最大的
        }
    }

    // 按要求输出
    printf("%d\n", count);     // 第一行：素数个数
    printf("%d\n", max_prime); // 第二行：最大素数（若无则为 -1）

    return 0;
}