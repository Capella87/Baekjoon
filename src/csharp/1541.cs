// 백준 1541번 문제 : 잃어버린 괄호
// https://www.acmicpc.net/problem/1541
// 알고리즘 분류 : 수학, 문자열, 그리디 알고리즘, 파싱

using System;

namespace LostBrackets
{
    public static class MainApp
    {
        public static void Main()
        {
            string input = Console.ReadLine();

            bool isSubtract = false;
            int total = 0, temp = 0, number = 0;

            for (int i = 0; i < input.Length; i++)
            {
                if (input[i] >= '0' && input[i] <= '9')
                {
                    number = number * 10 + (int)(input[i] - '0');
                    continue;
                }
                else if (input[i] == '-')
                {
                    if (!isSubtract)
                    {
                        isSubtract = true;
                        total += number;
                    }
                    else
                    {
                        temp += number;
                        total -= temp;
                        temp = 0;
                    }
                }
                else
                {
                    if (!isSubtract) total += number;
                    else temp += number;
                }
                number = 0;
            }
            if (isSubtract) total -= temp + number;
            else total += number;

            Console.WriteLine(total);
        }
    }
}