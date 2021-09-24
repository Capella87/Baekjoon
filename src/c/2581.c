// 백준 2581번 문제 : 소수
// https://www.acmicpc.net/problem/2581
// 알고리즘 분류 : 수학, 정수론, 소수 판정

#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    int m, n, last;
    int total = 0;
    bool isComposite[10001] = { false, };

    scanf("%d %d", &m, &n);
    if (m == 1) m++;
    for (int i = 2; i <= 10000; i++)
    {
        int j = 2;
        while (i * j <= 10000)
            isComposite[i * j++] = true;
    }
    for (int i = n; i >= m; i--)
    {
        if (!isComposite[i])
        {
            last = i;
            total += last;
        }
    }
    if (!total) puts("-1");
    else printf("%d\n%d\n", total, last);
    return 0;
}