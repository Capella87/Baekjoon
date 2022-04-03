// 백준 10829번 문제 : 이진수 변환
// https://www.acmicpc.net/problem/10829
// 알고리즘 분류 : 수학, 구현, 재귀

using System;
using System.Text;

namespace binary
{
    public class Program
    {
        public static void Main()
        {
            ulong n = Convert.ToUInt64(Console.ReadLine());
            StringBuilder result = new();
            while (n > 0)
            {
                result.Append(n % 2L);
                n /= 2L;
            }
            int len = result.ToString().Length;
            string rt = result.ToString();
            for (int i = len - 1; i >= 0; i--)
                Console.Write(rt[i]);
            Console.WriteLine();
        }
    }
}