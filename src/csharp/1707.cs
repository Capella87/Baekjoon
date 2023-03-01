// 백준 1707번 문제 : 이분 그래프
// https://www.acmicpc.net/problem/1707
// 알고리즘 분류 : 그래프 이론, 그래프 탐색, 너비 우선 탐색, 깊이 우선 탐색, 이분 그래프

using System;
using System.Collections.Generic;

namespace BipartiteGraph
{
    public static class BipartiteGraph
    {
        public enum VisitMark
        {
            None,
            RED,
            BLACK
        };

        public static void Main(string[] args)
        {
            int k = int.Parse(Console.ReadLine());
            for (int i = 0; i < k; i++)
            {
                int[] ve = Array.ConvertAll<string, int>(Console.ReadLine().Split(' '), int.Parse);

                var graph = new List<int>[ve[0] + 1];
                for (int j = 0; j <= ve[0]; j++)
                    graph[j] = new List<int>();

                for (int j = 0; j < ve[1]; j++)
                {
                    var info = Array.ConvertAll<string, int>(Console.ReadLine().Split(' '), int.Parse);
                    graph[info[0]].Add(info[1]);
                    graph[info[1]].Add(info[0]);
                }
                var isVisited = new VisitMark[ve[0] + 1];

                Console.WriteLine(BfsHelper(isVisited, graph, 1));
            }

            string BfsHelper(VisitMark[] isVisited, List<int>[] graph, int startNum)
            {
                var queue = new Queue<int>();

                isVisited[startNum] = VisitMark.BLACK;
                queue.Enqueue(startNum);

                bool isBipar = IsBipartite(queue, isVisited, graph);
                if (!isBipar) return "NO";

                int verticeCount = isVisited.Length - 1;
                for (int i = 1; i <= verticeCount; i++)
                {
                    if (isVisited[i] == VisitMark.None)
                    {
                        isVisited[i] = VisitMark.BLACK;
                        queue.Clear();
                        queue.Enqueue(i);
                        isBipar &= IsBipartite(queue, isVisited, graph);

                        if (!isBipar) return "NO";
                    }
                }

                return "YES";
            }

            bool IsBipartite(Queue<int> queue, VisitMark[] isVisited, List<int>[] graph)
            {
                while (queue.Count > 0)
                {
                    int vertex = queue.Dequeue();
                    VisitMark status = isVisited[vertex];

                    foreach (var v in graph[vertex])
                    {
                        if (isVisited[v] == VisitMark.None)
                        {
                            isVisited[v] = status switch
                            {
                                VisitMark.RED => VisitMark.BLACK,
                                VisitMark.BLACK => VisitMark.RED,
                                _ => throw new NotImplementedException()
                            };
                            queue.Enqueue(v);
                        }
                        else if (isVisited[v] == status)
                            return false;
                    }
                }

                return true;
            }
        }
    }
}