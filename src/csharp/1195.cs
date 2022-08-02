// 백준 1195번 문제 : 킥다운
// https://www.acmicpc.net/problem/1195
// 알고리즘 분류 : 구현, 브루트포스 알고리즘

using System;

namespace Kickdown
{
    public static class MainApp
    {
        public static void Main()
        {
            string[] arr = new string[2];
            arr[0] = Console.ReadLine();
            arr[1] = Console.ReadLine();

            int min = arr[0].Length + arr[1].Length;
            int shorter = arr[0].Length > arr[1].Length ? 1 : 0;
            int longer = shorter == 1 ? 0 : 1;
            int currentLength = min;
            
            for (int i = 0; i < arr[shorter].Length; i++)
            {
                currentLength--;
                bool isPossible = true;
                for (int j = 0; j <= i; j++)
                {
                    if (arr[shorter][arr[shorter].Length - 1 - i + j] == arr[longer][j] && arr[longer][j] == '2')
                    {
                        isPossible = false;
                        break;
                    }
                }
                if (isPossible) min = currentLength;
            }
            int diff = arr[longer].Length - arr[shorter].Length;
            for (int i = 0; i < diff; i++)
            {
                bool isPossible = true;
                for (int j = 0; j < arr[shorter].Length; j++)
                {
                    if (arr[shorter][j] == arr[longer][i + 1 + j] && arr[shorter][j] == '2')
                    {
                        isPossible = false;
                        break;
                    }
                }
                if (isPossible) min = arr[longer].Length;
            }
            for (int i = 0; i < arr[shorter].Length - 1; i++)
            {
                currentLength++;
                bool isPossible = true;
                for (int j = 0; j < arr[shorter].Length - i - 1; j++)
                {
                    if (arr[shorter][j] == arr[longer][diff + 1 + i + j] && arr[shorter][j] == '2')
                    {
                        isPossible = false;
                        break;
                    }
                }
                if (isPossible && min > currentLength) min = currentLength;
            }

            Console.WriteLine(min);
        }
    }
}