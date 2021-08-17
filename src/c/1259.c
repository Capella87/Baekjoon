// 백준 1259번 문제 : 팰린드롬수
// https://www.acmicpc.net/problem/1259
// 알고리즘 분류 : 구현, 문자열

#include <stdio.h>
#include <string.h>

int main(void)
{
    char input[6] = "";
    char* pos = NULL, * pos2 = NULL;
    size_t len;

    while (1)
    {
        scanf("%[^\n]", input);
        getchar();
        if (strcmp(input, "0") == 0) break;
        len = strlen(input);
        for (pos = input, pos2 = input + len - 1; pos < input + len / 2; pos++, pos2--)
            if (*pos != *pos2) break;
        printf("%s\n", *pos != *pos2 ? "no" : "yes");
    }
    return 0;
}