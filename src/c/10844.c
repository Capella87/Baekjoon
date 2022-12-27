// 백준 10844번 문제 : 쉬운 계단 수
// https://www.acmicpc.net/problem/10844
// 알고리즘 분류 : 다이나믹 프로그래밍

// Bottom-Up Method

#include <stdio.h>
#include <stdint.h>

int arr[100][10] = { 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, };

int64_t get_stair(int n)
{
    int64_t total = 0L;

    for (int i = 1; i <= n; i++)
    {
        arr[i][0] = arr[i - 1][1] % 1000000000L;
        for (int j = 1; j < 9; j++)
        {
            arr[i][j] = arr[i - 1][j - 1] % 1000000000L + arr[i - 1][j + 1] % 1000000000L;
            arr[i][j] %= 1000000000L;
        }
        arr[i][9] = arr[i - 1][8] % 1000000000L;
    }

    for (int i = 0; i < 10; i++)
        total += arr[n][i] % 1000000000L;
    
    return total % 1000000000L;
}

int main(void)
{
    int n;

    scanf("%d", &n);
    printf("%lld\n", get_stair(n - 1));

    return 0;
}