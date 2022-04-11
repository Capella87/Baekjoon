// 백준 11047번 문제 : 동전 0
// https://www.acmicpc.net/problem/11047
// 알고리즘 분류 : 그리디 알고리즘

using System;

namespace Coin
{
    public static class MainApp
    {
        public static void Main()
        {
            string[] input = Console.ReadLine().Split(' ');
            int n = int.Parse(input[0]);
            int k = int.Parse(input[1]);
            
            int[] unit = new int[n];
            for (int i = 0; i < n; i++)
                unit[i] = int.Parse(Console.ReadLine());
            
            int count = 0;
            for (int i = 1; i <= n; i++)
            {
                int q = k / unit[^i];
                count += q;
                k %= unit[^i];
            }

            Console.WriteLine(count);
        }
    }
}