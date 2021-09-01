// 백준 1673번 문제 : 치킨 쿠폰
// https://www.acmicpc.net/problem/1673
// 알고리즘 분류 : 구현, 애드 혹

#include <stdio.h>

int getChicken(int n, int k)
{
    if (n / k == 0)
        return n / k;
    else return n / k + getChicken(n / k + n % k, k);
}

int main(void)
{
    int n, k;

    while (scanf("%d %d", &n, &k) != EOF)
        printf("%d\n", getChicken(n, k) + n);
    return 0;
}