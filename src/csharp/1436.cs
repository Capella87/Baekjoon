// 백준 1436번 문제 : 영화감독 숌
// https://www.acmicpc.net/problem/1436
// 알고리즘 분류 : 브루트포스 알고리즘

using System;

namespace SixSixSix
{
    public class SixSixSix
    {
        public static void Main()
        {
            int n = Convert.ToInt32(Console.ReadLine());
            int i = 0;
            ulong num = 0;

            while (i < n)
            {
                num++;
                string converted = num.ToString();
                int sixDupCount = 0;
                bool isSix = false, isTitle = false;

                foreach (char c in converted)
                {
                    if (c == '6')
                    {
                        if (!isSix)
                        {
                            isSix = true;
                            sixDupCount = 0;
                        }
                        sixDupCount++;
                    }
                    else isSix = false;

                    if (sixDupCount >= 3) isTitle = true;
                }
                if (isTitle) i++;
            }
            Console.WriteLine(num);
        }
    }
}