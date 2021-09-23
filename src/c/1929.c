// 백준 1929번 문제 : 소수 구하기
// https://www.acmicpc.net/problem/1929
// 알고리즘 분류 : 수학, 정수론, 소수 판정, 에라토스테네스의 체

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void)
{
    int m, n;

    scanf("%d %d", &m, &n);
    bool* isComposite = (bool*)malloc(sizeof(bool) * (n + 1));
    for (int i = 0; i <= n; i++)
        isComposite[i] = false;
    if (m == 1) m++;
    for (int i = 2; i * i <= n; i++)
    {
        int j = 2;
        while (i * j <= n)
            isComposite[i * j++] = true;
    }
    for (int i = m; i <= n; i++)
        if (!isComposite[i]) printf("%d\n", i);
    free(isComposite);
    return 0;
}