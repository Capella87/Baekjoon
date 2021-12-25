// 백준 9934번 문제 : 완전 이진 트리
// https://www.acmicpc.net/problem/9934
// 알고리즘 분류 : 구현, 트리, 재귀

#include <iostream>
#include <cmath>
#include <queue>
using namespace std;

void get_inorder(int* tree, int count, int idx) // Inorder traversal
{
    if (idx * 2 + 1 < count - 1)
        get_inorder(tree, count, idx * 2 + 1);
    cin >> tree[idx];
    if (idx * 2 + 2 < count - 1)
        get_inorder(tree, count, idx * 2 + 2);
}

void print_tree(int* tree, const int count) // Level order traversal
{
    queue<pair<int, int>> q, buff;
    
    q.push(make_pair(tree[0], 0));
    while (!q.empty())
    {
        int temp = q.front().first;
        int idx = q.front().second;
        printf("%d ", temp);
        q.pop();

        if (q.empty())
            putchar('\n');

        if (idx * 2 + 1 < count - 1)
            buff.push(make_pair(tree[idx * 2 + 1], idx * 2 + 1));
        if (idx * 2 + 2 < count - 1)
            buff.push(make_pair(tree[idx * 2 + 2], idx * 2 + 2));
        
        if (q.empty())
        {
            while (!buff.empty())
            {
                q.push(buff.front());
                buff.pop();
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int k;
    
    cin >> k;
    int count = int(pow(2, k));
    int* tree = new int[count]();
    get_inorder(tree, count, 0);
    print_tree(tree, count);

    delete[] tree;
    return 0;
}