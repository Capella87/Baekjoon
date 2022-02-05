// 백준 7576번 문제 : 토마토
// https://www.acmicpc.net/problem/7576
// 알고리즘 분류 : 그래프 이론, 그래프 탐색, 너비 우선 탐색

#include <iostream>
#include <queue>
using namespace std;

int arr[1000][1000]{ 0, };
queue<pair<int, int>> q;
bool is_visited[1000][1000]{ false, };
int m, n;

const int y_move[4] = { 0, 1, 0, -1};
const int x_move[4] = { 1, 0, -1, 0 };

int explore()
{
    int day = 0;
    int next_rippen = 0;
    int rippen = (int)q.size();

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
                if (!is_visited[n_y][n_x] && arr[n_y][n_x] == 0)
                {
                    is_visited[n_y][n_x] = true;
                    arr[n_y][n_x] = 1;
                    q.push({ n_y, n_x });
                    next_rippen++;
                }
            }
        }

        rippen--;
        if (!rippen)
        {
            day++;
            rippen = next_rippen;
            next_rippen = 0;
        }
    }

    return day - 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    bool is_not_all = false;

    cin >> m >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] == 1)
            {
                q.push({ i, j });
                is_visited[i][j] = true;
            }
        }
    }
    int result = explore();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!is_visited[i][j] && !arr[i][j])
            {
                is_not_all = true;
                break;
            }
        }
    }
    if (!is_not_all) cout << result << '\n';
    else cout << -1 << '\n';

    return 0;
}