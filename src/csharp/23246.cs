// 백준 23246번 문제 : Sport Climbing Combined
// https://www.acmicpc.net/problem/23246
// 알고리즘 분류 : 정렬

using System;
using System.Collections.Generic;

namespace Sports
{
    public class Comp : IComparer<(int, int, int)>
    {
        public int Compare((int, int, int) a, (int, int, int) b)
        {
            if (a.Item2 > b.Item2) return 1;
            else if (a.Item2 < b.Item2) return -1;
            else
            {
                if (a.Item3 < b.Item3) return -1;
                else if (a.Item3 > b.Item3) return 1;
                else
                {
                    if (a.Item1 < b.Item1) return -1;
                    else return 1;
                }
            }
        }
    }

    public class Sports
    {
        public static void Main()
        {
            int n = Convert.ToInt32(Console.ReadLine());
            var entry = new List<(int back, int mult, int total)>();
            for (int i = 0; i < n; i++)
            {
                string[] input = Console.ReadLine().Split(' ');
                int b = Convert.ToInt32(input[0]);
                int l = Convert.ToInt32(input[1]);
                int s = Convert.ToInt32(input[2]);
                int bdr = Convert.ToInt32(input[3]);
                entry.Add((b, l * s * bdr, l + s + bdr));
            }
            entry.Sort(new Comp());
            for (int i = 0; i < 3; i++)
                Console.Write($"{entry[i].back} ");
            Console.WriteLine();
        }
    }
}