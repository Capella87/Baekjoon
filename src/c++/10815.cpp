// 백준 10815번 문제 : 숫자 카드
// https://www.acmicpc.net/problem/10815
// 알고리즘 분류 : 정렬, 이분 탐색

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> l;

int binary_search(int left, int right, const int target)
{
    while (left <= right)
    {
        int mid = (left + right) / 2;
        
        if (l[mid] == target) return 1;
        else if (l[mid] < target) left = mid + 1;
        else right = mid - 1;
    }

    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, temp;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        l.push_back(temp);
    }
    sort(l.begin(), l.end());
    int size = int(l.size());
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        cout << binary_search(0, size - 1, temp) << ' ';
    }
    cout << '\n';

    return 0;
}