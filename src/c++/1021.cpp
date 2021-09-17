// 백준 1021번 문제 : 회전하는 큐
// https://www.acmicpc.net/problem/1021
// 알고리즘 분류 : 자료 구조, 덱

#include <iostream>
#include <deque>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    deque<int> dq;
    int n, m, count = 0;

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        dq.push_back(i);
    for (int i = 0; i < m; i++)
    {
        int element;
        cin >> element;
        int j = 0, size = int(dq.size());
        while (element != dq[j]) j++;
        while (j + 1 <= size - j && dq.front() != element)
        {
            int temp = dq.front();
            dq.pop_front();
            dq.push_back(temp);
            count++;
        }
        while (j + 1 > size - j && dq.front() != element)
        {
            int temp = dq.back();
            dq.pop_back();
            dq.push_front(temp);
            count++;
        }
        dq.pop_front();
    }
    cout << count << '\n';
    return 0;
}