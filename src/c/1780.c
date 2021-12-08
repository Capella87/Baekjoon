// 백준 1780번 문제 : 종이의 개수
// https://www.acmicpc.net/problem/1780
// 알고리즘 분류 : 분할 정복, 재귀

#include <stdio.h>

int num_count[3] = { 0, };
int arr[2187][2187];

void count_paper(const int c, int row, int col)
{
    if (c == 1)
    {
        num_count[arr[row][col] + 1]++;
        return;
    }

    int first = arr[row][col];
    for (int i = 0; i < c; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (first != arr[row + i][col + j])
            {
                int new_c = c / 3;
                for (int k = 0; k < 9; k++)
                    count_paper(new_c, row + new_c * (k / 3), col + new_c * (k % 3));
                return;
            }
        }
    }
    num_count[first + 1]++;
    return;
}

int main(void)
{
    int n;

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &arr[i][j]);
    count_paper(n, 0, 0);

    for (int i = 0; i < 3; i++)
        printf("%d\n", num_count[i]);

    return 0;
}