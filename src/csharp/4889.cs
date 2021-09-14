// 백준 4889번 문제 : 안정적인 문자열
// https://www.acmicpc.net/problem/4889
// 알고리즘 분류 : 자료 구조, 문자열, 스택

using System;
using System.Collections.Generic;

namespace stable
{
    class Stable
    {
        static void Main()
        {
            int calcCount = 1;
            while (true)
            {
                Stack<char> brackets = new Stack<char>();
                int missCount = 0;
                string input = Console.ReadLine();
                if (input.Contains('-')) break;
                for (int i = 0; i < input.Length; i++)
                {
                    if (input[i] == '{') brackets.Push(input[i]);
                    else if (input[i] == '}' && brackets.Count > 0) brackets.Pop();
                    else if (input[i] == '}' && brackets.Count == 0) missCount++;
                }
                int unstableCount = brackets.Count % 2 + brackets.Count / 2 + missCount % 2 + missCount / 2;
                Console.WriteLine($"{calcCount++}. {unstableCount}");
            }
        }
    }
}