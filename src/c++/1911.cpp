// 백준 1911번 문제 : 흙길 보수하기
// https://www.acmicpc.net/problem/1911
// 알고리즘 분류 : 그리디 알고리즘, 정렬, 스위핑

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, l, count = 0;

    cin >> n >> l;
    vector<pair<int, int>> vctr;

    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        pair<int, int> p = make_pair(a, b);
        vctr.push_back(p);
    }
    sort(vctr.begin(), vctr.end());
    int idx = 0;
    for (int i = 0; i < n; i++)
    {
        if (idx < vctr[i].first)
        {
            idx = vctr[i].first;
        }
        while (idx < vctr[i].second)
        {
            idx += l;
            count++;
        }
    }
    cout << count << '\n';
    return 0;
}
