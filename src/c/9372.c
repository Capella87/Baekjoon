// 백준 9372번 문제 : 상근이의 여행
// https://www.acmicpc.net/problem/9372
// 알고리즘 분류 : 그래프 이론, 트리

#include <stdio.h>

int main(void)
{
    int t, n, m, a, b;

    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        scanf("%d %d", &n, &m);
        for (int i = 0; i < m; i++)
            scanf("%d %d", &a, &b);
        printf("%d\n", n - 1);
    }

    return 0;
}