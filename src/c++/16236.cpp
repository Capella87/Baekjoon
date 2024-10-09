// 백준 16236번 문제 : 아기 상어
// https://www.acmicpc.net/problem/16236
// 알고리즘 분류 : 구현, 그래프 이론, 그래프 탐색, 시뮬레이션, 너비 우선 탐색

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <queue>
using namespace std;

int n, y, x, shark_size = 2;
int y_move[4] = { -1, 0, 1, 0 };
int x_move[4] = { 0, 1, 0, -1 };

int forage_bfs(vector<vector<int>>& ocean, int* time, int exp)
{
    int nearest_y = n, nearest_x = n, nearest_dist = INT_MAX;
    vector<vector<int>> visitmap(n, vector<int>(n));
    queue<tuple<int, int, int>> q;
    q.push(make_tuple(y, x, 0));

    while (!q.empty())
    {
        tuple<int, int, int> cur = q.front();
        q.pop();
        int cur_y = get<0>(cur), cur_x = get<1>(cur), cur_time = get<2>(cur);
        if (visitmap[cur_y][cur_x] > 0 && cur_time >= visitmap[cur_y][cur_x]) continue;
        visitmap[cur_y][cur_x] = cur_time;

        if (ocean[cur_y][cur_x] > 0 && ocean[cur_y][cur_x] < shark_size)
        {
            if (cur_time < nearest_dist)
            {
                nearest_y = cur_y;
                nearest_x = cur_x;
                nearest_dist = cur_time;
                continue;
            }
            else if (cur_time == nearest_dist)
            {
                if (cur_y < nearest_y)
                {
                    nearest_y = cur_y;
                    nearest_x = cur_x;
                }
                else if (cur_y == nearest_y && cur_x < nearest_x) nearest_x = cur_x;
                continue;
            }
        }

        for (int i = 0; i < 4; i++)
        {
            int new_y = cur_y + y_move[i];
            int new_x = cur_x + x_move[i];

            if (new_y < 0 || new_y >= n || new_x < 0 || new_x >= n || shark_size < ocean[new_y][new_x] || ((visitmap[new_y][new_x] > 0) && (cur_time >= visitmap[new_y][new_x]))) continue;
            q.push(make_tuple(new_y, new_x, cur_time + 1));
        }
    }
    if (nearest_x < n && nearest_y < n)
    {
        ocean[nearest_y][nearest_x] = 0;
        y = nearest_y;
        x = nearest_x;
        *time += nearest_dist;
        return ++exp;
    }
    return 0;
}

int solve(vector<vector<int>>& ocean)
{
    int status = 0, time = 0;

    while ((status = forage_bfs(ocean, &time, status)) > 0)
    {
        if (status == shark_size)
        {
            ++shark_size;
            status = 0;
        }
    }
    return time;
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    vector<vector<int>> ocean(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> ocean[i][j];
            if (ocean[i][j] == 9)
            {
                y = i;
                x = j;
                ocean[i][j] = 0;
            }
        }
    }
    cout << solve(ocean) << '\n';
    return 0;
}
