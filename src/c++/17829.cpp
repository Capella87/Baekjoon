// 백준 17829번 문제 : 222-풀링
// https://www.acmicpc.net/problem/17829
// 알고리즘 분류 : 구현, 분할 정복

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

inline int max(const int a, const int b)
{
    return a > b ? a : b;
}

int pooling(int** board, int n, int y, int x)
{
    // Get the second largest number in the array.
    if (n == 2)
    {
        vector<int> v;
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                v.push_back(board[y + i][x + j]);
        sort(v.begin(), v.end());
        return v[2];
    }

    // Divide
    int n_size = n / 2;
    int** n_board = new int* [n_size];
    for (int i = 0; i < n_size; i++)
    {
        n_board[i] = new int[n_size];
        for (int j = 0; j < n_size; j++)
            n_board[i][j] = pooling(board, 2, i * 2, j * 2);
    }

    int ret = pooling(n_board, n_size, 0, 0);
    for (int i = 0; i < n_size; i++)
        delete[] n_board[i];
    delete[] n_board;
    return ret;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n;

    cin >> n;
    int** board = new int* [n];
    for (int i = 0; i < n; i++)
    {
        board[i] = new int[n];
        for (int j = 0; j < n; j++)
            cin >> board[i][j];
    }
    cout << pooling(board, n, 0, 0) << '\n';

    for (int i = 0; i < n; i++)
        delete[] board[i];
    delete[] board;
    return 0;
}