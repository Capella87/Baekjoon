// 백준 10814번 문제 : 나이순 정렬
// https://www.acmicpc.net/problem/10814
// 알고리즘 분류 : 정렬

#include <iostream>
#include <string>
using namespace std;

typedef struct _member
{
    string name;
    int age;
} Mem;

void mergeSort(Mem* arr, Mem* temp, int left, int right)
{
    if (left >= right) return;
    int mid = (left + right) / 2;
    mergeSort(arr, temp, left, mid);
    mergeSort(arr, temp, mid + 1, right);

    int i = left, j = mid + 1, k = left;
    while (i <= mid && j <= right)
    {
        if (arr[i].age <= arr[j].age)
            temp[k++] = arr[i++];
        else temp[k++] = arr[j++];

    }
    while (i <= mid)
        temp[k++] = arr[i++];
    while (j <= right)
        temp[k++] = arr[j++];
    for (auto l = left; l <= right; l++)
        arr[l] = temp[l];
    return;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n;

    cin >> n;
    cin.get();
    Mem* list = new Mem[n];
    Mem* temp = new Mem[n];
    for (auto i = 0; i < n; i++)
    {
        cin >> list[i].age >> list[i].name;
        cin.get();
    }
    mergeSort(list, temp, 0, n - 1);
    for (auto i = 0; i < n; i++)
        cout << list[i].age << ' ' << list[i].name << '\n';
    delete[] list;
    delete[] temp;
    return 0;
}