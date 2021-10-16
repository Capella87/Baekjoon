// 백준 2751번 문제 : 수 정렬하기 2
// https://www.acmicpc.net/problem/2751
// 알고리즘 분류 : 정렬

// Using heap sort

#include <stdio.h>
#include <stdlib.h>

inline void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int* arr, const int size, int target)
{
    int maxIdx = target;
    int left = target * 2 + 1;
    int right = target * 2 + 2;

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

int main(void)
{
    int n;

    scanf("%d", &n);
    int* arr = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
        scanf("%d", arr + i);
    heapSort(arr, n);
    for (int i = 0; i < n; i++)
        printf("%d\n", arr[i]);
    free(arr);
}