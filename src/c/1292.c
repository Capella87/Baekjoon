// 백준 1292번 문제 : 쉽게 푸는 문제
// https://www.acmicpc.net/problem/1292
// 알고리즘 분류 : 수학, 구현

#include <stdio.h>
#define SIZE 1000

int main(void)
{
    int arr[SIZE];
    int num = 1, numBeginIdx = 0, total = 0, i = 0;
    int start, end;
    
    scanf("%d %d", &start, &end);
    while (i < SIZE && i < end)
    {
        for (int j = 0; j < num && i < SIZE; j++)
            arr[i++] = num;
        num++;
    }
    for (int i = start - 1; i < end; i++)
        total += arr[i];
    printf("%d\n", total);
    return 0;
}