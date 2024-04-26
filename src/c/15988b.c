// 백준 15988번 문제 : 1, 2, 3 더하기 3
// https://www.acmicpc.net/problem/15988
// 알고리즘 분류 : 다이나믹 프로그래밍

// Top-down with memoization

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#define MAX 1000000

int64_t cache[MAX + 1] = { -1, };

int64_t get_case(int n)
{
    if (cache[n] != -1) return cache[n];
    else if (n <= 2)
        return cache[n] = n;
    else if (n == 3) return cache[n] = 1 + get_case(2) + get_case(1);
    else
    {
        cache[n] = get_case(n - 1) % 1000000009 + get_case(n - 2) % 1000000009 + get_case(n - 3) % 1000000009;
        return cache[n] %= 1000000009;
    }
}

int main(void)
{
    int n, input;

    scanf("%d", &n);
    memset((int64_t*)cache, -1, sizeof(int64_t) * (MAX + 1));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &input);
        printf("%lld\n", get_case(input));
    }

    return 0;
}