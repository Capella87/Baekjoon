// 백준 2485번 문제 : 가로수
// https://www.acmicpc.net/problem/2485
// 알고리즘 분류 : 수학, 정수론, 유클리드 호제법

#include <stdio.h>
#include <stdlib.h>

int getGCD(int a, int b)
{
    return (a % b == 0) ? b : getGCD(b, a % b);
}

int main(void)
{
    int n;
    int prevMargin = 0, margin = 0;

    scanf("%d", &n);
    int* street = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", street + i);
        if (i) margin = street[i] - street[i - 1];
        if (!prevMargin)
        {
            prevMargin = margin;
            continue;
        }
        if (prevMargin > margin)
        {
            int temp = prevMargin;
            prevMargin = margin;
            margin = temp;
        }
        prevMargin = getGCD(margin, prevMargin);
    }
    int answer = (street[n - 1] - street[0]) / prevMargin + 1 - n;
    printf("%d\n", answer);
    free(street);
    return 0;
}