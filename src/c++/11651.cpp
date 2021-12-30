// 백준 11651번 문제 : 좌표 정렬하기 2
// https://www.acmicpc.net/problem/11651
// 알고리즘 분류 : 정렬

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void heapify(vector<pair<int, int>>& t, const int size, int target)
{
    int idx = target;
    int left = target * 2 + 1;
    int right = target * 2 + 2;
    
    if (left < size)
    {
        if (t[idx].second < t[left].second)
            idx = left;
        else if (t[idx].second == t[left].second && t[idx].first < t[left].first)
            idx = left;
    }
    if (right < size)
    {
        if (t[idx].second < t[right].second)
            idx = right;
        else if (t[idx].second == t[right].second && t[idx].first < t[right].first)
            idx = right;
    }
    if (idx != target)
    {
        swap(t[target], t[idx]);
        heapify(t, size, idx);
    }
    return;
}

void heap_sort(vector<pair<int, int>>& t, const int size)
{
    for (int i = size / 2 - 1; i >= 0; i--)
        heapify(t, size, i);
    for (int i = size - 1; i >= 0; i--)
    {
        swap(t[0], t[i]);
        heapify(t, i, 0);
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    vector<pair<int, int>> coordinates;
    int n, t_x, t_y;

    cin >> n;
    cin.get();
    for (auto i = 0; i < n; i++)
    {
        cin >> t_x >> t_y;
        pair<int, int> temp(t_x, t_y);
        coordinates.push_back(temp);
    }
    heap_sort(coordinates, n);
    for (auto i = 0; i < n; i++)
        cout << coordinates[i].first << ' ' << coordinates[i].second << '\n';
    return 0;
}