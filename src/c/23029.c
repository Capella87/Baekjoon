// 백준 23029번 문제 : 시식 코너는 나의 것
// https://www.acmicpc.net/problem/23029
// 알고리즘 분류 : 다이나믹 프로그래밍

#include <stdio.h>

inline int max(int a, int b)
{
    return a > b ? a : b;
}

int arr[100000];
int cache[100000];

int main(void)
{
    int n;

    scanf("%d", &n);
    int cache_max = 0, result_max;
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    cache[0] = max(arr[0], 0);
    result_max = cache[0];
    if (n > 1)
    {
        cache[1] = max(arr[1] / 2 + arr[0], arr[1]);
        result_max = max(result_max, cache[1]);
    }
    for (int i = 2; i < n; i++)
    {
        cache[i] = max(arr[i] / 2 + arr[i - 1] + cache_max, arr[i] + max(cache_max, cache[i - 2]));
        cache_max = max(cache_max, cache[i - 2]);
        result_max = max(result_max, cache[i]);
    }
    printf("%d\n", result_max);

    return 0;
}