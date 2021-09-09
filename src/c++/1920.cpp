// 백준 1920번 문제 : 수 찾기
// https://www.acmicpc.net/problem/1920
// 알고리즘 분류 : 이분 탐색

#include <iostream>
#include <algorithm>
using namespace std;
typedef long long int64;

bool binarySearch(int* arr, int start, int end, const int64 target)
{
    if (start > end) return false;
    int mid = (start + end) / 2;
    if (arr[mid] == target) return true;
    else if (arr[mid] < target) return binarySearch(arr, mid + 1, end, target);
    else return binarySearch(arr, start, mid - 1, target);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, m;
    int64 temp;

    cin >> n;
    int* arr = new int[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr + n); // Use Quick sort of STL.
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> temp;
        cout << binarySearch(arr, 0, n - 1, temp) << '\n';
    }
    delete[] arr;
    return 0;
}