// 백준 4108번 문제 : 지뢰찾기
// https://www.acmicpc.net/problem/4108
// 알고리즘 분류 : 구현

#include <iostream>
#include <cstring>
using namespace std;

const int yMove[9] = { -1, -1, -1, 0, 0, 0, 1, 1, 1 };
const int xMove[9] = { -1, 0, 1, -1, 0, 1, -1, 0, 1 };

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int r, c;

    while (1)
    {
        cin >> r >> c;
        cin.get();
        if (!r && !c) break;
    
        char** mineBoard = new char* [r + 2];
        for (int i = 0; i < r + 2; i++)
        {
            mineBoard[i] = new char[c + 2];
            memset(mineBoard[i], '.', (c + 2) * sizeof(char));
            if (!i || i == r + 1) continue;
            for (int j = 1; j <= c; j++)
                cin >> mineBoard[i][j];
            cin.get();
        }
        for (int i = 1; i <= r; i++) // i < r + 1
        {
            for (int j = 1; j <= c; j++)
            {
                if (mineBoard[i][j] == '*')
                {
                    cout << '*';
                    continue;
                }
                int mineCount = 0;
                for (int k = 0; k < 9; k++)
                    if (mineBoard[i + yMove[k]][j + xMove[k]] == '*')
                        mineCount++;
                cout << mineCount;
            }
            cout << '\n';
        }
        for (int i = 0; i < r + 2; i++)
            delete[] mineBoard[i];
        delete[] mineBoard;
    }
    return 0;
}