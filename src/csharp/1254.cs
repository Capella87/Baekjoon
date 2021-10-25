// 백준 1254번 문제 : 팰린드롬 만들기
// https://www.acmicpc.net/problem/1254
// 알고리즘 분류 : 문자열, 브루트포스 알고리즘

/*
    This code implemented:
    a b a c a b a
          |||||||^ a b a c a b a   : 7
          ||||||^ b a c a b a      : 6
          |||||^                   : impossible (c and b are different)
          ||||^ c a b a            : 4
          |||^                     : impossible
          ||^                      : impossible
          |^                       : impossible
          ^                        : 0 (palindrome itself!)
    -> minimum required characters : 7 (+0);
*/

using System;

namespace palindrome
{
    public static class Palindrome
    {
        public static void Main()
        {
            string input = Console.ReadLine();
            int left = input.Length;
            int right = 0, pivot = input.Length;
            int req, min = input.Length * 2;

            for (int i = 0; i <= input.Length; i++)
            {
                req = input.Length;
                bool isPossible = true;
                left -= i % 2;
                right = i / 2;
                pivot -= i % 2;
                if (i % 2 == 0)
                {
                    for (int j = 0; j < right; j++)
                    {
                        if (input[pivot - 1 - j] != input[pivot + j])
                        {
                            isPossible = false;
                            break;
                        }
                        else req--;
                    }
                }
                else
                {
                    for (int j = 0; j < right; j++)
                    {
                        if (input[pivot - 1 - j] != input[pivot + 1 + j])
                        {
                            isPossible = false;
                            break;
                        } 
                        else req--;
                    }
                }
                if (isPossible)
                {
                    req += left;
                    min = (min > req) ? req : min;
                }
            }
            Console.WriteLine(min);
        }
    }
}