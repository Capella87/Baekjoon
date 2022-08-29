// 백준 16194번 문제 : 카드 구매하기 2
// https://www.acmicpc.net/problem/16194
// 알고리즘 분류 : 다이나믹 프로그래밍

using System;

namespace Cards2
{
    public static class MainApp
    {
        public static int[] price;
        public static int[] cache;

        public static int GetMin(int n)
        {
            if (n <= 0) return 0;
            if (cache[n] != -1) return cache[n];

            cache[n] = price[1] + GetMin(n - 1);
            for (int i = 2; i <= n; i++)
                cache[n] = Math.Min(cache[n], price[i] + GetMin(n - i));

            return cache[n];
        }

        public static void Main()
        {
            int n = int.Parse(Console.ReadLine());
            price = new int[n + 1];
            cache = new int[n + 1];
            Array.Fill(cache, -1);

            string[] input = Console.ReadLine().Split(' ');
            for (int i = 1; i <= n; i++)
                price[i] = int.Parse(input[i - 1]);
            Console.WriteLine(GetMin(n));
        }
    }
}