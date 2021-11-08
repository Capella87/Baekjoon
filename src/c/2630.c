// 백준 2630번 문제 : 색종이 만들기
// https://www.acmicpc.net/problem/2630
// 알고리즘 분류 : 분할 정복, 재귀

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int counter[2] = { 0, 0 };

void origami(int** arr, int b_y, int b_x, int size)
{
    int isDiff = arr[b_y][b_x];
    int origDiff = isDiff;

    if (size == 1)
    {
        counter[origDiff]++;
        return;
    }
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (isDiff != arr[b_y + i][b_x + j])
            {
                isDiff = arr[b_y + i][b_x + j];
                goto diff;
            }
        }
    }
diff:
    if (isDiff != origDiff)
    {
        int newSize = size / 2;
        origami(arr, b_y, b_x, newSize);
        origami(arr, b_y, b_x + newSize, newSize);
        origami(arr, b_y + newSize, b_x, newSize);
        origami(arr, b_y + newSize, b_x + newSize, newSize);
    }
    else counter[origDiff]++;
    return;
}

int main(void)
{
    int n;

    scanf("%d", &n);
    int** arr = (int**)malloc(sizeof(int*) * n);
    for (int i = 0; i < n; i++)
    {
        arr[i] = (int*)malloc(sizeof(int) * n);
        for (int j = 0; j < n; j++)
            scanf("%d", &arr[i][j]);
    }
    origami(arr, 0, 0, n);
    for (int i = 0; i < 2; i++) printf("%d\n", counter[i]);
    for (int i = 0; i < n; i++) free(arr[i]);
    free(arr);
    return 0;
}