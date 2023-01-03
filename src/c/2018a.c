// 백준 2018번 문제 : 수들의 합 5
// https://www.acmicpc.net/problem/2018
// 알고리즘 분류 : 수학, 두 포인터

// 일반적인 두 포인터로 푸는 방법 (느림)

#include <stdio.h>

int main(void)
{
    int n, count = 1, init_sum = 1;
    int first = 1, last = 1;

    scanf("%d", &n);
    
    for (int i = 2; i <= n; i++)
    {
        first = 1;
        init_sum += i;
        last = i;
        if (init_sum > n) break;

        int sum = init_sum;
        while (last <= n && sum <= n)
        {
            if (sum == n)
            {
                count++;
                break;
            }
            sum += ++last - first++;
        }
    }

    printf("%d\n", count);
    return 0;
}