// 백준 11724번 문제 : 연결 요소의 개수
// https://www.acmicpc.net/problem/11724
// 알고리즘 분류 : 그래프 이론, 그래프 탐색, 너비 우선 탐색, 깊이 우선 탐색

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<vector<int>> arr;
bool is_visited[1001]{ false, };

void add_edge(int from, int to)
{
    arr[from].push_back(to);
    arr[to].push_back(from);
}

void bfs(int start)
{
    queue<int> q;
    
    is_visited[start] = true;
    q.push(start);
    while (!q.empty())
    {
        start = q.front();
        q.pop();
        int size = (int)arr[start].size();
        for (int i = 0; i < size; i++)
        {
            if (!is_visited[arr[start][i]])
            {
                is_visited[arr[start][i]] = true;
                q.push(arr[start][i]);
            }
        }
    }
}

int get_component(const int n)
{
    int count = 0;

    for (int i = 1; i <= n; i++)
    {
        if (!is_visited[i])
        {
            if (!arr[i].empty()) bfs(i);
            count++;
        }
    }

    return count;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, m, from, to;

    cin >> n >> m;
    arr.resize(n + 1);
    for (int i = 0; i < m; i++)
    {
        cin >> from >> to;
        add_edge(from, to);
    }
    cout << get_component(n) << '\n';

    return 0;
}