// 백준 17176번 문제 : 암호해독기
// https://www.acmicpc.net/problem/17176
// 알고리즘 분류 : 구현, 문자열

using System;

namespace Decryption
{
    class Decryption
    {
        public static void Main()
        {
            int n = Convert.ToInt32(Console.ReadLine());
            string[] input = Console.ReadLine().Split(' ', StringSplitOptions.RemoveEmptyEntries);
            int[] charCount = new int[53];
            int[] plainCharCount = new int[53];

            foreach (string i in input)
                charCount[Convert.ToInt32(i)]++;

            string plainText = Console.ReadLine();
            foreach (char c in plainText)
            {
                if (c == ' ') plainCharCount[0]++;
                else if (c >= 'a' && c <= 'z') plainCharCount[c - 'a' + 27]++;
                else if (c >= 'A' && c <= 'Z') plainCharCount[c - 'A' + 1]++;
            }
            for (int i = 0; i < 53; i++)
                if (charCount[i] != plainCharCount[i])
                    goto no;
            Console.WriteLine("y");
            return;
        no:
            Console.WriteLine("n");
        }
    }
}