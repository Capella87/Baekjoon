// 백준 1264번 문제 : 모음의 개수
// https://www.acmicpc.net/problem/1264
// 알고리즘 분류 : 없음

#include <stdio.h>
#include <string.h>
#define MAX 256

int main(void)
{
    char input[MAX] = "", * pos = NULL;
    size_t len;
    const char vowels[] = "aiueoAIUEO";
    int vCount;
    while (1)
    {
        scanf("%[^\n]", input);
        getchar();
        if (strcmp(input, "#") == 0) break;
        len = strlen(input);
        vCount = 0;
        for (pos = input; pos < input + len; pos++)
            if (strchr(vowels, *pos) != NULL)
                vCount++;
        printf("%d\n", vCount);
    }

    return 0;
}