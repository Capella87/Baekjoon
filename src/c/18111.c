// 백준 18111번 문제 : 마인크래프트
// https://www.acmicpc.net/problem/18111
// 알고리즘 분류 : 구현, 브루트포스 알고리즘

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n, m, b; // b for inventory;
    int max = -1, min = 257;

    scanf("%d %d %d\n", &n, &m, &b);
    int** board = (int**)malloc(sizeof(int*) * (size_t)n);
    for (int i = 0; i < n; i++)
    {
        board[i] = (int*)malloc(sizeof(int) * m);
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &board[i][j]);
            if (max < board[i][j]) max = board[i][j];
            if (min > board[i][j]) min = board[i][j];
        }
    }
    
    int common = min;
    int r_max = -1, t_min = -1;
    for (; common <= max; common++)
    {
        int low = 0, high = 0, time = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (board[i][j] < common) low += (common - board[i][j]);
                else if (board[i][j] > common) high += (board[i][j] - common);
            }
        }
        int t_inven = b + high;
        time += high * 2;

        if (t_inven < low) continue;
        time += low;

        if (t_min == -1 || t_min >= time)
        {
            t_min = time;
            r_max = common;
        }
    }
    printf("%d %d\n", t_min, r_max);

    for (int i = 0; i < n; i++) free(board[i]);
    free(board);
    return 0;
}