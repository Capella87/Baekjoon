// 백준 1743번 문제 : 음식물 피하기
// https://www.acmicpc.net/problem/1743
// 알고리즘 분류 : 그래프 이론, 그래프 탐색, 너비 우선 탐색, 깊이 우선 탐색

using System;
using System.Collections.Generic;

namespace Trash
{
    public static class MainApp
    {
        static int[,] _arr;
        static bool[,] _isVisited;
        static int _n;
        static int _m;

        static readonly int[] yMove = { -1, 0, 1, 0 };
        static readonly int[] xMove = { 0, 1, 0, -1 };

        public static int BFS(int y, int x)
        {
            var q = new Queue<(int, int)>();
            int size = 1;
            q.Enqueue((y, x));
            _isVisited[y, x] = true;
            while (q.Count > 0)
            {
                (y, x) = q.Peek();
                q.Dequeue();
                for (int i = 0; i < 4; i++)
                {
                    int newY = y + yMove[i];
                    int newX = x + xMove[i];
                    if (newY >= 0 && newY < _n && newX >= 0 && newX < _m)
                    {
                        if (!_isVisited[newY, newX] && _arr[newY, newX] == 1)
                        {
                            q.Enqueue((newY, newX));
                            _isVisited[newY, newX] = true;
                            size++;
                        }

                    }
                }
            }

            return size;
        }

        public static int BFSHelper()
        {
            int max = 0;
            int temp = 0;

            for (int i = 0; i < _n; i++)
            {
                for (int j = 0; j < _m; j++)
                {
                    if (!_isVisited[i, j] && _arr[i, j] == 1)
                    {
                        temp = BFS(i, j);
                        if (temp > max) max = temp;
                    }
                }
            }

            return max;
        }

        public static void Main()
        {
            string[] input = Console.ReadLine().Split(' ');
            _n = int.Parse(input[0]);
            _m = int.Parse(input[1]);
            int k = int.Parse(input[2]);

            _arr = new int[_n, _m];
            _isVisited = new bool[_n, _m];
            for (int i = 0; i < k; i++)
            {
                input = Console.ReadLine().Split(' ');
                _arr[int.Parse(input[0]) - 1, int.Parse(input[1]) - 1] = 1;
            }
            Console.WriteLine(BFSHelper());
        }
    }
}