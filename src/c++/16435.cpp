// 백준 16435번 문제 : 스네이크버드
// https://www.acmicpc.net/problem/16435
// 알고리즘 분류 : 그리디 알고리즘, 정렬

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, l, temp;
    cin >> n >> l;
    vector<int> arr;

    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        arr.push_back(temp);
    }
    sort(arr.begin(), arr.end());

    for (int i = 0; i < n; i++)
    {
        if (arr[i] <= l) l++;
        else break;
    }
    cout << l << '\n';

    return 0;
}
