// 백준 1697번 문제 : 숨바꼭질
// https://www.acmicpc.net/problem/1697
// 알고리즘 분류 : 그래프 이론, 그래프 탐색, 너비 우선 탐색

#include <iostream>
#include <queue>
#define MAX 100000
using namespace std;

int n, k;
int arr[MAX + 1]{ 0, };
bool is_visited[MAX + 1]{ false, };
const char movecase[3]{ '*', '+', '-' };

int bfs()
{
    queue<pair<int, int>> q;
    
    is_visited[n] = true;
    q.push({ n, 0 });
    while (!q.empty())
    {
        pair<int, int> pos = q.front();
        q.pop();
        if (pos.first == k) return pos.second;

        int n_pos = pos.first;
        for (int i = 0; i < 3; i++)
        {
            if (movecase[i] == '*') n_pos = pos.first * 2;
            else if (movecase[i] == '+') n_pos = pos.first + 1;
            else n_pos = pos.first - 1;

            if (n_pos == k) return pos.second + 1;
            if (n_pos >= 0 && n_pos <= MAX && !is_visited[n_pos])
            {
                q.push({ n_pos, pos.second + 1 });
                is_visited[n_pos] = true;
            }
        }
    }

    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> k;
    cout << bfs() << '\n';

    return 0;
}