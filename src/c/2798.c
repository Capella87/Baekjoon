// 백준 2798번 문제 : 블랙잭
// https://www.acmicpc.net/problem/2798
// 알고리즘 분류 : 브루트포스 알고리즘

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n, m, total;
    int max = -1;

    scanf("%d %d", &n, &m);
    int* arr = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    for (int i = 0; i < n - 2; i++)
    {
        for (int j = i + 1; j < n - 1; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                total = arr[i] + arr[j] + arr[k];
                if (max < total && total <= m) max = total;
            }
        }
    }
    printf("%d\n", max);
    free(arr);
    return 0;
}