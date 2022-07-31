// 백준 1764번 문제 : 듣보잡
// https://www.acmicpc.net/problem/1764
// 알고리즘 분류 : 자료 구조, 문자열, 정렬, 해시를 이용한 집합과 맵

using System;
using System.Collections.Generic;

namespace PracticeDictionary
{
    public class MainApp
    {
        static public void Main()
        {
            SortedDictionary<string, string> l = new();
            SortedDictionary<string, string> deup = new();

            string[] input = Console.ReadLine().Split(' ', StringSplitOptions.RemoveEmptyEntries);
            string people;
            int n = int.Parse(input[0]);
            int m = int.Parse(input[1]);

            for (int i = 0; i < n; i++)
            {
                people = Console.ReadLine();
                l.Add(people, people);
            }
            for (int i = 0; i < m; i++)
            {
                people = Console.ReadLine();
                if (l.TryGetValue(people, out people))
                    deup.Add(people, people);
            }

            Console.WriteLine(deup.Count);
            foreach(KeyValuePair<string, string> p in deup)
                Console.WriteLine(p.Value);
        }
    }
}