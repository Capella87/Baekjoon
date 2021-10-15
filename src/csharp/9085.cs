// 백준 9085번 문제 : 더하기
// https://www.acmicpc.net/problem/9085
// 알고리즘 분류 : 수학, 구현, 사칙연산

using System;

namespace addition
{
    class Addition
    {
        static void Main()
        {
            int t = Convert.ToInt32(Console.ReadLine());
            for (var i = 0; i < t; i++)
            {
                int n = Convert.ToInt32(Console.ReadLine());
                int[] arr = new int[n];
                string[] input = Console.ReadLine().Split();
                int total = 0;
                for (var j = 0; j < n; j++)
                {
                    arr[j] = Convert.ToInt32(input[j]);
                    total += arr[j];
                }
                Console.WriteLine(total);
            }
        }
    }
}