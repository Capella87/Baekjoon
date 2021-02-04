// 백준 8958번 문제 : OX퀴즈
// https://www.acmicpc.net/problem/8958
// 알고리즘 분류 : 구현, 문자열

#include <stdio.h>
#include <string.h>

int main(void)
{
    char input[81] = "", *pos;
    int n, i, total, score;

    scanf("%d", &n);
    getchar();
    for (i = 0; i < n; i++)
    {
        scanf("%[^\n]", input);
        getchar();
        total = 0;
        score = 0;
        for (pos = input; pos < input + strlen(input); pos++)
        {
            if (*pos == 'O') score++;
            else if (*pos == 'X') score = 0;
            total += score;
        }
        printf("%d\n", total);
    }

    return 0;
}