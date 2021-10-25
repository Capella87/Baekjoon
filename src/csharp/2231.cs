// 백준 2231번 문제 : 분해합
// https://www.acmicpc.net/problem/2231
// 알고리즘 분류 : 브루트포스 알고리즘

using System;

namespace gen
{
    public class Gen
    {
        public static void Main()
        {
            int n = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine(GetDigitGenerator(n));

            int GetDigitGenerator(int n)
            {
                int rt = 0;
                for (var i = 1; i <= n; i++)
                {
                    int temp = i;
                    int gen = i;
                    while (temp != 0)
                    {
                        gen += temp % 10;
                        temp /= 10;
                    }
                    if (gen == n)
                    {
                        rt = i;
                        break;
                    }
                }
                return rt;
            }
        }
    }
}