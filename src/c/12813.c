// 백준 12813번 문제 : 이진수 연산
// https://www.acmicpc.net/problem/12813
// 알고리즘 분류 : 문자열, 비트 집합

#include <stdio.h>
#include <stdlib.h>
#define SIZE 100000

void bitAND(char* a, char* b, char* result)
{
    for (int i = 0; i < SIZE; i++)
        result[i] = (a[i] == '1' && b[i] == '1') ? '1' : '0';
    puts(result);
}

void bitOR(char* a, char* b, char* result)
{
    for (int i = 0; i < SIZE; i++)
        result[i] = (a[i] == '0' && b[i] == '0') ? '0' : '1';
    puts(result);
}

void bitXOR(char* a, char* b, char* result)
{
    for (int i = 0; i < SIZE; i++)
        result[i] = ((a[i] == '1' && b[i] == '1') || (a[i] == '0' && b[i] == '0')) ? '0' : '1';
    puts(result);
}

void bitNOT(char* target, char* result)
{
    for (int i = 0; i < SIZE; i++)
        result[i] = (target[i] == '0') ? '1' : '0';
    puts(result);
}

int main(void)
{
    char a[SIZE + 1];
    char b[SIZE + 1];
    char c[SIZE + 1];
    c[SIZE] = '\0';

    scanf("%s", a);
    getchar();
    scanf("%s", b);

    bitAND(a, b, c);
    bitOR(a, b, c);
    bitXOR(a, b, c);
    bitNOT(a, c);
    bitNOT(b, c);

    return 0;
}