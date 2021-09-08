// 백준 5347번 문제 : LCM
// https://www.acmicpc.net/problem/5347
// 알고리즘 분류 : 수학, 정수론, 유클리드 호제법

#include <stdio.h>
typedef unsigned long long uint64;

uint64 getGCD(uint64 a, uint64 b)
{
    return (a % b == 0) ? b : getGCD(b, a % b);
}

int main(void)
{
    int n;
    uint64 a, b;

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%llu %llu", &a, &b);
        if (a < b)
        {
            uint64 temp = a;
            a = b;
            b = temp;
        }
        printf("%llu\n", a * b / getGCD(a, b));
    }
    return 0;
}