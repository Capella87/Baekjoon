// 백준 11052번 문제 : 카드 구매하기
// https://www.acmicpc.net/problem/11052
// 알고리즘 분류 : 다이나믹 프로그래밍

using System;

namespace Cards
{
    public static class MainApp
    {
        public static int[] price;
        public static int[] cache;

        public static int GetMax(int n)
        {
            if (n <= 0) return 0;
            if (cache[n] != -1) return cache[n];

            for (int i = 1; i <= n; i++)
                cache[n] = Math.Max(cache[n], price[i] + GetMax(n - i));

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
            Console.WriteLine(GetMax(n));
        }
    }
}