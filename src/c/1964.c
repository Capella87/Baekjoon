// 백준 1964번 문제 : 오각형, 오각형, 오각형
// https://www.acmicpc.net/problem/1964
// 알고리즘 분류 : 수학

#include <stdio.h>
#define DVS 45678
typedef unsigned long long uint64;

uint64 getHexagonCount(uint64 n)
{
    return ((3 * n * n + 5 * n + 2) / 2) % DVS;
}

int main(void)
{
    uint64 n;

    scanf("%llu", &n);
    printf("%llu\n", getHexagonCount(n));
    return 0;
}