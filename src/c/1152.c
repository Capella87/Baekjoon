// 백준 1152번 문제 : 단어의 개수
// https://www.acmicpc.net/problem/1152
// 알고리즘 분류 : 구현, 문자열

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 1000000

int getWordCount(char*, size_t);

int main(void)
{
    char* input = (char*)malloc(sizeof(char) * (MAX + 1));
    if (input == NULL) exit(EXIT_FAILURE);
    size_t len;

    scanf("%[^\n]", input);
    len = strlen(input);
    getchar();
    input = (char*)realloc(input, sizeof(char) * (len + 1));
    if (input == NULL)
    {
        free(input);
        exit(EXIT_FAILURE);
    }
    len = strlen(input);
    printf("%d\n", getWordCount(input, len));

    free(input);
    return 0;
}

int getWordCount(char* input, size_t len)
{
    char* pos = NULL;
    int wordCount = 0;
    int isWord = false;

    for (pos = input; pos <= input + len; pos++)
    {
        if ((*pos >= 'a' && *pos <= 'z') || (*pos >= 'A' && *pos <= 'Z'))
        {
            if (!isWord) isWord = true;
            continue;
        }

        if ((*pos == ' ' || *pos == '\0') && isWord)
        {
            isWord = false;
            wordCount++;
        }
    }

    return wordCount;
}
