// 백준 1167번 문제 : 트리의 지름
// https://www.acmicpc.net/problem/1167
// 알고리즘 분류 : 그래프 이론, 그래프 탐색, 트리, 깊이 우선 탐색

using System;

namespace Tree
{
    public static class Program
    {
        private static int _v;
        private static List<(int, int)>[]? _trees;
        private static int _maxNode = 0;
        private static int _maxDist = 0;

        public static void Main()
        {
            _v = int.Parse(Console.ReadLine());
            _trees = new List<(int, int)>[_v + 1];
            for (int i = 1; i <= _v; i++) _trees[i] = new List<(int, int)>();

            int src, dest, dist;
            for (int i = 0; i < _v; i++)
            {
                string[] input = Console.ReadLine().Split(' ');
                src = int.Parse(input[0]);
                int j = 1;
                while (input[j] != "-1")
                {
                    dest = int.Parse(input[j]);
                    dist = int.Parse(input[++j]);

                    _trees[src].Add((dest, dist));
                    j++;
                }
            }

            bool[] isVisited = new bool[_v + 1];
            dfs(1, 0, isVisited); // Find the farthest node from the root node.
            isVisited = new bool[_v + 1];
            _maxDist = 0;
            dfs(_maxNode, 0, isVisited); // Find the farthest node from the node which is found at the first DFS.

            Console.WriteLine(_maxDist);
            
            void dfs(int src, int dist, bool[] isVisited)
            {
                isVisited[src] = true;
                
                if (_maxDist < dist)
                {
                    _maxDist = dist;
                    _maxNode = src;
                }

                for (int i = 0; i < _trees[src].Count; i++)
                    if (!isVisited[_trees[src][i].Item1])
                        dfs(_trees[src][i].Item1, dist + _trees[src][i].Item2, isVisited);
            }
        }
    }
}