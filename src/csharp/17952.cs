// 백준 17952번 문제 : 과제는 끝나지 않아!
// https://www.acmicpc.net/problem/17952
// 알고리즘 분류 : 구현, 자료 구조, 스택

using System;
using System.Collections.Generic;

namespace homework
{
    class Homework
    {
        static void Main()
        {
            int n = Convert.ToInt32(Console.ReadLine());
            int score = 0;
            Stack<int> assignments = new Stack<int>();
            Stack<int> points = new Stack<int>();

            for (int i = 0; i < n; i++)
            {
                string[] input = Console.ReadLine().Split(' ');
         
                if (input[0] == "1")
                {
                    int min = Convert.ToInt32(input[2]);
                    int s = Convert.ToInt32(input[1]);
                    if (min <= 1) score += s;
                    else
                    {
                        assignments.Push(min - 1);
                        points.Push(s);
                    }
                }
                else if (assignments.Count > 0)
                {
                    int temp = assignments.Pop();
                    if (--temp > 0) assignments.Push(temp);
                    else score += points.Pop();
                }
            }
            Console.WriteLine(score);
        }
    }
}