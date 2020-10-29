// 백준 2420번 문제 : 사파리월드
// https://www.acmicpc.net/problem/2420

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    long long n, m;

    scanf("%lld %lld", &n, &m);
    printf("%lld\n", llabs(n - m));

    return 0;
}
