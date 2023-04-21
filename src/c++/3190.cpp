// 백준 2504번 문제 : 뱀
// https://www.acmicpc.net/problem/3190
// 알고리즘 분류 : 구현, 자료 구조, 시뮬레이션, 덱, 큐

#include <iostream>
#include <deque>
#include <queue>
using namespace std;

const int y_move[4] = { 0, 1, 0, -1 };
const int x_move[4] = { 1, 0, -1, 0 };

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, k;

    cin >> n >> k;
    cin.get();
    int** board = new int* [n];
    for (int i = 0; i < n; i++) board[i] = new int[n]();
    for (int i = 0; i < k; i++)
    {
        int y, x;
        cin >> y >> x;
        board[y - 1][x - 1] = 2; // Apple
    }

    queue<pair<int, char>> shift;
    deque<pair<int, int>> snake; // snake body
    int l, temp;
    char t;
    
    cin >> l;
    cin.get();
    for (int i = 0; i < l; i++)
    {
        cin >> temp >> t;
        shift.push({ temp, t });
    }

    // Simulation
    int time_count = 0;
    int mode = 0;
    int x = 0, y = 0;
    snake.push_front({ 0, 0 });
    board[0][0] = 1;
    while (1)
    {
        y += y_move[mode];
        x += x_move[mode];
        time_count++;

        if (y >= n || x >= n || x < 0 || y < 0) // out of range
            break;
        else if (board[y][x] == 1) // collision
            break;
        else if (board[y][x] == 2)// Discovered Apple
            board[y][x] = 1;
        else if (!board[y][x]) // Normal case
        {
            board[y][x] = 1;
            // 맨 뒤 데크에서 꺼내야 한다.
            int tail_y = snake.back().first;
            int tail_x = snake.back().second;
            snake.pop_back();
            board[tail_y][tail_x] = 0;
        }

        snake.push_front({ y, x });
       
        // shift mode
        if (!shift.empty() && time_count == shift.front().first)
        {
            switch (shift.front().second)
            {
            case 'D':
                mode = (mode + 1) % 4;
                break;
            case 'L':
                mode = (mode - 1) == -1 ? 3 : mode - 1;
                break;
            }
            shift.pop();
        }
    }

    cout << time_count << '\n';

    for (int i = 0; i < n; i++) delete[] board[i];
    delete[] board;
    return 0;
}