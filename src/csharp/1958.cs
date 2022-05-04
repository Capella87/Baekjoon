// 백준 1958번 문제 : LCS 3
// https://www.acmicpc.net/problem/1958
// 알고리즘 분류 : 다이나믹 프로그래밍, 문자열

using System;

namespace ThreeDimension
{
    public static class Program
    {
        private static string _a;
        private static string _b;
        private static string _c;
        private static int[,,] _cache;

        public static void Main()
        {
            _a = Console.ReadLine();
            _b = Console.ReadLine();
            _c = Console.ReadLine();

            // It's necessary to use 3D array to solve
            _cache = new int[_a.Length + 1, _b.Length + 1, _c.Length + 1];
            for (int i = 1; i <= _a.Length; i++)
            {
                for (int j = 1; j <= _b.Length; j++)
                {
                    for (int k = 1; k <= _c.Length; k++)
                    {
                        if (_a[i - 1] == _b[j - 1] && _a[i - 1] == _c[k - 1])
                            _cache[i, j, k] = _cache[i - 1, j - 1, k - 1] + 1;
                        else // Compare other elements nearby except the upper case in the _cache array.
                        {
                            _cache[i, j, k] = Math.Max(_cache[i - 1, j - 1, k], _cache[i - 1, j, k]);
                            _cache[i, j, k] = Math.Max(_cache[i, j, k], _cache[i, j - 1, k]);
                            _cache[i, j, k] = Math.Max(_cache[i, j, k], _cache[i, j, k - 1]);
                            _cache[i, j, k] = Math.Max(_cache[i, j, k], _cache[i - 1, j, k - 1]);
                            _cache[i, j, k] = Math.Max(_cache[i, j, k], _cache[i, j - 1, k - 1]);
                        }
                    }
                }
            }
            Console.WriteLine(_cache[_a.Length, _b.Length, _c.Length]);
        }
    }
}