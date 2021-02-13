// 백준 2501번 문제 : 약수 구하기
// https://www.acmicpc.net/problem/2501
// 알고리즘 분류 : 수학

#include <stdio.h>

int main(void)
{
    int n, k, count = 0, pos;
    int i;

    scanf("%d %d", &n, &k);

    for (i = 1; i <= n; i++)
    {
        if (n % i == 0)
        {
            pos = i;
            count++;
        }
        if (count == k) break;
    }
    printf("%d\n", (count < k) ? 0 : pos);

    return 0;
}