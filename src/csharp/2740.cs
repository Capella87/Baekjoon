// 백준 2740번 문제 : 행렬 곱셈
// https://www.acmicpc.net/problem/2740
// 알고리즘 분류 : 수학, 구현, 선형대수학

using System;

namespace Matrix
{
    static class Matrix
    {
        public static void Main()
        {
            string[] input = Console.ReadLine().Split(' ');
            int n = int.Parse(input[0]);
            int m = int.Parse(input[1]);

            int[,] first = new int[n, m];
            for (int i = 0; i < n; i++)
            {
                string[] t = Console.ReadLine().Split(' ');
                for (int j = 0; j < t.Length; j++)
                    first[i, j] = int.Parse(t[j]);
            }
            input = Console.ReadLine().Split(' ');
            int k = int.Parse(input[1]);
            int[,] second = new int[m, k];
            for (int i = 0; i < m; i++)
            {
                string[] t = Console.ReadLine().Split(' ');
                for (int j = 0; j < t.Length; j++)
                    second[i, j] = int.Parse(t[j]);
            }

            int[,] result = new int[n, k];
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < k; j++)
                {
                    for (int l = 0; l < m; l++)
                        result[i, j] += first[i, l] * second[l, j];
                }
            }

            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < k; j++)
                    Console.Write($"{result[i, j]} ");
                Console.WriteLine();
            }
        }
    }
}