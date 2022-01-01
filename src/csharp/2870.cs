// 백준 2870번 문제 : 수학숙제
// https://www.acmicpc.net/problem/2870
// 알고리즘 분류 : 문자열, 정렬

using System;
using System.Collections.Generic;
using System.Text;

namespace Homework
{
    public class Comparer : IComparer<string>
    {
        public int Compare(string a, string b)
        {
            if (a.Length == b.Length) return string.Compare(a, b);
            else if (a.Length < b.Length) return -1;
            else return 1;
        }
    }

    public static class Program
    {
        public static void Main()
        {
            List<string> numList = new();
            
            int n = int.Parse(Console.ReadLine());
            for (int i = 0; i < n; i++)
            {
                string input = Console.ReadLine();
                StringBuilder num = new StringBuilder();

                for (int j = 0; j < input.Length; j++)
                {
                    bool firstZero = false;
                    while (j < input.Length && input[j] >= '0' && input[j] <= '9')
                    {
                        if (!firstZero && input[j] == '0' && num.Length == 0)
                        {
                            firstZero = true;
                            num.Append(input[j]);
                        }
                        else if (firstZero && input[j] == '0')
                        {
                            j++;
                            continue;
                        }
                        else if (firstZero && input[j] != '0')
                        {
                            firstZero = false;
                            num.Remove(0, 1);
                            num.Append(input[j]);
                        }
                        else if (!firstZero) num.Append(input[j]);
                        j++;
                    }
                    if (num.Length == 0) continue;
                    numList.Add(num.ToString());
                    num.Clear();
                }
            }

            numList.Sort(new Comparer());
            foreach (string num in numList)
                Console.WriteLine(num);
        }
    }
}