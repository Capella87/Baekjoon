// 백준 2667번 문제 : 단지번호붙이기
// https://www.acmicpc.net/problem/2667
// 알고리즘 분류 : 그래프 이론, 그래프 탐색, 너비 우선 탐색, 깊이 우선 탐색

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

char arr[25][25] = { 0 };
bool is_visited[25][25] = { false };

const int y_move[4] = {-1, 0, 1, 0 };
const int x_move[4] = { 0, 1, 0, -1 };

int dfs(int i, int j, const int n)
{
    if (i < 0 || i >= n || j < 0 || j >= n)
        return 0;
    else if (is_visited[i][j] || arr[i][j] == '0')
        return 0;
   
    is_visited[i][j] = true;
    int count = 1;
    for (int k = 0; k < 4; k++)
        count += dfs(i + y_move[k], j + x_move[k], n);

    return count;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n;
    vector<int> result;

    cin >> n;
    cin.get();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] == '1' && !is_visited[i][j])
            {
                int count = dfs(i, j, n);
                if (count) result.push_back(count);
            }
        }
    }
    sort(result.begin(), result.end());
    int size = int(result.size());
    cout << size << '\n';
    for (int i = 0; i < size; i++)
        cout << result[i] << '\n';

    return 0;
}