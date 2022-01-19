// 백준 1003번 문제 : 피보나치 함수
// https://www.acmicpc.net/problem/1003
// 알고리즘 분류 : 다이나믹 프로그래밍

#include <iostream>
#include <cstdio>

using namespace std;

int main(void)
{
    int t;
    int f, fm1, fm2; // fm1 = f(n - 1), fm2 = f(n - 2)
    int input;

    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        scanf("%d", &input);
        fm1 = 1, fm2 = 0, f = 0;
        for (int j = 1; j < input; j++)
        {
            f = fm1 + fm2;
            fm2 = fm1;
            fm1 = f;
        }
        if (input == 0) printf("%d %d\n", fm1, fm2);
        else if (input == 1) printf("%d %d\n", fm2, fm1);
        else printf("%d %d\n", fm2, f);
    }

    return 0;
}