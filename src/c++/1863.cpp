// 백준 1863번 문제 : 스카이라인 쉬운거
// https://www.acmicpc.net/problem/1863
// 알고리즘 분류 : 자료 구조, 스택

#include <iostream>
#include <stack>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, x, y, count = 0;
    stack<int> buildings;

    cin >> n;
    for (auto i = 0; i <= n; i++)
    {
        cin >> x >> y;
        while (!buildings.empty() && buildings.top() > y)
        {
            buildings.pop();
            count++;
        }
        if (!buildings.empty() && buildings.top() == y) continue;
        buildings.push(y);
    }
    while (!buildings.empty() && buildings.top() > 0)
    {
        buildings.pop();
        count++;
    }
    cout << count << '\n';
    return 0;
}