// 백준 1002번 문제 : 터렛
// https://www.acmicpc.net/problem/1002
// 알고리즘 분류 : 기하학

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int circleDist(int, int, int, int, int, int);

int main(void)
{
    double dist;
    int x1, y1, r1, x2, y2, r2;
    int t;

    scanf("%d", &t);
    getchar();
    for (int i = 0; i < t; i++)
    {
        scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);
        getchar();
        printf("%d\n", circleDist(x1, y1, r1, x2, y2, r2));
    }

    return 0;
}

int circleDist(int x1, int y1, int r1, int x2, int y2, int r2)
{
    double dist = sqrt(pow((x2 - x1), 2.0) + pow((y2 - y1), 2.0));

    if (r1 == r2 && x1 == x2 && y1 == y2)
        return -1;
    else if (dist > (double)(r1 + r2) || dist < (double)abs(r1 - r2))
        return 0;
    else if (dist == (double)(r1 + r2) || dist == (double)abs(r1 - r2))
        return 1;
    else if (dist > (double)abs(r1 - r2) && dist < (double)(r1 + r2))
        return 2;
}