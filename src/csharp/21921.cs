// 백준 21921번 문제 : 블로그
// https://www.acmicpc.net/problem/21921
// 알고리즘 분류 : 누적 합, 슬라이딩 윈도우

using System;

namespace Blog
{
    public static class MainApp
    {
        public static void Main()
        {
            string[] input = Console.ReadLine().Split(' ');
            int n = int.Parse(input[0]);
            int x = int.Parse(input[1]);
            int[] arr = new int[n];
            int max = 0, total = 0;
            
            input = Console.ReadLine().Split(' ');
            for (int i = 0; i < x; i++)
            {
                arr[i] = int.Parse(input[i]);
                total += arr[i];
            }
            int max_duration = 1;
            max = total;
            for (int i = x; i < n; i++)
            {
                arr[i] = int.Parse(input[i]);
                total += arr[i] - arr[i - x];
                if (max == total) max_duration++;
                else if (max < total)
                {
                    max = total;
                    max_duration = 1;
                }
            }
            if (max == 0) Console.WriteLine("SAD");
            else Console.WriteLine($"{max}\n{max_duration}");
        }
    }
}