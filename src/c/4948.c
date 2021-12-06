// 백준 4948번 문제 : 베르트랑 공준
// https://www.acmicpc.net/problem/4948
// 알고리즘 분류 : 수학, 정수론, 소수 판정, 에라토스테네스의 체

#include <stdio.h>
#include <math.h>

int main(void)
{
    int n;

    // Use the sieve
    int is_composite[246913] = { 0 };
    int ran = (int)sqrt(246913);
    is_composite[0] = is_composite[1] = 1;
    for (int i = 2; i <= ran; i++)
    {
        if (is_composite[i] == 1) continue;

        int j = i * 2;
        while (j <= 246913)
        {
            is_composite[j] = 1;
            j += i;
        }
    }

    scanf("%d", &n);
    while (n)
    {
        int range = n * 2;
        int total = 0;
        for (int i = n + 1; i <= range; i++)
            if (is_composite[i] == 0) total++;
        printf("%d\n", total);
        scanf("%d", &n);
    }

    return 0;
}