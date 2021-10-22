// 백준 1181번 문제 : 단어 정렬
// https://www.acmicpc.net/problem/1181
// 알고리즘 분류 : 정렬

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _str
{
    char str[51];
    int len;
} Str;

void mergeSort(Str* arr, Str* buf, int left, int right)
{
    if (left >= right) return;

    int mid = (left + right) / 2;
    mergeSort(arr, buf, left, mid);
    mergeSort(arr, buf, mid + 1, right);

    int i = left, j = mid + 1, k = left;
    while (i <= mid && j <= right)
    {
        int i_len = (int)strlen(arr[i].str);
        int j_len = (int)strlen(arr[j].str);
        if (i_len < j_len)
            buf[k++] = arr[i++];
        else if (i_len > j_len)
            buf[k++] = arr[j++];
        else if (strcmp(arr[i].str, arr[j].str) < 0)
            buf[k++] = arr[i++];
        else buf[k++] = arr[j++];
    }
    while (i <= mid)
        buf[k++] = arr[i++];
    while (j <= right)
        buf[k++] = arr[j++];
    for (int k = left; k <= right; k++)
        arr[k] = buf[k];
    return;
}

int main(void)
{
    int n;

    scanf("%d", &n);
    getchar();
    Str* arr = (Str*)malloc(sizeof(Str) * n);
    Str* temp = (Str*)malloc(sizeof(Str) * n);

    for (int i = 0; i < n; i++)
    {
        scanf("%[^\n]", arr[i].str);
        getchar();
        arr[i].len = (int)strlen(arr[i].str);
    }
    mergeSort(arr, temp, 0, n - 1);
    puts(arr[0].str);
    for (int i = 1; i < n; i++)
        if (strcmp(arr[i - 1].str, arr[i].str))
            puts(arr[i].str);
    free(arr);
    free(temp);
    return 0;
}