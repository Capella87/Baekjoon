// 백준 11659번 문제 : 구간 합 구하기 4
// https://www.acmicpc.net/problem/11659
// 알고리즘 분류 : 누적 합

#include <stdio.h>

int prefix[100001] = { 0, };

int main(void)
{
    int n, m, start, end, temp;
    
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &temp); // We only need the prefix total => don't have to use array for original values;
        prefix[i] = prefix[i - 1] + temp;
    }

    for (int i = 0; i < m; i++)
    {
        scanf("%d %d", &start, &end);
        printf("%d\n", prefix[end] - prefix[start - 1]);
    }
    
    return 0;
}