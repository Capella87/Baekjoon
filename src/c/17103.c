// 백준 17103번 문제 : 골드바흐 파티션
// https://www.acmicpc.net/problem/17103
// 알고리즘 분류 : 수학, 정수론, 소수 판정, 에라토스테네스의 체

#include <stdio.h>
#include <stdbool.h>

bool is_not_prime[1000001] = { false };

int main(void)
{
    int n, t;
    is_not_prime[0] = is_not_prime[1] = true;
    for (int i = 2; i <= 1000; i++)
    {
        if (is_not_prime[i]) continue;
        for (int j = i * i; j <= 1000000; j += i)
            is_not_prime[j] = true;
    }
    
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &t);

        int count = 0;
        int div = t / 2;
        for (int j = 2; j <= div; j++)
            if (!is_not_prime[j] && !is_not_prime[t - j]) count++;
        printf("%d\n", count);
    }

    return 0;
}