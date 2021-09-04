// 백준 1934번 문제 : 최소공배수
// https://www.acmicpc.net/problem/1934
// 알고리즘 분류 : 수학, 정수론, 유클리드 호제법

using System;

namespace euclid
{
    class Euclid
    {
        public UInt64 getGCD(UInt64 a, UInt64 b)
        {
            return (a % b == 0) ? b : getGCD(b, a % b);
        }

        static void Main()
        {
            Euclid result = new Euclid();
            int n = Convert.ToInt32(Console.ReadLine());

            for (int i = 0; i < n; i++)
            {
                string[] inputs = Console.ReadLine().Split();
                UInt64 a = UInt64.Parse(inputs[0]);
                UInt64 b = UInt64.Parse(inputs[1]);

                if (a < b)
                {
                    UInt64 temp = a;
                    a = b;
                    b = temp;
                }
                Console.WriteLine(a * b / result.getGCD(a, b));
            }
        }
    }
}