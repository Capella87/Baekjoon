// 백준 1654번 문제 : 랜선 자르기
// https://www.acmicpc.net/problem/1654
// 알고리즘 분류 : 이분 탐색, 매개 변수 탐색

#include <stdio.h>
#include <stdlib.h>
typedef long long int64;

int main(void)
{
    int k, n;

    scanf("%d %d", &k, &n);
    int64* arr = (int64*)malloc(sizeof(int64) * k);
    int64 max = -1, min = 1, max_length = 1;
    for (int i = 0; i < k; i++)
    {
        scanf("%lld", &arr[i]);
        if (arr[i] > max) max = arr[i];
    }

    while (min <= max) // Lower Bound
    {
        int64 mid = (max + min) / 2;
        int64 count = 0;
        for (int i = 0; i < k; i++)
            count += arr[i] / (int64)mid;
        
        if (count < n) max = mid - 1;
        else min = mid + 1;
    }
    printf("%lld\n", max); // min must be bigger than max; So max is returned.

    free(arr);
    return 0;
}