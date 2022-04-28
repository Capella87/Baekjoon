// 백준 13244번 문제 : Tree
// https://www.acmicpc.net/problem/13244
// 알고리즘 분류 : 그래프 이론, 자료 구조, 그래프 탐색, 트리, 분리 집합

#include <iostream>
using namespace std;

int nodes[1001]{ 0, };

int find_set(int target)
{
    if (!nodes[target]) // root;
        return target;
    else return nodes[target] = find_set(nodes[target]);
}

bool union_set(int src, int target)
{
    int root_src = find_set(src);
    int root_target = find_set(target);

    if (root_src == root_target) // It's cycle.
        return false;
    if (root_src == src) nodes[src] = root_target;
    else nodes[target] = root_src;
    
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t, n, m, src, dest;
    bool has_root = false;

    cin >> t;
    while (t > 0)
    {
        cin >> n;
        fill(nodes, nodes + n + 1, 0);
        bool is_tree = true;
        cin >> m;
        for (int i = 0; i < m; i++)
        {
            cin >> src >> dest;
            is_tree = union_set(src, dest);
        }
        cout << ((!is_tree || m != n - 1) ? "graph" : "tree") << '\n';
        t--;
    }

    return 0;
}