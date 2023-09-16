// 백준 2504번 문제 : 괄호의 값
// https://www.acmicpc.net/problem/2504
// 알고리즘 분류 : 구현, 자료 구조, 스택, 재귀

using System;
using System.Collections.Generic;

namespace Brackets
{
    public static class MainApp
    {
        public static void Main()
        {
            string input = Console.ReadLine();
            char prev = input[0];
            int temp = 0, sum = 0;
            Stack<char> bracket = new Stack<char>();
            var tempSum = new Stack<(int num, bool isAdd)>();

            for (int i = 0; i < input.Length; i++)
            {
                if ("([".Contains(input[i]))
                {
                    if (temp != 0) // prev == ')' || ']'
                    {
                        tempSum.Push((temp, true));
                        temp = 0;
                    }
                    bracket.Push(input[i]);
                    if (input[i] == '(') tempSum.Push((2, false));
                    else tempSum.Push((3, false));
                }
                else if (input[i] == ')')
                {
                    if (bracket.Count == 0) goto err_exit;

                    if (prev == '(')
                    {
                        if (temp == 0) temp = tempSum.Pop().num;
                        else temp *= tempSum.Pop().num;

                    }
                    else if (prev == ')' || prev == ']')
                    {
                        while (tempSum.Count > 0 && tempSum.Peek().isAdd)
                            temp += tempSum.Pop().num;
                        if (tempSum.Count == 0) goto err_exit;
                        else temp *= tempSum.Pop().num;
                    }
                    else goto err_exit;

                    if (bracket.Peek() == '(') bracket.Pop();
                    else goto err_exit;
                }
                else if (input[i] == ']')
                {
                    if (bracket.Count == 0) goto err_exit;

                    if (prev == '[')
                    {
                        if (temp == 0) temp = tempSum.Pop().num;
                        else temp *= tempSum.Pop().num;

                    }
                    else if (prev == ')' || prev == ']')
                    {
                        while (tempSum.Count > 0 && tempSum.Peek().isAdd)
                            temp += tempSum.Pop().num;
                        if (tempSum.Count == 0) goto err_exit;
                        else temp *= tempSum.Pop().num;
                    }
                    else goto err_exit;

                    if (bracket.Peek() == '[') bracket.Pop();
                    else goto err_exit;
                }

                prev = input[i];
            }
            while (tempSum.Count > 0)
            {
                if (tempSum.Peek().isAdd)
                    temp += tempSum.Pop().num;
                else if (temp > 0 && !tempSum.Peek().isAdd)
                    temp *= tempSum.Pop().num;
                else temp = tempSum.Pop().num;
            }
            if (bracket.Count == 0)
                sum = temp;

        err_exit:
            Console.WriteLine(sum);
        }
    }
}