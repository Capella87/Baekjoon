// 백준 2675번 문제 : 문자열 반복
// https://www.acmicpc.net/problem/2675
// 알고리즘 분류 : 구현

#include <stdio.h>
#include <string.h>

void NewStr(char*, char*, int);

int main(void)
{
    int t, i, r;
    char s[21];
    char p[170];

    scanf("%d", &t);
    getchar();
    for (i = 0; i < t; i++)
    {
        scanf("%d %s", &r, s);
        getchar();
        NewStr(s, p, r);
        puts(p);
    }

    return 0;
}

void NewStr(char* input, char* out, int repeat)
{
    char* pos, * pos2;

    for (pos = input, pos2 = out; pos < input + strlen(input); pos++)
    {
        for (int i = 0; i < repeat; i++)
            *pos2++ = *pos;
    }
    *pos2 = '\0';

}