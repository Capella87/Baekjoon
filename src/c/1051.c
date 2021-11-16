// 백준 1951번 문제 : 숫자 정사각형
// https://www.acmicpc.net/problem/1051
// 알고리즘 분류 : 구현, 브루트포스 알고리즘

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MIN(a, b) (((a) > (b)) ? (b) : (a))

bool comparer(char** square, int size, int y, int x)
{
    if (!size) return true;

    int arr[4] = {(int)square[y][x], (int)square[y + size][x + size], (int)square[y + size][x], (int)square[y][x + size]};
    for (int i = 0; i < 4; i++)
        if (arr[i] != arr[0]) return false;
    return true;
}

int main(void)
{
    int n, m;

    scanf("%d %d", &n, &m);
    getchar();
    char** sq = (char**)malloc(sizeof(char*) * n);
    for (int i = 0; i < n; i++)
    {
        sq[i] = (char*)malloc(sizeof(char*) * (m + 1));
        scanf("%[^\n]", sq[i]);
        getchar();
    }
    int i = MIN(n, m) - 1;
    for (; i >= 0; i--)
        for (int j = 0; j < n - i; j++)
            for (int k = 0; k < m - i; k++)
                if (comparer(sq, i, j, k)) goto rs;
rs:
    ++i;
    printf("%d\n", i * i);
    for (int i = 0; i < n; i++) free(sq[i]);
    free(sq);
    return 0;
}