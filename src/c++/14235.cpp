// 백준 14235번 문제 : 크리스마스 선물
// https://www.acmicpc.net/problem/14235
// 알고리즘 분류 : 자료 구조, 우선순위 큐

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    priority_queue<int> pq; // Max Heap
    int n;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        if (!a && !pq.size())
        {
            cout << "-1" << '\n';
            continue;
        }
        else if (!a)
        {
            cout << pq.top() << '\n';
            pq.pop();
            continue;
        }
        for (int j = 0; j < a; j++)
        {
            int temp;
            cin >> temp;
            pq.push(temp);
        }
    }
    return 0;
}