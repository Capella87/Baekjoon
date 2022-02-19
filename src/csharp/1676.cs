// 백준 1676번 문제 : 팩토리얼 0의 개수
// https://www.acmicpc.net/problem/1676
// 알고리즘 분류 : 수학, 임의 정밀도 / 큰 수 연산

using System;

namespace Factorial
{
    public static class Program
    {
        public static void Main()
        {
            int n = int.Parse(Console.ReadLine());
            int twoCount = 0, fiveCount = 0;

            for (int i = 2; i <= n; i *= 2) // The number of 2 in the factorial
                twoCount += n / i;
            for (int i = 5; i <= n; i *= 5)
                fiveCount += n / i;

            Console.WriteLine(twoCount > fiveCount ? fiveCount : twoCount);
        }
    }
}