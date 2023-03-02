// 백준 15991번 문제 : 1, 2, 3 더하기 6
// https://www.acmicpc.net/problem/15991
// 알고리즘 분류 : 다이나믹 프로그래밍

// Bottom-up

#include <stdio.h>
#include <stdint.h>

int64_t cache[100001] = { 0, };

int main(void)
{
    int n, temp;

    cache[0] = cache[1] = 1;
    cache[2] = cache[3] = 2;
    for (int i = 4; i <= 5; i++)
        cache[i] = cache[i - 2] + cache[i - 4];
    for (int i = 6; i <= 100000; i++)
        cache[i] = (cache[i - 2] % 1000000009 + cache[i - 4] % 1000000009 + cache[i - 6] % 1000000009) % 1000000009;

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &temp);
        printf("%lld\n", cache[temp]);
    }

    return 0;
}