// 백준 2804번 문제 : 크로스워드 만들기
// https://www.acmicpc.net/problem/2804
// 알고리즘 분류 : 구현, 문자열

using System;

namespace crossword
{
    class CrossWord
    {
        static void Main()
        {
            string[] input = Console.ReadLine().Split(' ');
            int[] len = { input[0].Length, input[1].Length };
            int firstStrJunction = 0, secondStrJunction = 0;

            foreach (char c in input[0])
            {
                if (input[1].Contains(c))
                {
                    firstStrJunction = input[0].IndexOf(c);
                    secondStrJunction = input[1].IndexOf(c);
                    break;
                }
            }
            char[,] crossWord = new char[len[1], len[0]];
            for (var i = 0; i < len[1]; i++)
            {
                if (i == secondStrJunction)
                {
                    for (var j = 0; j < len[0]; j++)
                        crossWord[i, j] = input[0][j];
                    continue;
                }
                for (var j = 0; j < len[0]; j++)
                {
                    if (j == firstStrJunction)
                        crossWord[i, j] = input[1][i];
                    else crossWord[i, j] = '.';
                }
            }
            printArray(crossWord, len);

            void printArray(char[,] crossword, int[] len) // Local function
            {
                for (var i = 0; i < len[1]; i++)
                {
                    for (var j = 0; j < len[0]; j++)
                        Console.Write(crossword[i, j]);
                    Console.WriteLine();
                }
            }
        }
    }
}