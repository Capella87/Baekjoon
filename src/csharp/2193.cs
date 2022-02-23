// 백준 2193번 문제 : 이친수
// https://www.acmicpc.net/problem/2193
// 알고리즘 분류 : 다이나믹 프로그래밍

// Bottom-up solution

using System;

namespace Pinary
{
    public static class MainApp
    {
        public static void Main()
        {
            long n = int.Parse(Console.ReadLine());
            var cache = new long[3] { 1, 1, 2 };

            if (n <= 3)
                Console.WriteLine(cache[n - 1]);
            else
            {
                for (int i = 4; i <= n; i++)
                {
                    cache[0] = cache[1];
                    cache[1] = cache[2];
                    cache[2] = cache[0] + cache[1];
                }
                Console.WriteLine(cache[2]);
            }
        }
    }
}