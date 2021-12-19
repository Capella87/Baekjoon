// 백준 15235번 문제 : Olympiad Pizza
// https://www.acmicpc.net/problem/15235
// 알고리즘 분류 : 구현, 자료 구조, 시뮬레이션, 큐

using System;
using System.Collections.Generic;

namespace Pizza
{
    public class Pizza
    {
        public static void Main()
        {
            int n = Convert.ToInt32(Console.ReadLine());
            int[] result = new int[n];
            Queue<(int slices, int idx)> q = new();

            string[] input = Console.ReadLine().Split(' ', StringSplitOptions.RemoveEmptyEntries);
            for (int i = 0; i < n; i++)
                q.Enqueue((slices: int.Parse(input[i]), idx: i));

            int timestamp = 1;
            while (q.Count > 0)
            {
                var (slices, idx) = q.Dequeue(); // Destructing a tuple into two variables.
                result[idx] = timestamp++;
                if (--slices > 0)
                    q.Enqueue((slices, idx));
            }

            foreach (int i in result)
                Console.Write($"{i} ");
            Console.WriteLine();
        }
    }
}