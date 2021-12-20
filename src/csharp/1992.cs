// 백준 1992번 문제 : 쿼드트리
// https://www.acmicpc.net/problem/1992
// 알고리즘 분류 : 분할 정복, 재귀

using System;
using System.Text;

namespace Quad
{
    static class Quad
    {
        private static char[,] _quadTree;
        private static StringBuilder _result;

        private static void Compression(int size, int y, int x)
        {
            if (size == 1)
            {
                _result.Append(_quadTree[y, x]);
                return;
            }

            char pattern = _quadTree[y, x];
            for (int i = y; i < y + size; i++)
                for (int j = x; j < x + size; j++)
                    if (pattern != _quadTree[i, j])
                        goto diff;
            _result.Append(pattern);
            return;

        diff:
            _result.Append('(');
            int newSize = size / 2;
            Compression(newSize, y, x);
            Compression(newSize, y, x + newSize);
            Compression(newSize, y + newSize, x);
            Compression(newSize, y + newSize, x + newSize);
            _result.Append(')');
        }

        public static void Main()
        {
            int n = int.Parse(Console.ReadLine());
            _quadTree = new char[n, n];
            _result = new StringBuilder();

            for (int i = 0; i < n; i++)
            {
                string input = Console.ReadLine();
                for (int j = 0; j < n; j++)
                    _quadTree[i, j] = input[j];
            }

            Compression(n, 0, 0);
            Console.WriteLine(_result.ToString());
        }
    }
}