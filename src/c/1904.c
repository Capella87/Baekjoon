// 백준 1904번 문제 : 01타일
// https://www.acmicpc.net/problem/1904
// 알고리즘 분류 : 다이나믹 프로그래밍

#include <stdio.h>
#include <stdint.h>

int main(void)
{
    int n;
    uint64_t f1 = 1, f2 = 2, f = 0; // Fibonacci Sequence

    scanf("%d", &n);
    for (int i = 3; i <= n; i++)
    {
        f = (f1 + f2) % 15746;
        f1 = f2;
        f2 = f;
    }
    if (n == 1) printf("1\n");
    else if (n == 2) printf("2\n");
    else printf("%llu\n", f);

    return 0;
}