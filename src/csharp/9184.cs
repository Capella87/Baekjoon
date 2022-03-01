// 백준 9184번 문제 : 신나는 함수 실행
// https://www.acmicpc.net/problem/9184
// 알고리즘 분류 : 다이나믹 프로그래밍, 재귀

using System;

namespace DynamicProgramming
{
    public class Program
    {
        private static int[,,] _arr = new int[21, 21, 21];

        public static void Main()
        {
            while (true)
            {
                string[] input = Console.ReadLine().Split(' ', StringSplitOptions.RemoveEmptyEntries);
                int a = int.Parse(input[0]);
                int b = int.Parse(input[1]);
                int c = int.Parse(input[2]);

                if (a == -1 && b == -1 && c == -1) break;
                Console.WriteLine($"w({a}, {b}, {c}) = {w(a, b, c)}");
            }

            int w(int a, int b, int c)
            {
                if (a <= 0 || b <= 0 || c <= 0)
                    return 1;
                else if (a > 20 || b > 20 || c > 20)
                    return w(20, 20, 20);

                if (_arr[a, b, c] > 0) return _arr[a, b, c]; // Top-down memoization
                else if (a < b && b < c)
                    _arr[a, b, c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c); // Memoization
                else
                    _arr[a, b, c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);

                return _arr[a, b, c];
            }
        }
    }
}