// 백준 2206번 문제 : 벽 부수고 이동하기
// https://www.acmicpc.net/problem/2206
// 알고리즘 분류 : 그래프 이론, 그래프 탐색, 너비 우선 탐색

using System;
using System.Collections.Generic;

namespace BreakingWall
{
    public static class MainApp
    {
        private static int _n;
        private static int _m;
        private static string[] _map;
        private static int[,,] _isVisited; // 뚫은 경우와 그렇지 않은 경우의 방문을 따로 체크한다.

        public readonly static int[] yMove = { -1, 0, 1, 0 };
        public readonly static int[] xMove = { 0, 1, 0, -1 };

        public static void Main()
        {
            string[] input = Console.ReadLine().Split(' ');
            _n = int.Parse(input[0]);
            _m = int.Parse(input[1]);

            _map = new string[_n];
            _isVisited = new int[_n, _m, 2];

            // 읽는 부분
            for (int i = 0; i < _n; i++)
                _map[i] = Console.ReadLine();
            Console.WriteLine(bfs());

            int bfs()
            {
                var q = new Queue<(int, int, int)>();
                int y = 0, x = 0, move = 1, mode = 0;
                _isVisited[y, x, mode] = move;
                q.Enqueue((y, x, mode));

                while (q.Count > 0)
                {
                    (y, x, mode) = q.Dequeue();
                    move = _isVisited[y, x, mode];

                    // Exit on arrival
                    if (y == _n - 1 && x == _m - 1) return move;

                    for (int i = 0; i < 4; i++)
                    {
                        int n_y = y + yMove[i];
                        int n_x = x + xMove[i];

                        // Escape prevention
                        if (n_y < 0 || n_y >= _n || n_x < 0 || n_x >= _m) continue;
                        
                        // If the next position is empty and not visited, visit it
                        if (_map[n_y][n_x] == '0' && _isVisited[n_y, n_x, mode] == 0)
                        {
                            _isVisited[n_y, n_x, mode] = move + 1;
                            q.Enqueue((n_y, n_x, mode));
                        }
                        // If the next position is a wall and not visited, visit it
                        else if (_map[n_y][n_x] == '1' && mode == 0 && _isVisited[n_y, n_x, mode] == 0)
                        {
                            _isVisited[n_y, n_x, mode + 1] = move + 1;
                            q.Enqueue((n_y, n_x, mode + 1));
                        }
                    }
                }

                return -1;
            }
        }
    }
}
