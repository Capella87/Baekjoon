// 백준 11729번 문제 : 하노이 탑 이동 순서
// https://www.acmicpc.net/problem/11729
// 알고리즘 분류 : 재귀

#include <stdio.h>
#include <math.h>

void hanoiMove(int, int, int, int);

int main(void)
{
    int n;

    scanf("%d", &n);
    printf("%d\n", (int)(pow(2, n) - 1));
    hanoiMove(n, 1, 2, 3);

    return 0;
}

void hanoiMove(int num, int from, int via, int to)
{
    if (num == 1)
    {
        printf("%d %d\n", from, to);
    }
    else
    {
        hanoiMove(num - 1, from, to, via);
        printf("%d %d\n", from, to);
        hanoiMove(num - 1, via, from, to);
    }
}