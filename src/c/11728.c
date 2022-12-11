// 백준 11728번 문제 : 배열 합치기
// https://www.acmicpc.net/problem/11728
// 알고리즘 분류 : 정렬, 두 포인터

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n, m;

    scanf("%d %d", &n, &m);
    int* a = (int*)malloc(sizeof(int) * n);
    int* b = (int*)malloc(sizeof(int) * m);
    int tot = n + m;
    int* result = (int*)malloc(sizeof(int) * tot);
   
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (int i = 0; i < m; i++)
        scanf("%d", &b[i]);
    int i = 0, j = 0, k = 0;

    // The variation of merge sort
    while (i < n && j < m)
    {
        if (a[i] < b[j]) result[k++] = a[i++];
        else result[k++] = b[j++];
    }
    while (i < n) result[k++] = a[i++];
    while (j < m) result[k++] = b[j++];

    for (int l = 0; l < tot; l++)
        printf("%d ", result[l]);
    putchar('\n');

    free(a);
    free(b);
    free(result);
    return 0;
}