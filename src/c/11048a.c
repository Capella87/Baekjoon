// 백준 11048번 문제 : 이동하기
// https://www.acmicpc.net/problem/11048
// 알고리즘 분류 : 다이나믹 프로그래밍

// Bottom-up solution

#include <stdio.h>

int n, m;
int arr[1002][1002] = { 0, };
int cache[1002][1002] = { 0,};

inline int max(const int a, const int b)
{
    return a > b ? a : b;
}

int main(void) // Bottom-up
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            scanf("%d", &arr[i][j]);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cache[i][j] = arr[i][j] + max(cache[i - 1][j - 1], cache[i][j - 1]);
            cache[i][j] = max(cache[i][j], arr[i][j] + cache[i - 1][j]);
        }
    }
    printf("%d\n", cache[n][m]);

    return 0;
}