// 백준 11727번 문제 : 2×n 타일링 2
// https://www.acmicpc.net/problem/11727
// 알고리즘 분류 : 다이나믹 프로그래밍

#include <stdio.h>

int arr[1001] = { 0, };

int main(void)
{
    int n;

    arr[1] = 1, arr[2] = 3;
    scanf("%d", &n);
    for (int i = 3; i <= n; i++)
    {
        arr[i] = arr[i - 1] % 10007 + (2 * arr[i - 2]) % 10007;
        arr[i] %= 10007;
    }
    printf("%d\n", arr[n] % 10007);

    return 0;
}