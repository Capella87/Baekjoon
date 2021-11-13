// 백준 14729번 문제 : 칠무해
// https://www.acmicpc.net/problem/14729
// 알고리즘 분류 : 정렬

#include <stdio.h>
#include <stdlib.h>

inline void swap(double* a, double* b)
{
    double temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(double* arr, const int size, int t_idx)
{
    int largest = t_idx;
    int left = t_idx * 2 + 1;
    int right = t_idx * 2 + 2;

    if (left < size && arr[largest] < arr[left])
        largest = left;
    if (right < size && arr[largest] < arr[right])
        largest = right;
    if (largest != t_idx)
    {
        swap(&arr[largest], &arr[t_idx]);
        heapify(arr, size, largest);
    }
    return;
}

void heap_sort(double* arr, const int size)
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

    double* arr = (double*)malloc(sizeof(double) * n);
    getchar();
    for (int i = 0; i < n; i++)
        scanf("%lf", &arr[i]);
    heap_sort(arr, n);
    for (int i = 0; i < 7; i++)
        printf("%.3lf\n", arr[i]);
    free(arr);
    return 0;
}