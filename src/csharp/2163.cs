// 백준 2163번 문제 : 초콜릿 자르기
// https://www.acmicpc.net/problem/2163
// 알고리즘 분류 : 수학, 사칙연산

using System;

namespace choco
{
    class Choco
    {
        static void Main()
        {
            string[] input = Console.ReadLine().Split();
            int a = Convert.ToInt32(input[0]);
            int b = Convert.ToInt32(input[1]);

            Console.WriteLine(a * b - 1);
        }
    }
}