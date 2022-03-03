// 백준 11399번 문제 : ATM
// https://www.acmicpc.net/problem/11399
// 알고리즘 분류 : 그리디 알고리즘, 정렬

using System;
using System.Collections.Generic;

namespace ATM
{
    public static class MainApp
    {
        public static void Main()
        {
            int n = int.Parse(Console.ReadLine());
            string[] input = Console.ReadLine().Split(' ');

            var arr = new List<(int, int)>();
            for (int i = 0; i < n; i++)
                arr.Add((int.Parse(input[i]), i));
            arr.Sort();

            int total = 0;
            int prev = 0;
            for (int i = 0; i < n; i++)
            {
                prev += arr[i].Item1;
                total += prev;
            }

            Console.WriteLine(total);
        }
    }
}