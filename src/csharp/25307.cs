// 백준 25307번 문제 : 시루의 백화점 구경
// https://www.acmicpc.net/problem/25307
// 알고리즘 분류 : 그래프 이론, 그래프 탐색, 너비 우선 탐색

using System;
using System.Collections.Generic;

namespace Siru
{
    public static class Program
    {
        static int[] _input;
        static int[][] _map;
        static int[,] _isVisited;
        static bool _hasBench = false;
        static (int, int) _start;
        static Queue<(int, int, int)> _mannequin = new Queue<(int, int, int)>();
        static readonly int[] _posY = { -1, 0, 1, 0 };
        static readonly int[] _posX = { 0, 1, 0, -1 };

        public static void Main()
        {
            _input = Array.ConvertAll<string, int>(Console.ReadLine().Split(' '), int.Parse);
            _isVisited = new int[_input[0], _input[1]];
            _map = new int[_input[0]][];
            for (int i = 0; i < _input[0]; i++)
            {
                _map[i] = Array.ConvertAll<string, int>(Console.ReadLine().Split(' '), int.Parse);
                for (int j = 0; j < _input[1]; j++)
                {
                    if (_map[i][j] == 3)
                    {
                        _isVisited[i, j] = -1;
                        _mannequin.Enqueue((i, j, _input[2]));
                    }
                    else if (_map[i][j] == 4)
                        _start = (i, j);
                    else if (_map[i][j] == 2 && !_hasBench)
                        _hasBench = true;
                }
            }

            SetExclusionZone();
            Console.WriteLine(!_hasBench ? -1 : FindBench());
        }

        public static void SetExclusionZone()
        {
            while (_mannequin.Count > 0)
            {
                var (y, x, dist) = _mannequin.Dequeue();

                if (--dist < 0) continue;
                for (int i = 0; i < 4; i++)
                {
                    int tempY = y + _posY[i];
                    int tempX = x + _posX[i];

                    if (tempX < 0 || tempY < 0 || tempX >= _input[1] || tempY >= _input[0])
                        continue;
                    if (_isVisited[tempY, tempX] == 0)
                    {
                        _mannequin.Enqueue((tempY, tempX, dist));
                        _isVisited[tempY, tempX] = -1;
                    }
                }
            }
        }

        public static int FindBench()
        {
            var q = new Queue<(int, int)>();
            _isVisited[_start.Item1, _start.Item2] = 0;
            q.Enqueue((_start.Item1, _start.Item2));
            while (q.Count > 0)
            {
                var (y, x) = q.Dequeue();

                if (_map[y][x] == 2) return _isVisited[y, x];

                int move = _isVisited[y, x] + 1;
                for (int i = 0; i < 4; i++)
                {
                    int tempY = y + _posY[i];
                    int tempX = x + _posX[i];

                    if (tempX < 0 || tempY < 0 || tempX >= _input[1] || tempY >= _input[0])
                        continue;
                    if (_map[tempY][tempX] == 0 || _map[tempY][tempX] == 2)
                    {
                        if (_isVisited[tempY, tempX] == 0)
                        {
                            _isVisited[tempY, tempX] = move;
                            q.Enqueue((tempY, tempX));
                        }
                    }
                }
            }
            return -1;
        }
    }
}