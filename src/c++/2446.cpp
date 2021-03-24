// 백준 2446번 문제 : 별 찍기 - 9
// https://www.acmicpc.net/problem/2446
// 알고리즘 분류 : 구현

#include <iostream>
#include <cstdio>

using namespace std;

int main(void)
{
    int n;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int pro = (n - i) * 2;
        for (int j = 0; j < i; j++)
            printf(" ");
        for (int k = 0; k < pro - 1; k++)
            printf("*");
        putchar('\n');
    }
    for (int i = 0; i < n - 1; i++)
    {
        int pro = (i + 2) * 2;
        for (int j = 0; j < n - i - 2; j++)
            printf(" ");
        for (int k = 0; k < pro - 1; k++)
            printf("*");
        putchar('\n');
    }

    return 0;
}