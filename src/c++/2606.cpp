// 백준 2606번 문제 : 바이러스
// https://www.acmicpc.net/problem/2606
// 알고리즘 분류 : 그래프 이론, 그래프 탐색, 너비 우선 탐색, 깊이 우선 탐색

#include <iostream>
#include <queue>
using namespace std;

bool arr[101][101]{ false, };
bool is_visited[101]{ false, };

void add_edge(int src, int dest)
{
    arr[src][dest] = true;
    arr[dest][src] = true;
}

int bfs(int v, const int n)
{
    queue<int> q;
    int infected = 0;

    is_visited[v] = true;
    q.push(v);
    while (!q.empty())
    {
        v = q.front();
        q.pop();
        for (int i = 1; i <= n; i++)
        {
            if (arr[v][i] && !is_visited[i])
            {
                is_visited[i] = true;
                infected++;
                q.push(i);
            }
        }
    }

    return infected;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, e, src, dest;

    cin >> n >> e;
    for (int i = 0; i < e; i++)
    {
        cin >> src >> dest;
        add_edge(src, dest);
    }
    cout << bfs(1, n) << '\n';

    return 0;
}