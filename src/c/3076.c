// 백준 3076번 문제 : 상근이의 체스판
// https://www.acmicpc.net/problem/3076
// 알고리즘 분류 : 구현, 문자열

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void)
{
    int r, c, a, b;

    scanf("%d %d %d %d", &r, &c, &a, &b);
    int colSize = c * b;
    bool isBlack = true, prevPattern = true; // true for black;

    for (int i = 0; i < r; i++)
    {
        prevPattern = isBlack;
        for (int k = 0; k < a; k++)
        {
            isBlack = prevPattern;
            for (int j = 0; j < colSize; j++)
            {
                if (j % b == 0 && j) isBlack = !isBlack;
                putchar(isBlack ? 'X' : '.');
            }
            putchar('\n');
        }
        isBlack = !prevPattern;
    }
    return 0;
}