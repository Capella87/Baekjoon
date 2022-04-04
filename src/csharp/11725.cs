// 백준 11725번 문제 : 트리의 부모 찾기
// https://www.acmicpc.net/problem/11725
// 알고리즘 분류 : 그래프 이론, 그래프 탐색, 트리, 너비 우선 탐색, 깊이 우선 탐색

using System;
using System.Collections.Generic;
using System.Text;

namespace Tree
{
    public static class MainApp
    {
        private static List<int>[] arr = new List<int>[100001];
        public static void Main()
        {
            int[] parentArr = new int[100001];

            int n = int.Parse(Console.ReadLine());
            for (int i = 1; i < 100001; i++) arr[i] = new List<int>();
            for (int i = 0; i < n - 1; i++)
            {
                string[] input = Console.ReadLine().Split(' ');
                int src = int.Parse(input[0]);
                int dest = int.Parse(input[1]);

                arr[src].Add(dest);
                arr[dest].Add(src);
            }

            dfs(parentArr, 1);
            var result = new StringBuilder();
            for (int i = 2; i < 100001; i++)
                if (parentArr[i] > 0)
                    result.AppendLine(Convert.ToString(parentArr[i]));
            Console.Write(result.ToString());

            void dfs(int[] parentArr, int v)
            {
                int size = arr[v].Count;
                for (int i = 0; i < size; i++)
                {
                    if (arr[v][i] == parentArr[v]) continue;
                    parentArr[arr[v][i]] = v;
                    dfs(parentArr, arr[v][i]);
                }
            }
        }
    }
}