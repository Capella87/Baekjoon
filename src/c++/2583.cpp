// 백준 2583번 문제 : 영역 구하기
// https://www.acmicpc.net/problem/2583
// 알고리즘 분류 : 그래프 이론, 그래프 탐색, 너비 우선 탐색, 깊이 우선 탐색

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int arr[101][101] = { 0, };
bool is_visited[101][101] = { false, };
int m, n;

const int y_move[4] = { -1, 0, 1, 0 };
const int x_move[4] = { 0, 1, 0, -1 };

void make_rectangle(int start_y, int start_x, int end_y, int end_x)
{
    for (int i = start_y; i < end_y; i++)
        for (int j = start_x; j < end_x; j++)
            arr[i][j] = 1;
}

int bfs(int y, int x)
{
    queue<pair<int, int>> q;
    int area = 1;

    is_visited[y][x] = true;
    q.push({ y, x });
    while (!q.empty())
    {
        pair<int, int> temp = q.front();
        y = temp.first;
        x = temp.second;
        q.pop();
        
        for (int i = 0; i < 4; i++)
        {
            int pos_y = y + y_move[i];
            int pos_x = x + x_move[i];
            if (pos_y >= 0 && pos_y < m && pos_x >= 0 && pos_x < n)
            {
                if (!arr[pos_y][pos_x] && !is_visited[pos_y][pos_x])
                {
                    is_visited[pos_y][pos_x] = true;
                    q.push({ pos_y, pos_x });
                    area++;
                }
            }
        }
    }

    return area;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int k;
    int start_y, start_x, end_y, end_x;
    vector<int> s;

    cin >> m >> n >> k;
    for (int i = 0; i < k; i++)
    {
        cin >> start_x >> start_y >> end_x >> end_y;
        make_rectangle(start_y, start_x, end_y, end_x);
    }
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (!arr[i][j] && !is_visited[i][j])
                s.push_back(bfs(i, j));
    sort(s.begin(), s.end());
    int size = (int)s.size();
    cout << size << '\n';
    for (int i = 0; i < size; i++)
        cout << s[i] << ' ';
    cout << ' ';

    return 0;
}