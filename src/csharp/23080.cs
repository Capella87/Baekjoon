// 백준 23080번 문제 : 스키테일 암호
// https://www.acmicpc.net/problem/23080
// 알고리즘 분류 : 구현, 문자열

using System;

namespace scytale
{
    class Scytale
    {
        static void Main()
        {
            int k = Convert.ToInt32(Console.ReadLine());
            string encrypted = Console.ReadLine();
            int i = 0;
            while (i < encrypted.Length)
            {
                if (i % k == 0)
                    Console.Write(encrypted[i]);
                i++;
            }
            Console.WriteLine();
        }
    }
}