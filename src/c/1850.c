// 백준 1850번 문제 : 최대공약수
// https://www.acmicpc.net/problem/1850
// 알고리즘 분류 : 수학, 정수론, 유클리드 호제법

#include <stdio.h>
typedef long long int64;

int64 getGCD(int64 a, int64 b)
{
    return (a % b == 0) ? b : getGCD(b, a % b);
}

int main(void)
{
    int64 a, b;

    scanf("%lld %lld", &a, &b);
    int64 digits = getGCD(a, b);
    for (int64 i = 0; i < digits; i++)
        putchar('1');
    putchar('\n');
    return 0;
}