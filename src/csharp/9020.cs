// 백준 9020번 문제 : 골드바흐의 추측
// https://www.acmicpc.net/problem/9020
// 알고리즘 분류 : 수학, 정수론, 소수 판정, 에라토스테네스의 체

using System;

namespace Goldbach
{
    public static class Program
    {
        public static void Main()
        {
            bool[] isNotPrime = new bool[10001];
            isNotPrime[0] = isNotPrime[1] = true;

            for (int i = 2; i <= 100; i++)
            {
                if (isNotPrime[i]) continue;
                for (int j = i * i; j <= 10000; j += i)
                    isNotPrime[j] = true;
            }

            int t = int.Parse(Console.ReadLine());
            for (int i = 0; i < t; i++)
            {
                int n = int.Parse(Console.ReadLine());
                int div = n / 2;
                int saved = -1;
                for (int j = 2; j <= div; j++)
                    if (!isNotPrime[j] && !isNotPrime[n - j])
                        saved = j;
                Console.WriteLine($"{saved} {n - saved}");
            }
        }
    }
}