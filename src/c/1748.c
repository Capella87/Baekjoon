// 백준 1748번 문제 : 수 이어 쓰기 1
// https://www.acmicpc.net/problem/1748
// 알고리즘 분류 : 수학, 구현

#include <stdio.h>
#include <stdint.h>

int main(void)
{
    int64_t total = 0, n, divider = 10, count = 1, prev = 1;

    scanf("%lld", &n);
    
    while (divider <= n) 
    {
        total += count * (divider - prev);
        prev = divider;
        divider *= 10;
        count++;
    }
    divider /= 10;
    total += (n - divider + 1) * count;
    printf("%lld\n", total);
    
    return 0;
}