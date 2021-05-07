// 백준 2941번 문제 : 크로아티아 알파벳
// https://www.acmicpc.net/problem/2941
// 알고리즘 분류 : 문자열

#include <stdio.h>
#include <string.h>
#define MAX 100

size_t countCroatian(char* input);
const char* chk = "cdlnsz";

int main(void)
{
    char input[MAX + 1] = "";

    scanf("%[^\n]", input);
    printf("%zu\n", countCroatian(input));

    return 0;
}

size_t countCroatian(char* input)
{
    char* pos = input;
    size_t len = strlen(input);
    size_t tot = 0;

    for (; pos < input + len; pos++)
    {
        if (strchr(chk, *pos) && *(pos + 1) != 0)
        {
            if (strchr("cd", *pos) && *(pos + 1) == '-')
                pos++;
            else if (strchr("csz", *pos) && *(pos + 1) == '=')
                pos++;
            else if (strchr("ln", *pos) && *(pos + 1) == 'j')
                pos++;
            else if (*pos == 'd' && *(pos + 1) == 'z' && *(pos + 2) == '=')
                pos += 2;
        }
        tot++;
    }

    return tot;
}