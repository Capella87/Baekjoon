// 백준 1068번 문제 : 트리
// https://www.acmicpc.net/problem/1068
// 알고리즘 분류 : 그래프 이론, 그래프 탐색, 트리, 깊이 우선 탐색

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> arr;
int cut_leaf = 0;

void add_edge(int parent, int target)
{
    arr[parent].push_back(target);
}

int dfs(int root, int cut_target, int parent) // Explore all nodes in the tree
{
    int size = (int)arr[root].size();
    if (size == 0)
    {
        if (root == cut_target) cut_leaf = 1;
        if (root == cut_target && parent != -1 && arr[parent].size() == 1) --cut_leaf;
        return 1;
    }

    int leaf_count = 0;
    for (int i = 0; i < size; i++)
        leaf_count += dfs(arr[root][i], cut_target, root);
    if (root == cut_target) cut_leaf = leaf_count;
    if (root == cut_target && parent != -1 && arr[parent].size() == 1) --cut_leaf;

    return leaf_count;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, temp;
    int root = -1;

    cin >> n;
    arr.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        if (temp == -1) root = i;
        else add_edge(temp, i);
    }
    cin >> temp;
    cout << dfs(root, temp, -1) - cut_leaf << '\n';

    return 0;
}