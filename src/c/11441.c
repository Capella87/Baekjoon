// 백준 11441번 문제 : 합 구하기
// https://www.acmicpc.net/problem/11441
// 알고리즘 분류 : 누적 합

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n, m, temp;
    int from, to;

    scanf("%d", &n);
    int* saveTot = (int*)malloc(sizeof(int) * (n + 1));
    *saveTot = 0;
    for (int i = 1; i < n + 1; i++)
    {
        scanf("%d", &temp);
        saveTot[i] = saveTot[i - 1] + temp;
    }
    scanf("%d", &m);
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d", &from, &to);
        printf("%d\n", saveTot[to] - saveTot[from - 1]);
    }

    free(saveTot);
    return 0;
}