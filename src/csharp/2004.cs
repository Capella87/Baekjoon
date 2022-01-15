// 백준 2004번 문제 : 조합 0의 개수
// https://www.acmicpc.net/problem/2004
// 알고리즘 분류 : 수학, 정수론

using System;

namespace Combination
{
    static class MainApp
    {
        public static void Main()
        {
            string[] input = Console.ReadLine().Split(' ');
            int n = int.Parse(input[0]);
            int m = int.Parse(input[1]);

            Console.WriteLine(ZeroCount(n, m));

            // Use the definition of binomial coefficient.
            // Also, multiplication means + in 'count' variables.
            int ZeroCount(int n, int m)
            {
                FactorialCount(n, out int nt, out int nf);
                FactorialCount(m, out int mt, out int mf);
                FactorialCount(n - m, out int nmt, out int nmf);

                return Min(nt - mt - nmt, nf - mf - nmf);
            }

            // Returns the number of two and the number of five in the factorial
            void FactorialCount(int n, out int twoCount, out int fiveCount)
            {
                twoCount = 0;
                fiveCount = 0;
                for (long i = 2; i <= n; i *= 2)
                    twoCount += (int)(n / i);
                for (long i = 5; i <= n; i *= 5)
                    fiveCount += (int)(n / i);
            }

            int Min(int a, int b)
            {
                return a > b ? b : a;
            }
        }
    }
}