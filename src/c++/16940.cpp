// 백준 16940번 문제 : BFS 스페셜 저지
// https://www.acmicpc.net/problem/16940
// 알고리즘 분류 : 그래프 이론, 그래프 탐색, 너비 우선 탐색

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> visit_order;
vector<int> order; // For sorting elements in vector

int bfs(vector<vector<int>>& arr)
{
    vector<bool> is_visited(arr.size());
    int order_idx = 1;

    int v = 1;
    is_visited[v] = true;
    queue<int> q;
    q.push(v);
    while (!q.empty())
    {
        v = q.front();
        q.pop();
        
        int size = (int)arr[v].size();
        for (int i = 0; i < size; i++)
        {
            if (!is_visited[arr[v][i]])
            {
                is_visited[arr[v][i]] = true;
                if (visit_order[order_idx] == arr[v][i])
                {
                    order_idx++;
                    q.push(arr[v][i]);
                }
                else goto wrong; // Exit the function if order is wrong
            }
        }
    }
    
    return 1;
wrong:
    return 0;
}

bool comparer(const int a, const int b) // Function for custom comparer
{
    return order[a] < order[b];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, src, dest;

    cin >> n;
    vector<vector<int>> arr(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        cin >> src >> dest;
        arr[src].push_back(dest);
        arr[dest].push_back(src);
    }
    
    order.resize(n + 1);
    for (int i = 0; i < n; i++)
    {
        cin >> src;
        visit_order.push_back(src);
        order[src] = i + 1;
    }
    for (int i = 1; i <= n; i++)
        sort(arr[i].begin(), arr[i].end(), comparer);
    
    if (visit_order.size() > 0 && visit_order[0] != 1) cout << "0" << '\n';
    else cout << bfs(arr) << '\n';

    return 0;
}