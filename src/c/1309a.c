// 백준 1309번 문제 : 동물원
// https://www.acmicpc.net/problem/1309
// 알고리즘 분류 : 다이나믹 프로그래밍

// Recurrence relation

#include <stdio.h>
#include <stdint.h>

uint64_t cache[3] = { 3, 7, 17 };

int main(void)
{
    int n;

    scanf("%d", &n);
    for (int i = 3; i < n; i++)
    {
        cache[0] = cache[1];
        cache[1] = cache[2];
        cache[2] = (cache[1] * 2) % 9901 + cache[0] % 9901;
        cache[2] %= 9901;
    }
    if (n >= 3) printf("%llu\n", cache[2]);
    else printf("%llu\n", cache[n - 1]);

    return 0;
}