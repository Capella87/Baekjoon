// 백준 1855번 문제 : 암호
// https://www.acmicpc.net/problem/1855
// 알고리즘 분류 : 구현, 문자열

using System;

namespace cryptography
{
    public class Cryptography
    {
        public static void Main()
        {
            int row = Convert.ToInt32(Console.ReadLine());
            string input = Console.ReadLine();
            int col = input.Length / row;
            char[,] outputStr = new char[col, row];
            for (int i = 0, cur = 0; i < col; i++)
            {
                if (i % 2 == 0)
                    for (var j = 0; j < row; j++)
                        outputStr[i, j] = input[cur++];
                else
                    for (var j = row - 1; j >= 0; j--)
                        outputStr[i, j] = input[cur++];
            }
            for (int i = 0; i < row; i++)
                for (int j = 0; j < col; j++)
                    Console.Write(outputStr[j, i]);
            Console.WriteLine();
        }
    }
}