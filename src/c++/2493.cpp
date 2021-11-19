// 백준 2493번 문제 : 탑
// https://www.acmicpc.net/problem/2493
// 알고리즘 분류 : 자료 구조, 스택

#include <iostream>
#include <stack>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    stack<pair<int, int>> city;
    int n, result = 0, temp;
    pair<int, int> max = make_pair(0, 0),
        prev = make_pair(0, 0);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        if (max.first < temp)
        {
            max = make_pair(temp, i + 1);
            result = 0;
        }
        else if (prev.first >= temp)
            result = prev.second;
        else
        {
            while (!city.empty() && city.top().first < temp)
                city.pop();
            result = city.top().second;
        }
        cout << result << ' ';
        prev = make_pair(temp, i + 1);
        city.push(prev);
    }
    cout << '\n';
}