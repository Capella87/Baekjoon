// 백준 7569번 문제 : 토마토
// https://www.acmicpc.net/problem/7569
// 알고리즘 분류 : 그래프 이론, 그래프 탐색, 너비 우선 탐색

// Same problem as question 7576 except dimension.

#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int arr[100][100][100]{0,};
queue<tuple<int, int, int>> q;
bool is_visited[100][100][100]{false,};
int m, n, h;

const int y_move[6] = { 0, 1, 0, -1, 0, 0};
const int x_move[6] = { 1, 0, -1, 0, 0, 0};
const int z_move[6] = { 0, 0, 0, 0, 1, -1 };

int explore()
{
    int day = 0;
    int next_rippen = 0;
    int rippen = (int)q.size();

    while (!q.empty())
    {
        tuple<int, int, int> pos = q.front();
        q.pop();

        for (int i = 0; i < 6; i++)
        {
            int n_z = get<0>(pos) + z_move[i];
            int n_y = get<1>(pos) + y_move[i];
            int n_x = get<2>(pos) + x_move[i];
            if (n_y >= 0 && n_y < n && n_x >= 0 && n_x < m && n_z >= 0 && n_z < h)
            {
                if (!is_visited[n_z][n_y][n_x] && arr[n_z][n_y][n_x] == 0)
                {
                    is_visited[n_z][n_y][n_x] = true;
                    arr[n_z][n_y][n_x] = 1;
                    q.push({ n_z, n_y, n_x });
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

    cin >> m >> n >> h;
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < m; k++)
            {
                cin >> arr[i][j][k];
                if (arr[i][j][k] == 1)
                {
                    q.push({ i, j, k });
                    is_visited[i][j][k] = true;
                }
            }
        }
    }
    int result = explore();
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < m; k++)
            {
                if (!is_visited[i][j][k] && !arr[i][j][k])
                {
                    is_not_all = true;
                    break;
                }
            }
        }
    }

    if (!is_not_all) cout << result << '\n';
    else cout << -1 << '\n';

    return 0;
}