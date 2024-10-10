// 백준 11559번 문제 : Puyo Puyo
// https://www.acmicpc.net/problem/11559
// 알고리즘 분류 : 구현, 그래프 이론, 그래프 탐색, 시뮬레이션, 너비 우선 탐색

#include <iostream>
#include <queue>
using namespace std;

const int xMove[4] = { 1, 0, -1, 0 };
const int yMove[4] = { 0, 1, 0, -1 };

void puyo(char board[][6], queue<pair<int, int>>& blocks)
{
    while (!blocks.empty())
    {
        pair<int, int> block = blocks.front();
        blocks.pop();
        board[block.first][block.second] = '.';
    }
}

void apply_gravity(char board[][6])
{
    for (int i = 0; i < 6; i++)
    {
        char remain[12] = { (char)0, };
        int k = 0, l = 0;
        // Retrieve remain blocks without vacant
        for (int j = 11; j >= 0; j--)
        {
            if (board[j][i] != '.')
                remain[k++] = board[j][i];
        }
        if (k == 0) continue;
        // Fill the vacant blocks
        for (int j = 11; j >= 0; j--)
        {
            if (l < k)
                board[j][i] = remain[l++];
            else
                board[j][i] = '.';
        }
    }
}

bool check_blocks(int floor, int x, char board[][6], int isVisited[][6])
{
    char blockType = board[floor][x];
    int clusterSize = 0;
    queue<pair<int, int>> q, b;

    q.push(make_pair(floor, x));
    while (!q.empty())
    {
        pair<int, int> loc = q.front();
        q.pop();

        if (isVisited[loc.first][loc.second]) continue;
        isVisited[loc.first][loc.second] = 1;
        b.push(make_pair(loc.first, loc.second));
        clusterSize++;

        for (int i = 0; i < 4; i++)
        {
            int new_y = loc.first + yMove[i];
            int new_x = loc.second + xMove[i];

            if (new_y < 0 || new_y >= 12 || new_x < 0 || new_x >= 6) continue;
            if (isVisited[new_y][new_x] == 0 && board[new_y][new_x] == blockType)
            {
                q.push(make_pair(new_y, new_x));
            }
        }
    }

    if (clusterSize >= 4)
    {
        puyo(board, b);
        return true;
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    char board[12][6];
    bool hasPuyo = true;
    int floor = 11;
    int max_combo_count = 0;

    for (int i = 0; i < 12; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            cin >> board[i][j];
        }
    }

    // Check the board from the bottom
    while (hasPuyo)
    {
        int isVisited[12][6] = { 0, };
        hasPuyo = false;
        // Find all possible things and remove them;
        for (floor = 11; floor >= 0; floor--)
        {
            for (int j = 0; j < 6; j++)
            {
                if (board[floor][j] == '.') continue;
                if (isVisited[floor][j] == 0)
                    hasPuyo |= check_blocks(floor, j, board, isVisited);
            }
        }
        if (hasPuyo) max_combo_count++;

        // Apply 'gravity'
        apply_gravity(board);
    }
    cout << max_combo_count << '\n';
    return 0;
}
