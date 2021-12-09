// 백준 2010번 문제 : 플러그
// https://www.acmicpc.net/problem/2010
// 알고리즘 분류 : 수학, 구현, 사칙연산

#include <stdio.h>

int main(void)
{
    int n, temp;
    long long total = 0;

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &temp);
        total += (long long)temp - 1;
    }
    printf("%lld\n", total + 1);

    return 0;
}