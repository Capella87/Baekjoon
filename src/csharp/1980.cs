// 백준 1980번 문제 : 햄버거 사랑
// https://www.acmicpc.net/problem/1980
// 알고리즘 분류 : 수학, 구현, 브루트포스 알고리즘

using System;

namespace Hamburger
{
    class Hamburger
    {
        public static void Main()
        {
            string[] input = Console.ReadLine().Split(' ');
            int n = Convert.ToInt32(input[0]);
            int m = Convert.ToInt32(input[1]);
            int t = Convert.ToInt32(input[2]);
            int burgerMaxCount = 0, colaMinCount = t;

            for (int i = 0; i * n <= t; i++) // Subtract n
            {
                int temp = t - (i * n);
                int mCount = temp / m;
                int colaCount = temp % m;

                if (colaCount == colaMinCount && burgerMaxCount < i + mCount || colaCount < colaMinCount)
                {
                    colaMinCount = colaCount;
                    burgerMaxCount = i + mCount;
                }
            }
            for (int i = 0; i * m <= t; i++) // Subtract m
            {
                int temp = t - (i * m);
                int nCount = temp / n;
                int colaCount = temp % n;

                if (colaCount == colaMinCount && burgerMaxCount < i + nCount || colaCount < colaMinCount)
                {
                    colaMinCount = colaCount;
                    burgerMaxCount = i + nCount;
                }
            }
            Console.WriteLine($"{burgerMaxCount} {colaMinCount}");
        }
    }
}