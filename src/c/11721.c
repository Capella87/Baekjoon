// 백준 11721번 문제 : 열 개씩 끊어 출력하기
// https://www.acmicpc.net/problem/11721
// 알고리즘 분류 : 구현, 문자열

#include <stdio.h>
#include <string.h>
#define MAX 100

int main(void)
{
    char input[MAX + 1];
    char* pos = input;
    size_t len;

    scanf("%[^\n]", input);
    getchar();
    len = strlen(input);
    for(; pos < input + len; pos++)
    {
        printf("%c", *pos);
        if ((pos - input + 1) % 10 == 0) putchar('\n');
    }

    return 0;
}