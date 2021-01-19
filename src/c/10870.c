// 백준 10870번 문제 : 피보나치 수 5
// https://www.acmicpc.net/problem/10870

#include <stdio.h>

int fibonacci(int);

int main(void)
{
    int input;

    scanf("%d", &input);
    printf("%d\n", fibonacci(input));

    return 0;
}

int fibonacci(int n)
{
    if (n == 0) return 0;
    else if (n == 1) return 1;
    else return fibonacci(n - 1) + fibonacci(n - 2);
}