// 백준 20492번 문제 : 세금
// https://www.acmicpc.net/problem/20492
// 알고리즘 분류 : 수학, 사칙연산

using System;

namespace bounty
{
    class BountyTax
    {
        static void Main(string[] args)
        {
            int n = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine($"{n * 0.78} {n * 0.956}");
        }
    }
}