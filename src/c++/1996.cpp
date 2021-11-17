// 백준 1996번 문제 : 지뢰 찾기
// https://www.acmicpc.net/problem/1996
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
    int n;

    cin >> n;
    cin.get();
    char** mineInfo = new char* [n + 2];
    for (int i = 0; i < n + 2; i++)
    {
        mineInfo[i] = new char[n + 2];
        memset(mineInfo[i], '.', sizeof(char));
        if (!i || i == n + 1) continue;
        for (int j = 1; j <= n; j++)
            cin >> mineInfo[i][j];
        cin.get();
    }
    char** mineField = new char* [n];
    for (int i = 0; i < n; i++)
    {
        mineField[i] = new char[n + 1];
        for (int j = 0; j < n; j++)
        {
            int mineTot = 0;
            if (mineInfo[i + 1][j + 1] >= '1' && mineInfo[i + 1][j + 1] <= '9')
            {
                mineField[i][j] = '*';
                continue;
            }
            for (int k = 0; k < 9; k++)
            {
                if (k == 4) k++;
                int y = i + 1 + yMove[k];
                int x = j + 1 + xMove[k];
                if (mineInfo[y][x] >= '1' && mineInfo[y][x] <= '9')
                    mineTot += int(mineInfo[y][x] - '0');
            }
            mineField[i][j] = (mineTot >= 10) ? 'M' : char(mineTot + '0');
        }
        mineField[i][n] = '\0';
    }
    for (int i = 0; i < n; i++)
    {
        cout << mineField[i] << '\n';
        delete[] mineField[i];
        delete[] mineInfo[i];
    }
    delete[] mineInfo[n];
    delete[] mineInfo[n + 1];
    delete[] mineInfo;
    delete[] mineField;
    return 0;
}