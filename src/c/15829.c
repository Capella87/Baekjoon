// 백준 15829번 문제 : Hashing
// https://www.acmicpc.net/problem/15829
// 알고리즘 분류 : 해싱

// This solution has subtasks.
// Small (50 points): 1 <= L <= 5
// Large (50 points): 1 <= L <= 50

// Apply properties of modulo operation.

#include <stdio.h>
#include <string.h>

typedef unsigned long long uint64;
const uint64 M = 1234567891;

uint64 getExponentialMod(int base, size_t exponent)
{
    if (!exponent) return 1;

    uint64 result = base;
    for (int i = 0; i < exponent - 1; i++)
        result = (result % M * base % M) % M;
    return result % M;
}

uint64 getHash(char* str, size_t len)
{
    uint64 result = 0;

    for (size_t i = 0; i < len; i++)
    {
        uint64 temp = ((getExponentialMod(31, i) % M) * (((size_t)(str[i] - 'a' + 1) % M))) % M;
        result = (result % M + temp % M) % M;
    }
    return result % M;
}

int main(void)
{
    char str[51] = "";
    size_t len;

    scanf("%zu", &len);
    getchar();
    scanf("%[^\n]", str);
    printf("%llu\n", getHash(str, strlen(str)));
    return 0;
}