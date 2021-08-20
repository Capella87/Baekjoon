// 백준 5532번 문제 : 방학 숙제
// https://www.acmicpc.net/problem/5532
// 알고리즘 분류 : 수학, 사칙연산

using System;

namespace vacation
{
    class Vacation
    {
        static void Main(string[] args)
        {
            int l = Convert.ToInt32(Console.ReadLine());
            int a = Convert.ToInt32(Console.ReadLine());
            int b = Convert.ToInt32(Console.ReadLine());
            int c = Convert.ToInt32(Console.ReadLine());
            int d = Convert.ToInt32(Console.ReadLine());

            int korean = a / c + ((a % c) > 0 ? 1 : 0);
            int english = b / d + ((b % d) > 0 ? 1 : 0);
            Console.WriteLine($"{l - (korean > english ? korean : english)}");
        }
    }
}