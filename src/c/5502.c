n// 백준 5502번 문제 : 팰린드롬
// https://www.acmicpc.net/problem/5502
// 알고리즘 분류 : 다이나믹 프로그래밍

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int smallCase[26] = {0, };
int bigCase[26] = {0, };
int numCase[26] = {0, };

bool isPalindrome(char* str, const size_t len)
{
    bool isTrue = true;
    for (int i = 0; i < len / 2; i++)
    {
        int endIdx = len - 1 - i;
        if (str[i] != str[endIdx]) isTrue = false;

        if (str[i] >= 'a' && str[i] <= 'z') smallCase[str[i] - 'a'];
        else if (str[i] >= 'A' && str[i] <= 'Z') bigCase[str[i] - 'A'];
        else if (str[i] >= '0' && str[i] <= '9') numCase[str[i] - '0'];

        if (str[endIdx] >= 'a' && str[endIdx] <= 'z') smallCase[str[endIdx] - 'a'];
        else if (str[endIdx] >= 'A' && str[endIdx] <= 'Z') bigCase[str[endIdx] - 'A'];
        else if (str[endIdx] >= '0' && str[endIdx] <= '9') numCase[str[endIdx] - '0'];
    }
    return isTrue;
}

void solvePalindrome(char* str, const size_t len)
{

}

int main(void)
{
    int n;
    
    
    scanf("%d", &n);
    char* str = (char*)malloc(sizeof(char) * (n + 1));
    scanf("%[^\n]", str);
    if (isPalindrome(str, strlen(str)))
        putchar('0');
    else solvePalindrome(str, strlen);
    return 0;
}
/*
    Ab3bd인 경우
    -> 2개 추가


    Ab3Abd인 경우,

    A d b A 3 A b d A -> 3개 추가

    AACA인 경우

    AAAC인 경우

    C A A A C -> 1개 추가

    AbCD인 경우
    A b D C D b A ->3개 추가

    AbAb인 경우
    
    A b A b A -> 1개 추가

    Cab인 경우

    C b a b C -> 2개

    CCb인 경우

    b C C b -> 1개

*/