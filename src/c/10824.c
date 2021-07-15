// 백준 10824번 문제 : 네 수
// https://www.acmicpc.net/problem/10824
// 알고리즘 분류 : 구현

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    char a[8] = "", b[8] = "", c[8] = "", d[8] = "";
    char ab[15] = "", cd[15] = "";

    scanf("%s %s %s %s", a, b, c, d);
    strcpy(ab, a);
    strcat(ab, b);
    strcpy(cd, c);
    strcat(cd, d);
    long long result = atoll(ab) + atoll(cd);
    printf("%lld\n", result);

    return 0;
}