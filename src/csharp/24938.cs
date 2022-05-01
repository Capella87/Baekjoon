// 백준 24938번 문제 : 키트 분배하기
// https://www.acmicpc.net/problem/24938
// 알고리즘 분류 : 그리디 알고리즘

using System;

namespace Kit
{
    public static class Program
    {
        public static long[] arr;
        
        public static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            long t = 0;
            arr = Array.ConvertAll<string, long>(Console.ReadLine().Split(' '), long.Parse);
            for (int i = 0; i < n; i++)
                t += arr[i];
            t /= n;

            long result = 0;
            for (int i = 0; i < n - 1; i++)
            {
                long diff = arr[i] - t;
                arr[i] -= diff;
                arr[i + 1] += diff;
                result += Math.Abs(diff);
            }

            Console.WriteLine(result);
        }
    }
}