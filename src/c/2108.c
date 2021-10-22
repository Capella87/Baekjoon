// 백준 2108번 문제 : 통계학
// https://www.acmicpc.net/problem/2108
// 알고리즘 분류 : 구현, 정렬

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

inline void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int* arr, const int size, int target)
{
    int maxIdx = target;
    int left = maxIdx * 2 + 1;
    int right = maxIdx * 2 + 2;

    if (left < size && arr[maxIdx] < arr[left])
        maxIdx = left;
    if (right < size && arr[maxIdx] < arr[right])
        maxIdx = right;
    if (maxIdx != target)
    {
        swap(&arr[maxIdx], &arr[target]);
        heapify(arr, size, maxIdx);
    }
    return;
}

void heapSort(int* arr, const int size)
{
    for (int i = size / 2 - 1; i >= 0; i--)
        heapify(arr, size, i);
    for (int i = size - 1; i >= 0; i--)
    {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
    return;
}

int mode(int* carr)
{
    int maxCount = 0;
    int mode;
    bool isDup = false;
    for (int i = 0; i <= 8000; i++)
    {
        if (maxCount < carr[i])
        {
            maxCount = carr[i];
            mode = i - 4000;
            isDup = false;
        }
        else if (maxCount && maxCount == carr[i] && !isDup)
        {
            mode = i - 4000;
            isDup = true;
        }
    }
    return mode;
}

int main(void)
{
    int n;
    double total = 0.0;

    scanf("%d", &n);
    int* arr = (int*)malloc(sizeof(int) * n);
    int* counting = (int*)malloc(sizeof(int) * 8001);
    memset(counting, 0, 8001 * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        total += (double)arr[i];
        counting[arr[i] + 4000]++;
    }
    printf("%.0lf\n", total / n);
    heapSort(arr, n);
    printf("%d\n", arr[n / 2]);
    printf("%d\n", mode(counting));
    printf("%d\n", arr[n - 1] - arr[0]);
    free(arr);
    free(counting);
    return 0;
}