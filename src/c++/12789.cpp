// 백준 12789번 문제 : 도키도키 간식드리미
// https://www.acmicpc.net/problem/12789
// 알고리즘 분류 : 자료 구조, 스택

#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, temp, pCount = 0;
    bool isNice = true;
    stack<int> waiting;
    queue<int> q;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        q.push(temp);
    }
    while (pCount < n)
    {
        if (!waiting.empty() && pCount + 1 == waiting.top())
        {
            waiting.pop();
            pCount++;
        }
        else if (!q.empty() && pCount + 1 < q.front())
        {
            waiting.push(q.front());
            q.pop();
        }
        else if (!q.empty() && pCount + 1 == q.front())
        {
            q.pop();
            pCount++;
        }
        else
        {
            isNice = false;
            break;
        }
    }
    cout << (isNice ? "Nice" : "Sad") << '\n';
    return 0;
}