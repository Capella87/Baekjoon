// 백준 2750번 문제 : 수 정렬하기
// https://www.acmicpc.net/problem/2750
// 알고리즘 분류 : 구현, 정렬

// Using bubble sort

#include <iostream>
using namespace std;

int main()
{
    int n, temp;
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    int* arr = new int[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < n; i++)
        cout << arr[i] << '\n';

    delete[] arr;
    return 0;
}
