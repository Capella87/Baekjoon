// 백준 11653번 문제 : 소인수분해
// https://www.acmicpc.net/problem/11653
// 알고리즘 분류 : 수학, 정수론, 소수 판정

#include <stdio.h>

int main(void)
{
    int n, divisor = 2;

    scanf("%d", &n);
    while (n != 1)
    {
        while (n % divisor == 0)
        {
            n /= divisor;
            printf("%d\n", divisor);
        }
        divisor++;
    }
    return 0;
}