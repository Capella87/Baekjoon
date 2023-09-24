// 백준 1913번 문제 : 달팽이
// https://www.acmicpc.net/problem/1913
// 알고리즘 분류 : 구현

#include <stdio.h>
#include <stdlib.h>
typedef enum modes {up, right, down, left } Mode;

int main(void)
{
    int n, target;

    scanf("%d", &n);
    scanf("%d", &target);
    int** newArr = (int**)malloc(sizeof(int*) * n);
    for (int i = 0; i < n; i++) newArr[i] = (int*)malloc(sizeof(int) * n);
    int range = n * n, t_y = 0, t_x = 0;
    int x = n / 2, y = n / 2, i = 1, move = 0;
    Mode m = up;

    newArr[y--][x] = i++;
    while (i <= range)
    {
        switch (m)
        {
        case up:
            for (int j = 0; j < move; j++)
                newArr[y--][x] = i++;
            if (i < range)
            {
                newArr[y][x++] = i++;
                m = right;
            }
            break;
        case right:
            for (int j = 0; j < move; j++)
                newArr[y][x++] = i++;
            newArr[y++][x] = i++;
            move++;
            m = down;
            break;
        case down:
            for (int j = 0; j < move; j++)
                newArr[y++][x] = i++;
            newArr[y][x--] = i++;
            m = left;
            break;
        case left:
            for (int j = 0; j < move; j++)
                newArr[y][x--] = i++;
            newArr[y--][x] = i++;
            move++;
            m = up;
            break;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", newArr[i][j]);
            if (newArr[i][j] == target)
            {
                t_y = i + 1;
                t_x = j + 1;
            }
        }
        free(newArr[i]);
        putchar('\n');
    }
    printf("%d %d\n", t_y, t_x);
    free(newArr);
    return 0;
}