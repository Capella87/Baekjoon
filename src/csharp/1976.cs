// 백준 1976번 문제 : 여행 가자
// https://www.acmicpc.net/problem/1976
// 알고리즘 분류 : 그래프 이론, 자료 구조, 그래프 탐색, 분리 집합

using System;

namespace Travel
{
    public static class MainApp
    {
        static int[] _disjointSet = new int[201];

        public static int FindSet(int target)
        {
            if (_disjointSet[target] <= -1) return target;
            else return _disjointSet[target] = FindSet(_disjointSet[target]);
        }

        public static void UnionSet(int a, int b)
        {
            int aRoot = FindSet(a);
            int bRoot = FindSet(b);

            if (aRoot == bRoot) return;
            if (_disjointSet[aRoot] < _disjointSet[bRoot]) // aRoot is bigger
                _disjointSet[bRoot] = aRoot;
            else if (_disjointSet[aRoot] == _disjointSet[bRoot])
            {
                _disjointSet[bRoot] = aRoot;
                _disjointSet[aRoot]--;
            }
            else _disjointSet[aRoot] = bRoot;
        }

        public static void Main()
        {
            int n = int.Parse(Console.ReadLine());
            Array.Fill(_disjointSet, -1);
            int m = int.Parse(Console.ReadLine());
            for (int i = 0; i < n; i++)
            {
                string[] input = Console.ReadLine().Split(' ');
                for (int j = 0; j < n; j++)
                    if (input[j] == "1")
                        UnionSet(i + 1, j + 1);
            }

            string[] input2 = Console.ReadLine().Split(' ');
            int root = FindSet(int.Parse(input2[0]));
            for (int i = 1; i < m; i++)
                if (root != FindSet(int.Parse(input2[i])))
                    goto impossible;

            Console.WriteLine("YES");
            return;
            
        impossible:
            Console.WriteLine("NO");
        }
    }
}