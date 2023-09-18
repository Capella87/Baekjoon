// 백준 13423번 문제 : Three Dots
// https://www.acmicpc.net/problem/13423
// 알고리즘 분류 : 브루트포스 알고리즘, 이분 탐색

#include <iostream>
#include <algorithm>
using namespace std;

int binary_search(int* arr, int low, int high, const int target)
{
    int left = low;
    int right = high;
    int idx = -1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (arr[mid] == target)
        {
            idx = mid;
            break;
        }
        else if (arr[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    
    return idx;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t, n;
    int arr[1000];

    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int count = 0;
        cin >> n;
        for (int j = 0; j < n; j++)
            cin >> arr[j];
        sort(arr, arr + n);
        for (int j = 0; j < n - 1; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                int diff = arr[k] - arr[j];
                int rt = binary_search(arr, k, n - 1, arr[k] + diff);
                if (rt != -1) count++;
            }
        }
        cout << count << '\n';
    }

    return 0;
}