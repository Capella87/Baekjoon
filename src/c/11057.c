// 백준 11057번 문제 : 오르막 수
// https://www.acmicpc.net/problem/11057
// 알고리즘 분류 : 다이나믹 프로그래밍

#include <stdio.h>
#include <stdint.h>

uint64_t cache[1001][10];

int main(void)
{
    int n;
    for (int i = 0; i < 10; i++)
        cache[1][i] = 1;
    scanf("%d", &n);
    uint64_t total = 10;
    for (int i = 2; i <= n; i++)
    {
        cache[i][9] = cache[i - 1][9];
        total = cache[i][9];
        for (int j = 8; j >= 0; j--)
        {
            cache[i][j] = (cache[i][j + 1] % 10007 + cache[i - 1][j] % 10007) % 10007;
            total = (total % 10007 + cache[i][j] % 10007) % 10007;
        }
    }
    printf("%llu\n", total);

    return 0;
}