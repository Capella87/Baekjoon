// 백준 16964번 문제 : DFS 스페셜 저지
// https://www.acmicpc.net/problem/16964
// 알고리즘 분류 : 그래프 이론, 자료 구조, 그래프 탐색, 깊이 우선 탐색

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> tree;
bool is_visited[100001]{ false };
int user_visit[100001]{ 0, };
int user_visit_order[100001]{ 0, };
int idx = 1;

void dfs(int v)
{
    if (is_visited[v]) return;
    
    is_visited[v] = true;
    if (user_visit[idx++] != v)
    {
        cout << 0 << '\n';
        exit(0);
    }
    
    int size = (int)tree[v].size();
    for (int i = 0; i < size; i++)
        if (!is_visited[tree[v][i]])
            dfs(tree[v][i]);
}

bool comparator(int a, int b)
{
    return user_visit_order[a] < user_visit_order[b];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, from, to;

    cin >> n;
    tree.resize(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        cin >> from >> to;
        tree[from].push_back(to);
        tree[to].push_back(from);
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> user_visit[i];
        user_visit_order[user_visit[i]] = i;
    }
    for (int i = 1; i <= n; i++)
        sort(tree[i].begin(), tree[i].end(), comparator);
    dfs(1);
    cout << 1 << '\n';

    return 0;
}