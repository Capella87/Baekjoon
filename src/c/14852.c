// 백준 14852번 문제 : 타일 채우기 3
// https://www.acmicpc.net/problem/14852
// 알고리즘 분류 : 다이나믹 프로그래밍

#include <stdio.h>
#include <stdint.h>
#define DIV 1000000007

int64_t cache[1000001] = { 0 };
int64_t special[1000001] = { 0, }; // For special cases

int main(void)
{
    int n;

    scanf("%d", &n);
    cache[0] = 1;
    cache[1] = 2;
    cache[2] = 7;
    cache[3] = cache[2] * 2 + (cache[1] * 3) + 2;
    special[0] = 2;
    for (int i = 4; i <= n; i++)
    {
        cache[i] = (cache[i - 1] * 2) % DIV;
        cache[i] = (cache[i] % DIV + (cache[i - 2] * 3) % DIV) % DIV;
        special[i - 3] = (special[i - 4] + 2 * cache[i - 3]) % DIV;
        cache[i] = (cache[i] + special[i - 3]) % DIV;
    }
    printf("%lld\n", cache[n]);

    return 0;
}