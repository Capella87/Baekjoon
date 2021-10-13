// 백준 1718번 문제 : 암호
// https://www.acmicpc.net/problem/1718
// 알고리즘 분류 : 문자열

using System;

namespace password
{
    class Password
    {
        static void Main()
        {
            string plaintext = Console.ReadLine();
            string key = Console.ReadLine();
            string encrypted = "";
            int n = key.Length;
            int i = 0;

            foreach (char c in plaintext)
            {
                if (c == ' ')
                    encrypted += c;
                else if (c >= 'a' && c <= 'z')
                {
                    int idx = i % n;
                    encrypted += (c - key[idx]) <= 0 ? (char)('z' + c - key[idx]) : (char)(c - key[idx] + 'a' - 1);
                }
                i++;
            }
            Console.WriteLine(encrypted);
        }
    }
}