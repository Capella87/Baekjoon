// 백준 1076번 문제 : 저항
// https://www.acmicpc.net/problem/1076
// 알고리즘 분류 : 구현

using System;

namespace resistance
{
    public enum Resistance
    {
        black, brown, red, orange, yellow, green, blue, violet, grey, white
    }

    public enum ResistanceMult
    {
        black = 1, brown = 10, red = 100,
        orange = 1000, yellow = 10000, green = 100_000,
        blue = 1_000_000, violet = 10_000_000, grey = 100_000_000,
        white = 1_000_000_000
    }

    public class Program
    {
        public static void Main()
        {
            string[] input = new string[3];
            input[0] = Console.ReadLine();
            input[1] = Console.ReadLine();
            input[2] = Console.ReadLine();
            Resistance first, second;
            ResistanceMult third;

            Enum.TryParse(input[0], out first); // Convert string to enum value.
            Enum.TryParse(input[1], out second);
            long result = Convert.ToInt64(first) * 10 + Convert.ToInt64(second);
            Enum.TryParse(input[2], out third);
            result *= Convert.ToInt64(third);
            Console.WriteLine(result);
        }
    }
}