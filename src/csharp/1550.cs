// 백준 1550번 문제 : 16진수
// https://www.acmicpc.net/problem/1550
// 알고리즘 분류 : 수학, 구현

using System;

namespace hex
{
    class Hex
    {
        static void Main()
        {
            string hex = Console.ReadLine();
            Console.WriteLine(Convert.ToInt32(hex, 16));
        }
    }
}