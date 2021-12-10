// 백준 1059번 문제 : 좋은 구간
// https://www.acmicpc.net/problem/1059
// 알고리즘 분류 : 수학, 브루트포스 알고리즘

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    vector<int> arr;
    int l, n;

    cin >> l;
    for (int i = 0; i < l; i++)
    {
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }
    cin >> n;
    arr.push_back(0);
    sort(arr.begin(), arr.end());

    int i = 0;
    int min_idx = 0;
    while (arr[i] <= n && i < l)
    {
        if (arr[i] < n)
            min_idx = i;
        else if (arr[i] == n)
            min_idx = -1;
        i++;
    }
    if (min_idx == -1) cout << "0" << '\n';
    else
    {
        int min = arr[min_idx] + 1;
        int max = arr[min_idx + 1] - 1;
        cout << (n - min) * (max - n + 1) + max - n << '\n';
    }

    return 0;
}