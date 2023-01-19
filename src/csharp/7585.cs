// 백준 7585번 문제 : Brackets
// https://www.acmicpc.net/problem/7585
// 알고리즘 분류 : 자료 구조, 문자열, 파싱, 스택

using System;
using System.Collections.Generic;

namespace brackets
{
    public class Brackets
    {
        public static void Main()
        {
            while (true)
            {
                string input = Console.ReadLine();
                if (input == "#") break;
                Stack<char> stk = new Stack<char> ();
                int len = input.Length;
                foreach (char c in input)
                {
                    if ("({[".Contains(c)) stk.Push(c);
                    else if ("})]".Contains(c))
                    {
                        if (stk.Count > 0 && c == ')' && stk.Peek() == '(')
                            stk.Pop();
                        else if (stk.Count > 0 && c == ']' && stk.Peek() == '[')
                            stk.Pop();
                        else if (stk.Count > 0 && c == '}' && stk.Peek() == '{')
                            stk.Pop();
                        else break;
                    }
                }
                Console.WriteLine(stk.Count > 0 ? "Illegal" : "Legal");
            }
        }
    }
}