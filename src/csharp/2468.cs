// 백준 2468번 문제 : 안전 영역
// https://www.acmicpc.net/problem/2468
// 알고리즘 분류 : 그래프 이론, 브루트포스 알고리즘, 그래프 탐색, 너비 우선 탐색, 깊이 우선 탐색

using System;
using System.Collections.Generic;

namespace SafeArea
{
    public static class MainApp
    {
        private static int[,] _arr;
        private static int _n;
        private static int max = 0;
        private static int min = 101;
        private static readonly int[] yMove = { -1, 0, 1, 0 };
        private static readonly int[] xMove = { 0, 1, 0, -1 };

        public static void Main()
        {
            _n = int.Parse(Console.ReadLine());
            _arr = new int[_n, _n];

            for (int i = 0; i < _n; i++)
            {
                string[] input = Console.ReadLine().Split(' ');
                for (int j = 0; j < _n; j++)
                {
                    _arr[i, j] = int.Parse(input[j]);
                    if (max < _arr[i, j]) max = _arr[i, j];
                    if (min > _arr[i, j]) min = _arr[i, j];
                }
            }

            int rt = 0;
            for (int i = min - 1; i <= max; i++)
            {
                int count = 0;
                var isVisited = new bool[_n, _n];
                for (int j = 0; j < _n; j++)
                {
                    for (int k = 0; k < _n; k++)
                    {
                        if (!isVisited[j, k] && i < _arr[j, k])
                        {
                            bfs(j, k, isVisited, i);
                            count++;
                        }
                    }
                }
                if (rt < count) rt = count;
            }
            Console.WriteLine(rt);

            void bfs(int y, int x, bool[,] isVisited, int level)
            {
                var q = new Queue<(int, int)>();
                q.Enqueue((y, x));
                isVisited[y, x] = true;
                
                while (q.Count > 0)
                {
                    (y, x) = q.Dequeue();

                    for (int i = 0; i < 4; i++)
                    {
                        int n_y = y + yMove[i];
                        int n_x = x + xMove[i];

                        if (n_y >= 0 && n_y < _n && n_x >= 0 && n_x < _n)
                        {
                            if (!isVisited[n_y, n_x] && _arr[n_y, n_x] > level)
                            {
                                isVisited[n_y, n_x] = true;
                                q.Enqueue((n_y, n_x));
                            }
                        }
                    }
                }
            }
        }
    }
}