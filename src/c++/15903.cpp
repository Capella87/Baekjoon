// 백준 15903번 문제 : 카드 합체 놀이
// https://www.acmicpc.net/problem/15903
// 알고리즘 분류 : 자료 구조, 그리디 알고리즘, 우선순위 큐

#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m;
    long long result = 0, temp;
    priority_queue<long long, vector<long long>, greater<long long>> pq;

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        pq.push(temp);
    }

    while (m > 0)
    {
        long long a = pq.top();
        pq.pop();
        long long b = pq.top();
        pq.pop();

        long long t = a + b;
        pq.push(t);
        pq.push(t);

        m--;
    }

    for (int i = 0; i < n; i++)
    {
        result += pq.top();
        pq.pop();
    }
    cout << result << '\n';
    return 0;
}
