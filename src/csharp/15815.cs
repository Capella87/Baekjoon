// 백준 15815번 문제 : 천재 수학자 성필
// https://www.acmicpc.net/problem/15815
// 알고리즘 분류 : 자료 구조, 스택

using System;
using System.Collections.Generic;

namespace reversePolish
{
    class reversePolish
    {
        static void Main()
        {
            Stack<int> num = new Stack<int>();
            int a, b;

            string expr = Console.ReadLine();
            int len = expr.Length;
            for (int i = 0; i < len; i++)
            {
                if (expr[i] >= '0' && expr[i] <= '9')
                    num.Push(Convert.ToInt32(expr[i] - '0'));
                else
                {
                    b = num.Pop();
                    a = num.Pop();
                    switch(expr[i])
                    {
                        case '+':
                            num.Push(a + b);
                            break;
                        case '-':
                            num.Push(a - b);
                            break;
                        case '*':
                            num.Push(a * b);
                            break;
                        case '/':
                            num.Push(a / b);
                            break;
                    }
                }
            }
            Console.WriteLine(num.Pop());
        }
    }
}