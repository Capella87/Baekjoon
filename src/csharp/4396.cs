// 백준 4396번 문제 : 지뢰 찾기
// https://www.acmicpc.net/problem/4396
// 알고리즘 분류 : 구현, 문자열, 파싱

using System;

namespace MineSweeper
{
    public static class MineSweeper
    {
        public static readonly int[] YMove = new int[] { -1, -1, -1, 0, 0, 0, 1, 1, 1 };
        public static readonly int[] XMove = new int[] { -1, 0, 1, -1, 0, 1, -1, 0, 1 };

        public static void Main()
        {
            int n = Convert.ToInt32(Console.ReadLine());

            char[,] arr = new char[n + 2, n + 2];
            FillValue(ref arr, '.', n + 2, n + 2);
            for (int i = 1; i <= n; i++)
            {
                string temp = Console.ReadLine();
                for (int j = 1; j <= n; j++)
                    arr[i, j] = (char)temp[j - 1];
            }
            char[,] result = new char[n, n];
            bool hasMineX = false;

            for (int i = 0; i < n; i++) // Check mine is exist in 'x'
            {
                string temp = Console.ReadLine();
                for (int j = 0; j < n; j++)
                {
                    result[i, j] = temp[j];
                    if (arr[i + 1, j + 1] == '*' && result[i, j] == 'x')
                        hasMineX = true;
                }
            }
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (arr[i + 1, j + 1] == '*' && (hasMineX || result[i, j] == 'x'))
                    {
                        hasMineX = true;
                        result[i, j] = '*';
                        continue;
                    }
                    else if (result[i, j] != 'x')
                    {
                        result[i, j] = '.';
                        continue;
                    }

                    int mineCount = 0;
                    for (int k = 0; k < 9; k++)
                    {
                        if (k == 4) continue;

                        int y = i + 1 + YMove[k];
                        int x = j + 1 + XMove[k];
                        if (arr[y, x] == '*')
                            mineCount++;
                    }
                    result[i, j] = Convert.ToChar(mineCount + '0');
                }
            }

            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                    Console.Write(result[i, j]);
                Console.WriteLine();
            }

            // For initialization
            void FillValue(ref char[,] target, char c, int row, int col)
            {
                for (int i = 0; i < row; i++)
                    for (int j = 0; j < col; j++)
                        target[i, j] = c;
            }
        }
    }
}