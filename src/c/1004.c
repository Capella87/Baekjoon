// 백준 1004번 문제 : 어린 왕자
// https://www.acmicpc.net/problem/1004
// 알고리즘 분류 : 기하학

#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    int t;
    int x1, y1, x2, y2;
    int p_count, minPassThrough = 0;
    int cx, cy, cr;
    bool x1Pass, x2Pass;

    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        getchar();
        scanf("%d", &p_count);
        minPassThrough = 0;
        for (int j = 0; j < p_count; j++)
        {
            scanf("%d %d %d", &cx, &cy, &cr);
            getchar();
            x1Pass = ((x1 - cx) * (x1 - cx) + (y1 - cy) * (y1 - cy)) < (cr * cr) ? true : false;
            x2Pass = ((x2 - cx) * (x2 - cx) + (y2 - cy) * (y2 - cy)) < (cr * cr) ? true : false;
            if ((x1Pass && !x2Pass) || (!x1Pass && x2Pass)) minPassThrough++;
        }
        printf("%d\n", minPassThrough);
    }

    return 0;
}