// 백준 4803번 문제 : 트리
// https://www.acmicpc.net/problem/4803
// 알고리즘 분류 : 그래프 이론, 자료 구조, 그래프 탐색, 트리, 깊이 우선 탐색, 분리 집합

#include <iostream>
#include <vector>
using namespace std;

bool dfs(vector<vector<int>>& arr, vector<bool>& is_visited, int prev, int src)
{
    is_visited[src] = true;
    bool rt = true;
    int size = (int)arr[src].size();
    for (int i = 0; i < size; i++)
    {
        if (!is_visited[arr[src][i]])
            rt &= dfs(arr, is_visited, src, arr[src][i]);
        else if (arr[src][i] != prev)
            rt &= false;
    }

    return rt;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, m, src, dest, count = 0;

    while (1)
    {
        cin >> n >> m;
        if (n == m && !n) break;

        vector<vector<int>> arr(n + 1);
        vector<bool> is_visited(n + 1);
        int tree_count = 0;

        for (int i = 0; i < m; i++)
        {
            cin >> src >> dest;
            arr[src].push_back(dest);
            arr[dest].push_back(src);
        }
        for (int i = 1; i <= n; i++)
        {
            if (!is_visited[i])
            {
                if (!arr[i].size())
                {
                    is_visited[i] = true;
                    tree_count++;
                }
                else tree_count += !dfs(arr, is_visited, -1, i) ? 0 : 1;
            }
        }
        cout << "Case " << ++count << ": ";
        if (!tree_count) cout << "No trees.\n";
        else if (tree_count == 1) cout << "There is one tree.\n";
        else cout << "A forest of " << tree_count << " trees.\n";
    }

    return 0;
}