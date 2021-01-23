// 백준 1712번 문제 : 손익분기점
// https://www.acmicpc.net/problem/1712

#include <stdio.h>

int main(void)
{
    int a, b, c;

    scanf("%d %d %d", &a, &b, &c);
    printf("%d\n", c - b > 0 ? a / (c - b) + 1 : -1);
    return 0;
}