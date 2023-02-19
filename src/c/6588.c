// 백준 6588번 문제 : 골드바흐의 추측
// https://www.acmicpc.net/problem/6588
// 알고리즘 분류 : 수학, 정수론, 소수 판정, 에라토스테네스의 체

#include <stdio.h>
#include <stdbool.h>

bool is_not_prime[1000001] = { false };

int main(void)
{
    int n;
    is_not_prime[0] = is_not_prime[1] = true;
    for (int i = 2; i <= 1000; i++)
    {
        if (is_not_prime[i]) continue;
        for (int j = i * i; j <= 1000000; j += i) // More Faster calc; begin with i * i;
            is_not_prime[j] = true;
    }
    
    while (1)
    {
        scanf("%d", &n);
        if (!n) break;

        int i = 2;
        for (; i <= n; i++)
            if (!is_not_prime[i] && !is_not_prime[n - i]) break;
        printf("%d = %d + %d\n", n, i, n - i);
    }

    return 0;
}