// 백준 1520번 문제 : 내리막 길
// https://www.acmicpc.net/problem/1520
// 알고리즘 분류 : 다이나믹 프로그래밍, 그래프 이론, 그래프 탐색, 깊이 우선 탐색

#include <iostream>
using namespace std;

int arr[500][500];
int cache[500][500];
int m, n;

const int y_move[4]{ -1, 0, 1, 0 };
const int x_move[4]{ 0, 1, 0, -1 };

int dfs(int y, int x)
{
    if (cache[y][x] == -1) cache[y][x] = 0;
    else return cache[y][x];

    if (y == m - 1 && x == n - 1) return cache[y][x] = 1; // It's success to reach the destination. Add 1 and return.
    
    for (int i = 0; i < 4; i++)
    {
        int n_y = y + y_move[i];
        int n_x = x + x_move[i];
        if (n_y < 0 || n_y >= m || n_x < 0 || n_x >= n) continue; // Ignore out of range.
        
        if (arr[n_y][n_x] < arr[y][x]) cache[y][x] += dfs(n_y, n_x); // Add possible cases from recursive functions.
    }

    return cache[y][x]; // returns the number of possible routes.
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> m >> n;
    for (int i = 0; i < m; i++)
    {
        fill(cache[i], cache[i] + n, -1);
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];
    }
    cout << dfs(0, 0) << '\n';
    
    return 0;
}