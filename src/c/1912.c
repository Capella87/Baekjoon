// 백준 1912번 문제 : 부분합
// https://www.acmicpc.net/problem/1912
// 알고리즘 분류 : 다이나믹 프로그래밍

#include <stdio.h>

int n;
int arr[100000];

static inline int max(const int a, const int b)
{
    return a > b ? a : b;
}

int kadane()
{
    int rt = arr[0];
    
    for (int i = 1; i < n; i++)
    {
        arr[i] = max(arr[i], arr[i - 1] + arr[i]); // Kadane's Algorithm; Save max subarray in the input array.
        if (rt < arr[i]) rt = arr[i];
    }
    
    return rt;
}

int main(void)
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    printf("%d\n", kadane());
    
    return 0;
}