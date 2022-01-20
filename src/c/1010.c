// 백준 1010번 문제 : 다리 놓기
// https://www.acmicpc.net/problem/1010
// 알고리즘 분류 : 수학, 다이나믹 프로그래밍, 조합론

// It's just a binomial coefficient!

#include <stdio.h>

long long get_binomial(int m, int n)
{
    long long arr[31] = { 1L, 0L, };
    if (m - n < n)
        n = m - n;
    for (int i = 1; i <= m; i++)
    {
        for (int j = n; j >= 1; j--)
            arr[j] += arr[j - 1];
    }

    return arr[n];
}

int main(void)
{
    int n, m, t;

    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        scanf("%d %d", &n, &m);
        printf("%lld\n", get_binomial(m, n));
    }

    return 0;
}