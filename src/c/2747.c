// 백준 2747번 문제 : 피보나치 수
// https://www.acmicpc.net/problem/2747

#include <stdio.h>

int fiboNonRecurv(int);

int main(void)
{
    int n;

    scanf("%d", &n);
    printf("%d\n", fiboNonRecurv(n));

    return 0;
}

int fiboNonRecurv(int input)
{
    int f0 = 0, f1 = 1, f;
    int i;

    if (input == 1) return f1;
    for (i = 2; i <= input; i++)
    {
        f = f0 + f1;
        f0 = f1;
        f1 = f;
    }

    return f;
}