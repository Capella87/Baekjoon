// 백준 1100번 문제 : 하얀 칸
// https://www.acmicpc.net/problem/1100
// 알고리즘 분류 : 구현, 문자열

using System;

namespace white
{
    class White
    {
        static void Main()
        {
            string[] arr = new string[8];
            int count = 0;
            for (var i = 0; i < 8; i++)
                arr[i] = Console.ReadLine();
            for (var i = 0; i < 8; i++)
            {
                for (var j = 0; j < 8; j++)
                {
                    if (i % 2 == 0 && j % 2 == 0 && arr[i][j] == 'F')
                        count++;
                    else if (i % 2 == 1 && j % 2 == 1 && arr[i][j] == 'F')
                        count++;
                }
            }
            Console.WriteLine(count);
        }
    }
}