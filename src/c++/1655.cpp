// 백준 1655번 문제 : 가운데를 말해요
// https://www.acmicpc.net/problem/1655
// 알고리즘 분류 : 자료 구조, 우선순위 큐

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    priority_queue<int> small; // Stores smaller number; Max heap
    priority_queue<int, vector<int>, greater<int>> big; // Min Heap
    int n, temp;

    cin >> n >> temp;
    small.push(temp);
    cout << small.top() << '\n';

    for (int i = 0; i < n - 1; i++)
    {
        cin >> temp;
        if (small.top() <= temp) big.push(temp);
        else small.push(temp);

        if ((small.size() + big.size()) % 2 == 0)
        {
            if (small.size() > big.size())
            {
                big.push(small.top());
                small.pop();
            }
            else if (small.size() < big.size())
            {
                small.push(big.top());
                big.pop();
            }
            cout << small.top() << '\n';
        }
        else if (small.size() > big.size())
            cout << small.top() << '\n';
        else cout << big.top() << '\n';
    }
    return 0;
}