// 백준 25306번 문제 : 연속 XOR
// https://www.acmicpc.net/problem/25306
// 알고리즘 분류 : 수학

using System;
using System.Collections.Generic;

namespace MultipleXOR
{
    public static class Program
    {
        public static void Main()
        {
            var range = Array.ConvertAll<string, long>(Console.ReadLine().Split(' '), long.Parse);
            long[] result;

            if (range[0] == range[1]) Console.WriteLine(range[0]);
            else
            {
                if (range[0] % 2 == 1)
                    result = new long[4] { range[0] ^ range[1], range[0] - 1, range[1] ^ range[0] - 1, range[0] };
                else
                    result = new long[4] { 1, range[1] + 1, 0, range[1] };

                Console.WriteLine(result[(range[1] - range[0] - 1) % 4]);
            }
        }
    }
}
