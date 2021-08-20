// 백준 2920번 문제 : 음계
// https://www.acmicpc.net/problem/2920
// 알고리즘 분류 : 구현

#include <stdio.h>
#define SIZE 8

int main(void)
{
    int arr[SIZE];
    int diff = 0, diffPrev = 0;

    for (int i = 0; i < SIZE; i++)
    {
        scanf("%d", &arr[i]);
        if (!i) continue;
        diff = arr[i] - arr[i - 1];
        if (i >= 2 && diff != diffPrev) break;
        diffPrev = diff;
    }
    if (diff != diffPrev) puts("mixed");
    else puts((diff == -1 ? "descending" : "ascending"));

    return 0;
}