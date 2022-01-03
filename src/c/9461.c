// 백준 9461번 문제 : 파도반 수열
// https://www.acmicpc.net/problem/9461
// 알고리즘 분류 : 수학, 다이나믹 프로그래밍

#include <stdio.h>

int main(void)
{
    long long arr[101] = { 0, 1, 1, 1, 0 };
    int n, t;

    scanf("%d", &n);
    for (int i = 4; i <= 100; i++)
        arr[i] = arr[i - 2] + arr[i - 3];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &t);
        printf("%lld\n", arr[t]);
    }

    return 0;
}