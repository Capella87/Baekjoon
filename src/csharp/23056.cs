// 백준 23056번 문제 : 참가자 명단
// https://www.acmicpc.net/problem/23056
// 알고리즘 분류 : 문자열, 정렬

using System;
using System.Collections.Generic;

namespace Participant
{
    class Comparer : IComparer<(int, string)>
    {
        public int Compare((int, string) t1, (int , string) t2)
        {
            if (t1.Item1 < t2.Item1) return -1;
            else if (t1.Item1 > t2.Item1) return 1;
            else
            {
                if (t1.Item2.Length < t2.Item2.Length) return -1;
                else if (t1.Item2.Length > t2.Item2.Length) return 1;
                else
                {
                    if (String.Compare(t1.Item2, t2.Item2) < 0) return -1;
                    else return 1;
                }
            }
        }
    }

    class Participant
    {
        public static void Main()
        {
            string[] input = Console.ReadLine().Split(' ');
            int n = Convert.ToInt32(input[0]);
            int m = Convert.ToInt32(input[1]);

            var odd = new List<(int c, string name)>();
            var even = new List<(int c, string name)>();
            int[] quota = new int[n];
            while (true)
            {
                string[] temp = Console.ReadLine().Split(' ');
                if (temp[0] == "0" && temp[0] == temp[1]) break;

                int cl = Convert.ToInt32(temp[0]);
                if (cl % 2 == 0 && quota[cl - 1] < m)
                {
                    even.Add((cl, temp[1]));
                    quota[cl - 1]++;
                }
                else if (cl % 2 == 1 && quota[cl - 1] < m)
                {
                    odd.Add((cl, temp[1]));
                    quota[cl - 1]++;
                }
            }
            var comp = new Comparer();
            odd.Sort(comp);
            even.Sort(comp);

            for (int i = 0; i < odd.Count; i++)
                Console.WriteLine($"{odd[i].c} {odd[i].name}");
            for (int i = 0; i < even.Count; i++)
                Console.WriteLine($"{even[i].c} {even[i].name}");
        }
    }
}