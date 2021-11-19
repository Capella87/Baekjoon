// 백준 11286번 문제 : 절댓값 힙
// https://www.acmicpc.net/problem/11286
// 알고리즘 분류 : 자료 구조, 우선순위 큐

#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <functional>
using namespace std;

bool enqueue(priority_queue<int, vector<int>, greater<int>>& pos, priority_queue<int>& neg, const int target)
{
    if (!target) return false;
    else if (target > 0) pos.push(target);
    else neg.push(target);
    return true;
}

int dequeue(priority_queue<int, vector<int>, greater<int>>& pos, priority_queue<int>& neg)
{
    int rt = 0;
    if (!pos.empty() && !neg.empty())
    {
        int posAbs = abs(pos.top());
        int negAbs = abs(neg.top());
        if (posAbs >= negAbs)
        {
            rt = neg.top();
            neg.pop();
        }
        else
        {
            rt = pos.top();
            pos.pop();
        }
    }
    else if (pos.empty() && !neg.empty())
    {
        rt = neg.top();
        neg.pop();
    }
    else if (!pos.empty() && neg.empty())
    {
        rt = pos.top();
        pos.pop();
    }
    return rt;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    priority_queue<int, vector<int>, greater<int>> positive;
    priority_queue<int> negative;
    int n, x;

    cin >> n;
    for (auto i = 0; i < n; i++)
    {
        cin >> x;
        if (!x) printf("%d\n", dequeue(positive, negative));
        else enqueue(positive, negative, x);
    }
    return 0;
}