// 백준 4779번 문제 : 칸토어 집합
// https://www.acmicpc.net/problem/4779
// 알고리즘 분류 : 분할 정복, 재귀

#include <stdio.h>
#include <math.h>

void cantor(int n)
{
    if (!n)
    {
        printf("-");
        return;
    }

    cantor(n - 1);
    int size = (int)pow(3, n - 1);
    for (int i = 0; i < size; i++)
        printf(" ");
    cantor(n - 1);
}

int main(void)
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        cantor(n);
        putchar('\n');
    }

    return 0;
}