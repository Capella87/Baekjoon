// 백준 10988번 문제 : 팰린드롬인지 확인하기
// https://www.acmicpc.net/problem/10988
// 알고리즘 분류 : 구현, 문자열

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool isPalindrome(char* str, size_t len)
{
    if (len <= 1)
        return true;
    if (*str != str[len - 1]) return false;
    else return isPalindrome(str + 1, len - 2);
}

int main(void)
{
    char input[101];

    scanf("%[^\n]", input);
    printf("%d\n", isPalindrome(input, strlen(input)));
    return 0;
}