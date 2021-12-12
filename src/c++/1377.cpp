// 백준 1371번 문제 : 버블 소트
// https://www.acmicpc.net/problem/1377
// 알고리즘 분류 : 정렬

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    vector<pair<int, int>> v;
    int n, temp, max = -1;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        v.push_back(make_pair(temp, i));
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++)
    {
        int idx_diff = v[i].second - i;
        if (idx_diff >= 0 && max < idx_diff)
            max = idx_diff;
    }
    cout << max + 1 << '\n';

    return 0;
}