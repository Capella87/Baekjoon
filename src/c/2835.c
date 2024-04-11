// 백준 2805번 문제 : 나무 자르기
// https://www.acmicpc.net/problem/2805
// 알고리즘 분류 : 이분 탐색, 매개 변수 탐색

// 복습 필요

#include <stdio.h>
#include <stdlib.h>
typedef long long int64;

int64 lower_bound(int64* arr, const int size, int64 min, int64 max, const int64 t)
{
    long long rt = 0;

    while (min <= max)
    {
        int64 mid = (min + max) / 2;
        int64 count = 0;
        for (int i = 0; i < size; i++)
            if (mid < arr[i])
                count += arr[i] - mid;
        if (count < t) max = mid - 1;
        else
        {
            min = mid + 1;
            if (mid > rt) rt = mid;
        }
    }

    return rt;
}

int main(void)
{
    int n;
    int64 m, max = -1, min = 1;

    scanf("%d %lld", &n, &m);
    getchar();
    int64* arr = (int64*)malloc(sizeof(int64) * n);
    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &arr[i]);
        if (max < arr[i])
            max = arr[i];
    }
    printf("%lld\n", lower_bound(arr, n, min, max, m));

    free(arr);
    return 0;
}