// 백준 15988번 문제 : 1, 2, 3 더하기 3
// https://www.acmicpc.net/problem/15988
// 알고리즘 분류 : 다이나믹 프로그래밍

// Bottom-Up

#include <stdio.h>
#include <stdint.h>
#define MAX 1000000

int64_t cache[MAX + 1];

int main(void)
{
    int n, temp;
    scanf("%d", &n);
    cache[1] = 1;
    cache[2] = 2;
    cache[3] = 4;
    for (int i = 4; i <= MAX; i++)
        cache[i] = (cache[i - 1] % 1000000009 + cache[i - 2] % 1000000009 + cache[i - 3] % 1000000009) % 1000000009;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &temp);
        printf("%lld\n", cache[temp]);
    }

    return 0;
}