// 백준 1193번 문제 : 분수찾기
// https://www.acmicpc.net/problem/1193
// 알고리즘 분류 : 수학, 구현

#include <stdio.h>

int main(void)
{
    int n, x, y;
    int elem = 1;
    int diff = 0;
    int total = 2;

    scanf("%d", &n);
    while ((elem + diff) < n)
    {
        elem += ++diff;
        total++;
    }
    if (total % 2) x = 1 + (n - elem), y = total - 1 - (n - elem);
    else x = total - 1 - (n - elem), y = 1 + (n - elem);
    printf("%d/%d\n", x, y);

    return 0;
}