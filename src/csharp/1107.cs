// 백준 1107번 문제 : 리모컨
// https://www.acmicpc.net/problem/1107
// 알고리즘 분류 : 브루트포스 알고리즘

using System;

namespace RemoteController
{
    public static class Program
    {
        public static void Main()
        {
            int n = int.Parse(Console.ReadLine());

            int m = int.Parse(Console.ReadLine());
            bool[] isBroken = new bool[10];
            if (m > 0)
            {
                int[] arr = Array.ConvertAll<string, int>(Console.ReadLine().Split(' '), int.Parse);
                foreach (var a in arr)
                    isBroken[a] = true;
            }

            int count = Math.Abs(n - 100);
            bool isValid = false;

            if (n == 100)
            {
                Console.WriteLine(0);
                return;
            }

            for (int i = 0; i <= 1000000; i++)
            {
                if (i == 100) continue;

                isValid = true;
                int temp = i;
                int digit = 0;
                do
                {
                    if (isBroken[temp % 10]) isValid = false;
                    temp /= 10;
                    digit++;
                } while (temp != 0);
                if (!isValid) continue;

                count = Math.Min(count, digit + Math.Abs(n - i));
            }

            Console.WriteLine(count);
        }
    }
}