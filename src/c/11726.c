// 백준 11726번 문제 : 2×n 타일링
// https://www.acmicpc.net/problem/11726
// 알고리즘 분류 : 다이나믹 프로그래밍

#include <stdio.h>

int getCase(int);

int main(void)
{
    int n;

    scanf("%d", &n);
    printf("%d\n", getCase(n) % 10007);

    return 0;
}

// 점화식 A(n) = A(n - 1) + A(n - 2)
int getCase(int input)
{
    if (input <= 3) return input;
    else return getCase(input - 1) + getCase(input - 2);
}