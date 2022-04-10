// 백준 11652번 문제 : 카드
// https://www.acmicpc.net/problem/11652
// 알고리즘 분류 : 자료 구조, 정렬, 트리를 이용한 집합과 맵

using System;
using System.Collections.Generic;

namespace Card
{
    public static class Card
    {
        public static void Main()
        {
            int n = int.Parse(Console.ReadLine());
            var l = new List<long>();
            
            for (int i = 0; i < n; i++)
            {
                long temp = long.Parse(Console.ReadLine());
                l.Add(temp);
            }
            l.Sort();

            long maxCount = 0, count = 0;
            long max = l[0], pick = l[0];
            for (int i = 0; i < n; i++)
            {
                if (pick != l[i])
                {
                    if (maxCount < count)
                    {
                        maxCount = count;
                        max = pick;
                    }
                    pick = l[i];
                    count = 1;
                }
                else count++;
            }
            if (maxCount < count) max = pick; // 마지막에 가장 많은 수가 나온 경우 고려

            Console.WriteLine(max);
        }
    }
}