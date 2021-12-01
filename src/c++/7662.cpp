// 백준 7662번 문제 : 이중 우선순위 큐
// https://www.acmicpc.net/problem/7662
// 알고리즘 분류 : 자료 구조, 트리를 이용한 집합과 맵, 우선순위 큐

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

void sync_heap(priority_queue<pair<int, int>>& max,
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>& min, bool* valid_table)
{
    while (!max.empty() && !valid_table[max.top().second])
        max.pop();
    while (!min.empty() && !valid_table[min.top().second])
        min.pop();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, q, target;
    char command;

    cin >> n;
    cin.get();
    for (int i = 0; i < n; i++)
    {
        cin >> q;
        cin.get();
        bool* valid_table = new bool[q]();
        priority_queue<pair<int, int>> max; // return the largest; default;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min;
        // C++14(greater); returns the smallest

        for (int j = 0; j < q; j++)
        {
            cin >> command >> target;
            cin.get();

            switch (command)
            {
            case 'I':
                max.push(make_pair(target, j));
                min.push(make_pair(target, j));
                valid_table[j] = true;
                break;

            case 'D':
                sync_heap(max, min, valid_table);
                if (target == -1 && !min.empty())
                {
                    valid_table[min.top().second] = false;
                    min.pop();
                }
                else if (target == 1 && !max.empty())
                {
                    valid_table[max.top().second] = false;
                    max.pop();
                }
                break;
            }
        }
        sync_heap(max, min, valid_table);
        if (max.empty() && min.empty()) cout << "EMPTY\n";
        else cout << max.top().first << ' ' << min.top().first << '\n';

        delete[] valid_table;
    }

    return 0;
}