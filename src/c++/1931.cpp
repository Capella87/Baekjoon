// 백준 1931번 문제 : 회의실 배정
// https://www.acmicpc.net/problem/1931
// 알고리즘 분류 : 그리디 알고리즘, 정렬

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool comparator(const pair<int, int> a, const pair<int, int> b)
{
    if (a.second < b.second) return true;
    else if (a.second == b.second)
        return a.first < b.first;
    else return false;
}

int allocate_room(vector<pair<int, int>>& arr, const int end_idx, int idx)
{
    int start_idx = idx + 1;
    while (start_idx <= end_idx && arr[start_idx].first < arr[idx].second)
        start_idx++;
    if (start_idx <= end_idx) return 1 + allocate_room(arr, end_idx, start_idx);
    else return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    vector<pair<int, int>> arr;
    int n, start, end;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> start >> end;
        arr.push_back({ start, end });
    }
    sort(arr.begin(), arr.end(), comparator);

    cout << allocate_room(arr, n - 1, -1) << '\n';

    return 0;
}