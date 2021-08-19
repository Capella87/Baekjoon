// 백준 9291번 문제 : 스도쿠 채점
// https://www.acmicpc.net/problem/9291
// 알고리즘 분류 : 구현

#include <iostream>
using namespace std;
#define SIZE 9

int main()
{
    int n;
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    int sudoku[SIZE][SIZE];
    for (int c = 0; c < n; c++)
    {
        bool isCorrect = true;
        for (int i = 0; i < SIZE; i++)
        {
            bool* chkDupCol = new bool[SIZE]();
            for (int j = 0; j < SIZE; j++)
            {
                cin >> sudoku[i][j];
                if (chkDupCol[sudoku[i][j] - 1]) isCorrect = false;
                else chkDupCol[sudoku[i][j] - 1] = true;
            }
            delete[] chkDupCol;
        }
        if (isCorrect)
        {
            bool chkDupBlock[SIZE][SIZE]{ false, };
            for (int i = 0; i < SIZE; i++)
            {
                auto chkDupRow = new bool[SIZE]();
                for (int j = 0; j < SIZE; j++)
                {
                    if (chkDupRow[sudoku[j][i] - 1] || chkDupBlock[j / 3 + (i / 3) * 3][sudoku[j][i] - 1])
                    {
                        isCorrect = false;
                        break;
                    }
                    else
                    {
                        chkDupRow[sudoku[j][i] - 1] = true;
                        chkDupBlock[j / 3 + (i / 3) * 3][sudoku[j][i] - 1] = true;
                    }
                }
                delete[] chkDupRow;
                if (!isCorrect) break;
            }
        }
        cout << "Case " << c + 1 << ": ";
        cout << (isCorrect ? "CORRECT" : "INCORRECT") << '\n';
    }
    return 0;
}