// 백준 1259번 문제 : 팰린드롬수
// https://www.acmicpc.net/problem/1259
// 알고리즘 분류 : 구현, 문자열

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main(void)
{
    char input[6] = "";
    char* pos = NULL, * pos2 = NULL;
    bool flag = false;
    size_t len;

    while (1)
    {
        scanf("%[^\n]", input);
        if (strcmp(input, "0") == 0) break;
        len = strlen(input);
        getchar();
        flag = false;
        for (pos = input, pos2 = input + len - 1; pos < input + len / 2; pos++, pos2--)
        {
            if (*pos != *pos2)
            {
                flag = true;
                break;
            }
        }
        printf("%s\n", flag == true ? "no" : "yes");
    }

    return 0;
}