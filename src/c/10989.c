// 백준 10989번 문제 : 수 정렬하기 3
// https://www.acmicpc.net/problem/10989
// 알고리즘 분류 : 정렬

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 10001

int main(void)
{
    int n, temp;

    scanf("%d", &n);
    getchar();
    int* numCount = (int*)malloc(sizeof(int) * SIZE);
    memset(numCount, 0, sizeof(int) * SIZE);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &temp);
        numCount[temp]++;
    }
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < numCount[i]; j++)
            printf("%d\n", i);
    free(numCount);
    return 0;
}