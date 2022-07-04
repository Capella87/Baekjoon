// 백준 11650번 문제 : 좌표 정렬하기
// https://www.acmicpc.net/problem/11650
// 알고리즘 분류 : 정렬

#include <iostream>
#include <string>
using namespace std;

typedef struct _coordinates
{
    int x;
    int y;
} Coor;

void merge_sort(Coor* arr, Coor* temp, int left, int right)
{
    if (left >= right) return;
    
    int mid = (left + right) / 2;
    merge_sort(arr, temp, left, mid);
    merge_sort(arr, temp, mid + 1, right);

    int i = left, j = mid + 1, k = left;
    while (i <= mid && j <= right)
    {
        if (arr[i].x < arr[j].x)
            temp[k++] = arr[i++];
        else if (arr[i].x > arr[j].x)
            temp[k++] = arr[j++];
        else
        {
            if (arr[i].y <= arr[j].y)
                temp[k++] = arr[i++];
            else temp[k++] = arr[j++];
        }
    }
    while (i <= mid)
        temp[k++] = arr[i++];
    while (j <= right)
        temp[k++] = arr[j++];
    for (auto l = left; l <= right; l++)
        arr[l] = temp[l];
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n;

    cin >> n;
    cin.get();
    Coor* arr = new Coor[n];
    Coor* temp = new Coor[n];
    for (auto i = 0; i < n; i++)
        cin >> arr[i].x >> arr[i].y;
    merge_sort(arr, temp, 0, n - 1);
    for (auto i = 0; i < n; i++)
        cout << arr[i].x << ' ' << arr[i].y << '\n';

    delete[] arr;
    delete[] temp;
    return 0;
}