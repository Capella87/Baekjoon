// 백준 18110번 문제 : solved.ac
// https://www.acmicpc.net/problem/18110
// 알고리즘 분류 : 수학, 구현, 정렬

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int compare(const void* a, const void* b)
{
    return *(int*)a - *(int*)b;
}

int main(void)
{
    int n;
    int* opinions = NULL;
    double total = 0.0;

    scanf("%d", &n);
    if (!n)
    {
        puts("0");
        return 0;
    }

    opinions = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
        scanf("%d", &opinions[i]);
    qsort((int*)opinions, n, sizeof(int), compare);
    int ex_per = (int)round((double)n * 0.15);
    for (int i = ex_per; i < n - ex_per; i++)
        total += (double)opinions[i];
    int result = (int)round(total / (double)(n - 2 * ex_per));
    printf("%d\n", result);

    free(opinions);
    return 0;
}