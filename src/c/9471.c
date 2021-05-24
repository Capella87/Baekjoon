// 백준 9471번 문제 : 피사노 주기
// https://www.acmicpc.net/problem/9471
// 알고리즘 분류 : 수학

#include <stdio.h>

long long getPisano(long long m)
{
    const long long size = m * m; // k(m) <= m^2 - 1의 성질을 이용
    long long f0 = 0, f1 = 1, f2 = f0 + f1, i = 0;
    for (; i < size; i++)
    {
        f2 = (f0 + f1) % m;
        if (f2 == 1 && f1 == 0) break; // 주기 시작시 0, 1로 시작되므로 그것을 따지면 된다.
        f0 = f1;
        f1 = f2;
    }
    return i + 1;
}

int main(void)
{
    int p, n;
    long long m;

    scanf("%d", &p);
    for (int i = 0; i < p; i++)
    {
        scanf("%d %lld", &n, &m);
        printf("%d %lld\n", n, getPisano(m));
    }

    return 0;
}