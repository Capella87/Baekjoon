// 백준 1065번 문제 : 한수
// https://www.acmicpc.net/problem/1065

#include <stdio.h>

int getAP(int);

int main(void)
{
    int n;

    scanf("%d", &n);
    printf("%d\n", getAP(n));

    return 0;
}

int getAP(int max)
{
    int hund, ten, one;
    int result = 0, target;

    if (max < 100)
        return max;
    else
    {
        for (target = 100; target <= max; target++)
        {
            hund = target / 100;
            ten = (target % 100) / 10;
            one = (target % 100) % 10;
            if (one - ten == ten - hund) result++;
        }
        return result + 99;
    }
}