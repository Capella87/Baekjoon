// 백준 13241번 문제 : 최소공배수
// https://www.acmicpc.net/problem/13241
// 알고리즘 분류 : 수학, 정수론, 유클리드 호제법

using System;

namespace lcm
{
    class LCM
    {
        public static long getGCD(long a, long b)
        {
            return a % b == 0 ? b : getGCD(b, a % b);
        }

        static void Main()
        {
            string[] tokens = Console.ReadLine().Split();
            long a = long.Parse(tokens[0]);
            long b = long.Parse(tokens[1]);

            Console.WriteLine(a * b / getGCD(a, b));
        }
    }
}