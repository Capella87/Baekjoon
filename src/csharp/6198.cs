// 백준 6198번 문제 : 옥상 정원 꾸미기
// https://www.acmicpc.net/problem/6198
// 알고리즘 분류 : 자료 구조, 스택

using System;
using System.Collections.Generic;

namespace Building
{
    public static class Building
    {
        public static void Main()
        {
            Stack<int> city = new();
            int n = int.Parse(Console.ReadLine());
            long result = 0;

            for (int i = 0; i < n; i++)
            {
                int temp = int.Parse(Console.ReadLine());
                if (city.Count == 0 || (city.Count > 0 && city.Peek() > temp))
                {
                    city.Push(temp);
                    continue;
                }

                while (city.Count > 0 && city.Peek() <= temp)
                {
                    result += (long)city.Count - 1;
                    city.Pop();
                }
                city.Push(temp);
            }
            while (city.Count > 0)
            {
                result += (long)city.Count - 1;
                city.Pop();
            }

            Console.WriteLine(result);
        }
    }
}