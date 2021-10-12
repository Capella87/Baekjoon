// 백준 2751번 문제 : 수 정렬하기 2
// https://www.acmicpc.net/problem/2751
// 알고리즘 분류 : 정렬

// Using merge sort

#include <stdio.h>

int leftArr[500000];
int rightArr[500000];
int arr[1000000];

void mergeSort(int* arr, int left, int right, int n)
{
    if (left >= right) return;

    // Division
    int mid = (left + right) / 2;
    mergeSort(arr, left, mid, n);
    mergeSort(arr, mid + 1, right, n);

    int leftLen = mid - left + 1;
    int rightLen = right - mid;
    int i = 0, j = 0, k = left;
    
    for (int l = 0; l < leftLen; l++) // Fill left and right array;
        leftArr[l] = arr[left + l];
    for (int l = 0; l < rightLen; l++)
        rightArr[l] = arr[mid + 1 + l];

    // Merge
    while (i < leftLen && j < rightLen)
    {
        if (leftArr[i] <= rightArr[j])
            arr[k] = leftArr[i++];
        else arr[k] = rightArr[j++];
        k++;
    }
    while (i < leftLen)
    {
        arr[k] = leftArr[i++];
        k++;
    }
    while (j < rightLen)
    {
        arr[k] = rightArr[j++];
        k++;
    }
    return;
}

int main(void)
{
    int n;

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    mergeSort(arr, 0, n - 1, n);
    for (int i = 0; i < n; i++)
        printf("%d\n", arr[i]);
    return 0;
}