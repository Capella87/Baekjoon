// 백준 4883번 문제 : 삼각 그래프
// https://www.acmicpc.net/problem/4883
// 알고리즘 분류 : 다이나믹 프로그래밍

// Bottom-up Solution

using System;
using System.Text;

namespace Trigraph
{
    public static class MainApp
    {
        public static void Main()
        {
            var result = new StringBuilder();
            int count = 1;

            while (true)
            {
                int n = int.Parse(Console.ReadLine());
                if (n == 0) break;
                var graph = new int[n, 3];
                var cache = new int[n, 3];
                for (int i = 0; i < n; i++)
                {
                    string[] input = Console.ReadLine().Split(' ');
                    for (int j = 0; j < 3; j++)
                    {
                        graph[i, j] = int.Parse(input[j]);
                        cache[i, j] = -1;
                    }
                }

                cache[0, 1] = graph[0, 1];
                cache[0, 2] = graph[0, 2] + graph[0, 1];
                cache[1, 0] = graph[1, 0] + graph[0, 1];
                cache[1, 1] = Math.Min(cache[0, 1], cache[1, 0]);
                cache[1, 1] = Math.Min(cache[1, 1], cache[0, 2]) + graph[1, 1];
                cache[1, 2] = Math.Min(cache[1, 1], cache[0, 1]);
                cache[1, 2] = Math.Min(cache[1, 2], cache[0, 2]) + graph[1, 2];
                for (int i = 2; i < n; i++)
                {
                    cache[i, 0] = Math.Min(cache[i - 1, 0], cache[i - 1, 1]) + graph[i, 0];
                    cache[i, 1] = Math.Min(cache[i, 0], cache[i - 1, 0]);
                    cache[i, 1] = Math.Min(cache[i, 1], cache[i - 1, 1]);
                    cache[i, 1] = Math.Min(cache[i, 1], cache[i - 1, 2]) + graph[i, 1];
                    cache[i, 2] = Math.Min(cache[i, 1], cache[i - 1, 1]);
                    cache[i, 2] = Math.Min(cache[i, 2], cache[i - 1, 2]) + graph[i, 2];
                }
                result.AppendLine($"{count++}. {cache[n - 1, 1]}");
            }
            Console.Write(result.ToString());
        }
    }
}