// 백준 2908번 문제 : 상수
// https://www.acmicpc.net/problem/2908
// 알고리즘 분류 : 구현

#include <stdio.h>
#include <string.h>
#define SIZE 4

int GetNum(char*);

int main(void)
{
    char a1[SIZE], a2[SIZE];
    int rev1, rev2;

    scanf("%s %s", a1, a2);
    rev1 = GetNum(a1);
    rev2 = GetNum(a2);
    printf("%d\n", rev1 > rev2 ? rev1 : rev2);

    return 0;
}

int GetNum(char* target)
{
    char* pos;
    int result = 0;
    for (pos = target + SIZE - 2; pos >= target; pos--)
        result = result * 10 + (int)(*pos - '0');

    return result;
}