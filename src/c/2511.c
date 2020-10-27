// 백준 2511번 문제:: 카드놀이
// https://www.acmicpc.net/problem/2511

#include <stdio.h>
#define ROUND 10

int main(void)
{
    int input[2][ROUND];
    char result[ROUND];
    int i, j;
    int atot = 0, btot = 0;

    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < ROUND; j++)
            scanf("%d", &input[i][j]);
        getchar();
    }
    for (i = 0; i < ROUND; i++)
    {
        if (input[0][i] > input[1][i])
        {
            result[i] = 'A';
            atot += 3;
        }
        else if (input[0][i] < input[1][i])
        {
            result[i] = 'B';
            btot += 3;
        }
        else if (input[0][i] == input[1][i])
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
    else
    {
        i = ROUND - 1;
        while (result[i] == 'D' && i >= 0)
            i--;
        printf("%c\n", result[i]);
    }
    
    return 0;
}
