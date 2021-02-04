// 백준 10872번 문제 : 팩토리얼
// https://www.acmicpc.net/problem/10872
// 알고리즘 분류 : 수학, 구현

#include <stdio.h>

int factorial(int);

int main(void)
{
    int input;

    scanf("%d", &input);
    printf("%d\n", factorial(input));
    return 0;
}

int factorial(int n)
{
    if (n == 0) return 1;
    else return factorial(n - 1) * n;
}