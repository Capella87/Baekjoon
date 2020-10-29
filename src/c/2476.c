// 백준 2476번 문제 : 주사위
// https://www.acmicpc.net/problem/2476

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    int n;
    int maxtotal = 0, total;
    int a, b, c;

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d %d", &a, &b, &c);
        total = 0;
        if (a == b && b == c && a == c)
            total = 10000 + a * 1000;
        else if (a == b || a == c)
            total = 1000 + a * 100;
        else if (b == c)
            total = 1000 + b * 100;
        else
            total = ((a > b) ? ((a > c) ? a : c) : ((c > b) ? c : b)) * 100;
        
        if (maxtotal < total)
            maxtotal = total;
    }

    printf("%d\n", maxtotal);
    return 0;
}
