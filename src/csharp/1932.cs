// 백준 1932번 문제 : 정수 삼각형
// https://www.acmicpc.net/problem/1932
// 알고리즘 분류 : 다이나믹 프로그래밍

using System;

namespace Triangle
{
    public static class Triangle
    {
        public static void Main()
        {
            int n = int.Parse(Console.ReadLine());
            int max = -1;
            int[] stair = new int[n + 1];

            stair[0] = int.Parse(Console.ReadLine());
            for (int i = 1; i < n; i++)
            {
                string[] input = Console.ReadLine().Split(' ', StringSplitOptions.RemoveEmptyEntries);
                for (int j = i; j > 0; j--)
                    stair[j] = Max(stair[j - 1], stair[j]) + int.Parse(input[j]);
                stair[0] += int.Parse(input[0]);
            }
            for (int i = 0; i < n; i++)
                if (max < stair[i]) max = stair[i];
            Console.WriteLine(max);

            int Max(int a, int b)
            {
                return a > b ? a : b;
            }
        }
    }
}