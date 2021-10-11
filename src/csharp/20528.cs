// 백준 20528번 문제 : 끝말잇기
// https://www.acmicpc.net/problem/20528
// 알고리즘 분류 : 문자열, 애드 혹

using System;

namespace wordrelay
{
    class WordRelay
    {
        static void Main()
        {
            int n = Convert.ToInt32(Console.ReadLine());
            string[] strList = Console.ReadLine().Split(' ');
            char start = strList[0][0];
            int isPossible = 1;

            foreach (string str in strList)
            {
                if (!str.EndsWith(start) || !str.StartsWith(start))
                {
                    isPossible = 0;
                    break;
                }
            }
            Console.WriteLine(isPossible);
        }
    }
}