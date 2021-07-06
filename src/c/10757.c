// 백준 2941번 문제 : 큰 수 A+B
// https://www.acmicpc.net/problem/10757
// 알고리즘 분류 : 수학, 구현, 사칙연산, 임의 정밀도 / 큰 수 연산

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char adder(char a, char b, char* carry)
{
    char rt = a + b + *carry - 2 * '0';
    if (rt > '9')
    {
        rt -= 10;
        *carry = '1';
    }
    else *carry = '0';

    return rt;
}

int main(void)
{
    char A[10002] = "", B[10002] = "";

    scanf("%s %s", A, B);
    getchar();
    size_t aLen = strlen(A), bLen = strlen(B);
    size_t cLen = 1 + ((aLen > bLen) ? aLen : bLen);
    size_t common = aLen > bLen ? bLen : aLen;
    char* C = (char*)malloc(sizeof(char) * (cLen + 1));

    C[cLen] = '\0';
    size_t i = 0;
    char carry = '0';
    for (; i < common; i++) // common digits
        C[cLen - 1 - i] = adder(A[aLen - 1 - i], B[bLen - 1 - i], &carry);
    if (aLen > bLen)
        for (; i < aLen; i++)
            C[cLen - 1 - i] = adder(A[aLen - 1 - i], '0', &carry);
    else
        for (; i < bLen; i++)
            C[cLen - 1 - i] = adder('0', B[bLen - 1 - i], &carry);
    C[cLen - 1 - i] = adder('0', '0', &carry);

    if (C[0] == '0') puts(C + 1);
    else puts(C);
    free(C);
    return 0;
}