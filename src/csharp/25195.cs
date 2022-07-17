// 백준 25195번 문제 : Yes or Yes
// https://www.acmicpc.net/problem/25195
// 알고리즘 분류 : 그래프 이론, 그래프 탐색, 너비 우선 탐색, 깊이 우선 탐색

using System;
using System.Collections.Generic;

namespace YesOrYes
{
    public static class Program
    {
        public static int[] _info;
        public static List<int>[] _nodes;
        public static bool[] _isFan;
        public static bool[] _isVisited;
        public static void Main()
        {
            _info = Array.ConvertAll<string, int>(Console.ReadLine().Split(' '), int.Parse);
            _nodes = new List<int>[_info[0] + 1];
            for (int i = 1; i <= _info[0]; i++)
                _nodes[i] = new List<int>();
            _isFan = new bool[_info[0] + 1];
            for (int i = 0; i < _info[1]; i++)
            {
                var node = Array.ConvertAll<string, int>(Console.ReadLine().Split(' '), int.Parse);
                _nodes[node[0]].Add(node[1]);
            }
            int s = int.Parse(Console.ReadLine());
            var goms = Array.ConvertAll<string, int>(Console.ReadLine().Split(' '), int.Parse);
            foreach (var a in goms)
                _isFan[a] = true;

            bool mustGom = false;
            _isVisited = new bool[_info[0] + 1];

            if (_isFan[1])
            {
                Console.WriteLine("Yes");
                return;
            }
            var q = new Queue<int>();
            q.Enqueue(1);
            while (q.Count > 0)
            {
                var cur = q.Dequeue();
                _isVisited[cur] = true;
                if (_nodes[cur].Count == 0)
                {
                    mustGom = false;
                    break;
                }

                foreach (var d in _nodes[cur])
                {
                    if (!_isFan[d] && !_isVisited[d])
                        q.Enqueue(d);
                    else if (_isFan[d] && !_isVisited[d])
                        mustGom = true;
                }
            }

            Console.WriteLine(!mustGom ? "yes" : "Yes");
        }
    }
}