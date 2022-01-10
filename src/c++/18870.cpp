// 백준 18870번 문제 : 좌표 압축
// https://www.acmicpc.net/problem/18870
// 알고리즘 분류 : 구현, 자료 구조, 시뮬레이션, 덱

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    vector<int> arr;
    int n, temp;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        arr.push_back(temp);
    }
    vector<int> orig = arr; // Backup original;
    
    sort(arr.begin(), arr.end());
    arr.erase(unique(arr.begin(), arr.end()), arr.end()); // Remove duplicates
    for (int i = 0; i < n; i++) // Use lower bound to cover bigger or equal numbers.
        cout << lower_bound(arr.begin(), arr.end(), orig[i]) - arr.begin() << ' ';
    cout << '\n';

    return 0;
}