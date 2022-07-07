// 백준 15990번 문제 : 1, 2, 3 더하기 5
// https://www.acmicpc.net/problem/15990
// 알고리즘 분류 : 다이나믹 프로그래밍

// Bottom-up

#include <stdio.h>
#include <stdint.h>

int64_t cache[100001][4] = { 0, };

int main(void)
{
    int n, temp;

    cache[1][0] = cache[2][0] = cache[1][1] = cache[2][2] = 1;
    cache[3][1] = cache[3][2] = cache[3][3] = 1;
    cache[3][0] = 3;

    for (int i = 4; i <= 100000; i++)
    {
        // 1, 2, 혹은 3을 더할 때 같은 수가 끝에 두 번 더해지지 않게 피해야 한다.
        cache[i][1] = (cache[i - 1][2] % 1000000009 + cache[i - 1][3] % 1000000009) % 1000000009; // 1을 더하는 경우
        cache[i][2] = (cache[i - 2][1] % 1000000009 + cache[i - 2][3] % 1000000009) % 1000000009; // 2를 더하는 경우
        cache[i][3] = (cache[i - 3][1] % 1000000009 + cache[i - 3][2] % 1000000009) % 1000000009; // 3을 더하는 경우
        cache[i][0] = (cache[i][1] % 1000000009 + cache[i][2] % 1000000009 + cache[i][3] % 1000000009) % 1000000009;
    }

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &temp);
        printf("%lld\n", cache[temp][0]);
    }

    return 0;
}