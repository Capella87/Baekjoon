// 백준 1026번 문제 : 보물
// https://www.acmicpc.net/problem/1026
// 알고리즘 분류 : 수학, 정렬

#include <stdio.h>
#include <stdlib.h>

int compareAscending(const void* a, const void* b)
{
    return (*(int*)a - *(int*)b);
}

int compareDescending(const void* a, const void* b)
{
    return -(*(int*)a - *(int*)b);
}

int main(void)
{
    int n, total = 0;

    scanf("%d", &n);
    int* A = (int*)malloc(sizeof(int) * n);
    int* B = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
        scanf("%d", A + i);
    for (int i = 0; i < n; i++)
        scanf("%d", B + i);
    qsort(A, n, sizeof(int), compareAscending);
    qsort(B, n, sizeof(int), compareDescending);
    for (int i = 0; i < n; i++)
        total += A[i] * B[i];
    printf("%d", total);

    free(A);
    free(B);
    return 0;
}