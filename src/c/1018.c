// 백준 1018번 문제 : 체스판 다시 칠하기
// https://www.acmicpc.net/problem/1018
// 알고리즘 분류 : 브루트포스 알고리즘

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int checkPattern(char** board, int startY, int startX)
{
    int result = 0;
    int whiteCase = 0;
    int blackCase = 0;

    for (int i = startY; i < startY + 8; i++)
    {
        if (i % 2 == 0)
        {
            for (int j = startX; j < startX + 8; j++)
            {
                int xidx = j - startX;
                // 흑일 경우(처음 시작하는 칸이 흑인 경우)
                if (xidx % 2 == 0 && board[i][j] == 'W')
                    blackCase++;
                else if (xidx % 2 && board[i][j] == 'B')
                    blackCase++;
                // 백일 경우 (처음 시작하는 칸이 백인 경우)
                if (xidx % 2 == 0 && board[i][j] == 'B')
                    whiteCase++;
                else if (xidx % 2 && board[i][j] == 'W')
                    whiteCase++;
            }
        }
        else
        {
            for (int j = startX; j < startX + 8; j++)
            {
                int xidx = j - startX;
                // 흑일 경우(처음 시작하는 칸이 흑인 경우)
                if (xidx % 2 == 0 && board[i][j] == 'B')
                    blackCase++;
                else if (xidx % 2 && board[i][j] == 'W')
                    blackCase++;
                // 백일 경우 (처음 시작하는 칸이 백인 경우)
                if (xidx % 2 == 0 && board[i][j] == 'W')
                    whiteCase++;
                else if (xidx % 2 && board[i][j] == 'B')
                    whiteCase++;
            }
        }
    }
    return whiteCase > blackCase ? blackCase : whiteCase; // returns minimal case;
}

int main(void)
{
    int n, m;

    scanf("%d %d", &n, &m);
    getchar();
    char** checkerBoard = (char**)malloc(sizeof(char*) * n);
    for (int i = 0; i < n; i++)
    {
        checkerBoard[i] = (char*)malloc(sizeof(char) * (m + 1));
        scanf("%[^\n]", checkerBoard[i]);
        getchar();
    }
    int min = INT_MAX;
    for (int i = 0; i <= n - 8; i++)
    {
        for (int j = 0; j <= m - 8; j++)
        {
            int temp = checkPattern(checkerBoard, i, j);
            if (temp < min) min = temp;
        }
    }
    printf("%d\n", min);
    for (int i = 0; i < n; i++)
        free(checkerBoard[i]);
    free(checkerBoard);
    return 0;
}