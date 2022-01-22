// 백준 1012번 문제 : 유기농 배추
// https://www.acmicpc.net/problem/1012
// 알고리즘 분류 : 그래프 이론, 그래프 탐색, 너비 우선 탐색, 깊이 우선 탐색

using System;
using System.Collections.Generic;
using System.Text;

namespace Cabbage
{
    public static class Cabbage
    {
        public static readonly int[] xMove = { 0, 1, 0, -1 };
        public static readonly int[] yMove = { -1, 0, 1, 0 };

        public static void Main()
        {
            int t = int.Parse(Console.ReadLine());
            var result = new StringBuilder();

            for (int i = 0; i < t; i++)
            {
                string[] input = Console.ReadLine().Split(' ');
                int m = int.Parse(input[0]);
                int n = int.Parse(input[1]);
                int k = int.Parse(input[2]);
                var info = new List<(int y, int x)>();
                var arr = new int[n, m];
                var isVisited = new bool[n, m];

                for (int j = 0; j < k; j++)
                {
                    string[] coor = Console.ReadLine().Split(' ');
                    int x = int.Parse(coor[0]);
                    int y = int.Parse(coor[1]);
                    info.Add((y, x));
                    arr[y, x] = 1;
                }

                int size = info.Count;
                int count = 0;
                for (int j = 0; j < size; j++)
                {
                    if (arr[info[j].y, info[j].x] == 1 && !isVisited[info[j].y, info[j].x])
                    {
                        dfs(info[j].y, info[j].x, arr, isVisited, m, n);
                        count++;
                    }
                }
                result.AppendLine(count.ToString());
            }
            Console.Write(result.ToString());

            void dfs(int y, int x, int[,] arr, bool[,] isVisited, int m, int n)
            {
                if (y < 0 || y >= n || x < 0 || x >= m) return;
                else if (arr[y, x] == 0 || isVisited[y, x]) return;

                isVisited[y, x] = true;
                for (int i = 0; i < 4; i++)
                    dfs(y + yMove[i], x + xMove[i], arr, isVisited, m, n);
            }
        }
    }
}