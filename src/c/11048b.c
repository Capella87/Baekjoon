// 백준 11048번 문제 : 이동하기
// https://www.acmicpc.net/problem/11048
// 알고리즘 분류 : 다이나믹 프로그래밍

// Top-down solution

#include <stdio.h>
#include <string.h>

int n, m;
int arr[1000][1000] = { 0 };
int cache[1000][1000] = { -1 };

inline int max(const int a, const int b)
{
    return a > b ? a : b;
}

int get_candy(int y, int x)
{
    if (y < 0 || x < 0) return 0;
    else if (!y && !x) return arr[0][0];
    else if (cache[y][x] != -1) return cache[y][x];

    cache[y][x] = arr[y][x] + max(get_candy(y - 1, x - 1), get_candy(y - 1, x));
    cache[y][x] = max(cache[y][x], get_candy(y, x - 1) + arr[y][x]);
    
    return cache[y][x];
}

int main(void)
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
        memset((void*)cache[i], -1, sizeof(int) * m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &arr[i][j]);
    printf("%d\n", get_candy(n - 1, m - 1));

    return 0;
}