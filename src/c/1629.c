// 백준 1629번 문제 : 곱셈
// https://www.acmicpc.net/problem/9085
// 알고리즘 분류 : 수학, 분할 정복을 이용한 거듭제곱

// Commit for this file is postponed to review the problem.

#include <stdio.h>
typedef unsigned long long ulong64;

ulong64 diviend;
ulong64 dcPowRecursive(ulong64 base, ulong64 exponent)
{
    if (exponent == 1) return base;
    else
    {
        ulong64 mid = dcPowRecursive(base, exponent / 2);
        if (exponent % 2)
            return ((mid * mid) % diviend * (base % diviend)) % diviend;
        else
            return (mid * mid) % diviend;
    }
}
// Remember properties of modulo operation.
// Use ab mod n = ((a mod n)*(b mod n))mod n
// Use (a mod n) mod n = a mod n
int main(void)
{
    ulong64 a, b;

    scanf("%llu %llu %llu", &a, &b, &diviend);
    printf("%llu\n", dcPowRecursive(a % diviend, b));
    return 0;
}