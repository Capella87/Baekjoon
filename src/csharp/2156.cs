// 백준 2156번 문제 : 포도주 시식
// https://www.acmicpc.net/problem/2156
// 알고리즘 분류 : 다이나믹 프로그래밍

// 복습 필요

using System;

namespace Wine
{
    public static class Wine
    {
        public static void Main()
        {
            int n = int.Parse(Console.ReadLine());
            var arr = new int[n];
            var cache = new int[n];
            for (int i = 0; i < n; i++)
                arr[i] = int.Parse(Console.ReadLine());

            cache[0] = arr[0];
            cache[1] = arr[1] + cache[0];
            for (int i = 2; i < n; i++)
            {
                cache[i] = arr[i] + Max(arr[i - 1] + cache[i - 3], cache[i - 2]); // 바로 이전 포도주를 고른 경우나 이이전 포도주를 고른 경우
                cache[i] = Max(cache[i], cache[i - 1]); // 아예 안 고르는 경우 (이전 cache값 재활용 비교)
            }
            Console.WriteLine(cache[n - 1]);
           
            int Max(int a, int b)
            {
                return a > b ? a : b;
            }
        }
    }
}