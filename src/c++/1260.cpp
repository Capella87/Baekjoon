// 백준 1260번 문제 : DFS와 BFS
// https://www.acmicpc.net/problem/1260
// 알고리즘 분류 : 그래프 이론, 그래프 탐색, 너비 우선 탐색, 깊이 우선 탐색

#include <iostream>
#include <queue>
using namespace std;

int arr[1001][1001] = { 0, };
bool is_visited[1001] = { false, };

void add_edge(int src, int dest)
{
    arr[src][dest] = 1;
    arr[dest][src] = 1;
}

void dfs(bool* is_visited, int v, const int n)
{
    is_visited[v] = true;
    cout << v << ' ';
    for (int i = 1; i <= n; i++)
        if (arr[v][i] && !is_visited[i])
            dfs(is_visited, i, n);
}

void bfs(int v, const int n)
{
    queue<int> q;
    bool* is_visit = new bool[n + 1]();

    is_visit[v] = true;
    q.push(v);
    while (!q.empty())
    {
        v = q.front();
        cout << v << ' ';
        q.pop();
        for (int i = 1; i <= n; i++)
        {
            if (arr[v][i] && !is_visit[i])
            {
                is_visit[i] = true;
                q.push(i);
            }
        }
    }
    cout << '\n';
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, m, v;
    int src, dest;

    cin >> n >> m >> v;
    for (int i = 0; i < m; i++)
    {
        cin >> src >> dest;
        add_edge(src, dest);
    }
    dfs(is_visited, v, n);
    cout << '\n';
    bfs(v, n);

    return 0;
}
