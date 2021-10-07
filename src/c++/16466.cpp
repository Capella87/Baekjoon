// 백준 16466번 문제 : 콘서트
// https://www.acmicpc.net/problem/16466
// 알고리즘 분류 : 자료 구조, 우선순위 큐

#include <iostream>
#include <queue>
#include <vector>
#include <functional>
#include <climits>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    priority_queue<int, vector<int>, greater<int>> sold;
    int n, ans = 1, temp;

    cin >> n;
    for (auto i = 0; i < n; i++)
    {
        cin >> temp;
        sold.push(temp);
    }
    while (ans < INT_MAX && !sold.empty() && sold.top() == ans)
    {
        ans = sold.top() + 1;
        sold.pop();
    }
    cout << ans << '\n';
    return 0;
}