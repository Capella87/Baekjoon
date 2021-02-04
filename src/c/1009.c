// 백준 1009번 문제 : 분산처리
// https://www.acmicpc.net/problem/1009
// 알고리즘 분류 : 수학, 구현

#include <stdio.h>

int main(void)
{
    int a, b, t;
    int i, j, result;

    scanf("%d", &t);
    for (i = 0; i < t; i++)
    {
        scanf("%d %d", &a, &b);
        result = 1;
        if (a % 10 == 1 || a % 10 == 5 || a % 10 == 6)
            result = a % 10;
        else if (a % 10 == 0)
            result = 10;
        else if (a % 10 == 9)
            result = (b % 2 == 0) ? 1 : 9;
        else
            for (j = 0; j <= ((b - 1) % 4); j++)
                result = (result * a) % 10;
        printf("%d\n", result);
    }

    return 0;
}