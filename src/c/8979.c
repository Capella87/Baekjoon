// 백준 8979번 문제 : 올림픽
// https://www.acmicpc.net/problem/8979
// 알고리즘 분류 : 정렬

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct _country
{
    int num;
    int gold;
    int silver;
    int bronze;
} Country;

int compare(const void* a, const void* b)
{
    const Country* first = (Country*)a;
    const Country* second = (Country*)b;
    int rt = first->gold - second->gold;
    
    if (!rt)
    {
        rt = first->silver - second->silver;
        if (!rt) return (first->bronze - second->bronze) * (-1);
        else return rt * (-1);
    }
    else return rt * (-1);
}

bool isSameRank(const Country* a, const Country* b)
{
    bool rt = false;
    if (a->gold == b->gold && a->silver == b->silver && a->bronze == b->bronze)
        rt = true;
    return rt;
}

int main()
{
    int n, k;

    scanf("%d %d", &n, &k);
    Country* part = (Country*)malloc(sizeof(Country) * n);
    for (int i = 0; i < n; i++)
        scanf("%d %d %d %d", &part[i].num, &part[i].gold, &part[i].silver, &part[i].bronze);
    qsort((void*)part, (size_t)n, sizeof(Country), compare);
    // qsort; quick sort -> In default, it sorts to increasing order.
    // comparator's return value: > 0 -> elem1 is greater than elem2 : target to be swapped.
    int rk = 1, dupRank = 0;

    if (part[0].num == k)
    {
        printf("%d\n", rk);
        goto term;
    }
    for (int i = 1; i < n; i++)
    {
        if (isSameRank(&part[i - 1], &part[i])) dupRank++;
        else
        {
            rk += dupRank + 1;
            dupRank = 0;
        }
        if (part[i].num == k)
        {
            printf("%d\n", rk);
            break;
        }
    }
term:
    free(part);
    return 0;
}