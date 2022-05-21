// 백준 16395번 문제 : 파스칼의 삼각형
// https://www.acmicpc.net/problem/16395
// 알고리즘 분류 : 수학, 다이나믹 프로그래밍, 조합론

using System;

namespace Pascal
{
    public static class Pascal
    {
        public static int Binomial(int n, int k)
        {
            int[,] b = new int[n + 1, k + 1];

            for (int i = 0; i < n + 1; i++)
            {
                int ran = Min(i, k) + 1;
                for (int j = 0; j < ran; j++)
                {
                    if (j == 0 || j == i)
                        b[i, j] = 1;
                    else b[i, j] = b[i - 1, j - 1] + b[i - 1, j];
                }
            }
            return b[n, k];

            int Min(int a, int b)
            {
                return a > b ? b : a;
            }
        }

        public static void Main()
        {
            string[] input = Console.ReadLine().Split(' ');
            int n = int.Parse(input[0]);
            int k = int.Parse(input[1]);

            Console.WriteLine(Binomial(n - 1, k - 1));
        }
    }
}