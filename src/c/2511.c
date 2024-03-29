// 백준 2511번 문제 : 카드놀이
// https://www.acmicpc.net/problem/2511
// 알고리즘 분류 : 구현

#include <stdio.h>
#define ROUND 10

int main(void)
{
    int input[2][ROUND];
    char result[ROUND];
    int i, j;
    int atot = 0, btot = 0;

    for (i = 0; i < 2; i++)
        for (j = 0; j < ROUND; j++)
            scanf("%d", &input[i][j]);
    for (i = 0; i < ROUND; i++)
    {
        if (input[0][i] > input[1][i]) // A wins
        {
            result[i] = 'A';
            atot += 3;
        }
        else if (input[0][i] < input[1][i]) // B wins
        {
            result[i] = 'B';
            btot += 3;
        }
        else // Draw
        {
            result[i] = 'D';
            atot++;
            btot++;
        }
    }
    printf("%d %d\n", atot, btot);
    if (atot > btot)
        puts("A");
    else if (atot < btot)
        puts("B");
    else if (atot == 10 && btot == 10)
        puts("D");
    else // Same scores, but not all draws
    {
        i = ROUND - 1;
        while (result[i] == 'D' && i >= 0) // Find the last winner before draw
            i--;
        printf("%c\n", result[i]);
    }
    return 0;
}