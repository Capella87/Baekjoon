// 백준 2703번 문제 : Cryptoquote
// https://www.acmicpc.net/problem/2703
// 알고리즘 분류 : 구현, 문자열

using System;
using System.Text;

namespace cryptoquote
{
    public static class CryptoQuote
    {
        public static void Main()
        {
            int n = Convert.ToInt32(Console.ReadLine());
            for (int i = 0; i < n; i++)
            {
                StringBuilder target = new StringBuilder(Console.ReadLine());
                string rule = Console.ReadLine();
                decrypt(ref target, ref rule);
                Console.WriteLine(target);
            }

            void decrypt(ref StringBuilder target, ref string rule)
            {
                int len = target.Length;
                for (int i = 0; i < len; i++)
                    if (target[i] != ' ')
                        target[i] = rule[target[i] - 'A'];
            }
        }
    }
}