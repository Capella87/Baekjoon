// 백준 1357번 문제 : 뒤집힌 덧셈
// https://www.acmicpc.net/problem/1357
// 알고리즘 분류 : 구현, 문자열

using System;

namespace Addition
{
    static class MainApp
    {
        public static void Main()
        {
            string[] numArr = Console.ReadLine().Split(' ');
            int rev_a = GetReversedNumber(numArr[0]);
            int rev_b = GetReversedNumber(numArr[1]);
            bool isFrontZero = true;

            string result = Convert.ToString(rev_a + rev_b);
            for (int i = result.Length - 1; i >= 0; i--)
            {
                while (isFrontZero && result[i] == '0' && i > 0)
                    i--;
                isFrontZero = false;
                if (!isFrontZero) Console.Write(result[i]);
            }
            Console.WriteLine();


            int GetReversedNumber(string target)
            {
                int total = 0;
                for (int i = target.Length - 1; i >= 0; i--)
                    total = total * 10 + (int)(target[i] - '0');
                return total;
            }
        }
    }
}