// 백준 20540번 문제 : 연길이의 이상형
// https://www.acmicpc.net/problem/20540
// 알고리즘 분류 : 구현, 문자열

#include <stdio.h>
#define MBTI 4

int main(void)
{
    char input[5];
    char out;

    scanf("%s", input);
    getchar();

    for (int i = 0; i < MBTI; i++)
    {
        out = input[i];
        switch (i)
        {
        case 0:
            printf("%c", (out == 'E' ? 'I' : 'E'));
            break;
        case 1:
            printf("%c", (out == 'S' ? 'N' : 'S'));
            break;
        case 2:
            printf("%c", (out == 'T' ? 'F' : 'T'));
            break;
        case 3:
            printf("%c", (out == 'J' ? 'P' : 'J'));
            break;
        }
    }
    putchar('\n');
    return 0;
}