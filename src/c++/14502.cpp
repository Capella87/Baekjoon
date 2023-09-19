// 백준 14502번 문제 : 연구소
// https://www.acmicpc.net/problem/14502
// 알고리즘 분류 : 구현, 그래프 이론, 브루트포스 알고리즘, 그래프 탐색, 너비 우선 탐색

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int board[8][8];
int temp[8][8];
int n, m, safe = 0;
vector<pair<int, int>> virus;

const int yMove[4]{ -1, 0, 1, 0 };
const int xMove[4]{ 0, 1, 0, -1 };

int simulate()
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            temp[i][j] = board[i][j];

    queue<pair<int, int>> q;
    for (auto v : virus)
        q.push(v);
    
    while (!q.empty())
    {
        auto t = q.front();
        q.pop();
        
        for (int i = 0; i < 4; i++)
        {
            int pos_y = t.first + yMove[i];
            int pos_x = t.second + xMove[i];

            if (pos_y < 0 || pos_x < 0 || pos_y >= n || pos_x >= m)
                continue;
            if (!temp[pos_y][pos_x])
            {
                temp[pos_y][pos_x] = 2;
                q.push({ pos_y, pos_x });
            }
        }
    }

    int safe_count = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (!temp[i][j])
                safe_count++;

    return safe_count;
}

void build_wall(int count)
{
    if (count == 3)
    {
        int c = simulate();
        if (safe < c) safe = c;

        return;
    }
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!board[i][j])
            {
                board[i][j] = 1;
                build_wall(count + 1);
                board[i][j] = 0;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> board[i][j];
            if (board[i][j] == 2)
                virus.push_back({ i, j });
        }
    }
    build_wall(0);
    cout << safe << '\n';

    return 0;
}