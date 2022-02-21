// 백준 2108번 문제 : 통계학
// https://www.acmicpc.net/problem/2108
// 알고리즘 분류 : 구현, 정렬

#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int arr[500000] = { 0, };
int counting[8001] = { 0, };

static inline void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(const int size, int target)
{
    int max_idx = target;
    int left = max_idx * 2 + 1;
    int right = max_idx * 2 + 2;

    if (left < size && arr[max_idx] < arr[left])
        max_idx = left;
    if (right < size && arr[max_idx] < arr[right])
        max_idx = right;
    if (max_idx != target)
    {
        swap(&arr[max_idx], &arr[target]);
        heapify(size, max_idx);
    }
    return;
}

void heap_sort(const int size)
{
    for (int i = size / 2 - 1; i >= 0; i--)
        heapify(size, i);
    for (int i = size - 1; i >= 0; i--)
    {
        swap(&arr[0], &arr[i]);
        heapify(i, 0);
    }
    return;
}

int mode(int* carr)
{
    int max_count = 0;
    int mode;
    bool is_dup = false;
    for (int i = 0; i <= 8000; i++)
    {
        if (max_count < carr[i])
        {
            max_count = carr[i];
            mode = i - 4000;
            is_dup = false;
        }
        else if (max_count && max_count == carr[i] && !is_dup)
        {
            mode = i - 4000;
            is_dup = true;
        }
    }
    return mode;
}

int main(void)
{
    int n;
    double total = 0.0;
    bool is_dup = false, is_positive = false;

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        total += (double)arr[i];
        counting[arr[i] + 4000]++;
    }

    double avg_result = round(total / n) + 0.0;
    printf("%.lf\n", avg_result);
    heap_sort(n);
    printf("%d\n", arr[n / 2]);
    printf("%d\n", mode(counting));
    printf("%d\n", arr[n - 1] - arr[0]);

    return 0;
}