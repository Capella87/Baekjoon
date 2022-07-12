// 백준 24416번 문제 : 알고리즘 수업 - 피보나치 수 1
// https://www.acmicpc.net/problem/24416
// 알고리즘 분류 : 수학, 다이나믹 프로그래밍

using System;

namespace Fibo
{
    public static class Program
    {
        public static void Main()
        {
            long n = long.Parse(Console.ReadLine());

            Console.WriteLine($"{RecursiveFibo(n)} {DynamicFibo(n)}");

            long RecursiveFibo(long n)
            {
                if (n == 1 || n == 2) return 1;
                else return RecursiveFibo(n - 1) + RecursiveFibo(n - 2);
            }

            long DynamicFibo(long n)
            {
                int count = 0;
                var f = new long[n + 1];
                f[1] = f[2] = 1;
                for (int i = 3; i <= n; i++)
                {
                    f[i] = f[i - 1] + f[i - 2];
                    count++;
                }
                return count;
            }
        }
    }
}