// 백준 11050번 문제 : 얼마?
// https://www.acmicpc.net/problem/9325
// 알고리즘 분류 : 수학, 사칙연산

#include <stdio.h>

int main(void)
{
    int n, price, options;

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &price);
        scanf("%d", &options);
        int opCount, opPrice, total = price;
        for (int i = 0; i < options; i++)
        {
            scanf("%d %d", &opCount, &opPrice);
            total += opCount * opPrice;
        }
        printf("%d\n", total);
    }
    return 0;
}