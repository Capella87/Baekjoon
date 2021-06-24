// 백준 1252번 문제 : 이진수 덧셈
// https://www.acmicpc.net/problem/1252
// 알고리즘 분류 : 수학, 구현, 사칙연산

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char digitCalc(char* aDigit, char* bDigit, char* carry)
{
    char result = *aDigit + *bDigit + *carry - 2 * '0';

    if (result >= '2')
    {
        *carry = '1';
        result -= 2;
    }
    else *carry = '0';
    return result;
}

void calc(char* a, char* b, char* result, const size_t rlen)
{
    const size_t blen = strlen(b), alen = strlen(a);
    size_t common = (blen > alen) ? alen : blen;
    int i;
    char carry = '0';

    result[rlen] = '\0';
    for (i = 0; i < common; i++) // 공통 자릿수
        result[rlen - 1 - i] = digitCalc(a + alen - 1 - i, b + blen - 1 - i, &carry);
    if (alen > blen) // a 자릿수가 더 큰 경우
        for (; i < rlen - 1; i++)
            result[rlen - 1 - i] = digitCalc(a + alen - 1 - i, "0", &carry);
    else if (alen < blen)// b 자릿수가 더 큰 경우
        for (; i < rlen - 1; i++)
            result[rlen - 1 - i] = digitCalc("0", b + blen - 1 - i, &carry);
    *result = digitCalc("0", "0", &carry);
}

int main(void)
{
    char a[81], b[81];
    int i = 0;

    scanf("%s %s", a, b);
    size_t a_len = strlen(a), b_len = strlen(b);
    size_t r_len = 1 + (a_len > b_len ? a_len : b_len);
    char* result = (char*)malloc(sizeof(char) * (r_len + 1));

    calc(a, b, result, r_len);
    while (result[i] == '0' && i != r_len - 1)
        i++;
    puts(result + i);

    free(result);
    return 0;
}