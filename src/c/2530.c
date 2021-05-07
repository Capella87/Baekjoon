// 백준 2530번 문제 : 인공지능 시계
// https://www.acmicpc.net/problem/2530
// 알고리즘 분류 : 수학, 사칙연산

#include <stdio.h>

void getTime(const int hh, const int mm, const int ss, const int d)
{
    int result = (hh * 3600 + mm * 60 + ss + d) % 86400;
    printf("%d %d %d\n", result / 3600, result % 3600 / 60, result % 3600 % 60);
}

int main(void)
{
    int hh, mm, ss, d;

    scanf("%d %d %d", &hh, &mm, &ss);
    scanf("%d", &d);
    getTime(hh, mm, ss, d);

    return 0;
}