// 백준 2436번 문제 : 공약수
// https://www.acmicpc.net/problem/2436
// 알고리즘 분류 : 수학, 정수론, 유클리드 호제법

#include <stdio.h>
typedef unsigned long long uint64;

uint64 getGCD(uint64 a, uint64 b)
{
    return (a % b == 0) ? b : getGCD(b, a % b);
}

int main(void)
{
    uint64 gcd, lcm;

    scanf("%llu %llu", &gcd, &lcm);
    uint64 ta = gcd, tb = lcm, minSum = gcd + lcm;
    uint64 comp = gcd * lcm;
    for (uint64 i = gcd; i * i <= comp; i++)
    {
        if (comp % i) continue;
        uint64 temp = comp / i;
        if (getGCD(i, temp) == gcd && (temp + i) < minSum)
        {
            minSum = temp + i;
            ta = i;
            tb = temp;
        }
    }
    printf("%d %d\n", ta, tb);
    return 0;
}