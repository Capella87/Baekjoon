// 백준 21318번 문제 : 피아노 체조
// https://www.acmicpc.net/problem/21318
// 알고리즘 분류 : 누적 합
#include <stdio.h>

int cache[100001];

int main(void)
{
    int n, temp, prev, q, x, y, result;

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &temp);
        if (!i)
        {
            prev = temp;
            continue;
        }
        cache[i] = cache[i - 1];
        if (prev > temp) cache[i]++;
        prev = temp;
    }
    scanf("%d", &q);
    for (int i = 0; i < q; i++)
    {
        scanf("%d %d", &x, &y);
        result = cache[y - 1] - cache[x - 1];
        printf("%d\n", result);
    }

    return 0;
}