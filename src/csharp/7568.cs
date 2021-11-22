// 백준 7568번 문제 : 덩치
// https://www.acmicpc.net/problem/7568
// 알고리즘 분류 : 구현, 브루트포스 알고리즘

using System;
using System.Collections.Generic;

namespace Scale
{
    public class Scale
    {
        public static void Main()
        {
            var people = new List<(int Weight, int Height)>(); // Use ValueTuple in C#
            var rank = new List<int>();

            int n = int.Parse(Console.ReadLine());
            for (int i = 0; i < n; i++)
            {
                string[] temp = Console.ReadLine().Split(' ');
                people.Add((Convert.ToInt32(temp[0]), Convert.ToInt32(temp[1])));
                rank.Add(1);
            }
            
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    if (people[i].Weight < people[j].Weight && people[i].Height < people[j].Height) 
                        rank[i]++; // Can cover the same score case

            foreach (int i in rank)
                Console.Write($"{i} ");
            Console.WriteLine();
        }
    }
}