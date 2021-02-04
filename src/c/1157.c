// 백준 1157번 문제 : 단어 공부
// https://www.acmicpc.net/problem/1157

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

int main(void)
{
    char input[1000001], * pos;
    int stat[26] = { 0, }, *max = stat;
    size_t len;
    bool dup = false;

    scanf("%[^\n]", input);
    getchar();
    len = strlen(input);
    for (pos = input; pos < input + len; pos++)
        stat[toupper(*pos) - 'A']++;
    for (int i = 0; i < 26; i++)
    {
        if (*(stat + i) > *max)
        {
            max = stat + i;
            if (dup) dup = false;
        }
        else if (*(stat + i) == *max && max != (stat + i))
            dup = true;
    }
    if (dup == true) putchar('?');
    else printf("%c\n", 'A' + (char)(max - stat));

    return 0;
}