// 백준 2178번 문제 : 미로 탐색
// https://www.acmicpc.net/problem/2178
// 알고리즘 분류 : 그래프 이론, 그래프 탐색, 너비 우선 탐색

#include <iostream>
#include <queue>
using namespace std;

int m, n;
const int x_move[4]{ 0, 1, 0, -1 };
const int y_move[4]{ -1, 0, 1, 0 };

int maze[100][100] = { 0, };
bool is_visited[100][100] = { false, };

int bfs(int y, int x)
{
    queue<pair<int, int>> q;
    is_visited[y][x] = true;
    q.push({ y, x });

    while (!q.empty())
    {
        pair<int, int> pos = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int n_y = pos.first + y_move[i];
            int n_x = pos.second + x_move[i];
            
            if (n_y >= 0 && n_y < n && n_x >= 0 && n_x < m)
            {
                if (!is_visited[n_y][n_x] && maze[n_y][n_x])
                {
                    maze[n_y][n_x] = maze[pos.first][pos.second] + 1; // Save passed count in the maze array.
                    is_visited[n_y][n_x] = true;
                    q.push({ n_y, n_x });
                }
            }
        }
    }

    return maze[n - 1][m - 1];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    char temp;

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> temp;
            maze[i][j] = (int)temp - '0';
        }
    }
    cout << bfs(0, 0) << '\n';

    return 0;
}