// 백준 15993번 문제 : 1, 2, 3 더하기 8
// https://www.acmicpc.net/problem/15993
// 알고리즘 분류 : 다이나믹 프로그래밍

// Bottom-up

#include <stdio.h>
#include <stdint.h>

int64_t cache[100001][2] = { 0, };

int main(void)
{
    int n, temp;

    cache[1][0] = cache[2][0] = cache[2][1] = 1;
    cache[3][0] = cache[3][1] = 2;
    for (int i = 4; i <= 100000; i++)
    {
        cache[i][0] = (cache[i - 1][1] + cache[i - 2][1] + cache[i - 3][1]) % 1000000009;
        cache[i][1] = (cache[i - 1][0] + cache[i - 2][0] + cache[i - 3][0]) % 1000000009;
    }

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &temp);
        printf("%lld %lld\n", cache[temp][0], cache[temp][1]);
    }

    return 0;
}